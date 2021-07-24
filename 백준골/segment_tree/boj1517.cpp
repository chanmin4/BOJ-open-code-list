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
vector<ll>tree;
vector<P>arr;
void update(ll node, ll start, ll end, ll index, ll value) {
	if (start == end) {
		tree[node] = value;
		return;
	}
	ll mid = (start + end) / 2;
	if (index <= mid)update(node * 2, start, mid, index, value);
	else update(node * 2 + 1, mid + 1, end, index, value);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll solve(ll node, ll start, ll end,ll qst,ll qed) {
	if (qst<=start && end<=qed) {
		return tree[node];
	}
	if (qed<start || qst>end)return 0;
	ll mid = (start+end) / 2;
	return solve(node * 2, start, mid,qst,qed) + solve(node * 2 + 1, mid+1,end,qst,qed);
}
bool compare(P a, P b) {
	//return a.first < b.first;
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	arr = vector<P>(n);
	tree = vector<ll>(4 * n);
	for (int i = 0; i <n; i++) {
		ll num;
		cin >> num;
		arr[i] = P(num, i);
	}
	ll result = 0;
	sort(arr.begin(), arr.end(),compare);
	for (int i = 0; i <n; i++) {
		ll index = arr[i].second;
		result += solve(1, 0,n-1,index+1,n-1);
		update(1, 0, n-1, index, 1);
	}
	cout << result << '\n';
}