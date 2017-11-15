#include <iostream>
#include <string>
#include <sstream>
using namespace std;
string board[6][7];
int put(string place, string type) {
  stringstream getInt(place);
  int loc = 0;
  int x = 0;
  if(!(getInt>>loc).fail()) {
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
      board[amount][loc] = type;
      return 1;
    }
  } else {
    return 0;
  }
}
int r(int i) {
  if(i == 0) {
    return 0;
  } else {
    //check if that spot is taken
    //if i =t is, check up and down

  }
  return 0;
}
// start with column 0 as column
// board[][] is board[row][column]
//if board[0][column] == [x];
  //if board[0+1][column] == [x];
//    if board[0+2][column]

int checkWin(string type) {
  // VERTICAL
  int v;
  for(int col = 0; col < 7; col++) {
    v = 0;
    for(int row = 0; row < 6; row++) {
      if(board[row][col] == type && board[row+1][col] == type) {
        v+=2;
      }
    }
    if(v == 6) {
      return 1;
    }
  }

  int h;
  for(int row = 0; row < 6; row++) {
    h = 0;
    for(int col = 0; col < 7; col++) {
      if(board[row][col] == type && board[row][col+1] == type) {
        h+=2;
        cout<<"horizontal at: "<<row<<" :: "<<col<<"=     "<<h<<endl;
      } else if(board[row][col] == type && board[row][col-1] == type) {
        h+=2;
      }
    }
    if(h == 8) {
      return 1;
    }
  }
  return 0;
}
int makeBoard() {
  //system("clear");
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
      //system("clear");
      cout<<"You did something wrong."<<endl;
    } else {
      //system("clear");
      while(1) {
        int x = rand() % 7;
        if(put(to_string(x), "[O]") == 1) {
          break;
        }
      }
      if(checkWin("[X]") == 1) {
        //system("clear");
        print();
        cout<<"Game over! X wins!"<<endl;
        break;
      }
      if(checkWin("[O]") == 1) {
        //system("clear");
        print();
        cout<<"You win because you managed to lose to a random number generator. Useless pathetic failure."<<endl;
        break;
      }
    }
  }
}
