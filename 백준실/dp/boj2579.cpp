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
int fibo(int a[], int n) {
	b[0] = 0;
	b[1] = a[1];
	b[2] = a[2] + a[1];
	for (int i = 3; i <= n; i++) {
		b[i] = max(b[i - 3] + a[i - 1] + a[i], b[i - 2] + a[i]);

	}
	return b[n];
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0),cout.tie(0);
	int test = 0;
	cin >> test;
	int* a = new int[test + 1];
	b.resize(test + 2, 0);
	for (int i = 1; i <= test; i++) {
		cin >> a[i];
	}
	cout << fibo(a, test);
}