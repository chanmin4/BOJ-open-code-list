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
    ll k;
    cin >> n >> k;
    vector<ll>prime;
    vector<bool>isprime(n + 1,true);
    ll cnt = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = i; j<=n; j+=i) {
            if (isprime[j])cnt++;
            isprime[j] = false;
            if (cnt == k) {
                cout << j;
                return 0;
            }
        }
    }
}