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
queue<int>q;
priority_queue<int, vector<int>, greater<int>>pq;
vector<int>result;
vector<int>indgree;
vector<int>c;
vector<vector<int>>adj;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> test;
	for (int i = 0; i < test; i++) {
		int k, m, p;
		cin >> k >> m >> p;
		c.resize(m + 1);
		result.resize(m + 1);
		adj.resize(m + 1);
		indgree.resize(m + 1);
		for (int i = 0; i < p; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			indgree[b]++;
		}
		for (int i = 1; i <= m; i++) {
			if (indgree[i] == 0) {
				q.push(i);
				result[i] = 1;
			}
		}
		for (int i = 1; i <= m; i++) {
			int cur = q.front();
			q.pop();
			if (c[cur] > 0)result[cur]++;
			for (int j : adj[cur]) {
				if (result[j] < result[cur]) {
					result[j] = result[cur];
					c[j] = 0;
				}
				else if (result[j] == result[cur]) {
					c[j]++;
				}

				if (--indgree[j] == 0)q.push(j);
			}
		}

		cout << k << " " << result[m] << "\n";
		c.clear();
		indgree.clear();
		adj.clear();
		result.clear();
	}
}

