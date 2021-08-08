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
ll dp() {
	for (int j = 1; j <= m - n + 1; j++) {
		b[1][j] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 1; k <= j - 1; k++) {
				b[i][j] += b[i - 1][k];
			}
		}

	}
	ll sum = 0;
	for (int i = 1; i <= m; i++) {
		sum += b[n][i];
	}
	return sum;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ld x1, y1, r1, x2, y2, r2 = 0;
	ll test = 0;
	cin >> test;
	for (int i = 0; i < test; i++) {
		cin >> n >> m;
		b=vector<vector<ll>>(n + 1, vector<ll>(m + 1));
		cout << dp() << "\n";
		b.clear();
	}
}