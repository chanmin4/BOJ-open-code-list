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
vector<vector<P>>adj;
vector<bool>visit;
priority_queue<P, vector<P>, greater<P>>pq;
vector<ll>dist;
ll s = 0, d = 0;
void dijkstra() {
	while (!pq.empty()) {
		ll curr;
		do {
			curr = pq.top().second;
			pq.pop();
		} while (!pq.empty() && visit[curr]);
		if (visit[curr])break;
		visit[curr] = true;
		for (int i = 0; i < adj[curr].size(); i++) {
			ll next = adj[curr].at(i).first, d = adj[curr].at(i).second;
			if (dist[next] > dist[curr] + d) {
				dist[next] = dist[curr] + d;
				pq.push(P(dist[next], next));
			}
		}

	}
	cout << dist[d];
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	ll S = 0, D = 0, W = 0;
	
	dist=vector<ll>(n + 1, 100000000);
	visit=vector<bool>(n + 1, false);
	adj=vector<vector<P>>(n + 1);

	for (int i = 1; i <= m; i++) {
		cin >> S >> D >> W;
		adj[S].push_back(P(D, W));
	}
	cin >> s >> d;
	dist[s] = 0;
	pq.push(P(0, s));
	dijkstra();
}