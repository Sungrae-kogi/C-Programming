#include <iostream>
using namespace std;

class Book {
private:
	int isbn;
	string title;
public:
	Book() {
		this->isbn = 0;
		title = "unknown";
	}
	Book(int isbn) {
		this->isbn = isbn;
		title = "unknown";
	}
	Book(int isbn, string title) {
		this->isbn = isbn;
		this->title = title;
	}
	void display() {
		cout << isbn << ":" << title << endl;
	}
};

int main() {
	Book b1 = 9782001;
	b1.display();
	b1 = 9783001;
	b1.display();
	return 0;
}
/*  **ex) Rect &a or Rect &b 식으로 하는 것은 Rect 클래스로 찍어낸 객체들의 주소를 참조하여 
그 객체들의 내용물을 바꾸기 위함  이것이 차이점** */