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
vector<ll>arr;
vector<vector<vector<ll>>>dp;
ll num = 0;
ll solve(ll left,ll right,ll cur) {
	if (cur==num) {
		return 0;
	}
	if (dp[cur][left][right] != -1) {
		return dp[cur][left][right];
	}
	ll result = 1e10;
	ll first = 0;
	ll second = 0;
	if (abs(left - arr[cur]) == 0) {
		first = 1;
	}
	else if (abs(left - arr[cur]) == 2) {
		first = 4;
	}
	else first = 3;
	if (abs(right- arr[cur]) == 0) {
		second = 1;
	}
	else if (abs(right - arr[cur]) == 2) {
		second = 4;
	}
	else second = 3;
	if (left == 0)first = 2;
	if (right == 0)second = 2;
	result = min(solve(arr[cur],right,cur+1)+first, solve(left,arr[cur],cur+1)+second);
	return dp[cur][left][right]=result;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll a = 1;
	while (a) {
		cin >> a;
		if (a != 0)arr.push_back(a);
	}
	num = arr.size();
	dp = vector<vector<vector<ll>>>(num+1,vector<vector<ll>>(5,vector<ll>(5,-1)));
	cout<<solve(0, 0,0);
}

