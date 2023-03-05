#include <iostream>
#include <cstdio>
using namespace std;

float matrix[4][5] = {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
};

void printMatrix() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 5; j++) {

      printf("%3.0f,",matrix[i][j]);

    }
    cout << endl;
  }
}

int main() {

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> matrix[i][j];
    }
  }
  printMatrix();

  cout << "Enter commands\n";
  while (true) {
    string command;
    cin >> command;

    // line that will be modified
    int orig = command[1] - '0' -1;
    cout<<"modified "<<orig<<endl;

    // modifier line multiplier
    int mul = command[7] - '0';

    // modifier line
    int modif = command[9] - '0' -1;
    cout<<"modifier "<<modif<<endl;

    // operation
    switch (command[6]) {
    case '+':
      for (int i = 0; i < 5; i++) {
        matrix[orig][i] += mul * matrix[modif][i];
      }
      break;
    case '-':
      for (int i = 0; i < 5; i++) {
        matrix[orig][i] -= mul * matrix[modif][i];
      }
      break;
    default:
      cout << "lol";
      break;
    }
    printMatrix();
  }
}
