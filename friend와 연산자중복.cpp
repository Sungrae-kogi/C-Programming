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
/*  **ex) Rect &a or Rect &b ������ �ϴ� ���� Rect Ŭ������ �� ��ü���� �ּҸ� �����Ͽ� 
�� ��ü���� ���빰�� �ٲٱ� ����  �̰��� ������** */