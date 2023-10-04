/****************************************
*  Author: Полозов В. А.                *
*  Name: Линейные алгоритмы             *
*  URL: https://onlinegdb.com/sFcHEb7P5 *
*****************************************/
#include <iostream>
#include <cmath>
#include <iomanip>


int main() {
  double l = 59.034; // теплопроводность Вт / м * град
  double R1 = 0.252; // в метрах
  double R2 = 0.293; // в метрах
  double t1 = 264; // градусов
  double t2 = 43; // градусов
  double F = 0.53; // площадь поверхности плоской стенки в м2
  double L = 1; // длина цилиндрической стенки в метрах
  double p = 3.1415926; // число пи
  double Q1 = 0;
  double Q2 = 0;
  double Q3 = 0;
  
  Q1 = l * F / (R2 - R1) * (t1 - t2);
  Q2 = 2 * p * l * L / log( (R2 / R1) ) * (t1 - t2);
  Q3 = 4 * p * l / (1 / R1 - 1 / R2) * (t1 - t2);
  
  std::cout << std::fixed;
  std::cout << std::setprecision(6) << Q1 << '\n' << Q2 << '\n' << Q3;
  
  return 0;
}




