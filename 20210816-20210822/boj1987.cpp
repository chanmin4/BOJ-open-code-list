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
vector<string>A;
ll result = 1;
ll mx[4] = { -1,1,0,0 };
ll my[4] = { 0,0,-1,1 };
ll C = 0, R = 0;
ll maxi = 0;
vector<bool>use;
void backtracking(ll x, ll y) {
	ll find = 0;
	use[A[y][x] - '0'] = true;
	result++;
	for (int k = 0; k < 4; k++) {
		ll nextx = mx[k] + x;
		ll nexty = my[k] + y;
		if (0 <= nextx && nextx < C && 0 <= nexty && nexty < R && !use[A[nexty][nextx] - '0']) {
			backtracking(nextx, nexty);
			use[A[nexty][nextx] - '0'] = false;
			find++;
		}
		else {
			find++;
		}
	}
	if (find == 4) {
		result--;
		if (maxi < result)maxi = result;
		if (x == 0 && y == 0)cout << maxi;
		return;
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0),cout.tie(0);
	cin >> R >> C;
	A=vector<string>(R + 1, "");
	for (int i = 0; i < R; i++) {
		cin >> A[i];
	}
	use=vector<bool>(27, false);
	backtracking(0, 0);
}