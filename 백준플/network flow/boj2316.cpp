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
ll INF = 100000000;
vector<vector<ll>>adj(1000);
vector<vector<ll>>c(1000, vector<ll>(1000));
vector<vector<ll>>f(1000, vector<ll>(1000));
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		ll u = i * 2 - 1, v = i * 2;
		adj[u].push_back(v);
		adj[v].push_back(u);
		c[u][v] = 1;

	}
	for (int i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		adj[a * 2].push_back(b * 2 - 1);
		adj[b * 2 - 1].push_back(a * 2);
		adj[b * 2].push_back(a * 2 - 1);
		adj[a * 2 - 1].push_back(b * 2);

		c[a * 2][b * 2 - 1] = c[b * 2][a * 2 - 1] = 1;
	}
	ll total = 0, S = 2, E = 3;
	while (1) {
		vector<ll>prev(n * 2 + 1, -1);
		queue<ll>q;
		q.push(S);
		while (!q.empty() && prev[E] == -1) {
			int curr = q.front();
			q.pop();
			for (int next : adj[curr]) {
				if (c[curr][next] - f[curr][next] > 0 && prev[next] == -1) {
					q.push(next);
					prev[next] = curr;
				}
				if (next == E)break;
			}

		}
		if (prev[E] == -1)break;
		ll flow = INF;
		for (int i = E; i != S; i = prev[i]) {
			flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
		}
		for (int i = E; i != S; i = prev[i]) {
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}
		total += flow;
	}
	cout << total;
}