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
priority_queue<P, vector<P>, greater<P>>p;
vector<vector<P>>adj;
vector<ll>dist;
ll K = 0, E = 0, V = 0;
vector<bool>visit;
ll inf = 100000000;
void dijkstra() {
	dist[K] = 0;
	p.push(P(0, K));
	while (!p.empty()) {
		ll curr = 0;
		do {
			curr = p.top().second;
			p.pop();
		} while (!p.empty() && visit[curr]);
		if (visit[curr])break;
		visit[curr] = true;
		for (int i = 0; i < adj[curr].size(); i++) {
			ll next = adj[curr].at(i).first, d = adj[curr].at(i).second;
			if (dist[next] > dist[curr] + d) {
				dist[next] = dist[curr] + d;
				p.push(P(dist[next], next));
			}
		}

	}
	for (int i = 0; i < V; i++) {
		if (dist[i] == inf)cout << "INF" << "\n";
		else cout << dist[i] << "\n";
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll u = 0, v = 0, w = 0;
	cin >> V >> E;
	cin >> K;
	K -= 1;
	dist=vector<ll>(E + 1, inf);
	visit=vector<bool>(V + 1, false);
	adj=vector<vector<P>>(V + 1);
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		adj[u - 1].push_back(P(v - 1, w));
	}
	dijkstra();
}