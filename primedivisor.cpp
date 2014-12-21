#include <cstdlib>
#include <iostream>
#include <cmath>
#include <unordered_map>
#include <vector>

using namespace std;

typedef unordered_map<int, int> _umap;
vector<long int> v_primes;
long int lprime;

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

void add_primes(int x, int b) {
	for (auto s = x; s <= b; s += 2) {
		if (IsPrime(s)) {
			v_primes.push_back(s);
			lprime = s;
		}
	}
}

int main(int argc, char const *argv[]) {

	_umap squareroots;

	if (argc < 2) {
		cout << "syntax: " << argv[0] << " [i]" << endl;
		exit(0);
	}

	auto is_prime = true;
	auto n = atoi(argv[1]);
	auto b = static_cast<int>(sqrt(n));

	if (n == 2) {
		cout << n << " is prime" << endl;
		exit(0);
	}
	if (n > 3 && n % 2 == 0) {
		cout << n << " is not prime" << endl;
		exit(0);
	}

	// Start with three as divisor if n > 2 to save one small step
	auto x = 2;
	if (n > 2) {
		x = 3;
	}

	cout << "n: " << n << ", b: " << b << endl;

	auto search = squareroots[b];
	if (search) {
		cout << "Squareroot " << b << " already added to map " << endl;
	} else {
		cout << "Adding squareroot " << b << " to map " << endl;
		squareroots[b] = b;
		add_primes(x, b);
		cout << "Elements in prime vector: " << v_primes.size() << endl;
	}
	cout << "Elements in squareroots: " << squareroots.size() << endl;

	is_prime = true;
	// Check whether n is prime
	for (auto i : v_primes) {
		if (n % i == 0) {
			is_prime = false;
		}
	}
	if (is_prime) {
		cout << n << " is prime" << endl;
	} else {
		cout << n << " is not prime" << endl;
	}
	cout << endl;

	return 0;
}