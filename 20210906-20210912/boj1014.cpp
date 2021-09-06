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
ll temp[10];
vector<string>line;
vector<vector<ll>>dp;
vector<vector<char>>arr;
void dfs(ll num) {
	if (num == m) {
		string s;
		for (int i = 0; i < m;i++) {
			s += to_string(temp[i]);
		}
		line.push_back(s);
		return;
	}
	temp[num] = 0;
	dfs(num + 1);
	if (0 < num && temp[num - 1] != 0)return;
	temp[num] = 1;
	dfs(num + 1);
}
ll solve(ll cur,ll prev) {
	if (n==cur) {
		return 0;
	}
	if (dp[cur][prev]) {
		return dp[cur][prev];
	}
	ll result = 0;
	for (auto s: line) {
		ll bits = 0;
		ll cnt = 0;
		for (int i = 0; i < m; i++) {
			if ('0' == s[i])continue;
			if ('x' == arr[cur][i])continue;
			if (i && prev & (1 << (i - 1)))continue;
			if (i < m && prev & (1 << (i + 1)))continue;
			cnt++;
			bits |= (1 << i);
		}
		result = max(result, solve(cur + 1, bits) + cnt);
	}
	return dp[cur][prev] = result;
	
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		arr = vector<vector<char>>(n,vector<char>(m));
		dp = vector<vector<ll>>(n, vector<ll>(1 << m));
		memset(temp, 0, sizeof(temp));
		line={};
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
			}
		}
		dfs(0);
		cout << solve(0, 0) << "\n";
	}
}

