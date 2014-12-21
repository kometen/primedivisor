#include <cstdlib>
#include <iostream>
#include <cmath>
#include <unordered_map>
#include <vector>

using namespace std;

typedef unordered_map<int, int> _umap;
std::vector<long int> v_primes;

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
	for (s = x; s <= b; s += 2) {
		if (IsPrime(s)) {
			v_primes.push_back(s);
		}
	}
}

int main(int argc, char const *argv[]) {

	_umap squareroots;

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
	} else {
		cout << "Adding squareroot prime divisors for " << b << endl;
		primedivisor(x, b, n);
	}

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

	return 0;
}