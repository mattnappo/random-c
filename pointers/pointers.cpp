#include <iostream>
#include <cstdint>
using namespace std;

int main() {
	uint64_t longArray[] = {4294967295 + 1, 1, 2};
	uint32_t *pointer = (uint32_t *)longArray;
	cout << *pointer << endl;
	pointer++;
	cout << *pointer;
	cout << pointer;
	
	return 0;
}
