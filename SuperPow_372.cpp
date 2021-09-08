/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 372. Super Pow
~ Link      : https://leetcode.com/problems/super-pow/
*/

/*
    Prerequisite:

    (a ^ b ) % M
    = (a ^ (b % ETF(M))) % M, where ETF = Euler's totient function

    ETF(n) = n * (1 - (1 / P1)) * (1 - (1 / P2)) * ... * (1 - (1 / Pk))
    where P1, P2, P3, ..., Pk are the prime factors of n

    (a ^ b ) % M
    = (a ^ (b % (M - 1))) % M, when M is prime
*/

class Solution {
public:

    int phi(int n) {

        int res = n;

        for (int i = 2; i * i <= n; ++i) {

            if (n % i == 0) { // i is a prime factor of n

                while (n % i == 0)
                    n /= i;

                res -= res / i;
            }
        }

        if (n > 1)
            res -= res / n;

        return res;
    }

    int bi_expo(int a, int p, int m) {

        a %= m;
    	int res = 1;

        while (p > 0) {

            if (p & 1)
			    res = (a * 1LL * res) % m;

            a = (a * 1LL * a) % m;
		    p >>= 1;
	    }

        return res;
    }

    int find_b(vector<int>& b, int m) {

        int res = 0;

        for (int d : b)
            res = (res * 10 + d) % m;

        return res;
    }

    int superPow(int a, vector<int>& b) {

        if (a == 1)
            return 1;

        int phi_m = phi(1337);
        int p = find_b(b, phi_m);

        return bi_expo(a, p, 1337);
    }
};
