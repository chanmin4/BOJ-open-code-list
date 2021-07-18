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
ll n, m, t, l;
ll one(ll N) {
	ll number = 0;
	for (int i = 1; i <= N; i++) {

		if (i < 100) {
			number++;
		}
		else {
			if (((i / 100) % 10 - (i / 10) % 10) == ((i / 10) % 10 - i % 10)) {
				number++;
			}
		}
		if (i == 1000) {
			number--;
		}
	}
	return number;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	cout << one(n);
}