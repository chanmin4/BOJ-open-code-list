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
vector<P>V;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0),cout.tie(0);
	cin >> n;
	ll s = 0, e = 0;
	V.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		V[i] = { s,e };
	}
	sort(V.begin(), V.end());
	ll l = -2000000000, r = -2000000000;
	ll result = 0;
	for (int i = 0; i < n; i++) {
		if (r < V[i].first) {
			result += r - l;
			l = V[i].first;
			r = V[i].second;
		}
		else {
			r = max(r, V[i].second);
		}
	}
	result += r - l;
	cout << result;
}