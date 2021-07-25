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
ll n, m, t;
vector<P>tree;
vector<ll>arr;
ll maxi = 0;
P init(ll node,ll start,ll end) {
	if (start == end) {
		tree[node].first = arr[start];
		tree[node].second = start;
		return tree[node];
	}
	ll mid = (start + end) / 2;
	P first = init(node * 2, start, mid);
	P second = init(node * 2 + 1, mid + 1, end);
	tree[node].first = first.first + second.first;
	if (arr[first.second] > arr[second.second]) {
		tree[node].second = second.second;
	}
	else tree[node].second = first.second;
	return tree[node];
}
P sum(ll node,ll start, ll end,ll ns,ll ne) {
	if (start <= ns && ne <= end) {
		return tree[node];
	}
	if (ns > end || ne < start)return { 0,-1 };
	ll mid = (ns + ne) / 2;
	P left = sum(node * 2, start, end, ns, mid);
	P right = sum(node * 2 + 1, start, end, mid + 1, ne);
	if (left.second == -1)return right;
	else if (right.second == -1)return left;
	ll num;
	if (arr[left.second] > arr[right.second]) {
		num = right.second;
	}
	else num = left.second;
	return P(left.first + right.first, num);
}
void solve(ll left,ll right) {
	if (left > right)return;
	P temp = sum(1, left, right, 1, n);//P( 합,최소 값 인덱스 )
	maxi = max(maxi,arr[temp.second]*temp.first);
	//왼쪽 오른쪽 둘다포함은 있을수가없음 주의
	// 둘다포함 이전의 과정이 더크기때문
	solve(left, temp.second - 1);
	solve(temp.second + 1, right);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	arr = vector<ll>(n+1);
	ll height = ceil(log2(n)) + 1;
	tree = vector<P>(1<<height, { 0,-1 });
	for (int i = 1; i <=n; i++) {
		cin >> arr[i];
	}
	init(1, 1, n);
	solve(1, n);
	cout << maxi;
}