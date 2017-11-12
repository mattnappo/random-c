#include <iostream>
#include <string>
#include <sstream>
using namespace std;
string board[3][3];
int userPut(string place) {
  if(place.length() == 3) {
    string xStr(1,place[2]);
    stringstream xstream(xStr);
    int x = 0;
    string yStr(1,place[0]);
    stringstream ystream(yStr);
    int y = 0;
    if(!(xstream>>x).fail() && !(ystream>>y).fail()) {
      if(board[x][y] == "[X]" || board[x][y] == "[O]") {
        return 0;
      } else {
        board[x][y] = "[X]";
        return 1;
      }
    } else {
      return 0;
    }
  } else {
    return 0;
  }
}
int checkWin(string type) {
  //VERTICAL
  for(int i = 0; i < 3; i++) {
    if(board[0][i] == type && board[1][i] == type && board[2][i] == type) {
      return 1;
    }
  }
  //HORIZONTAL
  for(int i = 0; i < 3; i++) {
    if(board[i][0] == type && board[i][1] == type && board[i][2] == type) {
      return 1;
    }
  }
  //DIAGONAL
  if(board[0][0] == type && board[1][1] == type && board[2][2] == type) {
    return 1;
  }
  //ANTI-DIAGONAL
  if(board[2][0] == type && board[1][1] == type && board[0][2] == type) {
    return 1;
  }
  return 0;
}
int cpuPut() {
  while(1) {
    int x = rand() % 3;
    int y = rand() % 3;
    if(board[x][y] != "[X]" && board[x][y] != "[O]") {
      board[x][y] = "[O]";
      return 1;
    }
  }
}
int makeBoard() {
  system("clear");
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      board[i][j] = "[ ]";
    }
  }
  return 1;
}
int printer() {
  for(int i = 2; i > -1; i--) {
    cout<<i<<" ";
    for(int j = 0; j < 3; j++) {
      cout<<board[i][j];
    }
    cout<<endl;
  }
  cout<<"  ";
  for(int i = 0; i < 3; i++) {
    cout<<" "<<i<<" ";
  }
  cout<<endl;
  return 1;
}
int main() {
  makeBoard();
  cout<<"Hey there. Let's play some tic tac no."<<endl;
  while(1) {
    printer();
    cout<<"where do you want to go (x:y)? ";
    string place;
    cin>>place;
    if(userPut(place) == 0) {
      system("clear");
      cout<<"You did something wrong."<<endl;
    } else {
      system("clear");
      cpuPut();
      if(checkWin("[X]") == 1) {
        system("clear");
        cout<<"Game over! X wins!"<<endl;
        break;
      }
      if(checkWin("[O]") == 1) {
        system("clear");
        cout<<"You win because you managed to lose to a random number generator."<<endl;
        break;
      }
    }
  }
}
