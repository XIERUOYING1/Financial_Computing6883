// TestEuropeanOption.cpp
// Test program for the exact solutions of European options.
// (C) Datasim Component Technology BV 2003-2006
//

#include "EuropeanOption.hpp"
#include <iostream>
#include <math.h>

int main()
{
	// Call option on a stock
	EuropeanOption callOption;
	cout << callOption.GetOptType() << " option on a stock: " << callOption.Price() << endl;
	
	// Put option on a stock index
	double r2 = 0.10;
	double sig2 = 0.30;
	double K2 = 50.0;
	double T2 = 0.25;
	double U2 = 50.0;
	double b2 = r2;
	char optT2 = 'P';
	char *opt2 = &optT2;
	
	EuropeanOption putOption(r2,sig2,K2,T2,U2,b2,opt2);
	cout << putOption.GetOptType() << " option on a stock: " << putOption.Price() << endl;
	double U3 = 50.0 - 1.5 * exp(-0.1*(2.0/12.0));
	EuropeanOption putOptionwDividend(0.1,0.3,50.0,0.25,U3,0.1,opt2);
	cout << putOptionwDividend.GetOptType() << " option with dividend: " << putOptionwDividend.Price() << endl;
	
	return 0;
}

/*
Call option on a stock: 2.13293
Put option on a stock: 2.37561
Put option with dividend: 3.03039
*/