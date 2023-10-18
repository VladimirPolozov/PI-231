/***************************************
* Author: Владимир Полозов             *
* Name: Циклы с пред- и постусловием   *
* URL: https://onlinegdb.com/mBh-qhedC *
****************************************/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
  float T, V1, A1[9], A2[9];
  float V2 = 2;
  const float R = 8.31; // газовая постоянная кДж/град
  const float n = 1.2;  // показатель адиабаты
  
  cout << "Температура процесса (в Кельвинах) = ";
  cin >> T; // 320
  cout << "Начальный объём газа (в м3) = ";
  cin >> V1; // 2
  cout << "Конечный объём газа (в м3, 9 значений отделенных переносом строки):\n";
  // 2.2, 2.4, 2.6, 2.8, 3, 4, 5, 6, 7}

  cout << fixed;
  cout << setprecision(3);
  
  do {
    V2 += 0.2;
    cout << "V2 = " << V2\
         << "\tA1 = " << R * T * log( ( V2 / V1 ) )\
         << "\tA2 = " << R * T / (n - 1) * ( 1 - pow( ( V1 / V2 ), (n - 1) ) ) << endl;
  } while (V2 < 3);
  while (V2 < 7) {
    V2 += 1;
    cout << "V2 = " << V2\
         << "\tA1 = " << R * T * log( ( V2 / V1 ) )\
         << "\tA2 = " << R * T / (n - 1) * ( 1 - pow( ( V1 / V2 ), (n - 1) ) ) << endl;
  }
  
  return 0;
}
