#include "PathDepOption02.h"
#include <cmath>

namespace fre {
    void Rescale(SamplePath& S, double x, int d)
    {
        
        int m = S.size();
        for (int j = 0; j < m; j++) S[j][d] = x * S[j][d];
    }
    
    double PathDepOption::PriceByMC(MCModel& Model, long N, double epsilon)
    {
        double H1 = 0.0, Heps1 = 0.0, Heps2 = 0.0, Heps3 = 0.0;
        SamplePath S(m);

        for (long i = 0; i < N; i++)
        {
            Model.GenerateSamplePath(T, m, S);
            H1 = (i * H1 + Payoff(S)) / (i + 1.0);
            Rescale(S, 1.0 + epsilon, 0);
            Heps1 = (i * Heps1 + Payoff(S)) / (i + 1.0);
            Rescale(S, 1/(1.0 + epsilon), 0);
            Rescale(S, 1.0 + epsilon, 1);
            Heps2 = (i * Heps2 + Payoff(S)) / (i + 1.0);
            Rescale(S, 1/(1.0 + epsilon), 1);
            Rescale(S, 1.0 + epsilon, 2);
            Heps3 = (i * Heps3 + Payoff(S)) / (i + 1.0);
        }
        /*for (long i = 0; i < N; i++)
        {
            Rescale(S, 1/(1.0 + epsilon), 0);
            //Rescale(S, 1.0 + epsilon, 1);
            H2 = (i * H2 + Payoff(S)) / (i + 1.0);
            //Rescale(S, 1/(1.0 + epsilon), 0);
            Rescale(S, 1.0 + epsilon, 1);
            Heps2 = (i * Heps2 + Payoff(S)) / (i + 1.0);
        }
        for (long i = 0; i < N; i++)
        {
            //Model.GenerateSamplePath(T, m, S);
            H3 = (i * H3 + Payoff(S)) / (i + 1.0);
            Rescale(S, 1/(1.0 + epsilon), 1);
            Rescale(S, 1.0 + epsilon, 2);
            Heps3 = (i * Heps3 + Payoff(S)) / (i + 1.0);
        }*/
        
        Price = std::exp(-Model.GetR() * T) * H1;
        delta0 = std::exp(-Model.GetR() * T) * (Heps1 - H1) / (epsilon * Model.GetS0()[0]);
        delta1 = std::exp(-Model.GetR() * T) * (Heps2 - H1) / (epsilon * Model.GetS0()[1]);
        delta2 = std::exp(-Model.GetR() * T) * (Heps3 - H1) / (epsilon * Model.GetS0()[2]);
        return Price;
    }

    
    double ArthmAsianCall::Payoff(const SamplePath& S) const
    {
        double Ave = 0.0;
        int d = S[0].size();
        Vector one(d);
        for (int i = 0; i < d; i++) one[i] = 1.0;
        for (int k = 0; k < m; k++)
        {
            Ave = (k * Ave + (one ^ S[k])) / (k + 1.0);
        }
        if (Ave < K) return 0.0;
        return Ave - K;
    }
}
