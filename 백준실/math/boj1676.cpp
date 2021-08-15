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
ll result5 = 0, result2 = 0;
ll factorial(ll n) {
	if (n == 0)return 0;
	ll num = 0;
	for (int i = 1; i <= n; i++) {
		num = i;
		if (i % 5 == 0) {
			while (num % 5 == 0) {
				num /= 5;
				result5++;
			}
		}
		else if (i % 2 == 0) {
			while (num % 2 == 0) {
				num /= 2;
				result2++;
			}
		}
	}
	return min(result2, result5);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	cout << factorial(n);

}