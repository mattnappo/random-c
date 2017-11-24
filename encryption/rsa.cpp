#include <iostream>
#include <string>
#include <cmath>
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
  int pub[2];
  int priv[2];
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
    //pub[0], pub[1] = n, e;
    //priv[0], priv[1] = n, d;
    pub[0] = n;
    pub[1] = e;
    priv[0] = n;
    priv[1] = d;
    return 1;
  }
  int* getPublic() {
    return pub;
  }
  int* getPrivate() {
    return priv;
  }
};
class Modifier {
private:
  string intArrToString(int intArr[], int arrSize) {
    string returnstring = "";
    for (int temp = 0; temp < arrSize; temp++) {
      returnstring += itoa(intArr[temp]);
      return returnstring;
    }
  }
  int* translate(string s) {
    int arr[s.length()];
    for(int i = 0; i < s.length(); i++) {
      arr[i] = s[i];
    }
    return arr;
  }
public:
  string encrypt(string decrypted, int key[]) {
    int len = decrypted.length();
    int asci[len] = translate(decrypted);
    for(int i = 0; i < len; i++) {
      asci[i] = pow(asci[i], key[1]) % key[0];
    }
    string encrypted = intArrToString(asci, len);
    return encrypted;
  }
  string decrypt(string encrypted, int key[]) {
    return "";
  }
};


int main() {
  Key key;
  key.generate();

  Modifier modifier;
  string encrypted = modifier.encrypt("Hello world", key.getPublic());
  string decrypted = modifier.decrypt(encrypted, key.getPrivate());
  cout<<"Encrypted: "<<encrypted<<endl;
  cout<<"Decrypted: "<<decrypted<<endl;
}
