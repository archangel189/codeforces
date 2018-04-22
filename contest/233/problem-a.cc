/*
    Solution to Contest 233 - Problem A.
    http://codeforces.com/contest/233/problem/A
*/

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

int main() {
    int n;
    cin >> n;
    if (n % 2 == 1) {
        cout << -1 << endl;
        return 0;
    }

    int i = 2;
    for (int j = 0; j < n; j++) {
        cout << i << " ";
        if (i % 2 == 0) i--;
        else i+=3;
    }
    cout << endl;

    return 0;
}
