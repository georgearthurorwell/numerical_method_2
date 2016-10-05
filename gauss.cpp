#include <iomanip>
#include <iostream>
#include <cmath>
#include <fstream>

const long double eps = 0.000000000001;

long double *resolve_gauss(myvector *m)
{
	int N = m[0].length - 1;
	int M = N - 1;

	for (int i = 0; i < N; ++i)
	{
		if (abs(m[i].m[i]) < eps)
		{
			for (int j = i + 1; j < N; ++j)
			{
				if (abs(m[j].m[i]) > 0)
				{
					swap(m[j], m[i]);
				}
			}
		}
		if (abs(m[i].m[i]) > eps)
		{
			for (int j = i + 1; j < N; ++j)
			{
				m[j] = m[i].m[i] * m[j] + (-m[j].m[i])* m[i];
			}
		}
	}

	long double *solutions = new long double[N];
	long double sum;

	for (int i = N - 1; i >= 0; --i)
	{
		sum = 0;
		for (int j = i+1; j < N; ++j)
		{
			sum = sum + m[i].m[j] * solutions[j];
		}
		if (abs(m[i].m[N] - sum) < eps && abs(m[i].m[i]) < eps)
		{
			cout << "INF";
			return 0;
		}
		// else if ((m[i].m[N] - sum) > eps && m[i].m[i] > eps)
		// {
		// 	cout << "NO";
		// 	return 0;
		// }
		solutions[i] = (m[i].m[N] - sum) / m[i].m[i];
	}

	return solutions;
}