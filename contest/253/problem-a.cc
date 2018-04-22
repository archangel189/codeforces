/*
    Solution to Contest 253 - Problem A.
    http://codeforces.com/contest/253/problem/A
*/

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int n, m, cn, cm;

    ifstream ifile ("input.txt");
    ofstream ofile ("output.txt");
    ifile >> n >> m;

    cn = n;
    cm = m;

    char s = (cn > cm ? 'B' : 'G');
    if (s == 'B') {
        cn--;
    }
    else {
        cm--;
    }
    ofile << s;

    for (int i = 1; i < n+m; i++) {
        if (s == 'B') {
            if (cm > 0) {
                s = 'G';
                cm--;
            }
            else {
                cn--;
            }
        }
        else {
            if (cn > 0) {
                s = 'B';
                cn--;
            }
            else {
                cm--;
            }
        }
        ofile << s;
    }
    ofile << endl;

    return 0;
}
