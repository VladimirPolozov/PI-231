/*****************************************
*  Author: Полозов В. А.                 *
*  Name: Частота повторений              *
*  URL: https://onlinegdb.com/YRgRPKcyjy *
******************************************/
#include <fstream>
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
  string fileName, line, content;
  cout << "Enter file name (20 symbols or less): ";
  cin >> fileName;
  ifstream file(fileName);
  if ( file.is_open() ) {
    while ( getline(file, line) ) {
      content += line;
    }
    file.close();
  } else {
    cout << "No such file. Restart the program" << endl;
  }
  //cout << "The file's content: " << content << std::endl; // Проверка, что всё окей с выводом
  
  // Создаем словарь, где ключом будет символ или двухбуквенное сочетание, а значением - количество повторений
  map<char, int> letterFrequency; // для букв
  map<string, int> twoLetterFrequency; // для двухбуквенных сочетаний
  
  for (int indexOfLetter = 0; indexOfLetter < content.length(); ++indexOfLetter) {
    // Подсчитываем частоту повторения букв
    if ( isalpha(content[indexOfLetter]) ) { // Проверяем, является ли символ буквой
      ++letterFrequency[content[indexOfLetter]]; // Увеличиваем счетчик для данной буквы
    }
  
  // Подсчитываем частоту повторения двухбуквенных сочетаний
  if (indexOfLetter < content.length() - 1 && isalpha(content[indexOfLetter]) && isalpha(content[indexOfLetter+1])) { // Учитываем только буквенные символы исключая пробелы или знаки препинания
    string twoLetters = content.substr(indexOfLetter, 2); // Берем два символа начиная с текущего
    ++twoLetterFrequency[twoLetters]; // Увеличиваем счетчик для данного двухбуквенного сочетания
    }
  }
  
  // Вывод частоты повторения букв
  cout << "Frequency of letters' repetition:" << endl;
  for (const auto& pair : letterFrequency) {
    cout << pair.first << ": " << pair.second << std::endl; // Печатаем символ и количество повторений
  }
  
  // Вывод частоты повторения двухбуквенных сочетаний
  cout << "Frequency of repetition of two-letter combinations:" << endl;
  for (const auto& pair : twoLetterFrequency) {
    cout << pair.first << ": " << pair.second << endl; // Печатаем двухбуквенное сочетание и количество повторений
  }
  
  return 0;
}
