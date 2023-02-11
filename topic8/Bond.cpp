#include "Bond.h"
#include <cmath>
namespace fre {
    double Bond::PriceBond(double F, double T, double y)
    {
        double PVC = 0;
        int i;
        for (i = 1; i <= T; i++)
        {
            PVC += C*exp(-y*i);
        }
        return PVC + F * exp(-y*T);
    }
    double Bond::DerivBond(double F, double T, double y)
    {
        double PVCderiv = 0;
        int i;
        for (i = 1; i <= T; i++)
        {
            PVCderiv -= i*C*exp(-y*i);
        }
        return PVCderiv - T*F*exp(-y*T);
    }
    double Intermediary::Value(double y)
    {
        return PriceBond(F,T,y);
    }
    double Intermediary::Deriv(double y)
    {
        return DerivBond(F,T,y);
    }
}
