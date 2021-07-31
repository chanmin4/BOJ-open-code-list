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
int max_level;
ll w, h, x, y, p;
ll ccw(ll x1, ll y1, ll x2, ll y2) {
	return x1 * y2 - x2 * y1;
}
bool checkin(ll p1, ll p2) {
	if (ccw(w, 0, p1 - x, p2 - y) >= 0 && ccw(w, 0, p1 - x, p2 - (y + h)) <= 0) {
		if (x <= p1 && p1 <= x + w)return true;
		else if (((pow(p1 - x, 2) + pow(p2 - (y + (h / 2) * 1ll), 2) <= pow((h / 2) * 1ll, 2)) && p1 <= x) ||
			(pow(p1 - (x + w), 2) + pow(p2 - (y + (h / 2) * 1ll), 2) <= pow((h / 2) * 1ll, 2)) && x + w <= p1)return true;
		else return false;
	}
	else return false;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> w >> h >> x >> y >> p;
	int result = 0;
	for (int i = 0; i < p; i++) {
		ll a, b;
		cin >> a >> b;
		if (checkin(a, b))result++;
	}
	cout << result << endl;
}