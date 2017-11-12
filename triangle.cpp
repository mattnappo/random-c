#include <iostream>
#include <string>
using namespace std;
int main() {
  int max;
  cout<<"Enter an integer: ";
  cin>>max;
  max++;
  for(int i = 0; i < max; i++) {
    for(int j = 0; max < i; j++) {
      cout<<"[]";
    }
    cout<<endl;
  }
  cout<<endl;
  max--;
  for(int i = 0; i < max; i++) {
    for(int j = 0; j < i; j++) {
      cout<<"[]";
    }
    cout<<endl;
  }
  cout<<endl;
}
