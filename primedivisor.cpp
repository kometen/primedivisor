#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> divisors;

vector<int> prime(int x, int b, int n) {
	auto s = 0;
	auto loop_prime_divisor = true;
	for (s = x; s <= b && loop_prime_divisor; ++s) {
		if (n % s == 0) {
			if (s <= (n / s)) {
				cout << "n = s * t : " << n << " = " << s << " * " << (n / s) << endl;
				divisors.push_back(s);
				divisors.push_back(n / s);
				return prime(x, b, (n / s));
				loop_prime_divisor = false;
			}
		}
	}
	return divisors;
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

	v = prime(x, b, n);

	cout << "vector size: " << v.size() << endl;

	for (auto i = 0; i < v.size(); ++i) {
		cout << v[i] << ",";
	}

	return 0;
}