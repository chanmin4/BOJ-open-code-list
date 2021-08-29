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
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0),cout.tie(0);
	string word = "";
	cin >> word;
	int howmany = 0;
	int count = 0;
	for (int i = 0; i < word.size() - 1; i++) {
		if (word[i] == 'c') {
			if (word[i + 1] == '-') count++;
			else if (word[i + 1] == '=')count++;
		}
		else if (word[i] == 'd') {
			if (word[i + 1] == 'z' && word[i + 2] == '=') count += 2;
			else if (word[i + 1] == '-')count++;
		}
		else if (word[i] == 'l') {
			if (word[i + 1] == 'j') count++;

		}
		else if (word[i] == 'n') {
			if (word[i + 1] == 'j') count++;

		}
		else if (word[i] == 's') {
			if (word[i + 1] == '=')count++;
		}
		else if (word[i - 1] != 'd' && word[i] == 'z')
		{
			if (word[i + 1] == '=') {
				count++;
			}
		}
	}
	howmany = word.size() - count;
	cout << howmany;

}