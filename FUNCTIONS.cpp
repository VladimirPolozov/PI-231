/*****************************************
* Author: Полозов В. А.                  *
* Name: Использование процедур и функций *
* URL: https://onlinegdb.com/i_Ob3SSTZ   *
******************************************/
#include <iostream>
#include <iomanip>
using namespace std;

double findMaxElement(double* array, int length) {
  double maxElement = array[0];
  
  for (int indexElement = 0; indexElement < length; ++indexElement) {
    if (array[indexElement] > maxElement) {
      maxElement = array[indexElement];
    }
  }
  
  return maxElement;
}

double* createArray(int length) {
  double* array = new double[length];
  
  for (int indexElement = 0; indexElement < length; ++indexElement) {
    cout << "Введите элемент матрицы = ";
    cin >> array[indexElement];
  }
  
  return array;
}

int main() {
  int arrays_col, userLength;
  cout << "Сколько массивов Вы хотите ввести?" << endl;
  cin >> arrays_col;
  for (int inputCount = 0; inputCount < arrays_col; ++inputCount) {
    cout << "Кол-во элементов в массиве = ";
    cin >> userLength;
    cout << "Самый большой элемент в введенном Вами массиве = " << findMaxElement(createArray(userLength), userLength) << endl;
  }
  
  return 0;
}
