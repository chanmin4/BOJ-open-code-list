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
	ll x = 0;
	ll y = 0;
	ll meter = 0;
	cin >> t;
	vector<ll>count(t + 1);
	for (int i = 0; i < t; i++) {
		cin >> x >> y;
		meter = y - x;
		n = 0;
		if (meter == 1) {
			n = 0;
		}
		else {
			while ((pow(n, 2)) < meter) {
				n++;
			}
			n -= 1;
		}
		if ((pow(n, 2)) < meter && meter < (pow(n + 1, 2))) {
			count[i] = (2 * n - 1) + ceil((meter - (pow(n, 2))) / n);
		}
		else if (meter == (pow(n + 1, 2))) {
			count[i] = 2 * (n + 1) - 1;
		}
	}
	for (int i = 0; i < t; i++) {
		cout << count[i] << endl;
	}
}