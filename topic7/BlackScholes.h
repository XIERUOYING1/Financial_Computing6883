#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;
namespace fre {
    class BlackScholes
    {
    private:
        double S0;
        double r;
        double sigma;
        double T;
        double K;
        int N;
    public:
        BlackScholes(): S0(0), r(0), sigma(0), T(0), K(0), N(0) {}
        BlackScholes(double S0_, double r_,double sigma_, double T_, double K_, int N_)
                            :S0(S0_), r(r_), sigma(sigma_), T(T_), K(K_), N(N_) {}
        BlackScholes(const BlackScholes &B)
                            :S0(B.S0), r(B.r), sigma(B.sigma), T(B.T), K(B.K), N(B.N) {}
        ~BlackScholes() {}
        void UpdateBlackScholes(double S0_, double r_, double sigma_, double T_, double K_, int N_)
        {
            S0 = S0_;
            r = r_;
            sigma = sigma_;
            T = T_;
            K = K_;
            N = N_;
        }
        double GetS0() const {return S0;}
        double Getr() const {return r;}
        double Getsigma() const {return sigma;}
        double GetT() const {return T;}
        double GetK() const {return K;}
        int getN() const {return N;}
        double CalculateU() const
        {
            return exp(sigma * sqrt(T/N));
        }
        double CalculateD() const
        {
            return 1 / (exp(sigma * sqrt(T/N)));
        }
        double CalculateR() const
        {
            return exp(r*T/N);
        }
    };
}