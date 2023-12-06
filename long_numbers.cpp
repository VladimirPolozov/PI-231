/***************************************
* Author: Полозов В. А.                *
* Name: Арифметика длинных чисел       *
* URL: https://onlinegdb.com/dSdngfU0Q *
****************************************/
#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
using namespace std;
using namespace boost::multiprecision;

int main() {
  int128_t firstBigNumber, secondBigNumber;
  char operation;
  
  cout << "Input the first number: ";
  cin >> firstBigNumber;
  cout << "Input the second number: ";
  cin >> secondBigNumber;
  cout << "Input operation (+, - , *, /, >, <, =): ";
  cin >> operation;
  
  if (operation == '+') {
    cout << firstBigNumber + secondBigNumber;
  } else if (operation == '-') {
    cout << firstBigNumber - secondBigNumber;
  } else if (operation == '*') {
    cout << firstBigNumber * secondBigNumber;
  } else if (operation == '/') {
    cout << firstBigNumber / secondBigNumber;
  } else if (operation == '>') {
    if (firstBigNumber > secondBigNumber) {
      cout << "True";
    } else {
      cout << "False";
    }
  } else if (operation == '<') {
    if (firstBigNumber < secondBigNumber) {
      cout << "True";
    } else {
      cout << "False";
    }
  } else if (operation == '=') {
    if (firstBigNumber == secondBigNumber) {
      cout << "True";
    } else {
      cout << "False";
    }
  }
}
