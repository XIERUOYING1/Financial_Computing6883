#pragma once
#include "NonlinearSolver02.h"
namespace fre {
    class Bond
    {
    private:
        double C;
    public:
        Bond(double C_) : C(C_) {}
        double PriceBond(double F, double T, double y);
        double DerivBond(double F, double T, double y);
    };
    
    class Intermediary : public Bond, public Function
    {
    private:
        double F, T;
    public:
        Intermediary(double F_, double T_, double C_)
            : Bond(C_), F(F_), T(T_) {}
        double Value(double y);
        double Deriv(double y);
    };
}