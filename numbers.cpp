/***************************************
* Author: Полозов В. А.                *
* Name: Арабские числа                 *
* URL: https://onlinegdb.com/7tL6vhvUC *
****************************************/
#include <iostream>
#include <map>
#include <string>
using namespace std;

string arabicToRoman(int arabicNumber) {
  string romanNumber = "";
  map<int, std::string> arabicAlphabet = {
    {1000, "M"},
    {900, "CM"},
    {500, "D"},
    {400, "CD"},
    {100, "C"},
    {90, "XC"},
    {50, "L"},
    {40, "XL"},
    {10, "X"},
    {9, "IX"},
    {5, "V"},
    {4, "IV"},
    {1, "I"}
  };
  
  // Проходим по словарю, пока число не станет равным 0
  for (auto arabicDigit = arabicAlphabet.rbegin(); arabicDigit != arabicAlphabet.rend(); ++arabicDigit) {
    while (arabicNumber >= arabicDigit->first) {
      romanNumber += arabicDigit->second;
      arabicNumber -= arabicDigit->first;
    }
  }
  
  return romanNumber;
}

int romanToArabic(string romanNumber) {
  int arabicNumber = 0;
  map<char, int> romanAlphabet = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
  };

  for (int romanDigit = 0; romanDigit < romanNumber.length(); ++romanDigit) {
    // Если текущий символ представляет число меньшее, чем следующий, вычитаем его из результата
    if (romanDigit < romanNumber.length() - 1 && romanAlphabet[romanNumber[romanDigit]] < romanAlphabet[romanNumber[romanDigit + 1]]) {
      arabicNumber -= romanAlphabet[romanNumber[romanDigit]];
    } else {
      arabicNumber += romanAlphabet[romanNumber[romanDigit]]; // Иначе прибавляем его к результату
    }
  }
  
  return arabicNumber;
}

int main() {
  int userArabicNumber;
  string userRomanNumber, userInput;
  bool stop = false;
  
  cout << "Выберите команду (напишите число):\nА) Арабские числа > римские числа\nБ) Римские числа > арабские числа\nЧтобы закончить введите: Стоп\n";
  while (not stop) {
    cin >> userInput;
    if (userInput == "А") {
      cout << "Введите натуральное число арабскими цифрами: ";
      cin >> userArabicNumber;
      cout << "Число " << userArabicNumber << " римскими цифрами: " << arabicToRoman(userArabicNumber) << endl;
      cout << "Продолжайте (доступные команды: А, Б, и Стоп): ";
    } else if (userInput == "Б") {
      cout << "Введите натуральное число римскими цифрами: ";
      cin >> userRomanNumber;
      cout << "Число " << userRomanNumber << " арабскими цифрами: " << romanToArabic(userRomanNumber) << endl;
      cout << "Продолжайте (доступные команды: А, Б, и Стоп): ";
    } else if (userInput == "Стоп" or userInput == "стоп") {
      stop = true;
    } else {
      cout << "Команда не распознана (доступные команды: А, Б, и Стоп)\n";
    }
  }
  
  return 0;
}
