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
	cin >> n >> m;
	ll truth = 0;
	cin >> truth;
	ll num = 0;
	vector<bool>trust;
	vector<vector<ll>>a;
	ll party = 0;
	trust=vector<bool>(n + 1);
	a=vector<vector<ll>>(m + 1);
	for (int i = 0; i < truth; i++) {
		cin >> num;
		trust[num] = true;
	}
	for (int i = 0; i < m; i++) {
		cin >> party;
		a[i].resize(party);
		for (int j = 0; j < party; j++) {
			cin >> a[i][j];
		}
	}
	bool check = false;
	for (int k = 0; k < m; k++) {
		for (int i = 0; i < m; i++) {
			check = false;
			for (int j = 0; j < a[i].size(); j++) {
				if (trust[a[i][j]] == true) {
					check = true;
				}
			}
			if (check == true) {
				for (int j = 0; j < a[i].size(); j++) {
					trust[a[i][j]] = true;
				}
			}
		}
	}
	ll result = 0;
	for (int i = 0; i < m; i++) {
		bool checkresult = false;
		for (int j = 0; j < a[i].size(); j++) {
			if (trust[a[i][j]]) {
				checkresult = true;
			}
		}
		if (checkresult == false) {
			result++;
		}
	}
	cout << result;
}