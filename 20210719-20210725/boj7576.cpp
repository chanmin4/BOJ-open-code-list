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
ll n, m, t, l;
vector<vector<ll>>mapp;
vector<vector<bool>>visit;
vector<vector<ll>>cal;
ll mx[4] = { -1,1,0,0 };
ll my[4] = { 0,0,-1,1 };
queue<P>q;
ll bfs() {
	while (!q.empty()) {
		ll tmpx = q.front().first;
		ll tmpy = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			ll nx = tmpx + mx[k];
			ll ny = tmpy + my[k];
			if (0 <= nx && nx < m && 0 <= ny && ny < n) {
				if (!visit[ny][nx] && mapp[ny][nx] == 0) {
					visit[ny][nx] = true;
					mapp[ny][nx] = 1;
					cal[ny][nx] = cal[tmpy][tmpx] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	ll max = cal[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mapp[i][j] == 0) {
				return -1;
			}
			if (max < cal[i][j])
				max = cal[i][j];
		}
	}
	return max;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> m >> n;
	mapp=vector<vector<ll>>(n + 1, vector<ll>(m + 1, 0));
	visit=vector<vector<bool>>(n + 1, vector<bool>(m + 1, false));
	cal=vector<vector<ll>>(n + 1, vector<ll>(m + 1, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mapp[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mapp[i][j] == 1 && !visit[i][j]) {
				q.push(make_pair(j, i));
				visit[i][j] = true;
			}
		}
	}
	cout << bfs();
}