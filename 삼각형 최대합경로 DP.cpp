#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <climits>

using namespace std;
const int N=501;

int triangle[N][N];
int dp[N][N] = { 0, };
int n;
int solve(int y, int x) {	//y, x 순서해놓은건 y를 높이로 보려고
	if (y > n || x > n)
		return -1000;
	if (y == n)
		return triangle[y][x];
	if (dp[y][x] != 0)
		return dp[y][x];
	int ret = 0;
	ret = max(triangle[y][x] + solve(y + 1, x),
		triangle[y][x] + solve(y + 1, x + 1));

	dp[y][x] = ret;
	return dp[y][x];
}

int main() {
	int i;
	cin >> n;
	for (i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> triangle[i][j];
		}
	}
	cout << solve(1, 1) << endl;

	return 0;
}