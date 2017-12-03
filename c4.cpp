#include <iostream>
#include <string>
#include <sstream>
using namespace std;
string board[6][7];
int put(string place, string token) {
  stringstream getInt(place);
  int loc = 0;
  int x = 0;
  if(!(getInt>>loc).fail()) {
    if(loc>7||loc<1) {
      return 0;
    }
    loc--;
    int amount = 0;
    for(int i = 0; i < 6; i++) {
      if(board[i][loc] == "[X]" || board[i][loc] == "[O]") {
        amount++;
      }
    }
    if(amount>5) {
      return 0;
    } else {
      board[amount][loc] = token;
      return 1;
    }
  } else {
    return 0;
  }
}
int combine(int a, int b) {
  int times = 1;
  while(times <= b) {
    times*=10;
  }
  return a*times + b;
}
int checkWin(string token) {
  // VERTICAL
  int v;
  for(int col = 0; col < 7; col++) {
    v = 0;
    for(int row = 0; row < 6; row++) {
      if(board[row][col] == token && board[row+1][col] == token) {
        v+=2;
      }
    }
    if(v >= 6) {
      return 1;
    }
  }
  // HORIZONTAL
  for(int row = 0; row < 6; row++) {
    for(int col = 0; col < 3; col++) {
      if(board[row][col] == token && board[row][col+2] == token && board[row][col+3] == token) {
        return 1;
      }
    }
  }
  // DIAGONAL
  for(int col = 3; col < 7; col++) {
    for(int row = 0; row < 6 - 3; row++) {
      if(board[col][row] == token && board[col-1][row+1] == token && board[col-2][row+2] == token && board[col-3][row+3] == token) {
        return 1;
      }
    }
  }

  // ANT-DAGONAL
  for(int col = 3; col < 7; col++) {
    for(int row = 3; row < 6; row++) {
      if(board[col][row] == token && board[col-1][row-1] == token && board[col-2][row-2] == token && board[col-3][row-3] == token) {
        return 1;
      }
    }
  }
  return 0;
}
int cpuPut() {
  while(1) {
    int x = rand() % 7;
    for(int i = 0; i < 6; i++) {
      for(int j = 0; j < 7; j++) {
        if(board[i][x+1] == "[X]" || board[i][x-1] == "[X]") {
          if(put(to_string(x), "[O]") == 1) {
            return 1;
          }
        }
        if(board[i][x+1] == "[O]" || board[i][x-1] == "[O]") {
          if(put(to_string(x), "[O]") == 1) {
            return 1;
          }
        }
        if(board[x+1][j] == "[X]" || board[x-1][j] == "[X]") {
          if(put(to_string(x), "[O]") == 1) {
            return 1;
          }
        }
        if(board[x+1][j] == "[O]" || board[x-1][j] == "[O]") {
          if(put(to_string(x), "[O]") == 1) {
            return 1;
          }
        }
      }
    }
  }

  return 0;
}

int makeBoard() {
  system("clear");
  for(int i = 0; i < 6; i++) {
    for(int j = 0; j < 7; j++) {
      board[i][j] = "[ ]";
      // board[i][j] = "[" + to_string(i) + ":" + to_string(j) + "]";
    }
  }
  return 1;
}
int print() {
  for(int i = 5; i > -1; i--) {
    for(int j = 0; j < 7; j++) {
      if(board[i][j] == "[X]") {
        cout<<"\033[1;31m[X]\033[0m";
      } else if(board[i][j] == "[O]") {
        cout<<"\033[1;34m[O]\033[0m";
      } else {
        cout<<board[i][j];
      }
    }
    cout<<endl;
  }
  for(int i = 0; i < 7; i++) {
    cout<<" "<<i+1<<" ";
  }
  cout<<endl;
  return 1;
}
int main() {
  makeBoard();
  cout<<"C4? I think so."<<endl;
  while(1) {
    print();
    cout<<"Where do you want to go? ";
    string place;
    cin>>place;
    if(put(place, "[X]") == 0) {
      system("clear");
      cout<<"You did something wrong."<<endl;
    } else {
      system("clear");
      cpuPut();
      if(checkWin("[X]") == 1) {
        system("clear");
        print();
        cout<<"Game over! X wins!"<<endl;
        break;
      }
      if(checkWin("[O]") == 1) {
        system("clear");
        print();
        cout<<"You win because you managed to lose to a random number generator. Useless pathetic failure."<<endl;
        break;
      }
    }
  }
}
