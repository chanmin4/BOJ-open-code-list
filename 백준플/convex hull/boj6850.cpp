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
struct point {
    ll x, y;
    ll  p, q;
    point(ll x1, ll y1) {
        x = x1;
        y = y1;
        p = 1, q = 0;
    }
    point() {
        x = 0;
        y = 0;
        p = 1;
        q = 0;
    }
};
vector<point>a;
bool sort1(point a, point b) {
    if (a.p * b.q != a.q * b.p)return a.p * b.q - a.q * b.p > 0;
    if (a.y != b.y)return a.y < b.y;
    return a.x < b.x;
}
ll ccw(point a, point b, point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    a.resize(n, point());
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        a[i] = point(x, y);
    }
    sort(a.begin(), a.end(), sort1);//y-x
    for (int i = 1; i < n; i++) {
        a[i].p = a[i].x - a[0].x;
        a[i].q = a[i].y - a[0].y;
    }
    sort(a.begin(), a.end(), sort1); // 반시계
    stack<ll>s;
    s.push(0);
    s.push(1);
    int next = 2;
    while (next < n) {
        while (s.size() >= 2) {
            ll first, second;
            first = s.top();
            s.pop();
            second = s.top();
            if (ccw(a[second], a[first], a[next]) > 0) {
                s.push(first);
                break;
            }
        }
        s.push(next++);
    }
    ll result = 0;
    ll now = s.size();
    for (int i = 1; i <= now - 2; i++) {
        ll first = s.top();
        s.pop();
        ll second = s.top();
        result += abs(ccw(a[0], a[first], a[second])) / 2.0;
    }
    cout << result / 50;
}

