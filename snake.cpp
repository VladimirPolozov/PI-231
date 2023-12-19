#define _CRT_SECURE_NO_WARNING
#include <iostream>
#include <windows.h>
#include <string>
#include <stdio.h>
using namespace std;

// размер консольного окна (в символах)
#define mHeight 25
#define mWidth 80
// максимальная длина хвоста змейки
#define tailMaxLenght 1000
#define applesCount 4

// Перевоит курсор в нужно положение
void moveXY(int positionX, int positionY) {
  COORD position;
  position.X = positionX;
  position.Y = positionY;
  SetConsoleCursorPosition( // устанавливает координаты курсора в положение, заданное вторым параметром
    GetStdHandle( // возвращает указатель на стандартное устройство ввода/вывода
      STD_OUTPUT_HANDLE // говорит, что мы хотим получить указатель на устройство вывода, связанное с консольным окном
    ), position 
  ); 
}

struct myMap {
  char myMap [mHeight][mWidth + 1]; // двумерный массив символов, которые будут выводится в окне
  POINT apples[applesCount];
  void Clear();
  void Show();
  void AddApple(int _x, int _y, int appleIndex);
  void DeleteApple(int _x, int _y);
};

void myMap::AddApple(int _x, int _y, int appleIndex) {
  apples[appleIndex].x = _x;
  apples[appleIndex].y = _y;
}

void myMap::DeleteApple(int _x, int _y) {
  for (int appleIndex = 0; appleIndex < applesCount; ++appleIndex) {
    if ( (apples[appleIndex].x == _x) && (apples[appleIndex].y == _y) ) {
      myMap[apples[appleIndex].x][apples[appleIndex].y] = ' ';
      AddApple(rand() % mHeight, rand() % mWidth, appleIndex);
      break;
    }
  }
}

void myMap::Clear() {
  for (int symbolIndex = 0; symbolIndex < mWidth; ++symbolIndex) {
    myMap[0][symbolIndex] = ' '; // Заполняем первую строку пробелами
  }
  myMap[0][mWidth - 1] = '|'; // символ конца строки
  myMap[0][mWidth] = '\0'; // символ конца строки

  for (int rowIndex = 1; rowIndex < mHeight; ++rowIndex) {
    strncpy(
      myMap[rowIndex], // в эту строку
      myMap[0], // из этой строки 
      mWidth + 1 // копируем первые mWidth + 1 символов (то есть все)
    );
  }

  for (int symbolIndex = 0; symbolIndex < mWidth; ++symbolIndex) {
    myMap[mHeight - 1][symbolIndex] = '_'; // Заполняем первую строку пробелами
  }

  // создаём яблочки
  for (int appleIndex = 0; appleIndex < applesCount; ++appleIndex) {
    myMap[apples[appleIndex].x][apples[appleIndex].y] = '*';
  }
}

void myMap::Show() {
  moveXY(0, 0); // устанавливаем курсор в левый верхний угол
  myMap[mHeight - 1][mWidth - 1] = '\0';
  for (int rowIndex = 0; rowIndex < mHeight; ++rowIndex) {
    cout << myMap[rowIndex]; // вывод строк
  }
}

enum Direction {dirLeft, dirRight, dirUp, dirDown}; // перечисление, в котором описывается направление движения
enum Result {reOk, reKill};

class Snake {
  int coordX, coordY; // положение головы змейки
  myMap *mp; // карта
  Direction dir; // направление движения змейки
  POINT tail[ // массив с координатами каждого элемента хвоста
    tailMaxLenght // максимальная длина хвоста змейки (задано через define)
  ];
  int currentTailLength; // текущая длина хвоста

  public:
    void AddTail(
      int coordX, int coordY
    ); // добавляет +1 элемент хвосту
    void MoveTail(
      int coordX, int coordY // координаты, куда должен передвинуться хвост
    ); // передвигает хвост
    Snake(myMap *_mp); // передаем карту, на которой рисуем змейку
    void Init(int _x, int _y, Direction _dir);
    void PutOnMap();
    Result UserControl(char w, char s, char a, char d);
};

// добавляет +1 элемент хвосту
void Snake::AddTail(int _x, int _y) {
  MoveTail(_x, _y); 
  ++currentTailLength;
  if (currentTailLength >= tailMaxLenght) {
    currentTailLength = tailMaxLenght - 1;
  }
}

// передвигает хвост
void Snake::MoveTail(int _x, int _y) {
  for (int tailIndex = currentTailLength; tailIndex >= 0; --tailIndex) {
    tail[tailIndex + 1] = tail[tailIndex]; // все элементы хвоста передвигаем на -1
  }
  tail[0].x = _x;
  tail[0].y = _y;
}

// в конструкторе устнавливаем карту, на которой рисуется змека
Snake::Snake(myMap *_mp) {
  mp = _mp;
  Init(0, 0, dirRight);
}

// устанавливает начальное положение и направление движения змейки
void Snake::Init(int currentX, int currentY, Direction currentDir) {
  coordX = currentX;
  coordY = currentY;
  dir = currentDir;
  currentTailLength = 0;
}

// помещает змейку на карту
void Snake::PutOnMap() {
  mp->myMap[coordX][coordY] = '@'; // голова змейки
  for (int tailIndex = 0; tailIndex < currentTailLength; ++tailIndex) {
    mp->myMap[tail[tailIndex].y][tail[tailIndex].x] = '#'; // проходим по всем элементам хвоста и отображаем их как #
  }
}

// управление движением змейки
Result Snake::UserControl(char w, char s, char a, char d) {
  POINT oldPosition; // позиция головы до перемещения
  oldPosition.x = coordX;
  oldPosition.y = coordY;

  // в завиимости от нажатой клавиши задаём одно из четырёх направлений
  if ( GetKeyState(w) < 0 ) {
    dir = dirUp;
  } else if ( GetKeyState(s) < 0 ) {
    dir = dirDown;
  } else if ( GetKeyState(a) < 0 ) {
    dir = dirLeft;
  } else if ( GetKeyState(d) < 0 ) {
    dir = dirRight;
  }

  // меняем координаты головы змейки в зависимости от направления
  // змейка продолжает двигаться в том же направлении, даже если ни одна клавиша не была нажата
  if (dir == dirUp) {
    --coordX;
  } else if (dir == dirDown) {
    ++coordX;
  } else if (dir == dirLeft) {
    --coordY;
  } else if (dir == dirRight) {
    ++coordY;
  }

  // если змейка выходит за границы экрана, игра начинается заново
  if ( ( (coordX < 0) || (coordX >= mHeight) ) || // если змейка выходит за границы массива (поля)
       ( (coordY < 0) || (coordY >= mWidth) ) ||
       ( mp->myMap[coordX][coordY] == '#' ) ) { // или голова сталкаивается с хвостом (точнее: координаты головы сопвали с координатами хвоста)
    return reKill; // змейка погибает
  }

  if (mp->myMap[coordX][coordY] == '*') {
    AddTail(oldPosition.y, oldPosition.x);
    mp->DeleteApple(coordX, coordY);
  } else {
    MoveTail(oldPosition.y, oldPosition.x); // хвост перемещается в старую позицию змейки, тем самым двигаясь за ней
  }
  
  return reOk; // тут всё ок
}

int main() {
  myMap newMap;
  Snake newSnake(&newMap);
  newSnake.Init(rand() % mHeight, rand() % mWidth, dirRight);
  for (int appleIndex = 0; appleIndex < applesCount; ++appleIndex) {
    newMap.AddApple(rand() % mHeight, rand() % mWidth, appleIndex);
  }

  do {
    if ( newSnake.UserControl('W', 'S', 'A', 'D') == reKill) {
      newSnake.Init(rand() % mHeight, rand() % mWidth, dirRight);
      for (int appleIndex = 0; appleIndex < applesCount; ++appleIndex) {
        newMap.AddApple(rand() % mHeight, rand() % mWidth, appleIndex);
      }
    };
    newMap.Clear(); // очищаем карту
    newSnake.PutOnMap(); // помещаем змейку на карту
    newMap.Show(); // выводим строки карты
    Sleep(80); // отдыхаем 80 миллисекунд
  } while ( GetKeyState( VK_ESCAPE ) >= 0 ); /// до нажатия кнопки escape

  return 0;
}
