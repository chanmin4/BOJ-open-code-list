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
void merge(ll a,ll b) {
	a = find(a);
	b = find(b);
	if (a == b)return;
	p[b] = a;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	p=vector<ll>(n + 1);
	for (int i = 0; i <= n; i++)p[i] = i;
	ll num1, num2, num3;
	for (int i = 0; i < m; i++) {
		cin >> num1 >> num2 >> num3;
		if (num1 == 0) {
			merge(num2, num3);
		}
		else {
			if (p[find(num2)] == p[find(num3)]) {
				cout << "YES" << "\n";
			}
			else cout << "NO" << "\n";
		}
	}
}