#pragma once

namespace fre {
	//pricing European option
	double PriceByCRR(double S0, double U, double D, double R, unsigned int N, double K);

	//computing call payoff
	double CallPayoff(double z, double K);
	
	int factorial(int x);
	
	double PriceByCRRHW01(double S0, double U, double D, double R, unsigned int N, double K);
	
}