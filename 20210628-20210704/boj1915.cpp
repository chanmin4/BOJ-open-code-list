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
ll  m, n, t;
vector<vector<char>>a;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    vector<vector<ll>>dp(n+1, vector<ll>(m+1,0));
    a= vector<vector<char>>(n+1, vector<char>(m+1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j]-'0' == 1)dp[i][j] = 1;
        }
    }
    ll check = 0;
    ll result = 0;
    for (int i = 1; i <=n; i++) {
        for (int j = 1; j <=m; j++) {
            if (a[i][j]-'0' == 1) {
                if (dp[i - 1][j] != 0 && dp[i - 1][j - 1] != 0 && dp[i][j - 1] != 0) {
                    if (dp[i - 1][j] != 1 && dp[i - 1][j - 1] != 1 && dp[i][j - 1] != 1) {
                        ll size = min(dp[i - 1][j], dp[i - 1][j - 1]);
                        size = min(size,dp[i][j - 1]);
                        check = sqrt(size) + 1;
                        dp[i][j] = check * check;
                    }
                    else {
                        dp[i][j] = 4;
                    }
                }
                result = max(result, dp[i][j]);
            }

        }
    }
    cout << result;
}