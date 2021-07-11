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
bool binarysearch(ll target) {
    ll l = 0, r = n - 1;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (a[mid] == target)return true;
        if (a[mid] < target) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    a=vector<ll>(n);
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    cin >> m;
    for (int i = 0; i < m; i++) {
        ll x;
        cin >> x;
        if (binarysearch(x))cout << 1 << "\n";
        else cout << 0 << "\n";
    }
}