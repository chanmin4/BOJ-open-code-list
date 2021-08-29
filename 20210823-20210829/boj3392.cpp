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
ll MAX = 30000;
vector<ll>seg(pow(2, ceil(log2(MAX)) + 1));
vector<ll>cnt(pow(2, ceil(log2(MAX)) + 1));
struct mars {
	ll x, y1, y2, direct;
	mars() {}
	mars(int a, int b, int c, int d) {
		x = a;
		y1 = b;
		y2 = c;
		direct = d;
	}
	bool operator<(mars m) {
		return x < m.x;
	}
};
vector<mars>ma;
void update(int start, int end, int val, int node, int fixstart, int fixend)
{
	if (end < fixstart || fixend < start)return;
	if (fixstart <= start && end <= fixend) {
		cnt[node] += val;
	}
	else {
		ll mid = (start + end) / 2;
		update(start, mid, val, node * 2, fixstart, fixend);
		update(mid + 1, end, val, node * 2 + 1, fixstart, fixend);
	}
	if (cnt[node]) {
		seg[node] = end - start + 1;
	}
	else {
		if (start == end) seg[node] = 0;
		else seg[node] = seg[node * 2] + seg[node * 2 + 1];
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0),cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		//x좌표,시작인지 끝인지 , y좌표구간
		ma.push_back(mars(x1, y1, y2 - 1, 1));
		ma.push_back(mars(x2, y1, y2 - 1, -1));
	}
	sort(ma.begin(), ma.end());
	ll result = 0;
	ll prev = 0;
	for (int i = 0; i < 2 * n; i++) {
		ll now = ma[i].x;
		if (i) {
			ll dx = now - prev;
			result += dx * seg[1];
		}
		prev = now;
		update(0, MAX, ma[i].direct, 1, ma[i].y1, ma[i].y2);
	}
	cout << result;
}