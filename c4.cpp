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
int checkWin(string type) {
  return 0;
}
int makeBoard() {
  system("clear");
  for(int i = 0; i < 6; i++) {
    for(int j = 0; j < 7; j++) {
      //board[i][j] = "[" + to_string(i) + ":" + to_string(j) + "]";
      board[i][j] = "[ ]";
    }
  }
  return 1;
}
int print() {
  for(int i = 5; i > -1; i--) {
    for(int j = 0; j < 7; j++) {
      cout<<board[i][j];
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
      while(1) {
        int x = rand() % 7;
        if(put(to_string(x), "[O]") == 1) {
          break;
        }
      }
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
