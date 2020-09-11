#include <bits/stdc++.h.gch>
#define int long long
#define mod 1000000007
using namespace std;
void solve() {
	string s, t;
	int n, ans = 0;
	cin >> n >> s >> t;
	bool ok = true;
	for (int i = 0; i < n; i++) {
		if (t[i] < s[i] || (s[i] == 't' && s[i] != t[i])) {
			ok = false;
		}
	}
	for (char c = 'a'; c <= 't'; c++) {
		char mn = 'z';
		for (int i = 0; i < n; i++) {
			if (s[i] != t[i] && s[i] == c) {
				mn = min(mn, t[i]);
			}
		}
		if (mn < 'z') {
			for (int i = 0; i < n; i++) {
				if (s[i] == c && s[i] != t[i]) {
					s[i] = mn;
				}
			}
			ans++;
		}
	}
	if (s != t) ok = false;
	if (!ok) ans = -1;
	cout << ans << endl;
}
main() {
	ios_base::sync_with_stdio(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}