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
ll n, m, t;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    vector<P>a(n);
    for (int i = 0; i <n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    //원래 자리 -정렬자리
    sort(a.begin(), a.end());
    ll cnt = -1;
    for (int i = 0; i < n; i++) {
        cnt = max(cnt, a[i].second-i);
    }
    cout << cnt + 1;
   
}