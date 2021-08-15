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
vector<vector<ll>>mapp;
vector<vector<ll>>b;
ll dp() {
	b[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if ((i == n && j == n))continue;
			ll dist = mapp[i][j];
			ll down = i + dist;
			ll right = j + dist;

			if (down <= n) {
				b[down][j] += b[i][j];
			}
			if (right <= n) {
				b[i][right] += b[i][j];
			}
		}
	}
	return b[n][n];
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	b=vector<vector<ll>>(n + 1, vector<ll>(n + 1));
	mapp=vector<vector<ll>>(n + 1, vector<ll>(n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mapp[i][j];
		}
	}
	cout << dp();
}