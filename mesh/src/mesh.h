#ifndef MESH_H
#define MESH_H

// ----- POINT -----

struct Point {
    float x;
    float y;
    float z;
};

float distance(struct Point a, struct Point b);
void print_point(struct Point p);
void test_point();

// ----- SHAPE -----

#endif