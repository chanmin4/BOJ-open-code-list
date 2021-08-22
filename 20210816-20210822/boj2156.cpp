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
vector<ll>b;
ll dp(ll n) {
	//b[i][마신횟수]
	//첫번째부터마심 1은 마심 0은 안마심
	b[1] = arr[1];
	if (n >= 2) {
		b[2] = b[1] + arr[2];//최대값을 구하는거기때문에
	}
	for (int i = 3; i <= n; i++) {
		int result = max(arr[i] + b[i - 2], max(b[i - 1], b[i - 3] + arr[i] + arr[i - 1]));
		b[i] = result;
	}
	return b[n];
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0),cout.tie(0);
	cin >> n;
	b=vector<ll>(n + 1);
	arr=vector<ll>(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	cout << dp(n);
}