#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int main() {
	int N;
	cin >> N;
	//idx 0~4000은 양수, 4001~8000은 음수 -(id-4000) ~ -(idx)
	int most_num[8001] = { 0, };

	vector<int> vec(N);
	int num;
	int sum = 0;
	
	for (int i = 0; i < N; i++) {
		cin >> vec[i];
		sum += vec[i];
	}
	sort(vec.begin(), vec.end());
	int big = vec[N - 1];
	int small = vec[0];
	vector<int>::iterator it;
	
	int idx = 0;
	//양수에서의 탐색우선
	for (it = vec.begin(); it != vec.end(); it++) {
		for (idx = 0; idx < 8001; idx++) {
			if (idx < 4001) {
				if (*it == idx)
					most_num[idx]++;
			}
			else if (idx > 4000) {
				if (*it == 4000-idx)
					most_num[idx]++;
			}
		}
	}

	//가장 많이나온 횟수가 max에 들어감
	int mxx=most_num[0];
	for (int i = 1; i < 8001; i++) {
		if (mxx < most_num[i])
			mxx = most_num[i];
	}

	
	//산술 평균 출력
	//double ans = (double)sum / N;

	cout << (int)round(sum/double(N)) << '\n';

	//중앙값 N/2 번째
	cout << vec[N / 2] << '\n';

	//최빈값 출력
	vector<int> vec2(8001);
	fill(vec2.begin(), vec2.end(), 0);
	int count = 0;
	int pos = 0;
	int maxpos = 0;


	for (int i = 0; i < N; i++) {
		pos = vec[i] + 4000;		//*** 이미 위에서 sort한 vec의 값이기때문에 작은수부터 들어가게 됨 pos에 따라서 pos도 정렬되있음
		vec2[pos]++;

		maxpos = max(maxpos, vec2[pos]);
	}
	//이 과정이 끝나면 pos는 index의 값을 가지고잇고 계속
	//maxpos는 vec2의 값  중에서 가장 큰 값을 가지고 있음

	int secondmany = 0;

	for (int i = 0; i < vec2.size(); i++) {
		//맥스값이 이미 판별났으니 그것과 같은것이 있는지 없는지만 조사하면된다, 2개이상 발견되는 순간 끝~
		if (vec2[i] == maxpos) {
			count++;					//본인꺼까지 포함해서 count가 2이상이 되는지가 중요함
			secondmany = i - 4000;	//두번째로 큰 것의 값은 인덱스값에서 4000을빼야함, 위에서 더했으니까
		}
		if (count == 2) {
			secondmany = i - 4000;
			break;	//2개가 되는순간 그냥 종료하게 해버림. 더이상 판단할 필요가 없다.
		}
	}
	cout << secondmany << '\n';

	//범위 출력
	cout << big-small << '\n';

	return 0;
}