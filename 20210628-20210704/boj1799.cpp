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
ll a[11][11];
ll result0;//흰색
ll result1;//검정
ll x_y[100];//x=y
ll x_m_y[100];//x=-y
void backtrack(ll y, ll x,ll count,ll chess) {
    if (x >= n) {
        y++;
        if (x % 2 == 0)x = 1;
        else x = 0;
    }
    if (y >= n) {//끝
        if (chess == 0) {
            result0 = max(result0, count);
            return;
        }
        else {
            result1 = max(result1, count);
            return;
        }
    }
    if (a[y][x] == 1 &&!x_y[x-y+n-1]&&!x_m_y[x+y]) {//비숍넣기
        x_y[x - y + n - 1] = x_m_y[x + y] = 1;
        backtrack(y, x + 2, count + 1, chess);
        x_y[x - y + n - 1] = x_m_y[x + y] = 0;
    }
    backtrack(y, x + 2, count, chess);

}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    backtrack(0, 0, 0, 0);
    backtrack(0, 1, 0, 1);
    cout << result1 + result0;
}