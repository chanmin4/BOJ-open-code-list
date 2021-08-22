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
vector<ll>p;
ll find(ll n) {
	if (p[n] == n)return n;
	p[n] = find(p[n]);
	return find(p[n]);
}
void merge(ll a, ll b) {
	a = find(a);
	b = find(b);
	if (a == b)return;
	p[b] = a;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0),cout.tie(0);
	cin >> n;
	cin >> m;
	p=vector<ll>(n + 1);
	for (int i = 1; i <= n; i++) {
		p[i] = i;
	}
	ll now = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> now;
			if (now == 1)
				merge(i, j);

		}
	}
	ll num = 0;
	cin >> num;
	ll b = 0;
	b = find(num);
	for (int i = 1; i < m; i++) {
		cin >> num;
		if (b != find(num)) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}