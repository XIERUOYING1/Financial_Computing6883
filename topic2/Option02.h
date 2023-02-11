#pragma once

namespace fre {
	//inputting and displaying option data
	int GetInputData(int& N, double& K);
	
	//pricing European option
	double * PriceByCRR(double S0, double U, double D, double R, unsigned int N, double K, double(*Payoff)(double z, double K));

	//computing call payoff
	double CallPayoff(double z, double K);
	
	//computing Put Payoff
	double PutPayoff(double z, double K);
	
	double DigitCallPayoff(double z, double K);
	
	double DigitPutPayoff(double z, double K);
	
}