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
//분할정복공부용
struct point {
	ll x, y;
};
ll dist(point a, point b) {
	return pow(a.x-b.x, 2) + pow(a.y-b.y, 2);
}
bool comp(point a, point b) {
	return a.x < b.x;
}
bool comp2(point a, point b) {
	return a.y < b.y;
}
ll solve(vector<point>::iterator it,ll num) {
	if (num == 2) {
		return dist(it[0], it[1]);
	}
	if (num == 3) {//NUM이 3일때 solve 재귀로가면 num이 1되므로 num==3 필요
		return min(min(dist(it[0],it[1]),dist(it[1],it[2])),dist(it[2],it[0]));
	}
	ll line = (it[num / 2 - 1].x+it[num/2].x)/2;//중간선분 x좌표
	ll d = min(solve(it, num / 2), solve(it + num / 2, num - num / 2));
	vector<point>mid;
	for (int i = 0; i < num; i++) {
		ll temp = line - it[i].x;//x좌표 d거리안에 들어오는점 넣기
		if (temp * temp < d)mid.push_back(it[i]);
	}
	sort(mid.begin(),mid.end(),comp2);//y좌표 정렬 높이d 밑변 2d인 직사각형모양검색
	ll midsize = mid.size();
	for (int i = 0; i < midsize - 1; i++) {
		for (int j = i + 1; j < midsize && 
			((mid[j].y - mid[i].y) * (mid[j].y - mid[i].y)<d);j++)
			d = min(d, dist(mid[i], mid[j]));
	}
	return d;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	vector<point>arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].x >> arr[i].y;
	}
	sort(arr.begin(), arr.end(), comp);
	cout << solve(arr.begin(),n);
}