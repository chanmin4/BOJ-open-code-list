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
typedef pair<ll, ll>P;
typedef pair<ld, ld>dP;
ll MOD = 1e6;
ll n, m, t;
// 컨벡스헐 복습용 코드
// 기울기가 같을때 처리를 잘해줘야함 그냥하면 첫기준점 y축에 거리가 작은거부터들감
struct point {
    ll x = 0, y = 0;
    ll p = 1, q = 0;//**기준점상대 위치**
    bool isconvex = false;
};
bool compare(point a, point b) {
    if (a.p * b.q != a.q * b.p)return a.p * b.q - a.q * b.p > 0;//반시계
    if (a.x != b.x)return a.x < b.x;
    return a.y < b.y;
}
ll ccw(point a,point b,point c) {//ab ac
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    ll cnt = 0;
    vector<point>a(n);
    for (int i = 0; i < n; i++) {
        ll x, y;
        char c;
        cin >> x >> y >> c;
        a[i].x = x;
        a[i].y = y;
        if (c == 'Y') {
            cnt++;
            a[i].isconvex = true;
        }
    }
    sort(a.begin(), a.end(), compare);
    for (int i = 1; i < n; i++) {
        a[i].p = a[i].x - a[0].x;
        a[i].q = a[i].y - a[0].y;
    }
    sort(a.begin() + 1, a.end(), compare);
    ll checkpoint = 0;
    for (int i = n - 1; i > 0; i--) {
        if (ccw(a[0], a[i], a[i - 1]) != 0) {
            checkpoint = i;
            break;
        }
    }
    reverse(a.begin() + checkpoint, a.end());
    cout << cnt << endl;
    for (int i = 0; i < n; i++) {
        if (a[i].isconvex == true) {
            cout << a[i].x << " " << a[i].y << "\n";
        }
    }
}