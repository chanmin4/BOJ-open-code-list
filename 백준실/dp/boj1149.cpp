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
ll n, t, m, k;
vector<vector<ll>>b;
ll fibo(ll test, vector<vector<ll>>&k) {
	b[0][1] = b[0][0] = b[0][2] = 0;
	for (int i = 1; i <= test; i++) {
		b[i][0] = min(b[i - 1][1], b[i - 1][2]) + k[i][0];
		b[i][1] = min(b[i - 1][2], b[i - 1][0]) + k[i][1];
		b[i][2] = min(b[i - 1][0], b[i - 1][1]) + k[i][2];
	}
	return min(min(b[test][0], b[test][1]), b[test][2]);
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> t;
	b=vector<vector<ll>>(t + 1, vector<ll>(3, 0));
	vector<vector<ll>>k(t + 1, vector<ll>(3, 0));
	for (int i = 1; i <= t; i++) {
		for (int j = 0; j < 3; j++)
			cin >> k[i][j];
	}

	cout << fibo(t, k);
}