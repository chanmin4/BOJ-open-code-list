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
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	vector<string>s;
	ll num = 0;
	ll result = 100;
	string hi = "";
	string A[2][8] = {
		{"WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW",
		"WBWBWBWB","BWBWBWBW", "WBWBWBWB","BWBWBWBW" },
		{
			"BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB",
			"BWBWBWBW", "WBWBWBWB","BWBWBWBW","WBWBWBWB"}
	};
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> hi;
		s.push_back(hi);
	}

	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			for (int k = 0; k < 2; k++) {
				num = 0;
				for (int y = 0; y < 8; y++) {
					for (int x = 0; x < 8; x++) {
						if (s.at(y + i)[x + j] != A[k][y][x])num++;

					}
				}
				result = min(result, num);
			}
		}
	}
	cout << result;
}