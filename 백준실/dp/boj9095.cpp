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
vector<int>b;
int a[3] = { 1,2,3 };
int dp(int num) {
	b[0] = 1;
	for (int k = 1; k <= num; k++) {
		for (int i = 0; i < 3; i++) {
			if (a[i] <= k)
				b[k] += b[k - a[i]];
		}
	}
	return b[num];
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int num = 0;
	cin >> test;
	for (int i = 0; i < test; i++) {
		cin >> num;
		b.clear();
		b.resize(num + 1, 0);
		cout << dp(num) << "\n";
	}
}

