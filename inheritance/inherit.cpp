#include <iostream>
using namespace std;

class Vehicle {
public:
    string license_plate;
    int wheel_count;
    string engine_type;
    float top_speed;

    Vehicle(string license_plate, int wheel_count, string engine_type, float top_speed) {
        this->license_plate = license_plate;
        this->wheel_count = wheel_count;
        this->engine_type = engine_type;
        this->top_speed = top_speed;
    }

    void print_stats() {
        cout << "License plate: " << license_plate << endl;
        cout << "  Wheel count: " << wheel_count << endl;
        cout << "  Engine type: " << engine_type << endl;
        cout << "    Top speed: " << top_speed << endl;
    }
};

class Car : public Vehicle {
public:
    string brand;
    int seats;

    Car(string brand, int seats) :  {
        this->brand = brand;
        this->seats = seats;
    }
};




int main() {
    Vehicle v("COOLGUY", 4, "v8 turbo", 200.5);
    v.print_stats();


    return 0;
}