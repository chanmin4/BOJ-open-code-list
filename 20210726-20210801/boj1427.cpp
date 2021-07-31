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
bool comp(ll a, ll b) {
	return a > b;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string test = "";
	cin >> test;
	vector<ll>A(test.size());
	for (int i = 0; i < test.size(); i++) {
		A[i] = test[i] - '0';
	}
	sort(A.begin(), A.end(), comp);
	for (int i = 0; i < test.size(); i++) {
		cout << A[i];
	}
}