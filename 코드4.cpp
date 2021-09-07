#include <iostream>
#include <vector>
using namespace std;

class Car {
	int speed;
	int gear;
	string color;
	int id;

public:
	static int numberOfCars;
	Car(int s = 0, int g = 1, string c = "white") : speed(s), gear(g), color(c) {
		id = ++numberOfCars;
	}
};

int Car::numberOfCars = 0;

int main() {
	Car c1;
	Car c2;
	cout << c2.numberOfCars << endl;
	cout << Car::numberOfCars << endl;
}