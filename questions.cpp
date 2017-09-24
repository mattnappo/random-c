#include <iostream>
#include <string>
using namespace std;
int main() {
  string name;
  string flavour;
  string sureName;
  string reason;
  int runName = 1;
  while(runName) {
    cout<<"What's your name? ";
    getline(cin, name);
    cout<<"Are you sure? ";
    cin>>sureName;
    cin.ignore();
    if(sureName=="no") {
      cout<<"Why? ";
      getline(cin, reason);
      cout<<"Yea. Okay."<<endl;
    }
    else if(sureName=="yes") {
      runName = 0;
    }
  }
  runName = 1;
  while(runName) {
    cout<<"Hello "<<name<<". What's your favourite flavour? ";
    getline(cin, flavour);
    cout<<"Are you sure? ";
    cin>>sureName;
    cin.ignore();
    if(sureName=="no") {
      cout<<"How? ";
      getline(cin, reason);
      cout<<"I don't believe it, but whatever."<<endl;
    }
    else if(sureName=="yes") {
      runName = 0;
    }
    getline(cin, flavour);
    cout<<"So you like "<<flavour<<", "<<name<<"!"<<endl;
  }
}
