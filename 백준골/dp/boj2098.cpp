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
ll n, t, m, k, test;
vector<vector<ll>>arr;
vector<vector<ll>>dp;
ll solve(ll cur, ll prev) {
	if (dp[cur][prev]) {
		return dp[cur][prev];
	}
	if (prev == ((1 << n) - 1)) {
		return arr[cur][0] > 0 ? arr[cur][0] : 1e10;
	}
	ll temp = 1e10;
	for (int i = 0; i < n; i++) {
		if (prev & (1 << i)||arr[cur][i]==0 ) {
			continue;
		}
		ll num = solve(i, prev|(1<<i)) + arr[cur][i];
		temp = min(temp, num);
		
	}
	return dp[cur][prev] = temp;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	arr = vector<vector<ll>>(n, vector<ll>(n));
	dp = vector<vector<ll>>(n, vector<ll>(1<<n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	cout << solve(0, 1);//0번도시 방문한채로 스타트
}

