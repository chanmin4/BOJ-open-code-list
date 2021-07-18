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
ll n, m, t, l;
vector<ll>b;
vector<vector<ll>>f;
ll fibo(ll n) {
	f[1][0] = f[1][1] = f[1][2] = 1;
	if (n == 1)return 3;
	for (int i = 2; i <= n; i++) {
		f[i][0] = (f[i - 1][0] + f[i - 1][1] + f[i - 1][2]) % 9901;
		f[i][1] = (f[i - 1][0] + f[i - 1][2]) % 9901;
		f[i][2] = (f[i - 1][0] + f[i - 1][1]) % 9901;
		b[i] = (f[i][0] + f[i][1] + f[i][2]) % 9901;
	}
	return b[n];
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	b = vector<ll>(n + 1);
	f=vector<vector<ll>>(n + 1, vector<ll>(3, 0));
	cout << fibo(n);
}