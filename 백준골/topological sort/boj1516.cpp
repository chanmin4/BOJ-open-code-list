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
vector<ll>indgree;
priority_queue<ll, vector<ll>, greater<ll>>pq;
vector<ll>result;
vector<vector<ll>>adj;
vector<ll>buildtime;
queue<ll>q;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	result=vector<ll>(n + 1);
	adj=vector<vector<ll>>(n + 1);
	indgree=vector<ll>(n + 1);
	buildtime=vector<ll>(n + 1);
	for (int i = 1; i <= n; i++) {
		ll time;
		cin >> time;
		buildtime[i] = time;
		while (1) {
			int num1;
			cin >> num1;
			if (num1 == -1)break;
			adj[num1].push_back(i);
			indgree[i]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (indgree[i] == 0) {
			q.push(i);
			result[i] = buildtime[i];
		}
	}
	for (int i = 1; i <= n; i++) {

		ll cur = q.front();
		q.pop();
		for (int k : adj[cur]) {
			result[k] = max(result[k], result[cur] + buildtime[k]);
			if (--indgree[k] == 0) { q.push(k); }
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << result[i] << "\n";
	}
}