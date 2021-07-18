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
ll n, m, t, l;
vector<ll>arr;
vector<ll>tree;
ll init(ll node,ll start,ll end) {
	if (start == end)return tree[node] = arr[start];
	ll mid = (start + end) / 2;
	return tree[node] = init(node * 2, start, mid)+init(node * 2 + 1, mid + 1, end);
}
ll sum(ll node,ll l,ll r,ll start,ll end) {
	if (l <= start && end <= r) {
		return tree[node];
	}
	if (r<start || l>end) {
		return 0;
	}
	ll mid = (start + end) / 2;
	return sum(node * 2, l, r, start, mid)+ sum(node * 2 + 1, l, r, mid + 1, end);
}
void update(ll node,ll start, ll end,ll temp,ll diff) {
	if (start <= temp && temp <= end) { tree[node] += diff; 
	}
	else return;
	if (start != end) {
		ll mid = (start + end) / 2;
		update(node * 2, start, mid, temp, diff);
		update(node * 2 + 1, mid + 1, end, temp, diff);
	}
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	arr = vector<ll>(n+1);
	tree = vector<ll>(4 * n);
	init(1, 1, n);
	for (int i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			arr[b] += c;
			update(1,1,n,b,c);
		}
		if (a == 2) {
			cout << sum(1, b, c, 1, n) << "\n";
		}
	}
}