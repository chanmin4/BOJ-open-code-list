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
    return tree[index] = init(index * 2, start, mid)*init(index * 2 + 1, mid + 1, end);
}
ll update(ll node, ll s, ll e, ll index, ll value) {
    if (!(s <= index && index <= e))return tree[node];
    if (s == e){
        if (value > 0)tree[node] = 1;
        else if (value == 0)tree[node] = 0;
        return tree[node];
    }

    ll mid = (s + e) / 2;
    return tree[node]=update(node * 2, s, mid, index, value)
        *update(node * 2 + 1, mid + 1, e, index, value);
}
ll sum(ll l, ll r, ll node, ll nodel, ll noder) {
    if (l <= nodel && noder <= r) {
        return tree[node];
    }
    if (r < nodel || noder < l)return 1;
    ll mid = (nodel + noder) / 2;
    return sum(l, r, node * 2, nodel, mid)* sum(l, r, node * 2 + 1, mid + 1, noder);
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll k;
    while (cin>>n>>k) {
        
        arr = vector<ll>(n + 1);
        vector<char>result;
        ll height = ceil(log2(n)) + 1;
        tree = vector<ll>(1 << (height));
        for (int i = 1; i <= n; i++) {
            ll x;
            cin >> x;
            if (x > 0)
                arr[i] = 1;
            else if (x == 0)arr[i] = 0;
            else arr[i] = -1;
        }
        init(1, 1, n);

        for (int i = 0; i < k; i++) {
            char a;
            ll b, c;
            cin >> a >> b >> c;
            if (a == 'C') {
                arr[b] = c;
                update(1, 1, n, b, c);
            }
            if (a == 'P') {
                ll check = sum(b, c, 1, 1, n);
                if (check > 0) {
                    result.push_back('+');
                }
                else if (check == 0) {
                    result.push_back('0');
                }
                else result.push_back('-');
            }
        }
        for (int i = 0; i < result.size(); i++) {
            cout << result[i];
        }
        cout << "\n";
    }
}