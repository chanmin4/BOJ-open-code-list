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
vector<ll>dist(30001);
vector<vector<ll>>adj(30001);
vector<vector<ll>>ac(30001, vector<ll>(20));
vector<ll>depth(30001);
void gettree(ll node, ll parent) {
	depth[node] = depth[parent] + 1;
	if (node != 1) {
		dist[node] = dist[parent] + 1;
	}
	ac[node][0] = parent;
	max_level = (ll)floor(log2(n));
	for (int i = 1; i <= max_level; i++) {
		ac[node][i] = ac[ac[node][i - 1]][i - 1];
	}
	for (int i = 0; i < adj[node].size(); i++) {
		ll there = adj[node][i];
		if (there != parent) {
			gettree(there, node);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		ll a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	gettree(1, 0);
	cin >> m;
	ll prev = 1;
	ll result = 0;
	for (int i = 0; i < m; i++) {
		ll a;
		cin >> a;
		ll tmpa = a;
		ll tmpb = prev;
		if (depth[a] != depth[prev]) {
			if (depth[a] > depth[prev])swap(a, prev);
			for (int i = max_level; i >= 0; i--) {
				if (depth[a] <= depth[ac[prev][i]]) {
					prev = ac[prev][i];
				}
			}
		}
		ll lca = a;
		if (a != prev) {
			for (int i = max_level; i >= 0; i--) {
				if (ac[a][i] != ac[prev][i]) {
					a = ac[a][i];
					prev = ac[prev][i];
				}
				lca = ac[a][i];
			}
		}
		if (i == 0) {
			result += dist[tmpa];
		}
		else {
			result += dist[tmpb] + dist[tmpa] - 2 * dist[lca];
		}
		prev = tmpa;
	}
	cout << result << "\n";
}