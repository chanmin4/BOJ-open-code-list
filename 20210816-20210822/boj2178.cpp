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
vector<string>a;
vector<vector<ll>>hi;
queue<P>q;
vector<vector<bool>>visit;
ll mx[4] = { -1,1,0,0 };
ll my[4] = { 0,0,-1,1 };
void bfs(ll x, ll y) {
	//이전방문값+1
	while (!q.empty()) {
		ll currentx = q.front().first;
		ll currenty = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nextx = mx[k] + currentx;
			int nexty = my[k] + currenty;
			if (0 <= nextx && nextx < m && 0 <= nexty && nexty < n) {
				if (visit[nexty][nextx] == false && a[nexty][nextx] == '1') {
					visit[nexty][nextx] = true;
					hi[nexty][nextx] = hi[currenty][currentx] + 1;
					q.push(make_pair(nextx, nexty));
				}
			}

		}//for

	}//while
	cout << hi[n - 1][m - 1];
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0),cout.tie(0);
	cin >> n >> m;
	a=vector<string>(n + 1);
	visit=vector<vector<bool>>(n + 1, vector<bool>(m + 1, false));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	hi=vector<vector<ll>>(n + 1, vector<ll>(m + 1, 0));
	q.push(make_pair(0, 0));
	visit[0][0] = true;
	hi[0][0] = 1;
	bfs(0, 0);
}