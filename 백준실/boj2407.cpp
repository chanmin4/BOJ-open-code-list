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
vector<vector<string>>cnt(101, vector<string>(101));
string biginteger(string num1, string num2)
{
    ll sum = 0;
    string result;
    while (!num1.empty() || !num2.empty() || sum)
    {
        if (!num1.empty())
        {
            sum += num1.back() - '0';
            num1.pop_back();
        }
        if (!num2.empty())
        {
            sum += num2.back() - '0';
            num2.pop_back();
        }
        result.push_back((sum % 10) + '0');
        sum /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}
string combination(ll n, ll r) {
    if (cnt[n][r] != "")return cnt[n][r];
    if (n == r || r == 0)return "1";
    else {
        cnt[n][r] = biginteger(combination(n - 1, r - 1) ,combination(n - 1, r));
        return cnt[n][r];
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    cout<<combination(n, m);
}