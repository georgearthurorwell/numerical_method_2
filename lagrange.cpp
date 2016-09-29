#include <iostream>

using namespace std;

long double power_(int n)
{
    return (n % 2 == 0 ? 1 : -1);
}

long double lagrange(long double * x, long double * y, int n, long double x_)
{
    // x - массив значений аргументов
    // y - массив значений функции
    // x_ - точка в которой ищем значение
    // n - размер массивов x и y

    long double P_x = 0;
    for (int i = 0; i < n-1; ++i)
    {
        long double P = 1;
        for (int j = 0; j < n-1; ++j)
        {
            if(i != j)
            {
                P = P * (x_ - x[j]) / (x[i] - x[j]);
            }
        }
        P_x = P_x + y[i] * P;
    }
    return P_x;
}
