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
vector<ll>indgree;
vector<ll>result;
vector<vector<ll>>adj;
queue<ll>q;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0),cout.tie(0);
	cin >> n >> m;
	indgree=vector<ll>(n + 1);
	adj=vector<vector<ll>>(n + 1);
	result=vector<ll>(n + 1);
	for (int i = 0; i < m; i++) {
		ll num1, num2;
		cin >> num1 >> num2;
		indgree[num2]++;
		adj[num1].push_back(num2);
	}
	for (int i = 1; i <= n; i++) {
		if (indgree[i] == 0)q.push(i);
	}
	for (int i = 0; i < n; i++) {
		ll cur = q.front();
		q.pop();
		result[i] = cur;
		for (int j : adj[cur]) {
			if (--indgree[j] == 0)q.push((j));
		}
	}
	for (int i = 0; i < n; i++) {
		cout << result[i] << " ";
	}

}