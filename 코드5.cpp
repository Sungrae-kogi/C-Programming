#include <iostream>
#include <vector>
using namespace std;

class Box {
private:
	double length;
	double width;
	double height;
public:
	static int objectCount;
public:
	Box(double l = 2.0, double w = 2.0, double h = 2.0) {
		length = l;
		width = w;
		height = h;
		objectCount++;
	}
	double Volume() { return length * width * height; }
};

int Box::objectCount = 0;;
int main(void) {
	Box Box1(1.0, 2.0, 3.0);
	Box Box2(1.0, 2.0, 5.0);
	cout << "ÀüÃ¼ °´Ã¼ ¼ö :" << Box::objectCount << endl;
	return 0;
}