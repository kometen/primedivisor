#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int prime(int x, int b, int n) {
	vector<int> divisors;
	auto s = 0;
	auto loop_prime_divisor = true;
	for (s = x; s <= b && loop_prime_divisor; ++s) {
		if (n % s == 0) {
			if (s <= (n / s)) {
				cout << "n = s * t : " << n << " = " << s << " * " << (n / s) << endl;
				divisors.push_back(prime(x, b, (n / s)));
				loop_prime_divisor = false;
			}
		}
	}
	return 0;
}

int main(int argc, char const *argv[]) {
	vector<int> v;
	auto y = 0;
	auto is_prime = true;
	auto n = 245;
	auto b = static_cast<int>(sqrt(n));

	// Start with three as divisor if n > 2 to save one small step
	auto x = 2;
	if (n > 2) {
		x = 3;
	}

	cout << "n: " << n << ", b: " << b << endl;

	y = prime(x, b, n);
	cout << "y: " << y << endl;

	return 0;
}