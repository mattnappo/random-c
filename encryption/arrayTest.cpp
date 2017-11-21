#include <iostream>
using namespace std;

int* filler(int arr[]) {
  for(int i = 0; i < 10; i++) {
    arr[i] = i;
  }
  return arr;
}

int main() {
  int arr[10];

  int *filled = filler(arr);

  for(int i = 0; i < 10; i++) {
    cout<<arr[i]<<" ";
  }

}
