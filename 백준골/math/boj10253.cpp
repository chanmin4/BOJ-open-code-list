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
ll a, b;
ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll temp = 0;
		cin >> a >> b;
		while (a != 1) {
			if (ll(b) % ll(a) == 0) {
				temp = ll(b / a);
			}
			else {
				temp = ll(b / a) + 1;
			}
			a = (a * temp - b);
			b = (b * temp);
			ll tempo = gcd(a, b);
			b /= tempo;
			a /= tempo;
		}
		cout << b << "\n";
	}
}

