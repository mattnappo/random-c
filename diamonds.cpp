#include <iostream>
#include <string>
using namespace std;
int main() {
  int n = 1;
  int c = 1;
  int k = 1;
  int space = 1;
  cout<<"Enter an integer: ";
  cin>>n;
  space = n - 1;
  for (k = 1; k <= n; k++) {
    for (c = 1; c<=space; c++)
       cout<<"   ";
     space--;
     for (c = 1; c<= 2*k-1; c++)
       cout<<"[+]";
     cout<<"\n";
   }
   space = 1;
   for (k = 1; k<= n - 1; k++) {
     for (c = 1; c<= space; c++)
       cout<<"   ";
     space++;
     for (c = 1 ; c<= 2*(n-k)-1; c++)
       cout<<"[+]";
     cout<<"\n";
   }
}
