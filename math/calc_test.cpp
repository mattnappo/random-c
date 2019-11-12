#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <Calculus.h>

#define MATH_UTILS_H
#include <tnt/tnt.h>

using namespace std;
using namespace TNT;

int main() {
	initialize_calculus(0);
	Variable x = "x";
	Variable y = "y";
	
	char *buffer;

	Function t = INT_POW(6, x) * y * y + x;
	t -> to_string(buffer = new char[t -> to_string(NULL) + 1]);

	printf("t: %s\n\n", buffer);
	delete [] buffer;

	Function dtdx = t -> get_partial_derivative(x);
	dtdx -> to_string(buffer = new char[dtdx -> to_string(NULL) + 1]);

	printf("dtdx: %s\n\n", buffer);
	delete [] buffer;

	return 0;
} 
