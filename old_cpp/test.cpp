#include<iostream>
int combine(int a, int b) {
  int times = 1;
  while(times <= b) {
    times*=10;
  }
  return a*times + b;
}
int main() {
	std::cout<<combine(12, 15);
}
