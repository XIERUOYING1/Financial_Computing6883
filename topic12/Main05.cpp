#include <iostream>
#include "PathDepOption02.h"

using namespace std;
using namespace fre;
int main()
{
    int d=3;
    Vector S0(d);
    S0[0]=40.0;
    S0[1]=60.0;
    S0[2]=100.0;
    double r=0.03;

    Matrix C(d);
    for(int i=0;i<d;i++) C[i].resize(d);

    C[0][0] =  0.1;  C[0][1] = -0.1;  C[0][2] = 0.0;
    C[1][0] = -0.1;  C[1][1] =  0.2;  C[1][2] = 0.0;
    C[2][0] =  0.0;  C[2][1] =  0.0;  C[2][2] = 0.3;
    MCModel Model(S0,r,C);

   double T=1.0/12.0, K=200.0;
   int m=30;
   ArthmAsianCall Option(T,K,m);
   double epsilon = 0.001;
   

   long N=3000;
   Option.PriceByMC(Model, N, epsilon);
   cout << "Arithmetic Basket Call Price = " << Option.GetPrice() << endl
        << "delta[0] = " << Option.GetDelta0() << endl
        << "delta[1] = " << Option.GetDelta1() << endl
        << "delta[2] = " << Option.GetDelta2() << endl;

   return 0;
}


/*
Arithmetic Basket Call Price = 2.19309
delta[0] = 0.502435
delta[1] = 0.510151
delta[2] = 0.526581
*/