#include <iostream>
#include <iomanip>
#include "BinomialTreeModel02.h"
#include "Option05.h"
using namespace std;
using namespace fre;
int main()
{
	int N = 8;
	double U = 1.15125, D = 0.86862, R = 1.00545;
	double S0 = 106.00, K = 100.00, K1 = 100.00, K2 = 110.00;
	BinomialTreeModel Model(S0, U, D, R);
	Call call(N, K);
	OptionCalculation callCalculation(&call);
	cout << "European call = " << fixed << setprecision(2) << callCalculation.PriceByCRR(Model) << endl;
	Put put(N, K);
	OptionCalculation putCalculation(&put);
	cout << "European put = "<< fixed << setprecision(2) << putCalculation.PriceByCRR(Model) << endl;
	BullSpread bullspread(N,K1,K2);
	OptionCalculation bullspreadCalculation(&bullspread);
	cout << "Bull Spread = " << fixed << setprecision(2) << bullspreadCalculation.PriceByCRR(Model) << endl;
	BearSpread bearspread(N,K1,K2);
	OptionCalculation bearspreadCalculation(&bearspread);
	cout << "Bear Spread = " << fixed << setprecision(2) << bearspreadCalculation.PriceByCRR(Model) << endl;
	
	return 0;
}
/*
European call = -11.43
European put = -21.68
Bull Spread = 4.72
Bear Spread = 4.86
*/