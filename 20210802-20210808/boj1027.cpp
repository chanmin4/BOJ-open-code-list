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
	cin >> n;
	vector<ll>v(n);
	vector<ll>b(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	for (int i = 0; i < n; i++) {
		ld max = -2000000000, a;
		for (int j = i + 1; j < n; j++) {
			a = ld(v[i] - v[j]) / ld(i - j);
			if (a > max) {
				max = a;
				b[i]++;
				b[j]++;
			}
		}
	}
	cout << *max_element(b.begin(), b.end());
}