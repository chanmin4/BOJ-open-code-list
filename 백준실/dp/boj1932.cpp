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
vector<vector<ll>>v;
vector<vector<ll>>b;
ll dp(ll n) {
	b[0][0] = v[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				b[i][j] = b[i - 1][j] + v[i][j];
			}
			else if (j == i) {
				b[i][j] = b[i - 1][j - 1] + v[i][j];
			}
			else
				b[i][j] = max(b[i - 1][j - 1], b[i - 1][j]) + v[i][j];
		}
	}
	ll max = b[n - 1][0];
	for (int i = 0; i < n; i++) {
		if (max < b[n - 1][i])
			max = b[n - 1][i];
	}
	return max;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	b=vector<vector<ll>>(n + 1, vector<ll>(n + 1, 0));
	v=vector<vector<ll>>(n + 1, vector<ll>(n + 1, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> v[i][j];
		}
	}
	cout << dp(n);
}