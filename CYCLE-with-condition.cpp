/****************************************
*  Author: Полозов В. А.                *
*  Name: Циклы с пред- и постусловием   *
*  URL: https://onlinegdb.com/_6d4SpxKW *
*****************************************/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
  float T, V1, V2[9], A1[9], A2[9];
  const float R = 8.31; // газовая постоянная кДж/град
  const float n = 1.2;  // показатель адиабаты
  int index = 0;
  
  cout << "Температура процесса (в Кельвинах) = ";
  cin >> T; // 320
  cout << "Начальный объём газа (в м3) = ";
  cin >> V1; // 2
  cout << "Конечный объём газа (в м3, 9 значений отделенных переносом строки):\n";
  while (index < 9) {
      cin >> V2[index]; // 2.2, 2.4, 2.6, 2.8, 3, 4, 5, 6, 7}
      index += 1;
  }
  
  cout << fixed;
  cout << setprecision(3);
  index = 0;
  while (index < 9) {
    A1[index] = R * T * log( ( V2[index] / V1 ) );
    A2[index] = R * T / (n - 1) * ( 1 - pow( ( V1 / V2[index] ), (n - 1) ) );
    cout << "V2 = " << V2[index]\
           << "\tA1 = " << A1[index]\
             << "\tA2 = " << A2[index] << '\n';
    index += 1;
  }
  
  return 0;
}
