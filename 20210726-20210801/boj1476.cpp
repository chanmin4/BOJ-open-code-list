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
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll e = 0, m = 0, s = 0;
	ll E = 0, M = 0, S = 0;
	ll result = 0;
	cin >> E >> S >> M;
	while (1) {
		if (E == e && M == m && S == s) {
			cout << result;
			break;
		}
		if (e == 15)e = 0;
		if (m == 19)m = 0;
		if (s == 28)s = 0;
		m++;
		s++;
		e++;
		result++;
	}
}