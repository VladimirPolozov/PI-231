#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

// Write your Student class here
class Student {
  private:
    vector<int> scores;

  public:
    void input() {
      for (int i = 0; i < 5; i++) {
        int score;
        cin >> score;
        scores.push_back(score);
      }
    }

    int calculateTotalScore() {
      int total = 0;
      for (int i = 0; i < 5; i++) {
        total += scores[i];
      }
      return total;
    }
};

int main() {
  int countOfStudent; // number of students
  cin >> n;
  Student *studentInfo = new Student[countOfStudent]; // an array of n students
    
  for (int studentIndex = 0; studentIndex < n; ++studentIndex) {
    studentInfo[studentIndex].input();
  }

  // calculate kristen's score
  int kristenScore = studentInfo[0].calculateTotalScore();
  // determine how many students scored higher than kristen
  int countOfStudentWhoIsBetterThanKristine = 0; 
  for (int studentIndex = 1; studentIndex < n; ++studentIndex) {
    int total = studentInfo[studentIndex].calculateTotalScore();
      if (total > kristenScore) {
        ++countOfStudentWhoIsBetterThanKristine;
      }
  }

  // print result
  cout << countOfStudentWhoIsBetterThanKristine;  
  return 0;
}
