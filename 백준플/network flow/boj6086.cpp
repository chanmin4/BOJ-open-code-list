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
vector<vector<int>>adj(701);
vector<vector<int>>f(701, vector<int>(701));
vector<vector<int>>c(701, vector<int>(701));
int make_num(char c) {
	if (c <= 'Z')return c - 'A';
	return c - 'a' + 26;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		char u, v;
		int w;
		cin >> u >> v >> w;
		u = make_num(u); v = make_num(v);
		c[u][v] = c[v][u] += w;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int total = 0, s = make_num('A'), e = make_num('Z');
	while (1) {
		vector<int>prev(701, -1);
		queue<int>q;
		q.push(s);
		while (!q.empty() && prev[e] == -1) {
			int cur = q.front();
			q.pop();
			for (int next : adj[cur]) {
				if (c[cur][next] - f[cur][next] > 0 && prev[next] == -1) {
					q.push(next);
					prev[next] = cur;
					if (next == e)break;
				}
			}
		}
		if (prev[e] == -1)break;
		int flow = 1000000000;
		for (int i = e; i != s; i = prev[i]) {
			flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);

		}
		for (int i = e; i != s; i = prev[i]) {
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}
		total += flow;
	}
	cout << total;
}