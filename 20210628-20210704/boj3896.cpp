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
    vector<ll>prime;
    vector<bool>isprime(1299709+1,true);
    cin >> t;
    for (int i = 2; i <= 1299709; i++) {
        if (isprime[i])prime.push_back(i);
        for (int j = i * 2; j <= 1299709; j+=i) {
            isprime[j] = false;
        }
    }
    while (t--) {
        ll k;
        cin >> k;
        if (!isprime[k]) {
            ll maxi = -1;
            for (int i = k+1; i <= 1299709; i++) {
                if (isprime[i]) {
                    maxi = i;
                    break;
                }
            }
            ll mini = 1e10;
            for (int i = k - 1; i >= 2; i--) {
                if (isprime[i]) {
                    mini = i;
                    break;
                }
            }
            cout << maxi - mini << "\n";
        }
        else if(isprime[k]){
            cout << 0 << "\n";
        }
    }
}