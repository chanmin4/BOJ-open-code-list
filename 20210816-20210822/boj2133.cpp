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
vector<ll>b;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0),cout.tie(0);
	cin >> n;
	b=vector<ll>(n + 1);
	b[0] = 1;
	b[2] = 3;
	for (int i = 4; i <= n; i += 2) {
		b[i] = b[i - 2] * 3;
		for (int j = 4; j <= i; j += 2) {
			b[i] += b[i - j] * 2;
		}
	}
	cout << b[n];
}