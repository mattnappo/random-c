#include <iostream>
#include <string>
using namespace std;
class Person {
private:
	int age;
	string gender;
	string name;
	string state;
public:
	int print() {
		if(name!=""&&age!=0&&gender!=""&&state!="") {
			system("clear");
			cout<<name<<" is a "<<age<<"-year-old "<<gender<<" from "<<state<<endl;
			return 1;
		} else {
			return 0;
		}
	}
	void build() {
		cout<<"What's your name? ";
		cin>>name;
		cout<<"Age? ";
		cin>>age;
		cout<<"Gender? ";
		cin>>gender;
		cout<<"Where are you from? ";
		cin.ignore();
		getline(cin, state);
	}
};
int main() { return 1; }
