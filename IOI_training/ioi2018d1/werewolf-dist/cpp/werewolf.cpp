#include "werewolf.h"
#include <bits/stdc++.h>

using namespace std;
#define pb push_back

std::vector<int> check_validity(int N, std::vector<int> X, std::vector<int> Y,
								std::vector<int> S, std::vector<int> E,
								std::vector<int> L, std::vector<int> R) {
	vector<vector<int>> g(N, vector<int>());

	for (int i = 0; i < N; i++) {
		g[X[i]].pb(Y[i]);
		g[Y[i]].pb(X[i]);
	}

	// bool adam = 1;

	vector<int> bo(N, 0);

	bool ha = 0;
	int l, r;
	int s, e;

	int q = S.size();
	vector<int> jv;
	for (int i = 0; i < q; i++) {
		l = L[i];
		r = R[i];
		ha = 0;
		s = S[i];
		e = E[i];

		queue<int> qu;

		while (!qu.empty()) {
			int h = q.front();
		}

		jv.pb(ha);
	}

	return jv;
}
