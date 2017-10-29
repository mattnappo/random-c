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



  int n, c, k, space = 1;
  clrscr();
  cout<<"\n\nEnter number of rows: ";
  cin>>n;
  space = n - 1;
  for (k = 1; k<=n; k++) {
    for (c = 1; c<=space; c++)
       cout<<" ";
     space--;
     for (c = 1; c<= 2*k-1; c++)
       cout<<"*";
     cout<<"\n";
   }
   space = 1;
   for (k = 1; k<= n - 1; k++)
   {
     for (c = 1; c<= space; c++)
       cout<<" ";

     space++;

     for (c = 1 ; c<= 2*(n-k)-1; c++)
       cout<<"*";

     cout<<"\n";
   }
  getch();

}
