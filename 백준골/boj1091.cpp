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
ll n, m, t, l;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    vector<ll>p(n);
    vector<ll>s(n);
    vector<ll>result(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    ll cnt = 0;
    bool check = true;
    for (int i = 0; i < n; i++) {
        result[i] = i;
    }
    for (int i = 0; i <=2e5; i++) {
        check = true;
        for (int j = 0; j < n; j++) {
            if (p[result[j]] != j % 3) {
                check = false;
            }
        }
        if (check)break;
        vector<ll>temp = result;
        for (int j = 0; j < n; j++) {
            result[s[j]] = temp[j];
        }
        
        cnt++;
        
    }
    if (cnt <= 2e5)cout << cnt;
    else cout << -1;
}