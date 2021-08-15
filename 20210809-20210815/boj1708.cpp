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
stack<ll>s;
struct point {
	ll x, y;
	ll p, q;
	point() {
		x = 0, y = 0;
		p = 1, q = 0;
	}
};
bool compare1(point & a, point & b) {
	if (a.p * b.q - a.q * b.p != 0)return a.p * b.q - a.q * b.p > 0;
	if (a.y != b.y)return a.y < b.y;
	return a.x < b.x;
}
ll ccw(point & a, point & b, point & c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	point* p = new point[n + 1];//
	for (int i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		p[i].x = x;
		p[i].y = y;
	}
	sort(p, p + n, compare1);//
	for (int i = 1; i < n; i++) {
		p[i].p = p[i].x - p[0].x;
		p[i].q = p[i].y - p[0].y;
	}
	sort(p + 1, p + n, compare1);//반시계
	s.push(0);
	s.push(1);
	ll next = 2;
	while (next < n) {
		while (s.size() >= 2) {
			int first, second;
			first = s.top();
			s.pop();
			second = s.top();
			if (ccw(p[second], p[first], p[next]) > 0) {
				s.push(first);
				break;
			}
		}
		s.push(next++);
	}
	cout << s.size();
	delete[]p;
}