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
ll n, t, m, k;
class Tree {
public:
	int N = 0;
	vector<char>parent;
	vector<char>lc;
	vector<char>rc;
	Tree(ll n) {
		N = n;
		parent=vector<char>(N + 1);
		lc=vector<char>(N + 1);
		rc=vector<char>(N + 1);
	}
	void setEdge(char p, char left, char right) {
		if (left != '.')parent[left - '0'] = p;
		if (right != '.')parent[right - '0'] = p;
		lc[p - '0'] = left;
		rc[p - '0'] = right;
	}
	void preorder(char p) {
		cout << p;
		if (lc[p - '0'] != '.')preorder(lc[p - '0']);
		if (rc[p - '0'] != '.')preorder(rc[p - '0']);
	}
	void inorder(char p) {
		if (lc[p - '0'] != '.')inorder(lc[p - '0']);
		cout << p;
		if (rc[p - '0'] != '.')inorder(rc[p - '0']);
	}
	void postorder(char p) {
		if (lc[p - '0'] != '.')postorder(lc[p - '0']);
		if (rc[p - '0'] != '.')postorder(rc[p - '0']);
		cout << p;
	}
};
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0),cout.tie(0);
	char p, l, r;
	cin >> t;
	Tree tr(100);
	for (int i = 0; i < t; i++) {
		cin >> p >> l >> r;
		tr.setEdge(p, l, r);
	}
	tr.preorder('A');
	cout << "\n";
	tr.inorder('A');
	cout << "\n";
	tr.postorder('A');
	cout << "\n";
}