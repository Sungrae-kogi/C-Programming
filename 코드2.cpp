#include <iostream>
#include <vector>
using namespace std;

class Point {
	int x, y;
public:
	Point(int x, int y): x(x),y(y){}
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	int getX() { return x; }
	int getY() { return y; }

};
int main() {
	Point* p = new Point(100, 200);
	p->setX(30);
	p->setY(60);
	cout << "¸â¹öº¯¼ö x:" << p->getX() << endl;
	cout << "¸â¹öº¯¼ö y:" << p->getY() << endl;
	delete p;
	return 0;
}