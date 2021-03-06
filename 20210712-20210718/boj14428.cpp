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
vector<P>tree;
P init(ll node,ll start,ll end) {
	if (start == end)return tree[node] = P(arr[start],start);
	ll mid = (start + end) / 2;
		P left = init(node * 2, start, mid);
		P right = init(node * 2 + 1, mid + 1, end);
		if (left.first < right.first) {
			tree[node] = left;
		}
		else if (left.first == right.first) {
			tree[node].first = left.first;
			tree[node].second = min(left.second, right.second);
		}
		else {
			tree[node] = right;
		}
		return tree[node];
}
P findmin(ll node,ll l,ll r,ll start,ll end) {
	if (l <= start && end <= r) {
		return P(tree[node].first,tree[node].second);
	}
	if (r<start || l>end) {
		return P(1e10, -1);
	}
	ll mid = (start + end) / 2;
	return min(findmin(node * 2, l, r, start, mid), findmin(node * 2 + 1, l, r, mid + 1, end));
}
P update(ll node,ll start, ll end,ll temp,ll diff) {
	if (!(start <= temp && temp <= end)) {
		return tree[node];
	}
	if (start != end) {
		ll mid = (start + end) / 2;
		P left = update(node * 2, start, mid, temp, diff);
		P right=update(node * 2 + 1, mid + 1, end, temp, diff);
		if (left.first < right.first) {
			tree[node] = left;
		}
		else if (left.first == right.first) {
			tree[node].first = left.first;
			tree[node].second = min(left.second, right.second);
		}
		else {
			tree[node] = right;
			
		}
		return tree[node];
	}
	else return tree[node]=P(diff,temp);
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	arr = vector<ll>(n+1);
	tree = vector<P>(4 * n,P(1e10,-1));
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	init(1, 1, n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a;
		if (a == 1) {
			cin >> b >> c;
			arr[b] = c;
			update(1, 1, n, b,c );
		}
		else {
			cin >> b >> c;
			cout << findmin(1, b,c,1,n).second << "\n";
		}
	}
}