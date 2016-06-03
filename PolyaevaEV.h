#pragma once
#include "lab.h"

class PolyaevaEV : public lab
{
  /**
   * Метод Гаусса
   */
  virtual void lab1();
  /**
   * Метод Гаусса с выбором главного элемента
   */
  virtual void lab2();
  /**
   * Метод квадратного корня (метод Холецкого)
   */
  virtual void lab3();
  /**
   * Метод прогонки
   */
  virtual void lab4();
  /**
   * Метод Якоби
   */
  virtual void lab5();
  /**
   * Метод Зейделя
   */
  virtual void lab6();
  /**
   * Один из градиентных методов
   */
  virtual void lab7();


  void zeroing(double *x);
  double multiplication_of_vectors(double *x, double *y);

  void difference(double* x, double *y, double *z);

  double* multiplication_matrix_on_vector(double **A, double *y);
  void transposition(double **a, double **result);

 void multiplication(double **a, double **b, double **result);

void lab8();

};
