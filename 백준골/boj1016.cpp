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
    ll mini, maxi;
    cin >> mini >> maxi;
    vector<bool>visit(1e6 + 1);
    for (ll i = 2; i*i <= maxi; i++) {
        ll num = mini / (i * i);
        if (mini % (i * i))num++;
        //i*i*num이 mini보다 크거나 같아짐
        for (ll j = i*i*num; j <= maxi;j=i*i*(++num)) {
            visit[j - mini] = true;
        }
    }
    ll cnt = 0;
    for (int i = 0; i <= maxi - mini; i++) {
        if (!visit[i])cnt++;
    }
    cout << cnt;
}