#include "shoes.h"
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

long long count_swaps(std::vector<int> s) {
	ll jv = 0;

	while (!s.empty()) {
		int t = s[0];
		int jj = 0;
		s.erase(s.begin());

		if (t > 0)
			jj++;
		t = -t;

		auto it = find(s.begin(), s.end(), t);
		jj += it - s.begin();

		s.erase(it);

		jv += jj;
	}

	return jv;
}
