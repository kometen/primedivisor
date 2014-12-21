#include <iostream>
#include <cstdlib>
#include <cmath>
#include <unordered_map>

using namespace std;

typedef unordered_map<int, int> _divisors;
_divisors divisors;

bool IsPrime(int a) {
	auto b = static_cast<int>(sqrt(a));
	auto prime = true;

	// Start with three as divisor if n > 2 to save one small step
	auto x = 2;
	if (a > 2) {
		x = 3;
	}

	for (auto i = x; i <= b; ++i) {
		if (a % i == 0) {
			prime = false;
		}
	}

	return prime;
}

void primedivisor(int x, int b, int n) {
	auto s = 0;
	auto second = 0;
	auto loop_prime_divisor = true;
	for (s = x; s <= b && loop_prime_divisor; s += 2) {
		if (n % s == 0) {
			second = n / s;
			if (s <= second) {
				cout << "n = s * t : " << n << " = " << s << " * " << second << endl;
				if (IsPrime(s)) {
					divisors[s] = s;
				}
				if (s != second) {	// Second divisor, only add if different from first
					if (IsPrime(second)) {
						divisors[second] = second;
					}
				}
				primedivisor(x, b, second);
				loop_prime_divisor = false;
			}
		}
	}
}

int main(int argc, char const *argv[]) {

	unordered_map<long int, _divisors> squareroots;

	if (argc < 2) {
		cout << "syntax: " << argv[0] << " [i]" << endl;
		exit(0);
	}

	auto y = 0;
	auto is_prime = true;
	auto n = atoi(argv[1]);
	auto b = static_cast<int>(sqrt(n));

	// Start with three as divisor if n > 2 to save one small step
	auto x = 2;
	if (n > 2) {
		x = 3;
	}

	cout << "n: " << n << ", b: " << b << endl;

	auto search = squareroots.find(b);
	if (search != squareroots.end()) {
		cout << "Squareroot prime divisors for " << search->first << " found" << endl;
		for (auto it = search->second.begin(); it != search->second.end(); ++it) {
			cout << " " << it->first << ":" << it->second;
		}
		cout << endl;
	} else {
		cout << "Adding squareroot prime divisors for " << b << endl;
		primedivisor(x, b, n);
		squareroots[b] = divisors;
		divisors.clear();
	}

	n += 2;
	b = static_cast<int>(sqrt(n));
	cout << "n: " << n << ", b: " << b << endl;

	search = squareroots.find(b);
	if (search != squareroots.end()) {
		cout << "Squareroot prime divisors for " << search->first << " found" << endl;
		for (auto it = search->second.begin(); it != search->second.end(); ++it) {
			cout << " " << it->first << ":" << it->second;
		}
		cout << endl;
	} else {
		cout << "Adding squareroot prime divisors for " << b << endl;
		primedivisor(x, b, n);
		squareroots[b] = divisors;
		divisors.clear();
	}

	n += 2;
	b = static_cast<int>(sqrt(n));
	cout << "n: " << n << ", b: " << b << endl;

	search = squareroots.find(b);
	if (search != squareroots.end()) {
		cout << "Squareroot prime divisors for " << search->first << " found" << endl;
		for (auto it = search->second.begin(); it != search->second.end(); ++it) {
			cout << " " << it->first << ":" << it->second;
		}
		cout << endl;
	} else {
		cout << "Adding squareroot prime divisors for " << b << endl;
		primedivisor(x, b, n);
		squareroots[b] = divisors;
		divisors.clear();
	}

	return 0;
}