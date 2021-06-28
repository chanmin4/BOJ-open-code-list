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
ll  m, l, r, t, q, n, k;
vector<P>tree;
vector<ll>a;
P build(ll id, ll l, ll r) {
    if (r==l) {
        tree[id].first = a[l];
        tree[id].second = a[l];
        return tree[id];
    }
    ll mid = (l + r) / 2;
    P left = build(id * 2, l, mid);
    P right=build(id * 2 + 1, mid+1, r);
    tree[id].first = min(left.first, right.first);
    tree[id].second = max(left.second, right.second);
    return tree[id];
}
P find(ll id, ll idstart, ll idend, ll start, ll end) {
    if (idstart > end || idend < start)return P(1e10, 1);
    if (start <= idstart && idend <= end)return tree[id];
    ll mid = (idstart + idend) / 2;
    P left =find(id * 2, idstart, mid, start, end);
    P right=find(id * 2 + 1, mid + 1, idend, start, end);
    return P(min(left.first,right.first),max(left.second,right.second));
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    a = vector<ll>(n);
    ll size = 1 << ll(ceil(log2(n)) + 1);//크기주의
    tree = vector<P>(size);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(1, 0, n - 1);
    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        P result=find(1, 0,n-1,a-1,b-1);
        cout << result.first << " " << result.second << "\n";
    }
}