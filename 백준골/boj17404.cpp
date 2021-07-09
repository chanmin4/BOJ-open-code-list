#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<stdio.h>
#include<cstring>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<list>
#include<unordered_set>
#include<time.h>
#define fup(i,a,b,c) for(int i=a;i<=b;i+=c)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef pair<ll, ll>P;
typedef pair<ld, ld>dP;
ll MOD = 1e6;
ll n, m, t, l, c;
vector<vector<ll>>dp;
vector<vector<ll>>a;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
	dp = vector<vector<ll>>(n + 1, vector<ll>(3));
	a = vector<vector<ll>>(n + 1, vector<ll>(3));
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			ll num;
			cin >> num;
			a[i][j] = num;
		}
	}
	ll result = 1e10;
	for (int color = 0; color <= 2; color++) {
		for (int i = 0; i <= 2; i++) {
			if (color == i) {
				dp[1][i] = a[1][i];
				
			}
			else {
				dp[1][i] = 1e10;
			}
		}
		for (int i = 2; i <= n; i++) {
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + a[i][0];
			dp[i][1] = min(dp[i - 1][2], dp[i - 1][0]) + a[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + a[i][2];
		}
		for (int i = 0; i <= 2; i++) {
			if (i == color)continue;
			result = min(result, dp[n][i]);
		}
	}
	cout << result;
}