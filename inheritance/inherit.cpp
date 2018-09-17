#include <iostream>
using namespace std;

class Vehicle {
public:
    string license_plate;
    int wheel_count;
    string engine_type;
    float top_speed;

    Vehicle(string _license_plate = "", int _wheel_count = 0, string _engine_type = "", float _top_speed = 0.0) {
        license_plate = _license_plate;
        wheel_count = _wheel_count;
        engine_type = _engine_type;
        top_speed = _top_speed;
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

    Car(string _brand = "", int _seats = 0) {
        brand = _brand;
        seats = _seats;
    }

    void print_car() {
        cout << "Brand: " << brand << endl;
        cout << "Seats: " << seats << endl;
    }
};

int main() {
    Vehicle v("COOLGUY", 4, "v8 turbo", 200.5);
    v.print_stats();

    Car c("Ferrari", 2);
    c.print_stats();
    c.print_car();

    return 0;
}