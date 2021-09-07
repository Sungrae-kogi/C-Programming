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
		vector<Student>::iterator it2;	//채용 대상을 가리키게 할 반복자
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> pap >> mee;
			vec.push_back(Student(pap, mee));
		}
		sort(vec.begin(), vec.end(), compare);
		//제 1의 조건을 기준으로 오름차순으로 정렬, 그러면 맨 위에는 최소한 하나의 과목에 있어서는 그 누구에게도 뒤지지않는 사람이 나타남
		//즉, 그사람은 무조건 채용 가능하다는 의미 ****

		it2 = vec.begin();	//바로 찾은 무조건 채용가능한 사람의 위치 임의 저장
		count = 1;			//채용했으니까
		for (it = vec.begin()+1; it != vec.end(); it++) {	//2번째 인덱스부터 탐색한다
			if (it->meeting < it2->meeting) {	//채용확정인 사람보다 제 2의 조건이 더 높은 사람을 가장 먼저 나오는 사람을 찾는다, 이미 제1 조건이 정렬되어 있으니까 이사람이 그다음
				count++;							//채용 최우선 순위가 되는 것이다.
				it2 = it;					//채용확정 사람을 변경해줌, 
			}
		}

		cout << count << '\n';
	}
	return 0;
}