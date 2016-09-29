#include <iostream>
#define _USE_MATH_DEFINES // for C++
#include <cmath>

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
    int N = 11;
    int M = 2 * N -1;
    //long double l = 1.0;
    long double a = -1.0;
    long double b = 1.0;
    long double h = (b - a) / (N - 1);
    long double h_m = (b - a) / (M - 1);

    //long double a = new long double[N];

    long double *x = new long double[N];
    for(int i = 0; i < N; ++i)
    {
        x[i] = a + h * i;
    }

    long double *f = new long double[N];
    for(int i = 0; i < N; ++i)
    {
        f[i] = abs(x[i]);
	cout << f[i] << endl;
    }

    myvector * y = new myvector[N];
    long double *coords = new long double[N];
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            coords[j] = pow(x[j], i); // DEFINE y_i
        }
        y[i] = myvector(N, coords);
    }

    long double *x_m = new long double[M];
    for(int i = 0; i < M; ++i)
    {
        x_m[i] = a + h_m * i;
    }

//    myvector * m = new myvector [N+1];
//    for (int i = 0; i < N+1; ++i)
//    {
//        long double * v = new long double[N + 1];
//        for (int j = 0; j < M + 1; ++j)
//        {
//            v[j] = scal(f[i], f[j]);
//            cout << v[j] << endl;
//        }
//        m[i].set(M + 1, v);
//    }

    //END DEFINE



    ofstream fout("output.txt");
    for(int i = 0; i < M; ++i)
    {
        fout << x_m[i] << ' ' << lagrange(x,f,N,x_m[i]) << endl;
    }
    fout.close();
}
