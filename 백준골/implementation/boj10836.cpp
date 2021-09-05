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
vector<vector<int>>mapp;
vector<int>a;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int num0 = 0, num1 = 0, num2 = 0;
	cin >> m >> n;
	mapp.resize(m+ 1, vector<int>(m + 1, 1));
	a.resize(2 * m, 1);
	for (int j = 0; j < n; j++) {
		cin >> num0 >> num1 >> num2;
		for (int i = num0; i < num0 + num1; i++) {
			a[i] += 1;
		}
		for (int k = num0 + num1; k < 2 * m - 1; k++) {
			a[k] += 2;
		}
	}
	for (int j = 0; j < 2 * m- 1; j++) {
		if (j >= m - 1) {
			mapp[0][j - (m - 1)] = a[j];
		}
		else {
			mapp[(m - 1) - j][0] = a[j];
		}
	}
	for (int r = 1; r < m; r++) {
		for (int l = 1; l < m; l++) {
			int up = max(mapp[r][l - 1], max(mapp[r - 1][l - 1], mapp[r - 1][l]));
			mapp[r][l] = up;
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << mapp[i][j] << " ";
		}
		cout << "\n";
	}
}

