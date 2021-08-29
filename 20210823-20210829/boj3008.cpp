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
vector<P>v;
struct fx {
    int r;
    ll a, b;
    void rotate() {
        r = (r + 1) % 4;
        swap(a, b); b = -b;
    }
    bool operator ==(fx& x) {
        return x.a * b == x.b * a;
    }
};
bool sort1(fx a, fx b) {
    return a.a * b.b - a.b * b.a > 0;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0),cout.tie(0);
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        v[i] = P(x, y);
    }
    ll cnt[4];
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        vector<fx>vec;
        for (int j = 0; j < n; j++) {
            if (i == j)continue;
            fx prime;
            prime.r = 0;
            prime.a = v[j].first - v[i].first;
            prime.b = v[j].second - v[i].second;
            while (!(prime.a > 0 && prime.b >= 0))prime.rotate();
            vec.push_back(prime);
        }
        sort(vec.begin(), vec.end(), sort1);
        for (int j = 0, k; j < vec.size(); j = k) {
            cnt[0] = cnt[1] = cnt[2] = cnt[3] = 0;
            for (k = j; (k < vec.size() && vec[j] == vec[k]); k++) {
                cnt[vec[k].r]++;
            }
            ans += cnt[0] * cnt[1] + cnt[1] * cnt[2] + cnt[2] * cnt[3] + cnt[0] * cnt[3];
        }


    }

    cout << ans;

}