/*********************************************************************
* Author: Полоозов В. А.                                             *
* Name: Работа с файлами (Вариант №15)                               *
* Description: Файл содержит сведения о музыкальных компакт-дисках:  *
*              - исполнитель,                                        *
*              - название альбома,                                   *
*              - год издания,                                        *
*              - стоимость.                                          *
*              Выведите сведения об альбомах задаваемого исполнителя *
*              и определите название самого нового альбома.          *
*              Среди всех сведений найдите самый дорогой альбом.     *
* URK: https://onlinegdb.com/70uq-w2q2                               *
**********************************************************************/
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct Cd {
  string artist;
  string albumName;
  int release;
  float price;
};

int main() {
  string fileName, artistNameUserWantToSee = "";
  int countOfCd, artistIndexUserEntered, theNewestAlbumReleasaIndex = 0, theMostExpensiveAlbumIndex = 0;
  
  cout << "Enter file name (20 symbols or less): ";
  cin >> fileName;
  ifstream fin(fileName);
  if ( fin.is_open() == 0 ) {
    cout << "No such file. Restart the program" << endl;
  } else {
    cout << "Enter count of objects you want to see (7 or less): ";
    cin >> countOfCd;
    Cd cdSet[countOfCd];
    cout << "Enter number of artist's name, whose albums info u want to see:\n1. Vladimir\n2. NoName\n3. User\n";
    while (artistNameUserWantToSee == "") {
      cin >> artistIndexUserEntered;
      if (artistIndexUserEntered == 1) {
        artistNameUserWantToSee = "Vladimir";
      } else if (artistIndexUserEntered == 2) {
        artistNameUserWantToSee = "NoName";
      } else if (artistIndexUserEntered == 3) {
        artistNameUserWantToSee = "User";
      } else {
        cout << "There is no such artist in the file. Enter again: ";
      }
    }
    cout << "Info about albums by " << artistNameUserWantToSee << ":\nNAME / RELEASE YEAR / PRICE" << endl;
    for (int indexOfCd = 0; indexOfCd < countOfCd; ++indexOfCd) {
      fin >> cdSet[indexOfCd].artist
          >> cdSet[indexOfCd].albumName
          >> cdSet[indexOfCd].release
          >> cdSet[indexOfCd].price;
      if (cdSet[indexOfCd].price > cdSet[theMostExpensiveAlbumIndex].price) {
        theMostExpensiveAlbumIndex = indexOfCd;
      }
      if (cdSet[indexOfCd].artist == artistNameUserWantToSee) {
        cout << cdSet[indexOfCd].albumName << " " << cdSet[indexOfCd].release << " " << cdSet[indexOfCd].price << "$\n";
        if (cdSet[indexOfCd].release < cdSet[theNewestAlbumReleasaIndex].release) {
          theNewestAlbumReleasaIndex = indexOfCd;
        }
      }
    }
    cout << "\nThe newest album by " << cdSet[theNewestAlbumReleasaIndex].artist << " is: " << cdSet[theNewestAlbumReleasaIndex].albumName << endl;
    cout << "The most expensive album (in the file) is: " << cdSet[theMostExpensiveAlbumIndex].albumName << " (by " << cdSet[theMostExpensiveAlbumIndex].artist << ", " << cdSet[theMostExpensiveAlbumIndex].price << "$)\n";
  }
  
  return 0;
}
