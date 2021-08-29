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
ll n, t, m, k, test;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    while (1) {
        string S;
        cin >> S;
        if (S == ".") {
            break;
        }
        ll N = S.size();
        vector<ll>fail(N + 1);
        for (int i = 1, j = 0; i < N; i++) {
            while (j > 0 && S[i] != S[j])j = fail[j - 1];
            if (S[i] == S[j])fail[i] = ++j;
        }
        if (N % (N - fail[N - 1]) != 0)cout << 1 << "\n";
        else cout << N / (N - fail[N - 1]) << "\n";
    }
}