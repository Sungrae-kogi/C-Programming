#include <iostream>
#include <vector>
using namespace std;

class Car {
	int speed, gear, id;
	string color;
public:
	static int numberOfCars;
	Car(int s = 0, int g = 1, string c = "white") : speed(s), gear(g), color(c) {
		id = ++numberOfCars;
	}
	static int getNumberOfCars() {
		return numberOfCars;
	}
};
int Car::numberOfCars = 0;

int main() {
	Car c1(100, 0, "blue");
	Car c2(0, 0, "white");
	int n = Car::getNumberOfCars();
	cout << "지금까지 생성된 자동차 수 =" << n << endl;
	return 0;
}