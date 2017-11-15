#include <iostream>
#include <string>
using namespace std;
int main() {
  int i = 0;
  cout<<"How many? ";
  cin>>i;
  system("clear");
  for(int j = 0; j < i; j++) {
    for(int x = 0; x < i; x++) {
      cout<<" . ";
    }
    cout<<endl;
  }
  cout<<"viola. "<<i<<" negroids."<<endl;
}
