/***************************************
* Author: Полозов В. А.                *
* Name: календарь                      *
* URL: https://onlinegdb.com/6GbE-vkXn *
***************************************/
#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <clocale>
using namespace std;

int main() {
  setlocale(LC_CTYPE, "rus"); // вызов функции настройки локали
  string year, month, daysInWeekName;
  int monthsCount, daysCount, daysInWeekCount, firstDayOfMonth, spaceSize;
  map<string, int> months;
  
  cout << "Введите год: ";
  cin >> year;
  cout << "Введите кол-во месяцев в " << year << " году: ";
  cin >> monthsCount;
  cout << "Введите названия месяцев:" << endl;
  for (int inputIndex = 1; inputIndex < monthsCount + 1; ++inputIndex) {
    cout << inputIndex << ". ";
    cin >> month;
    cout << "Кол-во дней: ";
    cin >> daysCount;
    months[month] = daysCount;
  }
  
  cout << "Введите кол-во дней в неделе: ";
  cin >> daysInWeekCount;
  string daysInWeek[daysInWeekCount]; // Массив с днями недели
  cout << "Введите сокращения названий дней недели (используйте двухбуквенные сочетания)" << endl;
  for (int inputIndex = 1; inputIndex < daysInWeekCount + 1; ++inputIndex) {
    cout << inputIndex << ". ";
    cin >> daysInWeekName;
    daysInWeek[inputIndex - 1] = daysInWeekName;
  }
  
  cout << "С какого дня недели начинается первый месяц? (Введите число)" << endl;
  for (int dayInWeekIndex = 1; dayInWeekIndex < daysInWeekCount + 1; ++dayInWeekIndex) {
    cout << dayInWeekIndex << ". " << daysInWeek[dayInWeekIndex - 1] << endl;
  }
  cin >> firstDayOfMonth;
  
  cout << "Интервал пробелов между числами в календаре (обычно равен кол-ву символов в названии дней недели): ";
  cin >> spaceSize;
  
  //  
  //  Далее начинается вывод календаря
  
  for (auto month = months.rbegin(); month != months.rend(); ++month) {
    cout << month->first << endl;
    
    // Вывод шапки (названия дней недели)
    string monthHeader;
    for (int dayInWeekIndex = 0; dayInWeekIndex < daysInWeekCount; ++dayInWeekIndex) {
      monthHeader = monthHeader + daysInWeek[dayInWeekIndex] + string(spaceSize, ' ');
    }
    cout << monthHeader << endl;
    
    cout << string( (spaceSize + 1) * (firstDayOfMonth - 1) - 1, ' ');
    for (int dayIndex = 1; dayIndex < month->second + 1; ++dayIndex) {
      if (dayIndex < 10) {
        cout << dayIndex << string(spaceSize, ' ');
      } else {
        cout << dayIndex << string(spaceSize - 1, ' ');
      }
      if ( (dayIndex + firstDayOfMonth - 1) % daysInWeekCount == 0) {
        cout << "\n";
      }
    }
    cout << "\n";
    firstDayOfMonth = (month->second % daysInWeekCount) + firstDayOfMonth;
  }
}
