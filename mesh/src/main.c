#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct Point {
    float x;
    float y;
    float z;
};

float distance(struct Point a, struct Point b) {
    float distance = sqrt( pow((a.x - b.x), 2) + pow((a.y - b.y), 2) + pow((a.z - b.z), 2) );
    return distance;
}

void print_point(struct Point p) {
    printf("(%f, %f, %f)\n", p.x, p.y, p.z);
}


int main() {
    // struct Point A = {1, 0, 0};
    // struct Point B = {0, 1, 3};
    // struct Point C = {2, 3, 2};

    struct Point A = {0, 0, 0};
    struct Point B = {3, 0, 0};
    struct Point C = {3, 4, 0};

    float distances[] = {
        distance(A, B),
        distance(B, C),
        distance(A, C)
    };

    print_point(A);
    print_point(B);
    print_point(C);

    int size = sizeof(distances) / sizeof(float);
    for (int i = 0; i < size; i++) {
        printf("%d: %f\n", i, distances[i]);
    }

    
    // print(a, b, c)
    // print(a.distance(b)) #Should equal 3
    // print(a.distance(c)) #Should equal 5
    // print(b.distance(c)) #Should equal 4

}
