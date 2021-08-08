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
vector<vector<bool>>check;
vector<ll>a;
int fibo(int n, int m) {
	int result = -1;
	check[0][a[0]] = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (!check[i - 1][j]) {
				continue;
			}
			if (j + a[i] <= m) {
				check[i][j + a[i]] = true;
			}
			if (j - a[i] >= 0) {
				check[i][j - a[i]] = true;
			}
		}
		//check[i] 가 전부  false 면 return -1;->result=-1
	}
	//check[n]의 true 중에서 최대값 출력
	for (int i = 0; i <= m; i++) {
		if (check[n][i] == true) {
			if (result < i)result = i;
		}
	}
	return result;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll s = 0;
	cin >> n >> s >> m;
	a = vector<ll>(n + 1);
	a[0] = s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	check=vector<vector<bool>>(n + 2, vector<bool>(m + 2, false));
	cout << fibo(n, m);
}