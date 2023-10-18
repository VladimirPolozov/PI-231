/***************************************
* Author: Полозов В. А.                *
* Name: Обработка массивов             *
* URL: https://onlinegdb.com/tKP8FABti *
****************************************/
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main() {
  int row_col, column_col;
  cout << "Введите размерность матрицы (два числа, каждое на отдельной строке)" << endl;
  cin >> row_col;
  cin >> column_col;
  double matrix[row_col][column_col];
  
  for (int index_row = 0; index_row < row_col; ++index_row) {
    for (int column_index = 0; column_index < column_col; ++column_index) {
      cout << "Введите элемент матрицы" << endl;
        cin >> matrix[index_row][column_index]; 
    }
  }
  
  for (int index_row = 0; index_row < row_col; ++index_row) {
    for (int column_index = 0; column_index < column_col; ++column_index) {
      cout << matrix[index_row][column_index] << " ";
    }
    cout << "\n";
  }
  cout << "***" << endl;
  
  // сортировка методом выбора наимешьнего элемента
  for (int index_row = 0; index_row < row_col; ++index_row) {
    for (int position_in_row_sorting = 0; position_in_row_sorting < column_col; ++position_in_row_sorting) {
      int index_of_min_el_in_remaining_row_part = position_in_row_sorting;
      for (int index_of_processed_row_element = position_in_row_sorting + 1; index_of_processed_row_element < column_col; ++index_of_processed_row_element) {
        if (matrix[index_row][index_of_processed_row_element] < matrix[index_row][index_of_min_el_in_remaining_row_part]) {
          index_of_min_el_in_remaining_row_part = index_of_processed_row_element;
        }
      }
      swap(matrix[index_row][position_in_row_sorting], matrix[index_row][index_of_min_el_in_remaining_row_part]);
    }
  }
  
  for (int index_row = 0; index_row < row_col; ++index_row) {
    for (int column_index = 0; column_index < column_col; ++column_index) {
      cout << matrix[index_row][column_index] << " ";
    }
    cout << "\n";
  }
  
  return 0;
}
