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
    ll a, b, color;
    edge() {

    }
    edge(ll x,ll y,char BR) {
        a = x;
        b = y;
        //B일때만 가중치
        if (BR == 'B') {
            color = 1;
        }
        else {
            color = 0;
        }
    }
};
bool comp(edge e1, edge e2) {
    return e1.color < e2.color;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    
    while (1) {
        vector<edge>e;
        ll k;
        cin >> n >> m >> k;
        if (n == 0)break;
        for (int i = 0; i < m; i++) {
            char col;
            ll a, b;
            cin >> col >> a >> b;
            e.push_back(edge(a, b, col));
            e.push_back(edge(b, a, col));
        }
        sort(e.begin(), e.end(),comp);
            ll result = 0, cnt = 0;
            p = vector<ll>(n + 1, -1);
            for (int i = 0;i<=e.size()-1; i++) {
                if (merge(e[i].a, e[i].b)) {
                    result += e[i].color;
                    if (++cnt == n - 1)break;
                }
            }
            reverse(e.begin(), e.end());
            ll result2 = 0, cnt2 = 0;
            p = vector<ll>(n + 1, -1);
            for (int i = 0; i <=e.size()-1; i++) {
                if (merge(e[i].a, e[i].b)) {
                    result2 += e[i].color;
                    if (++cnt2 == n - 1)break;
                }
            }
            if (result <= k && k <= result2) {
                cout << 1 << "\n";
            }
            else cout << 0<<"\n";
    }


}