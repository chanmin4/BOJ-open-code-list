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
vector<ll>tree;
void update(ll node, ll start, ll end, ll index, ll diff) {
	if (!(start <= index && index <= end)) {
		return;
	}
	tree[node] += diff;
	if (start != end) {
		ll mid = (start + end) / 2;
		update(node * 2, start, mid, index, diff);
		update(node * 2 + 1, mid + 1, end, index, diff);
	}

}
ll query(ll node,ll start,ll end,ll num) {
	if (start==end) {
		cout << start << "\n";
		return start;
	}
	ll mid = (start + end) / 2;
	if (tree[node*2]>=num) {
		return query(node * 2, start, mid, num);
	}
	num -= tree[node * 2];
	if (tree[node*2+1]>=num) {
		return query(node * 2 + 1, mid + 1, end, num);
	}

}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	ll height = ceil(log2(1e6+1)) + 1;
	tree = vector<ll>(1<<height);
	for (int i = 0; i < n; i++) {
		ll a, b, c;
		cin >> a;
		if (a == 1) {
			cin >> b;
			ll num = query(1, 1, 1e6, b);
			update(1, 1, 1e6, num, -1);
		}
		else {
			cin >> b >> c;
			update(1, 1, 1e6, b, c);
		}
	}

}