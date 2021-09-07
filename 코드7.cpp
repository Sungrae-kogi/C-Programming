#include <iostream>
#include <vector>
using namespace std;

class Employee {
	string name;
	double salary;
	static int count;
public:
	Employee(string n = "", double s = 0.0) : name(n), salary(s) {
		count++;
	}
	~Employee() {
		count--;
	}
	static int getCount() {
		return count;
	}

};

int Employee::count = 0;
int main() {
	Employee e1("±èÃ¶¼ö", 35000);
	Employee e2("ÃÖ¼öÃ¶", 50000);
	Employee e3("±èÃ¶È£", 20000);

	int n = Employee:getCount();
	cout << "ÇöÀçÀÇ Á÷¿ø¼ö=" << n << endl;
	return 0;

}