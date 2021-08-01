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
ll M = 0, N = 0, H = 0;
ll h = 0;
vector<vector<vector<ll>>>v;
vector<vector<vector<bool>>>check;
vector<vector<vector<ll>>>cal;
queue<pair<ll, P>>hi;//h n m순서
ll mx[6] = { -1,1,0,0,0,0 };
ll my[6] = { 0,0,-1,1,0,0 };
ll mh[6] = { 0,0,0,0,-1,1 };
int bfs() {
	while (!hi.empty()) {
		ll curx = hi.front().second.second;
		ll cury = hi.front().second.first;
		ll curh = hi.front().first;
		hi.pop();
		for (int k = 0; k < 6; k++) {
			ll nextx = curx + mx[k];
			ll nexty = cury + my[k];
			ll nexth = curh + mh[k];
			if (1 <= nextx && nextx <= M && 1 <= nexty && nexty <= N && 1 <= nexth && nexth <= H)
				if (!check[nexth][nexty][nextx] && v[nexth][nexty][nextx] == 0) {
					hi.push(make_pair(nexth, make_pair(nexty, nextx)));
					check[nexth][nexty][nextx] = true;
					v[nexth][nexty][nextx] = 1;
					cal[nexth][nexty][nextx] = cal[curh][cury][curx] + 1;
				}
		}
	}
	ll max = cal[0][0][0];
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				if (v[i][j][k] == 0)return -1;
				if (max < cal[i][j][k])max = cal[i][j][k];
			}
		}
	}
	return max;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> M >> N >> H;
	v.resize(H + 1, vector<vector<ll>>(N + 1, vector<ll>(M + 1)));
	cal.resize(H + 1, vector<vector<ll>>(N + 1, vector<ll>(M + 1)));
	check.resize(H + 1, vector<vector<bool>>(N + 1, vector<bool>(M + 1, false)));
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				cin >> v[i][j][k];
			}
		}
	}
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				if (v[i][j][k] == 1 && !check[i][j][k]) {
					hi.push(make_pair(i, make_pair(j, k)));
					check[i][j][k] = true;
				}
			}
		}
	}
	cout << bfs();
}