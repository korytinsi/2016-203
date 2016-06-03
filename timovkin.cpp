#include "timovkin.h"

/**
 * Метод Гаусса
 */
void timovkin::lab1()
{
float c;
for (int i = 0; i<N; i++)
 for (int k=i+1;k<N;k++)
 {
   c=A[k][i]/A[i][i];
   b[k]=b[k]-b[i]*c;
   for (int j=0;j<N;j++)
     A[k][j]=A[k][j]-A[i][j]*c;
 }
 for (int i = N-1; i>=0; i--)
 for (int k=i-1;k>=0;k--)
 {
   c=A[k][i]/A[i][i];
   b[k]=b[k]-b[i]*c;
   for (int j=N-1;j>=0;j--)
     A[k][j]=A[k][j]-A[i][j]*c;
 }
 for (int j = 0; j<N; j++)
    x[j]=b[j]/A[j][j];
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void timovkin::lab2()
{
   float s,c,max1,l,l1;
 int p;
 max1=abs(A[0][0]);int d=0;
 for(int i=1; i<N;i++)
   if (abs(A[i][0])>max1)
      { max1=abs(A[i][0]); d=i;};

if (p!=0)
{
  for (int j=0;j<N;j++)
   {
    l=A[0][j];    A[0][j]=A[d][j];    A[d][j]=l;
    l1=b[0];    b[0]=b[p];    b[p]=l1;
    }
}
for (int k = 0; k<N; k++)
     for (int i=k+1;i<N;i++)
     {
         float c=A[i][k]/A[k][k];
         b[i]=b[i]-(b[k]*c);
      for (int j=0;j<N;j++)
      {
           A[i][j]=A[i][j]-(A[k][j]*c);

      }
     }


      for(int i=N-1; i>=0; i--)

      {s=0;
          for(int j=i+1; j<N; j++)
             s=s+A[i][j]*x[j];
         x[i]=(b[i]-s)/(A[i][i]);
      }
}

/**
 * Метод квадратного корня (метод Холецкого)
 */
void timovkin::lab3()
{
double** L = new double*[N];
  for (int i=0; i<N; i++)
  L[i] = new double[N];
  double* y = new double[N];

   for (int i=0; i<N; i++)
    for (int j=0; j<N; j++)
     {L[i][j]=0;}

  for(int i=0;i<N;i++)
  {
   for(int k=0;k<=i-1;k++)
    L[i][i]+=L[i][k]*L[i][k];
   L[i][i]=sqrt(A[i][i]-L[i][i]);
   for(int j=i+1;j<N;j++)
   {
    for(int k=0;k<=i-1;k++)
     L[j][i]+=L[i][k]*L[j][k];
    L[j][i]=(A[i][j]-L[j][i])/L[i][i];
    }
  }
    double summa=0;
     for(int i=0;i<N;i++)
      {
       for(int j=0;j<i;j++){
        summa+=L[i][j]*y[j];}
       y[i]=(b[i]-summa)/L[i][i];
       summa=0;
      }
     for(int i=N-1;i>=0;i--)
      {
       for(int j=i+1;j<N;j++){
        summa+=L[j][i]*x[j];}
       x[i]=(y[i]-summa)/L[i][i];
       summa=0;
      }
      delete[] y;

}


/**
 * Метод прогонки
 */
void timovkin::lab4()
{
  double* k=new double[N];
 double* k1=new double[N];
    k[0]=-A[0][1]/A[0][0];
    k1[0]=b[0]/A[0][0];
   for(int i=1;i<N;i++)
    {
     k[i]=-A[i][i+1]/(A[i][i-1]*k[i-1]+A[i][i]);
     k1[i]=(b[i]-A[i][i-1]*k1[i-1])/(A[i][i-1]*k[i-1]+A[i][i]);
    }
    //вычисляем x
    x[N-1] = k1[N-1];
    for(int i=N-1; i>=0; i--){
     x[i] = k[i]*x[i+1]+k1[i];
    };
      delete[] k;
      delete[] k1;

}



/**
 * Ìåòîä ßêîáè
 */
void timovkin::lab5()
{

}



/**
 * Ìåòîä Çåéäåëÿ
 */
void timovkin::lab6()
{

}



/**
 * Îäèí èç ãðàäèåíòíûõ ìåòîäîâ
 */
void timovkin::lab7()
{

}
