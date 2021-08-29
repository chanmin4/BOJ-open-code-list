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
vector<int>result;
vector<int>indgree;
vector<vector<int>>adj;
queue<int>q;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0),cout.tie(0);
	cin >> n >> m;
	indgree.resize(n + 1);
	adj.resize(n + 1);
	result.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int num;
		int pre, cur;
		cin >> num;
		cin >> pre;
		for (int j = 1; j < num; j++) {
			cin >> cur;
			indgree[cur]++;
			adj[pre].push_back(cur);
			pre = cur;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (indgree[i] == 0)q.push(i);
	}
	for (int i = 1; i <= n; i++) {
		int cur = q.front();
		result[i] = cur;
		if (q.empty()) {
			cout << 0;
			return 0;
		}
		q.pop();
		for (auto j : adj[cur]) {
			indgree[j]--;
			if (indgree[j] == 0)q.push(j);
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << result[i] << "\n";
	}
}