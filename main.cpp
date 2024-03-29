#include <cstdio>
#include <iostream>
#include <string>

int rows = 0;
int columns = 0;

using namespace std;

float **matrix;

void printMatrix() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {

      printf("%5.2f,", matrix[i][j]);
    }
    cout << endl;
  }
}

void parseAndExecSum(string command, int firstLine, char operation) {
  // try parse second line multiplier
  float mult = 1.;
  int ind = 3; // store second line name index
  if (command[3] != 'r') {
    // extract multiplier string
    string multiplier;
    for (ind = 3; command[ind] != 'r'; ind++) {
      multiplier += command[ind];
    }
    mult = stof(multiplier);
  }
  int secLine = command[ind + 1] - '0' - 1;

  // exec sum with mult

  switch (operation) {
  case '+':
    for (int i = 0; i < columns; i++) {
      matrix[firstLine][i] += mult * matrix[secLine][i];
    }
    break;
  case '-':
    for (int i = 0; i < columns; i++) {
      matrix[firstLine][i] -= mult * matrix[secLine][i];
    }
    break;
  default:
    cout << "lol";
    break;
  }
}
void parseAndExecMult(string command, int firstLine, char operation) {
  // parse multiplicator or divisor
  string number;
  for (int i = 3; i < command.length(); i++) {
    number += command[i];
  }
  float num = stof(number);

  // exec mult or div

  switch (operation) {
  case '*':
    for (int i = 0; i < columns; i++) {
      matrix[firstLine][i] *= num;
    }
    break;
  case '/':
    for (int i = 0; i < columns; i++) {
      matrix[firstLine][i] /= num;
    }
    break;
  default:
    cout << "lol";
    break;
  }
}

void parseAndExecSwap(string command, int firstLine, char operation) {
  // parse second line
  int secLine = command[5] - '0' - 1;

  // exec swap
  for (int i = 0; i < columns; i++) {
    float tmp = matrix[firstLine][i];
    matrix[firstLine][i] = matrix[secLine][i];
    matrix[secLine][i] = tmp;
  }
}

void parseAndExec(string command) {
  // parse first matrix line
  int firstLine = command[1] - '0' - 1;

  // parse operation
  char operation = command[2];
  switch (operation) {
  case '+':
  case '-':
    parseAndExecSum(command, firstLine, operation);
    break;
  case '*':
  case '/':
    parseAndExecMult(command, firstLine, operation);
    break;
  case '<':
    parseAndExecSwap(command, firstLine, operation);
    break;
  default:
    cout << "Lmao\n";
  }
}

int main() {

  cout << "Rows:";
  cin >> rows;
  cout << "Columns:";
  cin >> columns;

  // alocate matrix

  matrix = new float *[rows];

  for (int i = 0; i < columns; i++) {
    matrix[i] = new float[columns];
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      cin >> matrix[i][j];
    }
  }
  printMatrix();

  cout << "Enter commands\n";
  while (true) {
    string command;
    cin >> command;

    parseAndExec(command);

    printMatrix();
  }
}
