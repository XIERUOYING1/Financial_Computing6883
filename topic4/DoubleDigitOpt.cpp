#include "DoubleDigitOpt.h"
namespace fre {
    double DoubDigitOpt::Payoff(double z) const
    {
        if (K1 < z && z < K2)
            return 1.0;
        return 0.0;
    }
    double Strangle::Payoff(double z) const
    {
        if (z<=K1) return K1-z;
        else if (K2<z) return z-K2;
        else return 0.0;
    }
    double Butterfly::Payoff(double z) const
    {
        if (z>K1 && z<=(K1+K2)/2) return z-K1;
        else if (z<=K2 && z>(K1+K2)/2) return K2-z;
        else return 0.0;
    }
}