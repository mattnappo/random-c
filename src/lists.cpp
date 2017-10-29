#include <iostream>
//#include <list>
#include <string>
using namespace std;

int main() {
  int numbers [3][3];
  //----------MAKE BOARD------------
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      numbers[i][j] = "[ ]";
    }
  }
  for(int i = 0; i < 3; i++) {
    cout<<numbers[i]<<endl;
  }
}
