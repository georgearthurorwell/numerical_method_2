#include <iomanip>
#include <iostream>
#include <cmath>
#include <fstream>
#include "myvector.cpp"
#include "lagrange.cpp"

using namespace std;

const long double eps = 0.000000000001;

int main()
{
    // DEFINE N, f, x
    int N = 101;
    int M = 2 * N -1;
    long double l = 1.0;
    long double h = 1.0 / (N - 1);
    long double h_m = 1.0 / (M - 1);

    long double a[N] = {};

    long double x[N] = {};
    for(int i = 0; i < N; ++i)
    {
        x[i] = h * i;
    }

    long double f[N] = {};
    for(int i = 0; i < N; ++i)
    {
        f[i] = pow(x,2) + x + 1.0;
    }

    myvector * y = new myvector[N];
    long double coords[N] = {};
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            coords[j] = pow(x[j], i); // DEFINE y_i
        }
        y[i] = myvector(N, coords);
    }

    long double x_m[N] = {};
    for(int i = 0; i < N; ++i)
    {
        x_m[i] = h_m * i;
    }

    //END DEFINE



    ofstream fout("output.txt");
    for(int i = 0; i < M; ++i)
    {
        fout << x_m[i] << ' ' << lagrange(x,f,N,x_m[i]) << endl;
    }
    fout.close();
}