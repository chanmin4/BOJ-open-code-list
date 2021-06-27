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
ll MOD = 1147;
ll  m, l, r, t, q, n, k, x;
vector<vector<char>>a;
vector<vector<vector<ll>>>dp;
ll solved() {
    dp = vector<vector<vector<ll>>>(n+2, vector<vector<ll>>(m+2,vector<ll>(2)));
    // dp[x][y][cross]   cross=0 오른쪽아래대각선  cross=1 왼쪽 아래대각선
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if(a[i][j]-'0'==1)dp[i][j][0] = dp[i][j][1] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j]-'0' == 1) { 
                dp[i][j][0] = 1 + dp[i - 1][j - 1][0];
                dp[i][j][1] = 1 + dp[i - 1][j + 1][1];
            }
        }
    }
    ll result = 0;
    //꼭짓점으로 마름모인지확인  
    for (int i = 1; i<=n; i++) {
        for (int j = 1; j <=m; j++) {
            int checkpoint = dp[i][j][0];
            for (ll k = checkpoint; k >= result; k--) {
                if (dp[i][j][1] >= k) {//마름모의 완성 꼭짓점가능한지  result 갱신으로 수행횟수줄이기
                    if (dp[i - (k - 1)][j - (k - 1)][1] >= k && dp[i - (k - 1)][j + (k - 1)][0] >= k) {//대칭 꼭짓점
                        result = max(result, k);
                    }
                }
            }
        }
    }
    return result;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    a=vector<vector<char>>(n+2, vector<char>(m+2));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    cout << solved();
}