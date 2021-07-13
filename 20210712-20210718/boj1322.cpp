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
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll x, k;
    cin >> x >> k;
    ll check = 1;
    vector<ll>a(100);
    for (int i = 0; x > 0; x /= 2) {
        a[i++] = x % 2;
    }
    ll result = 0;
    for (int i = 0; i < 100 && k; i++, check *= 2) {
        if (!a[i]) {
            if (k % 2)result += check;
            k /= 2;
        }
    }
    cout << result;
}