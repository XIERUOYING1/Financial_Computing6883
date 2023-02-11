#include <iostream>
#include <cmath>
using namespace std;

class DefInt
{
private:
    double a;
    double b;
    double (*f)(double x);
public:
    DefInt(double lower, double upper, double (*func)(double x))
    {
        a = lower;
        b = upper;
        f = func;
    }

    double ByTrapzoid(int N)
    {
        double h = (b-a)/N;
        double x[N+1],y[N+1];
        double result = 0;
        for (int k = 0; k <= N; k++)
        {
            x[k] = a + k * h;
            y[k] = f(x[k]);
        }
        for (int k = 1; k < N; k++)
        {
            result = result + 2*y[k];
        }
        result = h / 2 * (f(a) + result + f(b));
        return result;
    }
    double BySimpson(int N)
    {
        double h = (b-a)/N;
        double x[N+1],y[N+1];
        double result = 0;
        for (int k = 0; k <= N; k++)
        {
            x[k] = a + k * h;
            y[k] = f(x[k]);
        }
        for (int k = 1; k < N; k++)
        {
            if (k % 2 == 0)
                result = result + 2 * y[k];
            else
                result = result + 4 * y[k];
        }
        result = h / 3 * (f(a) + result + f(b));
        return result;
    }
    
};
double f(double x)
{
    return (x*x*x - x*x + 1);
    
}

int main()
{
	double a = 1.0;
	double b = 2.0;
	int N = 6;
	DefInt MyInt(a,b,f);
	cout << "The result of trapzoid is :" << MyInt.ByTrapzoid(N) << endl;
	cout << "The result of simpson is :" << MyInt.BySimpson(N) << endl;
	return 0;
}

/*
The result of trapzoid is :2.43287
The result of simpson is :2.41667
*/