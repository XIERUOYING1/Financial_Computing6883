#include <iostream>
#include <iomanip>
#include "Function02.h"
#include "NonlinearSolver02.h"
#include "Bond.h"
using namespace std;
using namespace fre;
int main()
{
    double F=100.0;
    double T=3.0;
    double C=1.2;
    double Tgt=98.56;
    
    Intermediary BondB(F,T,C);

    double Acc=0.0001;
    double LEnd=0.0;
    double REnd=1.0;
    double Guess=0.2;
    NonlinearSolver solver(Tgt,LEnd,REnd,Acc,Guess);
    cout << "Yield by bisection method: " << fixed << setprecision(4) << solver.SolveByBisect(&BondB) << endl;
    cout << "Yield by Newton-Raphson method: " << fixed << setprecision(4) << solver.SolveByNR(&BondB) << endl;
    return 0;
}

/*
Yield by bisection method: 0.0168
Yield by Newton-Raphson method: 0.0168
*/
