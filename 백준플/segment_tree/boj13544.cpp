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
vector <vector<ll>>tree;
vector<ll>arr;
vector<ll> init(ll node,ll start,ll end) {
	if (start == end) {
		tree[node].push_back(arr[start]);
		return tree[node];
	}
	ll mid = (start + end) / 2;
	vector<ll>left = init(node * 2, start, mid);
	vector<ll>right = init(node * 2 + 1, mid + 1, end);
	tree[node] = left;
	tree[node].insert(tree[node].end(),right.begin(), right.end());
	sort(tree[node].begin(),tree[node].end());
	return tree[node];
}
ll solve(ll node, ll start, ll end, ll num,ll ns = 1, ll ne = n) {
	if (start <= ns && ne <= end) {
		return (tree[node].end() - upper_bound(tree[node].begin(),tree[node].end(),num));
	}
	if (ne<start || ns>end)return 0;
	ll mid = (ns + ne) / 2;
	return solve(node * 2, start, end,num,ns,mid) + solve(node * 2 + 1, start, end,num,mid+1,ne);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	arr = vector<ll>(n+1);
	tree = vector<vector<ll>>(4 * n);
	for (int i = 1; i <=n; i++) {
		cin >> arr[i];
	}
	init(1, 1, n);
	cin >> m;
	ll l_result = 0;
	for (int i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		a ^= l_result, b ^= l_result, c ^= l_result;
		l_result = solve(1, a, b,c);
		cout << l_result << "\n";
	}
}