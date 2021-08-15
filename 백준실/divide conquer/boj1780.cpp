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
vector<vector<ll>>arr;
vector<ll>result(4);
void diveconquer(ll curx, ll cury, ll size) {
	ll checknum = arr[cury][curx];
	bool checkmate = true;
	if (size == 1) {
		result[checknum + 1]++;
		return;
	}
	for (int i = curx; i < curx + size; i++) {
		for (int j = cury; j < cury + size; j++) {
			if (arr[j][i] != checknum) {
				checkmate = false;
				break;
			}
		}
		if (!checkmate)break;
	}
	if (checkmate) {
		result[checknum + 1]++;
		return;
	}
	size = size / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			diveconquer(curx + i * size, cury + j * size, size);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	arr=vector<vector<ll>>(n + 1, vector<ll>(n + 1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	diveconquer(0, 0, n);
	cout << result[0] << endl;
	cout << result[1] << endl;
	cout << result[2] << endl;
}