#include <iostream>
#include <string>
#include <sstream>
using namespace std;
string board[3][3];
int checkWin(int tok) {
  string token = tok == 0?"[X]":"[O]";
  for(int i = 0; i < 3; i++) {
    if(board[0][i] == token && board[1][i] == token && board[2][i] == token) {
      return 1;
    }
  }
  for(int i = 0; i < 3; i++) {
    if(board[i][0] == token && board[i][1] == token && board[i][2] == token) {
      return 1;
    }
  }
  if(board[0][0] == token && board[1][1] == token && board[2][2] == token) {
    return 1;
  }
  if(board[2][0] == token && board[1][1] == token && board[0][2] == token) {
    return 1;
  }
  return 0;
}
int minimax(int depth, int token) {
  if((depth = 0) || checkWin(token) == 1) {

  }
  return 0;
}
int cpuPut(int turn) {
  int value = 0;
  int move;
  int depth = 10 - turn;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      if(board[i][j] == "[ ]") {
        int temp;
        if((temp = minimax(depth - 1, 1)) > value) {
          move = i*3+j;
          value = temp;
        }
      }
    }
  }
  return move;
}
int userPut(string place) {
  if(place.length() == 3) {
    string xStr(1,place[2]);
    stringstream xstream(xStr);
    int x = 0;
    string yStr(1,place[0]);
    stringstream ystream(yStr);
    int y = 0;
    if(!(xstream>>x).fail() && !(ystream>>y).fail()) {
      if(x > 2 || x < 0 || y > 2 || y < 0) {
        return 0;
      }
      string split(1,place[1]);
      if(split != ",") {
        return 0;
      }
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

int badcpuPut() {
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
  cout<<"  ";
  for(int i = 0; i < 3; i++) {
    cout<<" "<<i<<" ";
  }
  cout<<endl;
  return 1;
}
int main() {
  int turn = 0;
  makeBoard();
  cout<<"Hey there. Let's play some tic tac no."<<endl;
  while(1) {
    turn++;
    printer();
    cout<<"where do you want to go (x,y)? ";
    string place;
    cin>>place;
    // LAST WORKING ON USERPUT TAKING A STRING OR AN INTEGER? TURN OR THE LOCATION IN X,Y
    if(userPut(turn) == 0) {
      system("clear");
      cout<<"You did something wrong."<<endl;
    } else {
      system("clear");
      turn++;
      if(checkWin(0) == 1) {
        system("clear");
        printer();
        cout<<"Game over! X wins!"<<endl;
        break;
      }
      int loc = cpuPut(board[loc/3][loc%3]);
      if(checkWin(1) == 1) {
        system("clear");
        printer();
        cout<<"You win because you managed to lose to a random number generator. Useless pathetic failure."<<endl;
        break;
      }
    }
  }
}
