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
vector<vector<ll>>adj;
vector<bool>finished;
ll SN = 0;
vector<ll>dfsn;
vector<vector<ll>>SCC;
stack<ll>s;
ll cnt = 0;
ll DFS(ll cur) {
	dfsn[cur] = ++cnt;
	s.push(cur);
	ll result = dfsn[cur];
	for (int next : adj[cur]) {
		if (dfsn[next] == 0)result = min(result, DFS(next));
		else if (!finished[next])result = min(result, dfsn[next]);
	}
	if (result == dfsn[cur]) {
		vector<ll>curscc;
		while (1) {
			ll t = s.top();
			s.pop();
			curscc.push_back(t);
			finished[t] = true;
			if (t == cur)break;
		}
		sort(curscc.begin(), curscc.end());
		SCC.push_back(curscc);
		SN++;
	}
	return result;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0),cout.tie(0);
	ll v, e;
	cin >> v >> e;
	finished=vector<bool>(v + 1);
	adj=vector<vector<ll>>(v + 1);
	dfsn=vector<ll>(v + 1);

	for (int i = 0; i < e; i++) {
		ll a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
	for (int i = 1; i <= v; i++) {
		if (dfsn[i] == 0)DFS(i);
	}
	sort(SCC.begin(), SCC.end());
	cout << SN << "\n";
	for (auto& a : SCC) {
		for (auto j : a) {
			cout << j << " ";
		}
		cout << "-1" << "\n";
	}
}