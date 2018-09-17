#include <iostream>
using namespace std;

class Point {
public:
    int x;
    int y;

    Point(int xx = 0, int yy = 0) : x(xx), y(yy) {
        // x = xx;
        // y = yy;
    }

    void print_point() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    
    Point p(10, 5);
    p.print_point();

    return 0;
}