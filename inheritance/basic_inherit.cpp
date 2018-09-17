#include <iostream>
using namespace std;

class Person {
public:
    string m_name;
    int m_age;
 
    Person(string name = "", int age = 0) : m_name(name), m_age(age) {
        cout << "name: " << name << endl;
        cout << "m_name: " << m_name << endl;

    }
 
};

class BaseballPlayer : public Person {
public:
    double m_battingAverage;
    int m_homeRuns;
 
    BaseballPlayer(double battingAverage = 0.0, int homeRuns = 0)
        : m_battingAverage(battingAverage), m_homeRuns(homeRuns)
    {
    }
};
 
int main()
{
    // Create a new BaseballPlayer object
    BaseballPlayer joe;
    // Assign it a name (we can do this directly because m_name is public)
    joe.m_name = "Joe";
    // Print out the name
    cout << joe.getName() << '\n'; // use the getName() function we've acquired from the Person base class
 
    return 0;
}