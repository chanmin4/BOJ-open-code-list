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
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0),cout.tie(0);
	cin >> n;
	ll num = 0;
	ll count = 2;
	ll inte = 0;
	ll zi = 0;
	for (int i = 0; i < n; i++) {
		count = 2;
		cin >> num;
		while (num != 1) {
			zi = 0;
			if (num % count == 0) {
				while (num % count == 0) {

					num /= count;
					zi++;
				}
				cout << count << " " << zi << "\n";

			}
			count++;
		}
	}
}