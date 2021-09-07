#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int main() {
	int N;
	cin >> N;
	//idx 0~4000�� ���, 4001~8000�� ���� -(id-4000) ~ -(idx)
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
	//��������� Ž���켱
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

	//���� ���̳��� Ƚ���� max�� ��
	int mxx=most_num[0];
	for (int i = 1; i < 8001; i++) {
		if (mxx < most_num[i])
			mxx = most_num[i];
	}

	
	//��� ��� ���
	//double ans = (double)sum / N;

	cout << (int)round(sum/double(N)) << '\n';

	//�߾Ӱ� N/2 ��°
	cout << vec[N / 2] << '\n';

	//�ֺ� ���
	vector<int> vec2(8001);
	fill(vec2.begin(), vec2.end(), 0);
	int count = 0;
	int pos = 0;
	int maxpos = 0;


	for (int i = 0; i < N; i++) {
		pos = vec[i] + 4000;		//*** �̹� ������ sort�� vec�� ���̱⶧���� ���������� ���� �� pos�� ���� pos�� ���ĵ�����
		vec2[pos]++;

		maxpos = max(maxpos, vec2[pos]);
	}
	//�� ������ ������ pos�� index�� ���� �������հ� ���
	//maxpos�� vec2�� ��  �߿��� ���� ū ���� ������ ����

	int secondmany = 0;

	for (int i = 0; i < vec2.size(); i++) {
		//�ƽ����� �̹� �Ǻ������� �װͰ� �������� �ִ��� �������� �����ϸ�ȴ�, 2���̻� �߰ߵǴ� ���� ��~
		if (vec2[i] == maxpos) {
			count++;					//���β����� �����ؼ� count�� 2�̻��� �Ǵ����� �߿���
			secondmany = i - 4000;	//�ι�°�� ū ���� ���� �ε��������� 4000��������, ������ �������ϱ�
		}
		if (count == 2) {
			secondmany = i - 4000;
			break;	//2���� �Ǵ¼��� �׳� �����ϰ� �ع���. ���̻� �Ǵ��� �ʿ䰡 ����.
		}
	}
	cout << secondmany << '\n';

	//���� ���
	cout << big-small << '\n';

	return 0;
}