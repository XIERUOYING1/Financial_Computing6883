#include "BinomialTreeModel02.h"
#include "Option08.h"
#include <iostream>
#include <iomanip>

using namespace std;
using namespace fre;

int main() 
{
	double S0 = 106.0;
	double r = 0.058;
	double sigma = 0.46;
	double T = (double)9/12;
	double K = 100.0;
	int N = 8;
	
	BlackScholes BS(S0, r, sigma, T, K, N);
    BinomialTreeModel Model(S0, BS.CalculateU(), BS.CalculateD(), BS.CalculateR());
    Call call(N, K);
    OptionCalculation callCalculation(&call);
    BinLattice<double> CallPriceTree(N);
    BinLattice<bool> CallStoppingTree(N);
    cout << setiosflags(ios::fixed) << setprecision(5);
    cout << "S0 = " << S0 << endl;
    cout << "r = " << r << endl;
    cout << "sigma = " << sigma << endl;
    cout << "T = " << T << endl;
    cout << "K = " << K << endl;
    cout << "N = " << N << endl << endl;
    cout << "U = " << BS.CalculateU() << endl;
    cout << "D = " << BS.CalculateD() << endl;
    cout << "R = " << BS.CalculateR() << endl << endl;
    cout << "American call option price = " << fixed << setprecision(3) << callCalculation.PriceBySnell(Model, CallPriceTree, CallStoppingTree) << endl;
    
    return 0;
}

/*
S0 = 106.00000
r = 0.05800
sigma = 0.46000
T = 0.75000
K = 100.00000
N = 8

U = 1.15125
D = 0.86862
R = 1.00545

American call option price = 21.682
*/
