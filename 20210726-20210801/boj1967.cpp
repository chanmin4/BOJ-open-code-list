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
vector<vector<P>>adj;
vector<bool>check;
ll maximum = 0;
ll result = 0;
ll test = 0;
ll point = 0;
ll lastmaxi = 0;
void dfs(ll a) {
	ll cur = a;
	check[a] = true;
	for (int i = 0; i < adj[cur].size(); i++) {
		int next = adj[cur].at(i).first;
		if (!check[next]) {
			result += adj[cur].at(i).second;
			if (maximum < result) {
				maximum = result;
				point = next;
			}
			dfs(next);
			result -= adj[cur].at(i).second;
		}
	}

}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >>t;
	int num1 = 0, num2 = 0;
	int nnum = 0;
	check = vector<bool>(t + 1, false);
	adj=vector<vector<P>>(t + 1);
	for (int i = 1; i < t; i++) {
		cin >> nnum >> num1 >> num2;
		adj[nnum].push_back(P(num1, num2));
		adj[num1].push_back(P(nnum, num2));
	}
	dfs(1);
	maximum = 0;
	for (int i = 1; i <= t; i++) {
		check[i] = false;
	}
	dfs(point);
	lastmaxi += maximum;
	cout << lastmaxi;
}