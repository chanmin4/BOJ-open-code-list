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
ll n, m, t, l, c;
vector<dP>adj;
vector<dP>point;
vector<ll>p;
ll find(ll a) {
    if (p[a] < 0)return a;
    return p[a] = find(p[a]);
}
bool merge(ll a, ll b) {
    a = find(a);
    b = find(b);
    if (a == b)return false;
    p[b] = a;
    return true;
}
struct edge {
    dP x, y;
    ld dist;
    ll startnum = 0;
    ll endnum = 0;
    edge() {}
    edge(dP a, dP b,ll c,ll d) {
        x = a;
        y = b;
        dist = hypot(a.first - b.first, a.second - b.second);
        startnum = c;
        endnum = d;
    }
};
bool comp(edge e1, edge e2) {
    return e1.dist < e2.dist;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> t;
    vector<edge>e;
    p = vector<ll>(t + 1,-1);
    point = vector<dP>(t + 1);
    for (int i = 0; i < t; i++) {
        ld a, b;
        cin >> a >> b;
        point[i] = dP(a, b);
    }
    for (int i = 0; i < t; i++) {
        dP first = point[i];
        for (int j = 0; j < t; j++) {
            if (i != j) {
                
                dP second = point[j];
                e.push_back(edge(first, second,i,j));
                e.push_back(edge(second, first,j,i));
            }
        }
    }
    sort(e.begin(), e.end(), comp);
    ll cnt = 0;
    ld result = 0;

    for (int i = 0;; i++) {
        if (merge(e[i].startnum,e[i].endnum)) {
            result += e[i].dist;
            if (++cnt == t - 1)break;
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << result;
}