#include <iostream>
#include <string>
using namespace std;
//#include "header.h"
class Math {
public:
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
};
class Key {
private:
  Math math;
  int p;
  int q;
  int n;
  int totient;
  int e;
  int d;
  int public[2];
  int private[2];
  int eCalc() {
    int r = 2;
    while(1) {
      if(math.gcd(e, totient) == 1) {
        return r;
      } else {
        r = rand() % totient;
      }
    }
  }
  int dCalc() {
    int r = 2;
    while(1) {
      if(r * e % totient == 1) {
        return r;
      } else {
        r = rand() % n;
      }
    }
  }
public:
  int generate() {
    p = 61;
    q = 53;
    n = p*q;
    totient = math.lcm(p--, q--);
    e = eCalc();
    d = dCalc();

    return 1;
  }
  int* getPublic() {
    return public;
  }
  int* getPrivate() {
    return private;
  }
};
class Modifier {
public:
  string encrypt(string decrypted, int[2] key) {
    return "";
  }
  string decrypt(string encrypted, int[2] key) {
    return "";
  }
};


int main() {
  Key key;
  key.generate();

  Modifier modifier;
  string encrypted = modifier.encrypt("Hello world", key.getPublic())
  string decrypted = modifier.decrypt(encrypted, key.getPrivate());
  cout<<"Encrypted: "<<encrypted<<endl;
  cout<<"Decrypted: "<<decrypted<<endl;
}
