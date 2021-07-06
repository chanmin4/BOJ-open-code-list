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
    ll a, b, c;
    edge() {

    }
    edge(ll a1, ll b1, ll c1) {
        a = a1;
        b = b1;
        c = c1;
    }
    bool operator <(const edge& O)const { return c < O.c; }
};
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll v, e;
    cin >> v >> e;
    edge *E = new edge[e];
    p = vector<ll>(v + 1,-1);
    for (int i = 0; i < e; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        E[i] = edge(a, b, c);
    }
    sort(E, E+ e);
    ll result = 0;
    ll cnt = 0;
    for (int i = 0;i<=e-1; i++) {
        if (merge(E[i].a, E[i].b)) {
            result += E[i].c;
            if (++cnt == n - 1)break;
        }
    }
    cout << result;
}