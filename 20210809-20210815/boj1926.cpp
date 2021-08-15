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
ll componet = 0;
ll coun = 0;
ll sizeP = 0;
vector<vector<bool>>check;
vector<vector<ll>>mapp;
ll mx[4] = { -1,1,0,0 };
ll my[4] = { 0,0,-1,1 };
void bfs(ll x, ll y) {
	for (int k = 0; k < 4; k++) {
		ll nextx = x + mx[k];
		ll nexty = y + my[k];
		if (1 <= nextx && nextx <= m && 1 <= nexty && nexty <= n) {
			if (!check[nexty][nextx] && mapp[nexty][nextx] == 1) {
				check[nexty][nextx] = true;
				coun++;
				bfs(nextx, nexty);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	check=vector<vector<bool>>(n + 1, vector<bool>(m + 1));
	mapp=vector<vector<ll>>(n + 1, vector<ll>(m + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mapp[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!check[i][j] && mapp[i][j] == 1) {
				check[i][j] = true;
				coun++;
				componet++;
				bfs(j, i);
				if (sizeP < coun)sizeP = coun;
				coun = 0;
			}
		}
	}
	cout << componet << "\n" << sizeP;
}