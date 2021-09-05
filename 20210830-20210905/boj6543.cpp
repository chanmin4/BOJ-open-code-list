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
int cnt = 0, SN = 0;
vector<int>dfsn;
stack<int>s;
vector<bool>finished;
vector<vector<int>>adj;
vector<vector<int>>SCC;
vector<int>sn;
vector<bool>resultcount;
int DFS(int cur) {
	dfsn[cur] = ++cnt;
	s.push(cur);
	int result = dfsn[cur];
	for (int next : adj[cur]) {
		if (dfsn[next] == 0)result = min(result, DFS(next));
		else if (!finished[next])result = min(result, dfsn[next]);
	}
	if (result == dfsn[cur]) {
		vector<int>curscc;
		while (1) {
			int t = s.top();
			s.pop();
			curscc.push_back(t);
			finished[t] = true;
			sn[t] = SN;
			if (t == cur)break;
		}
		SCC.push_back(curscc);
		SN++;
	}
	return result;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	while (1) {
		cin >> n;
		sn.resize(n + 1);
		adj.resize(n + 1);
		finished.resize(n + 1);
		dfsn.resize(n + 1);
		resultcount.resize(n + 1);
		if (n == 0)return 0;
		cin >> m;

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
		}
		for (int i = 1; i <= n; i++) {
			if (dfsn[i] == 0)DFS(i);
		}
		for (int i = 1; i <= n; i++) {
			for (int j : adj[i]) {
				if (sn[i] != sn[j]) {
					resultcount[sn[i]] = true;
					break;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (!resultcount[sn[i]])cout << i << " ";
		}
		cout << "\n";
		sn.clear();
		finished.clear();
		adj.clear();
		dfsn.clear();
		SCC.clear();
		resultcount.clear();
		cnt = 0;
		SN = 0;
	}
}

