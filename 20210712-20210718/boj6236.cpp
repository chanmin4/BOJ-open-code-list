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
vector<ll>a;
ll solve(ll num) {
    ll cnt = 1;
    ll result = 0;
    for (int i = 0; i < n; i++) {
        if (result + a[i] > num) {
            cnt++;
            result= a[i];
        }
        else {
            result += a[i];
        }
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    a = vector<ll>(n);
    ll maxi = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxi = max(maxi, a[i]);
    }
    ll l = maxi , r = 1e10;
    while (l < r) {
        ll mid = (l + r) / 2;
        if (solve(mid) > m) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }
    cout << l;
}