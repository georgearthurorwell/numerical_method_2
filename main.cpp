#include <iomanip>
#include <iostream>
#include <cmath>
#include <fstream>
#include "myvector.cpp"
#include "lagrange.cpp"
#include "gauss.cpp"

using namespace std;

//const long double eps = 0.000000000001;

long double polinom(long double * a, int N, long double x)
{
    long double f = 0;
    for(int i = 0; i < N; ++i)
    {
        //cout << a[i] << " ";
        f += a[i] * pow(x, N-1-i);
    }
    return f;
}

int main()
{
    // DEFINE N, f, x
    int N = 9;
    int M = 2 * N -1;
    long double a = 0.0;
    long double b = 1.0;
    long double l = (b - a);
    long double h = l / (N - 1);
    long double h_m = l / (M - 1);

    long double * x = new long double[N];
    for(int i = 0; i < N; ++i)
    {
        x[i] = a + h * i;
    }

    long double * f = new long double[N];
    for(int i = 0; i < N; ++i)
    {
        // f[i] = x[i] + 1.0;
        f[i] = 10 * pow(x[i],8) + pow(x[i],3) + 3 * pow(x[i],2) + 7; //10*x^8+x^3+3x^2+7 
    }

    cout.setf(ios::showpos);
    long double * x_m = new long double [M];
    for(int i = 0; i < M; ++i)
    {
        x_m[i] = a + h_m * i;
    }

    long double * f_m = new long double[M];
    for(int i = 0; i < M; ++i)
    {
        // f[i] = x[i] + 1.0;
        f_m[i] = 10 * pow(x_m[i],8) + pow(x_m[i],3) + 3 * pow(x_m[i],2) + 7; //10*x^8+x^3+3x^2+7 
    }

    myvector * m = new myvector [N];
    for (int i = 0; i < N; ++i)
    {
        long double * v_ = new long double[N + 1];
        v_[N] = f[i]; //some function f(x[i])
        v_[N-1] = 1;
        for (int j = N-2; j >= 0; --j)
        {
            v_[j] = v_[j+1] * x[i];
        }
        m[i].set(N + 1, v_);
    }
    //END DEFINE

    long double * solutions = resolve_gauss(m);

    for(int i = 0; i < N; ++i)
    {
        cout << solutions[i] << " ";
    }

    long double * delta = new long double[M];

    myvector delta_l;
    for(int i = 0; i < M; ++i)
    {
        delta[i] = abs(f_m[i] - lagrange(x,f,N,x_m[i]));
    }
    delta_l = myvector(M, delta);

    myvector delta_g;
    for(int i = 0; i < M; ++i)
    {
        delta[i] = abs(f_m[i] - polinom(solutions,N,x_m[i]));
    }
    delta_g = myvector(M, delta);

    cout << max(delta_l) << " " << max(delta_g) << endl;

    ofstream fout("output.txt");
    for(int i = 0; i < M; ++i)
    {
        fout << x_m[i] << " " << lagrange(x,f,N,x_m[i]) << " " << polinom(solutions,N,x_m[i]) << endl;
    }
    fout.close();
}