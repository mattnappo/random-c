#include <iostream>
#include <string>
using namespace std;

int main() {

  string s = "mom";
  int a[s.length()];

  for(int i = 0; i < s.length(); i++) {
    a[i] = s[i];
  }

  for(int i = 0; i < s.length(); i++) {
    cout<<a[i]<<" "<<endl;
  }
}
