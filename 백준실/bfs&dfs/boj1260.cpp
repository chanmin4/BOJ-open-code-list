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
bool visitdfs[1001] = { false };
bool visitbfs[1001] = { false };
vector<ll>a[10001];
ll result = 0;
ll x = 0;
void dfs(ll start, ll N) {

	if (visitdfs[start]) {
		return;
	}

	visitdfs[start] = true;
	result++;
	cout << start << " ";
	sort(a[start].begin(), a[start].end());
	for (int i = 0; i < a[start].size(); i++) {
		x = a[start][i];
		dfs(x, N);
	}
}
void bfs(ll start) {
	ll num = 0;
	queue<ll> q;
	q.push(start);
	visitbfs[start] = true;
	while (!q.empty()) {
		start = q.front();
		q.pop();
		cout << start << " ";
		sort(a[start].begin(), a[start].end());
		for (int i = 0; i < a[start].size(); i++) {
			num = a[start][i];
			if (!visitbfs[num]) {
				q.push(num);
				visitbfs[num] = true;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll v = 0;
	cin >> n>>m >> v;
	int num1, num2 = 0;
	for (int i = 0; i <m; i++) {
		cin >> num1 >> num2;
		a[num1].push_back(num2);
		a[num2].push_back(num1);
	}
	dfs(v, n);
	cout << "\n";
	bfs(v);
}