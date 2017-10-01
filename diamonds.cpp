#include <iostream>
#include <string>
using namespace std;
int main() {
  int max;
  cout<<"Enter an integer: ";
  cin>>max;
  max++;
  for(int i = 0; i < max; i++) {
    for(int j = 0; j < i; j++) {
      cout<<"[]";
    }
    cout<<endl;
  }
  cout<<endl;
  max--;
  for(int i = 0; i < max; i++) {
    for(int j = 0; j < max; j++) {
      cout<<"[]";
    }
    cout<<endl;
  }
  cout<<endl;

  cout<<"0001000";
  cout<<"0011100";
  cout<<"0111110";
  cout<<"1111111";
  int nos = max/2-0.5;
  int num = max;
  for(int space = 0; space < nos; space--) {
    cout<<"0";
    for(int block = 0; block < num; block++) {
      cout<<"1";
    }
    cout<<endl;
  }
}
