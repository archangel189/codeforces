/*
    Solution to Contest 244 - Problem B.
    http://codeforces.com/contest/244/problem/B
*/

#include <iostream>
#include <sstream>
#include <deque>
#include <cmath>
#include <cstdlib>

#define ctoi(X) (char) (((int)'0')+X)

using namespace std;

int digits(int n) {
    stringstream ss;
    ss << n;
    return ss.str().size();
}

long int change(string ss, int a, int b) {
    for (int i = 0; i < ss.size(); i++) {
        if (ss[i] == '0') ss[i] = ctoi(b);
        else ss[i] = ctoi(a);
}
    return atoi(ss.c_str());
}

string to_base2(int num, int h) {
    string res = "";
    int quot, rem;

    for (int i = h-1; i >= 0; i--) {
        quot = num / pow(2, i);
        rem = num % (int) pow(2, i);
        num = rem;
        res += ctoi(quot);
    }

    return res;
}

int main() {
    int n, total = 0;
    cin >> n;

    int s = digits(n);
    if (s == 10) {
        s = 9;
        total++;
    }

    for (int h = 1; h <= s; h++) {
        for (int x = 1; x <= 9; x++) {
            int res;
            if (h == 1) {
                res = change("0", 0, x);
                if (res <= n) total++;
            }
            else {
                string brep;
                for (int k = pow(2, h-1); k <= pow(2, h)-1; k++) {
                    brep = to_base2(k, h);

                    if (k == pow(2, h)-1) {
                        res = change(brep, x, x);
                        if (res <= n) total++;
                    }
                    else {
                        for (int y = 0; y <= 9; y++) {
                            if (x == y) continue;
                            res = change(brep, x, y);
                            if (res <= n) total++;
                        }
                    }
                }
            }
        }
    }

    cout << total << endl;

    return 0;
}
