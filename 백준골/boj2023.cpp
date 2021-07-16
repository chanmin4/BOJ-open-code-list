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
bool prime(ll num) {
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)return false;
    }
    return true;
}
void backtrack(ll num,ll size) {
    if (prime(num)) {
        if (size == n) {
            result.push_back(num);
            return;
        }

        for (int i = 1; i < 10; i++) {
            backtrack(num * 10 + i, size + 1);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 2; i < 10; i++) {
        backtrack(i,1);
    }
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << "\n";
    }

}