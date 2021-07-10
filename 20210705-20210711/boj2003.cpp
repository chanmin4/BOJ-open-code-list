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
    cin >> n >> m;
    vector<ll>arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ll sum = 0, l = 0, h = 0, result = 0;
    while (1) {
        //if (h == n)break;
        if (sum >= m)sum -= arr[l++];
        else if (h == n)break;
        else sum += arr[h++];
        if (sum == m)result++;
    }
    cout << result;
}