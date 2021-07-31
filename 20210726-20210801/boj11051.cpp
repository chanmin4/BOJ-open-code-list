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
vector<ll>arr;
vector<ll>result;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	cin >> m;
	arr=vector<ll>(m + 1);
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
	}
	result.push_back(arr[0]);
	result.push_back(n - arr[m - 1]);
	for (int i = 0; i < m - 2; i++) {
		int a = arr[i + 1] - arr[i];
		if (a % 2 == 0) {
			result.push_back(a / 2);
		}
		else {
			result.push_back(a / 2 + 1);
		}
	}
	cout << *max_element(result.begin(), result.end());
}