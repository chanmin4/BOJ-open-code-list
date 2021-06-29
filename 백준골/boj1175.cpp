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
int x[4] = { 1,-1,0,0 };
int y[4] = { 0,0,1,-1 };
// 0 오 1 왼 2 위 3 아래
bool visited[51][51][5][2][2];//방향 크기5
struct checking {
    ll x = 0, y = 0, direct=0, C1=0, C2=0;
};
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    bool check = false;
    a = vector<vector<char>>(n, vector<char>(m));
    checking start;
    P C1;//y,x
    P C2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'S') {
                start.x = j;
                start.y = i;
                start.direct = 4;
                start.C1 = 0;
                start.C2 = 0;
            }
            if (a[i][j] == 'C'&&!check) {
                C1.first = i;
                C1.second = j;

                check = true;
            }
            else if (a[i][j] == 'C' && check) {
                C2.first = i;
                C2.second = j;
            }
        }
    }
    queue<checking>Q;
    ll level = 0;
    bool checkC1 = false;
    bool checkC2 = false;
    visited[start.y][start.x][4][0][0] = true;
    Q.push(start);

    while (!Q.empty()) {
        ll qsize = Q.size();
        for (int i = 0; i < qsize; i++) {
            checking cur = Q.front();
            Q.pop();
            if (cur.C1 && cur.C2) {
                cout << level;
                return 0;
            }
            for (int k = 0; k < 4; k++) {
                if (cur.direct == k)continue;
                checking next = cur;//정보땡겨오기
                ll ny = cur.y + y[k];
                ll nx = cur.x + x[k];
                next.y = ny;
                next.x = nx;
                next.direct = k;
                if (ny >= 0 && ny <= n - 1 && nx >= 0 && nx <= m - 1 && !visited[ny][nx][k][next.C1][next.C2]
                    && a[ny][nx] != '#') {
                    if (ny == C1.first && nx == C1.second)next.C1 = 1;
                    if (ny == C2.first && nx == C2.second)next.C2 = 1;
                    visited[ny][nx][k][next.C1][next.C2] = true;
                    Q.push(next);
                }
            }
        }
        level++;
        
    }
    cout << -1;
}