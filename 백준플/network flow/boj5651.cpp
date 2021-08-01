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
ll INF = 100000000;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<vector<ll>>adj(1000);
		vector<vector<ll>>c(1000, vector<ll>(1000));
		vector<vector<ll>>f(1000, vector<ll>(1000));
		vector<P>vc;
		for (int i = 0; i < m; i++) {
			ll f, t, b;
			cin >> f >> t >> b;
			adj[f].push_back(t);
			adj[t].push_back(f);
			vc.push_back(P(f, t));
			c[f][t] += b;
		}
		ll total = 0, source = 1, sink = n;
		while (1) {
			vector<ll>prev(301, -1);
			queue<ll>q;
			q.push(source);
			while (!q.empty() && prev[sink] == -1) {
				int curr = q.front();
				q.pop();
				for (int next : adj[curr]) {
					if (c[curr][next] - f[curr][next] > 0 && prev[next] == -1) {
						q.push(next);
						prev[next] = curr;
						if (next == sink)break;
					}
				}
			}
			if (prev[sink] == -1)break;
			ll flow = INF;
			for (int i = sink; i != source; i = prev[i]) {
				flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
			}
			for (int i = sink; i != source; i = prev[i]) {
				f[prev[i]][i] += flow;
				f[i][prev[i]] -= flow;
			}
			total += flow;
		}
		ll ans = 0;
		for (int i = 0; i < vc.size(); i++) {
			ll S = vc[i].first;
			ll T = vc[i].second;
			vector<ll>prev(n + 1, -1);
			queue<ll>q;
			q.push(S);
			while (!q.empty() && prev[T] == -1) {
				ll curr = q.front();
				q.pop();
				for (int next : adj[curr]) {
					if (c[curr][next] - f[curr][next] > 0 && prev[next] == -1) {
						prev[next] = curr;
						q.push(next);
						if (next == T)break;
					}
				}
			}
			if (prev[T] == -1) {
				ans++;
			}
		}
		cout << ans << "\n";


	}
}