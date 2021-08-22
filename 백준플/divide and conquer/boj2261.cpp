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
vector<P>arr;
ll distance(vector<P>&arr, ll start, ll end) {
	ll x = arr[start].first - arr[end].first;
	ll y = arr[start].second - arr[end].second;
	return x * x + y * y;
}
ll find_short(ll start, ll end) {
	ll min = 10000000000;
	for (int i = start; i < end; i++) {
		for (int j = i + 1; j <= end; j++) {
			ll tmp = distance(arr, i, j);
			if (tmp < min)min = tmp;

		}
	}
	return min;
}
bool compare(P pair1, P pair2) {
	return pair1.second < pair2.second;
}
ll solve(ll start,ll end) {
	if (end - start + 1 <= 3) {
		return find_short(start, end);
	}
	ll mid = (start + end) / 2;
	ll lm = solve(start, mid - 1);
	ll rm = solve(mid + 1, end);
	ll d = min(lm, rm);
	vector<P>tmp;
	for (int i = start; i <= end; i++) {
		ll tempd = arr[i].first - arr[mid].first;
		if (tempd * tempd < d)tmp.push_back(arr[i]);
	}
	int sizetmp = tmp.size();
	sort(tmp.begin(), tmp.end(), compare);
	for (int i = 0; i < sizetmp - 1; i++) {
		for (int j = i + 1; j < sizetmp; j++) {
			if (tmp[j].second - tmp[i].second < d) {
				d = min(d, distance(tmp, i, j));
			}
			else break;
		}
	}
	return d;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0),cout.tie(0);
	cin >> n;
	arr=vector<P>(n);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		arr[i] = P(x, y);
	}
	sort(arr.begin(), arr.end());
	ll ans = solve(0, n - 1);
	cout << ans;

}