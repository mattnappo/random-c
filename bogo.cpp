#include <iostream>
#include <iterator>
#include <algorithm>

#define SIZE 14
using namespace std;

void print(int(&numbers)[SIZE]) {
    copy(
        numbers,
        numbers + sizeof(numbers) / sizeof(numbers[0]),
        ostream_iterator<short>(cout, " ")
    );
	cout << endl;
}

int main() {
    clock_t tStart = clock();
	int numbers[SIZE] = { 4, 3, 2, 4, 1, 8, 2, 3, 1, 2, 6, 3, 6, 2 };
	while (true) {
		bool isSorted = true;
		for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]) - 1; i++) {
			if (numbers[i] > numbers[i + 1]) {
				isSorted = false;
                print(numbers);
				break;
			}
		} if (isSorted) {
			break;
		}
		random_shuffle(&numbers[0], &numbers[SIZE]);
	}
    
	print(numbers);
    printf("\033[1;32m%.2f seconds.\033[0m\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}

// 10 nums: 0.10 seconds
// 11 nums: 0.11 seconds
// 12 nums: 4.83 seconds
// 13 nums: 4.07 seconds
// 14 nums: no.