#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

class Student {
  private:
    vector<int> scores;

  public:
    void input() {
      for (int inputIndex = 0; inputIndex < 5; ++inputIndex) {
        int score;
        cin >> score;
        scores.push_back(score);
      }
    }

    int calculateTotalScore() {
      int total = 0;
      for (int scoreIndex = 0; scoreIndex < 5; ++scoreIndex) {
        total += scores[scoreIndex];
      }
      return total;
    }
};

int main() {
  int countOfStudent;
  cin >> n;
  Student *studentInfo = new Student[countOfStudent];
    
  for (int studentIndex = 0; studentIndex < n; ++studentIndex) {
    studentInfo[studentIndex].input();
  }
  
  int kristenScore = studentInfo[0].calculateTotalScore();
  int countOfStudentWhoIsBetterThanKristine = 0; 
  for (int studentIndex = 1; studentIndex < n; ++studentIndex) {
    int total = studentInfo[studentIndex].calculateTotalScore();
      if (total > kristenScore) {
        ++countOfStudentWhoIsBetterThanKristine;
      }
  }
  
  cout << countOfStudentWhoIsBetterThanKristine;  
  return 0;
}
