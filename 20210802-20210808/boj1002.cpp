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
	ld x1, y1, r1, x2, y2, r2 = 0;
	ll test = 0;
	ld r0 = 0;
	cin >> test;
	for (int i = 0; i < test; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		r0 = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));

		if (r0 != 0) {
			if (r0 < r1 + r2) {
				if (r0 + r2 < r1 || r0 + r1 < r2)cout << 0 << "\n";
				else if ((r1 + r0 == r2) || (r2 + r0 == r1)) cout << 1 << "\n";
				else if (r1 + r0 > r2 || r2 + r0 > r1)cout << 2 << "\n";
			}
			else if (r0 == r1 + r2)cout << 1 << "\n";
			else if (r0 > r1 + r2) cout << 0 << "\n";
		}
		else if (r0 == 0) {
			if (r1 == r2)cout << -1 << "\n";
			else cout << 0 << "\n";
		}

	}
}