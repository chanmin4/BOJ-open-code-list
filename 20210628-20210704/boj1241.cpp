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
    vector<ll>visit(1e6+1);
    vector<ll>a(n);
    vector<ll>result(n);
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        a[i] = x;
        visit[x]++;
    }

    for (int i = 0; i < n; i++) {
        ll num = a[i];
        for (int j = 1; j <= sqrt(num); j++) {
            if (num % j == 0) {
                if (num / j != j) {
                    //제곱아닐때
                    result[i] += visit[j] + visit[num / j];
                }
                else {
                    //제곱
                    result[i] += visit[j];
                }
            }
        }
   }
    for (int i = 0; i < n; i++) {
        cout << result[i] - 1 << "\n";
    }
}