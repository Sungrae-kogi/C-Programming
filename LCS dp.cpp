#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <climits>

using namespace std;
char a[1001], b[1001];
int n, m;
int dp[1001][1001];
int solve(int pos1, int pos2) {
	
	if (pos1 == n || pos2 == m) {
		return 0;
	}
	if (a[pos1] == b[pos2])
		return 1 + solve(pos1 + 1, pos2 + 1);		//앞에서 같은게 발견되는순간이니 +1해주는거

	int ret = 0;
	if (dp[pos1][pos2] != -1)
		return dp[pos1][pos2];

	ret = max(solve(pos1 + 1, pos2), solve(pos1, pos2 + 1));

	dp[pos1][pos2] = ret;
	return dp[pos1][pos2];
	
}

int main() {
	
	cin >> a >> b;
	n = strlen(a);
	m = strlen(b);
	memset(dp, -1, sizeof(int) * 1001 * 1001);

	int ret = solve(0, 0);

	cout << ret << endl;

	return 0;
}