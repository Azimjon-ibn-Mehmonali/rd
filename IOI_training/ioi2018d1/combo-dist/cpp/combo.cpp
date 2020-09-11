#include "combo.h"

#include <bits/stdc++.h>

using namespace std;

#define pb push_back

std::string guess_sequence(int N) {
	string f;

	if (press("A"))
		f = "A";
	else if (press("B"))
		f = "B";
	else if (press("X"))
		f = "X";
	else
		f = "Y";

	if (N == 1) return f;

	if (f == "A") {
		for (int i = 0; i < N - 2; i++) {
			string p = f + "B" + f + "XX" + f + "XY" + f + "XB";
			int n = press(p);
			int us = f.size();

			if (n == us + 1) {
				f.pb('B');
			} else if (n == us + 2) {
				f.pb('X');
				// cerr << p << endl;
			} else {
				f.pb('Y');
			}
		}

		if (press(f + "B") == N) return f + "B";
		if (press(f + "X") == N) return f + "X";
		return f + "Y";
	} else if (f == "B") {
		for (int i = 0; i < N - 2; i++) {
			string p = f + "A" + f + "XX" + f + "XY" + f + "XA";
			int n = press(p);
			int us = f.size();

			if (n == us + 1) {
				f.pb('A');
			} else if (n == us + 2) {
				f.pb('X');
				// cerr << p << endl;
			} else {
				f.pb('Y');
			}
		}

		if (press(f + "A") == N) return f + "A";
		if (press(f + "X") == N) return f + "X";
		return f + "Y";
	} else if (f == "X") {
		for (int i = 0; i < N - 2; i++) {
			string p = f + "B" + f + "AA" + f + "AY" + f + "AB";
			int n = press(p);
			int us = f.size();

			if (n == us + 1) {
				f.pb('B');
			} else if (n == us + 2) {
				f.pb('A');
				// cerr << p << endl;
			} else {
				f.pb('Y');
			}
		}

		if (press(f + "B") == N) return f + "B";
		if (press(f + "A") == N) return f + "A";
		return f + "Y";
	} else {
		for (int i = 0; i < N - 2; i++) {
			string p = f + "B" + f + "XX" + f + "XA" + f + "XB";
			int n = press(p);
			int us = f.size();

			if (n == us + 1) {
				f.pb('B');
			} else if (n == us + 2) {
				f.pb('X');
				// cerr << p << endl;
			} else {
				f.pb('A');
			}
		}

		if (press(f + "B") == N) return f + "B";
		if (press(f + "X") == N) return f + "X";
		return f + "A";
	}

	return f;
}
