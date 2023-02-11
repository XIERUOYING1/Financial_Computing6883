#pragma once
#include "Option05.h"
namespace fre {
    class DoubDigitOpt : public EurOption
    {
    private:
        double K1, K2;
    public:
        DoubDigitOpt(int N_, double K1_, double K2_) : EurOption(N_), K1(K1_), K2(K2_) {};
        ~DoubDigitOpt() {}
        double Payoff(double z) const;
    };
    class Strangle : public EurOption
    {
    private:
        double K1, K2;
    public:
        Strangle(int N_, double K1_, double K2_) : EurOption(N_), K1(K1_), K2(K2_) {}
        ~Strangle() {}
        double Payoff(double z) const;
    };
    class Butterfly : public EurOption
    {
    private:
        double K1, K2;
    public:
        Butterfly(int N_, double K1_, double K2_) : EurOption(N_), K1(K1_), K2(K2_) {}
        ~Butterfly() {}
        double Payoff(double z) const;
    };
}