#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <climits>

using namespace std;

const int N = 4;
const int M = 14;
const int INF = INT_MAX;

int dp[M + 1];
int coin[N] = { 1,4,5,6 };
int main() {
	for (int i = 1; i <= M; i++) {
		dp[i] = INF;
	}
	for (int i = 0; i < N; i++) {
		for (int j = coin[i]; j <= M; j++) {
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}

	cout << dp[M] << endl;

	return 0;
}