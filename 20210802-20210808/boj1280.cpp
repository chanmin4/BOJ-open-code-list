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
vector<ll>tree;
vector<ll>treecount;
vector<ll>dist;
ll MAX = 200001;
ll mod = 1000000007;
ll sum_(vector<ll>&tree, ll index) {
	ll result = 0;
	while (index >= 0) {
		result += tree[index];
		if (index == 0)break;
		index -= (index & -index);
	}
	return result;
}
ll sum(vector<ll>&tree, ll s, ll e) {
	if (s > e)return 0;
	return sum_(tree, e) - sum_(tree, s - 1);
}

void update(vector<ll>&tree,ll num,ll value) {
	while (num <= MAX) {
		tree[num] += value;
		num += (num & -num);
		if (num == 0)break;
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	tree=vector<ll>(MAX);
	treecount=vector<ll>(MAX);
	dist=vector<ll>(n + 1);
	for (int i = 1; i <= n; i++) {
		ll num;
		cin >> num;
		if (i == 1) {
			update(tree, num, num);
			update(treecount, num, 1);
		}
		else {
			dist[i] = (num * sum(treecount, 0, num - 1) - sum(tree, 0, num - 1)
				+ sum(tree, num + 1, MAX - 1) - num * sum(treecount, num + 1, MAX - 1)) % mod;
			update(treecount, num, 1);
			update(tree, num, num);
		}
	}
	ll ans = 1;
	for (int i = 2; i <= n; i++) {
		ans = (ans * dist[i]) % mod;
	}
	cout << ans;
}