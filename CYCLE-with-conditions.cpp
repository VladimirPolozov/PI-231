/***************************************
* Author: Владимир Полозов             *
* Name: Циклы с пред- и постусловием   *
* URL: https://onlinegdb.com/QVIbddiQA *
****************************************/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
  float T, V1, V2[9], A1[9], A2[9];
  const float R = 8.31; // газовая постоянная кДж/град
  const float n = 1.2;  // показатель адиабаты
  
  cout << "Температура процесса (в Кельвинах) = ";
  cin >> T; // 320
  cout << "Начальный объём газа (в м3) = ";
  cin >> V1; // 2
  cout << "Конечный объём газа (в м3, 9 значений отделенных переносом строки):\n";
  int input_counter = 0;
  while (input_counter < 9) {
      cin >> V2[input_counter]; // 2.2, 2.4, 2.6, 2.8, 3, 4, 5, 6, 7}
      input_counter += 1;
  }
  
  cout << fixed;
  cout << setprecision(3);
  
  int index_of_array_element = 0;
  while (index_of_array_element < 9) {
    A1[index_of_array_element] = R * T * log( ( V2[index_of_array_element] / V1 ) );
    A2[index_of_array_element] = R * T / (n - 1) * ( 1 - pow( ( V1 / V2[index_of_array_element] ), (n - 1) ) );
    cout << "V2 = " << V2[index_of_array_element]\
         << "\tA1 = " << A1[index_of_array_element]\
         << "\tA2 = " << A2[index_of_array_element] << '\n';
    index_of_array_element += 1;
  }
  
  return 0;
}
