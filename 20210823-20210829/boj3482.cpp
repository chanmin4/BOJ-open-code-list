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
int x = 0, y = 0;
vector<vector<bool>>check;
int mx[4] = { -1,1,0,0 };
int my[4] = { 0,0,-1,1 };
int maximum = 1;
int result = 1;
pair<int, int>p;

void labyrinth(int xi, int yi, int depth) {
	if (maximum < depth) {
		maximum = depth;
		p = { xi,yi };
	}
	for (int k = 0; k < 4; k++) {
		int nextx = xi + mx[k];
		int nexty = yi + my[k];
		if (0 <= nextx && nextx < x && 0 <= nexty && nexty < y) {
			if (!check[nexty][nextx] && mapp[nexty][nextx] == '.') {
				check[nexty][nextx] = true;
				labyrinth(nextx, nexty, depth + 1);
			}
		}
	}
}
void init() {
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			check[i][j] = false;
		}
		mapp[i] = "";
	}

}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0),cout.tie(0);
	int test = 0;
	cin >> test;
	mapp.resize(1001);
	check.resize(1001, vector<bool>(1001));
	for (int i = 0; i < test; i++) {
		maximum = 1;
		cin >> x >> y;
		for (int j = 0; j < y; j++) {
			cin >> mapp[j];
		}

		for (int j = 0; j < y; j++) {
			for (int k = 0; k < x; k++) {
				if (!check[j][k] && mapp[j][k] == '.') {
					check[j][k] = true;
					labyrinth(k, j, 1);
				}
			}
		}
		for (int j = 0; j < y; j++) {
			for (int k = 0; k < x; k++) {
				check[j][k] = false;
			}
		}
		check[p.first][p.second] = true;
		labyrinth(p.first, p.second, 1);
		cout << "Maximum rope length is " << maximum - 1 << "." << "\n";
		init();
	}
}