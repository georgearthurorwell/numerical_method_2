#include <iomanip>
#include <iostream>
#include <cmath>
#include <fstream>

const long double eps = 1e-59;

long double *resolve_gauss(myvector *);

long double *resolve_gauss(myvector *m)
{
	int N = m[0].length - 1;
    //int M = N - 1;

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
            cout << "0000" << endl;
		}
		if (abs(m[i].m[i]) > eps)
		{
			for (int j = i + 1; j < N; ++j)
			{
				m[j] = m[i].m[i] * m[j] + (-m[j].m[i])* m[i];
                cout << j;
			}
            cout << "1111" << endl;
		}

        cout << "-----------------------------------------------------" << endl;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N+1; ++j)
            {
                cout << m[i].m[j] << " ";
            }
            cout << endl;
        }
        cout << "-----------------------------------------------------" << endl;

	}

//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 0; j < N+1; ++j)
//		{
//			cout << m[i].m[j] << " ";
//		}
//		cout << endl;
//	}

	long double *solutions = new long double[N];
	long double sum;

	// cout << N ;

	for (int i = N - 1; i >= 0; --i)
	{
		sum = 0;
		for (int j = i+1; j < N; ++j)
		{
			sum = sum + m[i].m[j] * solutions[j];
		}
		// if (abs(m[i].m[N] - sum) < eps && abs(m[i].m[i]) < eps)
		// {
		// 	cout << "INF";
		// 	return 0;
		// }
		// else if ((m[i].m[N] - sum) > eps && m[i].m[i] > eps)
		// {
		// 	cout << "NO";
		// 	return 0;
		// }
		//cout << i;
		solutions[i] = (m[i].m[N] - sum) / m[i].m[i];
	}

	return solutions;
}
