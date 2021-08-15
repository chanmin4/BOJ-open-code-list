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
ll max_level;
vector<ll>depth(40001);
vector<vector<ll>>ac(40001, vector<ll>(30));
vector<vector<P>>adj(40001);
vector<ll>dist(40001);
void gettree(ll node, ll parent, ll val) {
	depth[node] = depth[parent] + 1;
	ac[node][0] = parent;
	if (node != 1) {
		dist[node] += dist[parent] + val;
	}
	max_level = (ll)floor(log2(n));
	for (int i = 1; i <= max_level; i++) {
		ll tmp = ac[node][i - 1];
		ac[node][i] = ac[tmp][i - 1];
	}
	ll len = adj[node].size();
	for (int i = 0; i < len; i++) {
		ll there = adj[node][i].first;
		if (there != parent)gettree(there, node, adj[node][i].second);
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(P(b, c));
		adj[b].push_back(P(a, c));
	}
	ll result = 0;
	gettree(1, 0, 0);
	cin >> m;
	for (int i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		ll tempa = a, tempb = b;
		if (depth[a] != depth[b]) {
			if (depth[a] > depth[b])swap(a, b);
			for (int i = max_level; i >= 0; i--) {
				if (depth[a] <= depth[ac[b][i]]) {
					b = ac[b][i];
				}
			}
		}
		ll lca = a;
		if (a != b) {
			for (int i = max_level; i >= 0; i--) {
				if (ac[a][i] != ac[b][i]) {
					result +=
						result +=
						a = ac[a][i];
					b = ac[b][i];

				}
				lca = ac[a][i];
			}
		}
		cout << dist[tempa] - dist[lca] * 2 + dist[tempb] << "\n";

	}
}