#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define TYPE float
#define LEN 16
#define INITIAL 0.0

typedef struct data {
	TYPE internal;
} Data;

Data *init_data_val(TYPE internal)
{
	Data *data = calloc(1, sizeof(Data));
	data->internal = internal;
	return data;
}

Data *init_data()
{
	Data *data = calloc(1, sizeof(Data));
	data->internal = 0.0;
	return data;
}

void free_data(Data *data)
{
    free(data);
}

void print_data(Data *data)
{
	printf("Data{i: %f}", data->internal);
}

// init_vec_data initializes a vector of n `Data`s.
Data **init_vec(uint32_t n) {
	Data **vec = malloc(sizeof(Data *) * n);
	for (int i = 0; i < n; i++) {
		vec[i] = init_data();
	}
	return vec;
}

void free_vec(Data **vec, uint32_t n)
{
    for (int i = 0; i < n; i++)
        free_data(vec[i]);

    free(vec);
}

void print_vec_row(Data **vec, uint32_t n)
{
    printf("\n| ");
	for (int i = 0; i < n; i++) {
		printf("%.2f ", vec[i]->internal);
	}
    printf("|\n\n");
}

void print_vec_col(Data **vec, uint32_t n)
{
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("| %.2f |\n", vec[i]->internal);
    }
    printf("\n");
}

// init_vec_2dinitializes a vector of vectors of `Data`s.
Data ***init_vec_2d(uint32_t n, uint32_t m)
{
	Data ***vec_2d = malloc(sizeof(Data **) * m);
	for (int i = 0; i < m; i++) {
		vec_2d[i] = init_vec(n);
	}
    return vec_2d;
}

void free_vec_2d(Data ***vec_2d, uint32_t n, uint32_t m)
{
    for (int i = 0; i < m; i++)
        free_vec(vec_2d[i], n);

    free(vec_2d);
}

void print_vec_2d(Data ***vec_2d, uint32_t n, uint32_t m)
{
    printf("\n");
    for (int i = 0; i < m; i++) {
        printf("| ");
        for (int j = 0; j < n; j++) {
            printf("%.2f ", vec_2d[i][j]->internal);
        }
        printf("|\n");
    }
    printf("\n");
}

int main(void)
{
    uint32_t s = 5;
	Data **vec = init_vec(s);
	print_vec_row(vec, s);
	print_vec_col(vec, s);

    free_vec(vec, s);

    uint32_t n = 5;
    uint32_t m = 5;

    Data ***vec_2d = init_vec_2d(n, m);
    print_vec_2d(vec_2d, n, m);
    free_vec_2d(vec_2d, n, m);

	return 0;
}

