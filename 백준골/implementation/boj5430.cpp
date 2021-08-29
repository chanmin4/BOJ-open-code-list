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
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int test = 0;
	cin >> test;
	int first = 0, last = 0, n = 0, num = 0;
	int count = 0;
	int position = 0;
	int tempo = 0;
	int check = 0;
	deque<int>arr;
	string a = "";
	string hello = "";
	for (int i = 0; i < test; i++) {
		check = 0;
		count = 0;
		position = 0;
		while (!arr.empty()) {
			arr.pop_front();
		}
		cin >> a;
		cin >> n;
		cin >> hello;
		if (n != 0) {
			hello = hello.substr(1, hello.length() - 2);
			while (1) {
				tempo = hello.find(",", position);
				if (tempo == -1) {
					num = stoi(hello.substr(position, hello.size() - position));
					arr.push_back(num);
					break;
				}
				num = stoi(hello.substr(position, tempo - position));
				position = tempo + 1;
				arr.push_back(num);
			}
		}
		first = 0;
		last = arr.size() - 1;
		for (int k = 0; k < a.length(); k++) {
			if (a[k] == 'R') {
				swap(first, last);
				count++;
			}
			else if (a[k] == 'D') {
				if (count % 2 == 1) {
					if (first < last) { cout << "error" << "\n"; check++; break; }
					first--;
				}
				else if (count % 2 == 0) {
					if (first > last) { cout << "error" << "\n"; check++;  break; }
					first++;
				}
			}

		}

		if (check != 1) {
			if (count % 2 == 1) {
				cout << "[";
				if (last != first + 1 && n != 0) {
					for (int l = first; l >= last; l--) {
						cout << arr.at(l);
						if (l != last)cout << ",";
					}
				}
				cout << "]\n";

			}
			else if (count % 2 == 0) {

				cout << "[";
				if (first != last + 1 && n != 0) {
					for (int l = first; l <= last; l++) {
						cout << arr.at(l);
						if (l != last)cout << ",";
					}
				}
				cout << "]\n";

			}

		}
	}

}