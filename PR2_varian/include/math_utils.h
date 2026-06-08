#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#include <vector>
using namespace std;

int gcd_int(int a, int b);
bool is_prime(int n);
int mod_pow(int base, int power, int mod);
int extended_gcd(int a, int b, int &u, int &v);
int mod_inverse(int a, int mod);
vector<int> continued_fraction(int a, int b);

#endif
