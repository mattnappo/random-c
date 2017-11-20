#include <iostream>
#include <string>
using namespace std;
#include "header.h"

/*
class GenerateKey {
private:
  int p;
  int q;
  int n;
  int totient;

}
*/
int lcm(int one, int two) {
  int max = (one > two) ? one : two;
  while(1) {
    if (max % one == 0 && max % two == 0) {
      return max;
    } else {
      ++max;
    }
  }
  return 0;
}
int gcd (int a, int b) {
  int x;
  while (b) {
    x = a % b;
    a = b;
    b = x;
  }
  return a;
}
int eCalc(totient) {
  while(1) {
    int r = 0;
    //random number 'r' less than totient
    if(r>1) {
      return r;
    }
  }
}
int main() {
  int p = 7;
  int q = 5;
  int n = p*q;
  int totient = lcm(p--, q--);
  //eCalc(random number, totient)

}
