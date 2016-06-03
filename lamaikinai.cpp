#include "lamaikinai.h"

/**
 * ����� ������
 */
void lamaikinai::lab1()
{
 double t=0;
    for(int k=0; k<N; k++)
        {
            for(int i=k+1; i<N; i++)
                {
                    t=A[i][k]/A[k][k];
                    b[i]-=t*b[k];

                    for (int j=0; j<N; j++)
                        A[i][j]-=t*A[k][j];
                }
        }

        for(int i=N-1; i>=0; i--)
        {
            t=0;
            for(int j=i+1; j<N; j++)
            t+=A[i][j]*x[j];
            x[i]=(b[i]-t)/A[i][i];
        }
}


/**
 * ����� ������ � ������� �������� ��������
 */
void lamaikinai::lab2()
{

    double t=0;
    for(int k=0; k<N; k++)
        {
            double max_el=abs(A[k][k]);  //������ �����
            int max_id=k;
            for (int i=k+1; i<N; i++)
                {
                    if (abs(A[i][k]) > max_el)
                        {
                            max_el=abs(A[max_id][k]);
                            max_id=i;
                        }
                }
             for (int j=0; j<N; j++)
                std::swap(A[k][j], A[max_id][j]);
                std::swap(b[k], b[max_id]);


        for(int i=k+1; i<N; i++)
            {
                t=A[i][k]/A[k][k];
                b[i]-=t*b[k];

                for (int j=0; j<N; j++)
                    A[i][j]-=t*A[k][j];

            }
        }

        for(int i=N-1; i>=0; i--)
        {
            t=0;
            for(int j=i+1; j<N; j++)
            t+=A[i][j]*x[j];
            x[i]=(b[i]-t)/A[i][i];
        }

}



/**
 * ����� ����������� ����� (����� ���������)
 */
void lamaikinai::lab3()
{
    double **L = new double*[N];
	for (int i = 0; i<N; i++)
		L[i] = new double[N];

	double *y = new double[N];


	for (int i = 0; i < N; i++)
	{
		x[i] = 0;
		y[i] = 0;
		for (int j = 0; j < N; j++)
		{
			L[i][j] = 0;
		}
	}

	double t = 0;
	for (int i = 0; i<N; i++)
	{
		for (int k = 0; k <= i - 1; k++)
			t += L[i][k] * L[i][k];

		L[i][i] = sqrt(A[i][i] - t);
		t = 0;
		for (int j = i + 1; j<N; j++)
			{
				for (int k = 0; k <= i - 1; k++)
					t += L[i][k] * L[j][k];

				L[j][i] = (A[i][j] - t) / L[i][i];
				t = 0;
			}
	}


	for (int i = 0; i<N; i++)
	{
		t = 0;
		for (int j = 0; j<i; j++)
			t += L[i][j] * y[j];

		y[i] = (b[i] - t) / L[i][i];
	}


	for (int i = N - 1; i >= 0; i--)
	{
		t = 0;
		for (int j = i + 1; j<N; j++)
			t += L[j][i] * x[j];

		x[i] = (y[i] - t) / L[i][i];
	}

    delete[] y;
	for (int i = 0; i<N; i++)
		delete[] L[i];
	delete[] L;

}



/**
 * ����� ��������
 */
void lamaikinai::lab4()
{
    double* Alpha = new double[N];
	double* Beta = new double[N];

	Alpha[0] = -A[0][1] / A[0][0];
	Beta[0] = b[0] / A[0][0];

	for (int i = 1; i < N; i++)
	{
		Alpha[i] = -A[i][i + 1] / (A[i][i - 1] * Alpha[i - 1] + A[i][i]);
		Beta[i] = (b[i] - A[i][i - 1] * Beta[i - 1]) / (A[i][i - 1] * Alpha[i - 1] + A[i][i]);
	}

	x[N - 1] = Beta[N - 1];
	for (int i = N - 2; i >= 0; i--)
	{
		x[i] = Alpha[i] * x[i + 1] + Beta[i];
	}

	delete[] Alpha;
	delete[] Beta;
}



/**
 * ����� �����
 */
void lamaikinai::lab5()
{
long double eps = 0.0001;
    long double* y = new long double[N];
	long double norm;
    do {
		for (int i = 0; i < N; i++)
        {
			y[i] = b[i];
			for (int j = 0; j < N; j++)
			{
				if (i != j)
					y[i] -= A[i][j] * x[j];
			}
			y[i] /= A[i][i];
		}
        norm = abs(x[0] - y[0]);
		for (int h = 0; h < N; h++)
        {
			if (abs(x[h] - y[h]) > norm)
				norm = abs(x[h] - y[h]);
			x[h] = y[h];
		}
	} while (norm > eps);
	delete[] y;
}



/**
 * ����� �������
 */
void lamaikinai::lab6()
{
    long double eps = 0.0001;
    long double* y = new long double[N];
    long double norm = 0;
	long double var = 0;

    for (int i = 0; i < N; i++)
			x[i] = 0;
	do
	{
		for (int i = 0; i < N; i++)
			y[i] = x[i];

		for (int i = 0; i < N; i++)
		{
			var = 0;
            norm = 0;
			for (int j = 0; j < i; j++)
				var += (A[i][j] * x[j]);
			for (int j = i + 1; j < N; j++)
				var += (A[i][j] * x[j]);
			x[i] = (b[i] - var) / A[i][i];
			for (int i = 0; i < N; i++)
				norm += (x[i] - y[i])*(x[i] - y[i]);
		}
	} while (sqrt(norm) >= eps);

	delete[] y;
}



/**
 * ���� �� ����������� �������
 */
void lamaikinai::lab7()
{

}