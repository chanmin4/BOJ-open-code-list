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
vector<vector<int>>v;
vector<vector<int>>b;
int dp(int n) {
	b[0][0] = v[0][0];
	b[1][0] = v[1][0];
	//v[0]부터시작
	for (int i = 1; i <= n - 1; i++) {
		b[1][i] = max(b[1][i], max(b[1][i - 1], b[0][i - 1] + v[1][i]));
		b[0][i] = max(b[0][i], max(b[0][i - 1], b[1][i - 1] + v[0][i]));

	}
	//v[1]부터시작
	return max(b[0][n - 1], b[1][n - 1]);
}
void init(int n) {
	for (int i = 0; i < n; i++) {
		v[0][i] = 0;
		b[0][i] = 0;
	}
	for (int i = 0; i < n; i++) {
		b[1][i] = 0;
		v[1][i] = 0;
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int num = 0;
	cin >> test;
	for (int i = 0; i < test; i++) {
		cin >> n;
		v.resize(2, vector<int>(n + 1));
		b.resize(2, vector<int>(n + 1));
		for (int j = 0; j < n; j++) {
			cin >> v[0][j];
		}
		for (int k = 0; k < n; k++) {
			cin >> v[1][k];
		}
		cout << dp(n) << "\n";
		v.clear();
		b.clear();
	}
}

