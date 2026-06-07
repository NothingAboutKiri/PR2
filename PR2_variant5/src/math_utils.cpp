#include "math_utils.h"

int gcd_int(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

bool is_prime(int n) {
    if (n < 2) return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }

    return true;
}

int mod_pow(int base, int power, int mod) {
    int result = 1;
    base = base % mod;

    while (power > 0) {
        if (power % 2 == 1) {
            result = (result * base) % mod;
        }

        base = (base * base) % mod;
        power = power / 2;
    }

    return result;
}

int extended_gcd(int a, int b, int &u, int &v) {
    if (b == 0) {
        u = 1;
        v = 0;
        return a;
    }

    int u1, v1;
    int d = extended_gcd(b, a % b, u1, v1);

    u = v1;
    v = u1 - (a / b) * v1;

    return d;
}

int mod_inverse(int a, int mod) {
    int u, v;
    int d = extended_gcd(a, mod, u, v);

    if (d != 1) return -1;

    return (u % mod + mod) % mod;
}

vector<int> continued_fraction(int a, int b) {
    vector<int> result;

    while (b != 0) {
        int q = a / b;
        int r = a % b;

        result.push_back(q);
        a = b;
        b = r;
    }

    return result;
}
