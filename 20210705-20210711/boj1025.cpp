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
ll n, m, t, l, c;
vector<ll>result;
void backtrack(ll x,ll y,ll xincrease,ll yincrease) {
    for (int i = 0; i < m; i++) {

    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    vector<string>s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    ll num = -1;
    //현재 yx
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            
            //등차수열
            for (int yi = -n; yi < n; yi++) {
                for (int xj = -m; xj < m; xj++) {
                    if (yi == 0 && xj == 0)continue;
                    ll tempx = j; ll tempy = i;
                    string temp = "";
                    while (tempx >= 0 && tempx <= m - 1 && tempy <= n - 1 && tempy >= 0) {
                        temp += s[tempy][tempx];
                        ll checknum = stoll(temp);
                        
                        if (((ll)sqrt(checknum) * ((ll)sqrt(checknum)))== checknum){
                            num=max(num,checknum);
                        }
                        tempx += xj;
                        tempy += yi;
                    }
                }
            }
        }
    }
    cout << num;
}