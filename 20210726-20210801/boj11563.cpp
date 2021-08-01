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
vector<dP>arr1;
vector<dP>arr2;
ld distance(ld x1, ld y1, ld x2, ld y2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
ld dot(ld x1,ld y1,ld x2,ld y2) {
	return x1 * x2 + y1 * y2;
}
ld cross(ld x1,ld y1,ld x2,ld y2) {
	return x1 * y2 - x2 * y1;
}
ld can_vertic(ld x1,ld y1,ld x2,ld y2
	,ld x3,ld y3) {
	ld dot1 = dot(x3 - x1, y3 - y1, x2 - x1, y2 - y1);
	ld dot2 = dot(x3 - x2, y3 - y2, x1 - x2, y1 - y2);
	if (dot1 * dot2 >= 0) {
		return abs(cross(x3 - x1, y3 - y1, x2 - x1, y2 - y1)) / distance(x1, y1, x2, y2);
	}
	else return -1;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	long double result = 1000000000;
	arr1=vector<dP>(n + 1);
	arr2=vector<dP>(n + 1);
	for (int i = 0; i < n; i++) {
		ld x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		arr1[i] = dP(x1, y1);
		arr2[i] = dP(x2, y2);
	}
	for (int i = 0; i < m; i++) {
		ld x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = 0; i < n; i++) {
			ld dist = distance(arr1[i].first, arr1[i].second, x1, y1), temp;
			dist = min(dist, distance(arr1[i].first, arr1[i].second, x2, y2));
			dist = min(dist, distance(arr2[i].first, arr2[i].second, x1, y1));
			dist = min(dist, distance(arr2[i].first, arr2[i].second, x2, y2));
			temp = can_vertic(x1, y1, x2, y2, arr1[i].first, arr1[i].second);
			if (temp != -1) {
				dist = min(temp, dist);
			}
			temp = can_vertic(x1, y1, x2, y2, arr2[i].first, arr2[i].second);
			if (temp != -1) {
				dist = min(temp, dist);
			}
			temp = can_vertic(arr1[i].first, arr1[i].second, arr2[i].first, arr2[i].second, x2, y2);
			if (temp != -1) {
				dist = min(temp, dist);
			}
			temp = can_vertic(arr1[i].first, arr1[i].second, arr2[i].first, arr2[i].second, x1, y1);
			if (temp != -1) {
				dist = min(temp, dist);
			}
			result = min(result, dist);
		}
	}
	cout.precision(6);
	cout << fixed << result;
}