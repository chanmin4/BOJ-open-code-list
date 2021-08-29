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
vector<ll>seg;
ll x, y;
bool compare(P a, P b) {
	if (a.first != b.first) {
		return a.first < b.first;
	}
	return a.second > b.second;
}
ll sum(ll start, ll end, ll node, ll fixstart, ll fixend) {
	if (end < fixstart || fixend < start)return 0;
	if (fixstart <= start && end <= fixend) {
		return seg[node];
	}
	return sum(start, (start + end) / 2, node * 2, fixstart, fixend) + sum((start + end) / 2 + 1, end, node * 2 + 1, fixstart, fixend);

}
ll update(ll position, ll val, ll node, ll start, ll end) {
	if (end < position || position < start)return seg[node];
	if (start == end)return seg[node] = val;
	ll mid = (start + end) / 2;
	return seg[node] = update(position, val, node * 2, start, mid) + update(position, val, node * 2 + 1, mid + 1, end);

}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> test;
	while (test--) {
		cin >> n;
		vector<P>arr;
		vector <ll> ymaker;
		vector<ll>b;
		seg.resize(pow(2, ceil(log2(n)) + 1));
		arr.resize(n);
		ymaker.resize(n);
		b.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			arr[i] = P(x, y);
			ymaker[i] = y;
		}
		sort(ymaker.begin(), ymaker.end());
		ymaker.erase(unique(ymaker.begin(), ymaker.end()), ymaker.end());
		sort(arr.begin(), arr.end(), compare);
		ll result = 0;
		for (int i = 0; i < n; i++) {
			ll z = lower_bound(ymaker.begin(), ymaker.end(), arr[i].second) - ymaker.begin();
			result += sum(0, n - 1, 1, z, n - 1);
			b[z]++;
			update(z, b[z], 1, 0, n - 1);
		}
		cout << result << "\n";
		seg.clear();
	}
}