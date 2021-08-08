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
vector<vector<ll>>b;
vector<vector<bool>>visit;
ll mx[4] = { -1,1,0,0 };
ll my[4] = { 0,0,-1,1 };
ll component = 0;
void dfs(ll x, ll y) {
	for (int k = 0; k < 4; k++) {
		ll nx = x + mx[k];
		ll ny = y + my[k];
		if (0 <= nx && nx < m && 0 <= ny && ny < n) {
			if (!visit[ny][nx] && b[ny][nx] == 1) {
				visit[ny][nx] = true;
				dfs(nx, ny);
			}
		}
	}
}
void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			b[i][j] = 0;
			visit[i][j] = false;
		}
	}
	component = 0;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll test = 0;
	cin >> test;
	ll k = 0;
	ll num1 = 0, num2 = 0;
	b=vector<vector<ll>>(50, vector<ll>(50, 0));
	visit=vector<vector<bool>>(50, vector<bool>(50, false));
	while (test != 0) {
		cin >> m >> n >> k;
		init();
		for (int i = 0; i < k; i++) {
			cin >> num1 >> num2;
			b[num2][num1] = 1;
			//num1은 가로 num2는 세로
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visit[i][j] && b[i][j] == 1) {
					visit[i][j] = true;
					component++;
					dfs(j, i);
				}
			}
		}
		cout << component << "\n";
		test--;
	}
}