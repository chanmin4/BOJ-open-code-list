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
ll n, m, t, l;
vector<ll>tree;
vector<ll>arr;
ll init(ll index, ll start, ll end) {
    if (start == end) {
        return tree[index] = arr[start];
    }
    ll mid = (start + end) / 2;
    return tree[index] = init(index * 2, start, mid) + init(index * 2 + 1, mid + 1, end);
}
void update(ll node, ll s, ll e, ll index, ll value) {
    if (s <= index && index <= e)tree[node] += value;
    else return;
    if (s == e)return;
    ll mid = (s + e) / 2;
    update(node * 2, s, mid, index, value);
    update(node * 2 + 1, mid + 1, e, index, value);
}
ll sum(ll l, ll r, ll node, ll nodel, ll noder) {
    if (l <= nodel && noder <= r) {
        return tree[node];
    }
    if (r < nodel || noder < l)return 0;
    ll mid = (nodel + noder) / 2;
    return sum(l, r, node * 2, nodel, mid) + sum(l, r, node * 2 + 1, mid + 1, noder);
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    arr = vector<ll>(n + 1);
    ll height = ceil(log2(n)) + 1;
    tree = vector<ll>(1 << (height));
    init(1, 1, n);
    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 0) {
            if (b > c)swap(b,c);
            cout << sum(b,c, 1, 1,n) << "\n";
        }
        else {
            ll diff = c - arr[b];
            arr[b] = c;
            update(1,1,n,b,diff);
        }
 
    }
}