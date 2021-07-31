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
vector<ll>a;
ll func(ll none) {
	ll result = 0;
	for (ll i = 1; i < n; i++) {
		result += abs(i * none - a[i]);
	}
	return result;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    a=vector<ll>(100001);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll hi = a[n - 1], lo = 0;
    while (hi - lo >= 3) {
        ll p = (lo * 2 + hi) / 3, q = (lo + hi * 2) / 3;
        if (func(p) <= func(q)) {
            hi = q;
        }
        else lo = p;
    }
    ll mini = 1e18;
    for (int i = lo; i <= hi; i++) {
        mini = min(func(i), mini);
    }
    cout << mini;
}