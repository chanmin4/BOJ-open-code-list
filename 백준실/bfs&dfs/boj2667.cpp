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
vector<string>mapp;
vector<vector<bool>>visit;
vector<int>a;
queue<pair<int, int>>q;
int result = 0;
int mx[4] = { -1,1,0,0 };
int my[4] = { 0,0,-1,1 };
void bfs(int x, int y) {
	int count = 0;
	visit[y][x] = true;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int tmpx = q.front().first;
		int tmpy = q.front().second;
		q.pop();
		count++;
		for (int k = 0; k < 4; k++) {
			int nx = tmpx + mx[k];
			int ny = tmpy + my[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (!visit[ny][nx] && mapp[ny][nx] == '1') {
					visit[ny][nx] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	a.push_back(count);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0),cout.tie(0);
	cin >> n;
	mapp.resize(n + 1);
	visit.resize(n + 1, vector<bool>(n + 1, false));
	for (int i = 0; i < n; i++) {
		cin >> mapp[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mapp[i][j] == '1' && !visit[i][j]) {
				bfs(j, i);
				result++;
			}
		}
	}
	cout << result << "\n";
	sort(a.begin(), a.end());
	for (int i = 0; i < a.size(); i++) {
		cout << a.at(i) << "\n";
	}
}