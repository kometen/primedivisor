#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> divisors;
unordered_map<int, int> map_divisors;

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

unordered_map<int, int> primedivisor(int x, int b, int n) {
	auto s = 0;
	auto second = 0;
	auto loop_prime_divisor = true;
	for (s = x; s <= b && loop_prime_divisor; ++s) {
		if (n % s == 0) {
			second = n / s;
			if (s <= second) {
				cout << "n = s * t : " << n << " = " << s << " * " << second << endl;
				if (IsPrime(s)) {
					map_divisors = {{s, s}};
				}
				if (s != second) {
					if (IsPrime(second)) {
						map_divisors = {{second, second}};
					}
				}
				return primedivisor(x, b, second);
				loop_prime_divisor = false;
			}
		}
	}
	return map_divisors;
}

int main(int argc, char const *argv[]) {
	unordered_map<int, int> mm;
	auto y = 0;
	auto is_prime = true;
	auto n = 45;
	auto b = static_cast<int>(sqrt(n));

	// Start with three as divisor if n > 2 to save one small step
	auto x = 2;
	if (n > 2) {
		x = 3;
	}

	cout << "n: " << n << ", b: " << b << endl;

	mm = primedivisor(x, b, n);

	cout << "mm map contains:";
	for (auto it = mm.begin(); it != mm.end(); ++it) {
		cout << " " << it->first << ":" << it->second;
	}
	cout << endl;
	return 0;
}