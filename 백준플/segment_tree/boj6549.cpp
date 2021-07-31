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
ll n, m, t, k;
ll a, b;
vector<vector<ll>>map;
vector<ll>tree;
vector<ll>arr;
vector<bool>check;
ll c, r, result = 0, sum = 0;
void init(int node, int start, int end) {
	if (start == end) {
		tree[node] = start;
	}
	else {
		init(node * 2, start, (start + end) / 2);
		init(node * 2 + 1, (start + end) / 2 + 1, end);
		if (arr[tree[node * 2]] <= arr[tree[node * 2 + 1]]) {
			tree[node] = tree[node * 2];
		}
		else tree[node] = tree[node * 2 + 1];
	}
}
ll segmentsum(int node, int start, int end, int fixstart, int fixend) {
	if (fixstart > end || fixend < start)return -1;
	if (fixstart <= start && fixend >= end)
		return tree[node];
	ll m1 = segmentsum(node * 2, start, (start + end) / 2, fixstart, fixend);
	ll m2 = segmentsum(node * 2 + 1, (start + end) / 2 + 1, end, fixstart, fixend);
	if (m1 == -1)return m2;
	else if (m2 == -1)return m1;
	else {
		if (arr[m1] <= arr[m2])
			return m1;
		else return m2;

	}
}
ll divconq(ll start, ll end) {
	ll m = segmentsum(1, 0, n - 1, start, end);
	ll area = (end - start + 1) * arr[m];
	if (start <= m - 1) {
		ll temp = divconq(start, m - 1);
		if (area < temp) {
			area = temp;
		}
	}
	if (end >= m + 1) {
		ll temp = divconq(m + 1, end);
		if (area < temp)
			area = temp;
	}
	return area;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	while (1) {
		cin >> n;
		if (n == 0)break;
		arr.resize(n + 1);
		tree.resize(pow(2, ceil(log2(n)) + 1));
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		init(1, 0, n - 1);
		cout << divconq(0, n - 1) << "\n";
	}
}