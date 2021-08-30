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
vector<ll>result;
vector<P>arr;
ll binary(ll left, ll right, ll target) {
	ll mid = 0;
	while (left < right) {
		mid = (left + right) / 2;
		if (result[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
	return left;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	arr = vector<P>(n);
	vector<ll>pos(100001);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr.begin(), arr.end());
	ll posi = 1;
	result.push_back(arr[0].second);
	while (posi < n) {
		if (result.back() < arr[posi].second) {
			result.push_back(arr[posi].second);
			pos[posi] = result.size() - 1;
		}
		else {
			ll idx = binary(0, result.size() - 1, arr[posi].second);
			result[idx] = arr[posi].second;
			pos[posi] = idx;
		}
		posi += 1;
	}
	cout << n - result.size() << "\n";
	vector<bool>visit(n);
	ll checksize = result.size() - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (checksize == pos[i]) {
			visit[i] = true;
			checksize--;
		}
	}
	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			cout << arr[i].first << "\n";
		}
	}
}