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
map<ll, ll>ma;
ll fibonacii(ll n, ll p, ll q) {
	if (n == 0)return 1;
	if (ma[n] != 0) { return ma[n]; }
	else {
		ll ip = n / p;
		ll iq = n / q;
		ma[ip] = fibonacii(ip, p, q);
		ma[iq] = fibonacii(iq, p, q);
		return ma[ip] + ma[iq];
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll num = 0, p = 0, q = 0;
	cin >> num >> p >> q;
	cout << fibonacii(num, p, q);
}