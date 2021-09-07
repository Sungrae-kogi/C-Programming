#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <climits>

using namespace std;

enum {
	LEFT = 1,
	UP = -1,
	CROSS = 0
};

int main() {
	string A, B;
	cin >> A >> B;
	

	
	int** arr = new int* [A.length() + 1]();
	int** s_arr = new int* [A.length() + 1]();
	for (int i = 0; i <= A.length(); i++) {
		arr[i] = new int[B.length() + 1]();
		s_arr[i] = new int[B.length() + 1]();
	}

	int result = 0;
	for (int i = 1; i <= A.length(); i++) {
		for (int j = 1; j <= B.length(); j++) {
			if (A[i - 1] == B[j - 1]) {
				arr[i][j] = arr[i - 1][j - 1] + 1;
				result = max(arr[i][j], result);
				s_arr[i][j] = CROSS;
			}
			else {
				arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
				if (arr[i][j] == arr[i - 1][j])
					s_arr[i][j] =UP;
				else
					s_arr[i][j] = LEFT;
			}
		}
	}
	int k = A.length();
	int l = B.length();
	string answer = "";
	while (arr[k][l] != 0) {
		switch (s_arr[k][l]) {
		case UP:
		{
			k--;
			break;
		}
		case CROSS:	//대각선만이 연속되는 스트링을 발견하고 추가한 경우니까 answer 을 더해줘야한다
		{
			answer = A[k - 1] + answer;
			k--; l--;
			break;
		}
		case LEFT:
		{
			l--;
			break;
		}
		}
	}


	
	for (int i = 0; i <= A.length(); i++) {
		for (int j = 0; j <= B.length(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	cout << answer << endl;

	cout << result << endl;
	return 0;
}