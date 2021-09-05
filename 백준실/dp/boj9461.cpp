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
vector<ll>b;
ll fibonacii(int n) {
	if (1 <= n && n <= 3)return 1;
	if (4 <= n && n <= 5) { return 2; }
	if (b[n] != -1) {
		return b[n];
	}
	b[n] = fibonacii(n - 1) + fibonacii(n - 5);
	return b[n];
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n = 0;

    cin >> test;
    for (int i = 0; i < test; i++) {
        cin >> n;
        b.resize(n + 1, -1);
        cout << fibonacii(n) << "\n";
    }
}

