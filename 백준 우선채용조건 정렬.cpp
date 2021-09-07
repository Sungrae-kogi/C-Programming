#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
	int paper;
	int meeting;

	Student(int paper, int meeting) {
		this->paper = paper;
		this->meeting = meeting;
	}
};

bool compare(Student a, Student b) {
	if (a.paper < b.paper) {
		return true;
	}
	return false;
}


int main() {

	int T;
	cin >> T;

	int N;
	int pap, mee, count;
	for (int i = 0; i < T; i++) {
		count = 0;
		vector<Student> vec;
		
		vector<Student>::iterator it;
		vector<Student>::iterator it2;	//ä�� ����� ����Ű�� �� �ݺ���
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> pap >> mee;
			vec.push_back(Student(pap, mee));
		}
		sort(vec.begin(), vec.end(), compare);
		//�� 1�� ������ �������� ������������ ����, �׷��� �� ������ �ּ��� �ϳ��� ���� �־�� �� �������Ե� �������ʴ� ����� ��Ÿ��
		//��, �׻���� ������ ä�� �����ϴٴ� �ǹ� ****

		it2 = vec.begin();	//�ٷ� ã�� ������ ä�밡���� ����� ��ġ ���� ����
		count = 1;			//ä�������ϱ�
		for (it = vec.begin()+1; it != vec.end(); it++) {	//2��° �ε������� Ž���Ѵ�
			if (it->meeting < it2->meeting) {	//ä��Ȯ���� ������� �� 2�� ������ �� ���� ����� ���� ���� ������ ����� ã�´�, �̹� ��1 ������ ���ĵǾ� �����ϱ� �̻���� �״���
				count++;							//ä�� �ֿ켱 ������ �Ǵ� ���̴�.
				it2 = it;					//ä��Ȯ�� ����� ��������, 
			}
		}

		cout << count << '\n';
	}
	return 0;
}