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
int x[4] = { 1,-1,0,0 };
int y[4] = { 0,0,-1,1 };
struct point {
    ll x=0, y=0, cnt = 0;
};
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> m >> n;
    vector<string> a(n);
    bool visit[100][100] = { false };
    for (int j = 0; j < n; j++) {
            cin >> a[j];
    }
    point start;
    queue<point>q;
    q.push(start);
    visit[start.y][start.x] = true;
    vector<vector<ll>>dp(n, vector<ll>(m, 1e10));
    dp[0][0] = 0;
    while (!q.empty()) {
        point cur = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            point next = cur;
            int ny = cur.y + y[k];
            int nx = cur.x + x[k];
            next.x = nx;
            next.y = ny;
            if (ny <= n - 1 && ny >= 0 && nx <= m - 1 && nx >= 0) {      
                if (a[ny][nx]-'0' == 1) {
                        next.cnt += 1;
                        
                }
                if (visit[ny][nx] && (next.cnt) < dp[ny][nx]) {//핵심코드 이것만기억
                    visit[ny][nx] = false; 
                }
                if (!visit[ny][nx]) {
                    dp[ny][nx] = min(dp[ny][nx], next.cnt);
                    visit[ny][nx] = true;
                    q.push(next);
                }
                
            }
        }
    }
    cout << dp[n - 1][m - 1];
}