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
vector<bool>visit;
ll dfs(ll num, string s) {
    ll cnt = 0;
    for (int i = num; i < s.size(); i++) {
        if (s[i] == '(' && !visit[i]) {
            visit[i] = true;
            ll check = s[i - 1] - '0';
            cnt--;
            cnt += check * dfs(i+1,s);
        }
        else if (s[i] == ')' && !visit[i]) {
            visit[i] = true;
            return cnt;
        }
        else if (!visit[i]) {
            visit[i] = true;
            cnt++;
        }
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string s;
  
    cin >> s;
    visit = vector<bool>(s.size() + 1);
    cout << dfs(0,s);

}