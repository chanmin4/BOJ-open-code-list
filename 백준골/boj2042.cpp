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
void update(ll index, ll s, ll e, ll t, ll value) {
    if (s <= t && t <= e)tree[index] += value;
    else return;
    if (s == e)return;
    ll mid = (s + e) / 2;
    update(index * 2, s, mid, t, value);
    update(index * 2 + 1, mid + 1, e, t, value);
}
ll sum(ll l, ll r, ll index, ll s, ll e) {
    if (l <= s && e <= r) {
        return tree[index];
    }
    if (r < s || e < l)return 0;
    ll mid = (s + e) / 2;
    return sum(l, r, index * 2, s, mid) + sum(l, r, index * 2 + 1, mid + 1, e);
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll k;
    cin >> n >> m >> k;
    arr = vector<ll>(n+1);
    ll height = ceil(log2(n)) + 1;
    tree = vector<ll>(1<<(height));
    for (int i = 1; i <=n; i++) {
        cin >> arr[i];
    }
    init(1, 1, n);
    for (int i = 0; i < m + k; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            ll num = c - arr[b];
            arr[b] = c;
            update(1, 1,n, b, num);
        }
        else { 
            cout << sum(b, c, 1, 1,n) << "\n"; }
    }
}