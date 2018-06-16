#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

int n, m;
bitset<10> X, Y, Z;
vector<int> vX, R;

void input() {
    int x, y;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> x;
        X.set(x);
        vX.push_back(x);
    }

    for (int i = 0; i < m; i++) {
        cin >> y;
        Y.set(y);
    }
}

void solve(){
    Z = X&Y;

    for (int i = 0; i < n; i++) {
        if (Z.test(vX[i])) {
            R.push_back(vX[i]);
        }
    }

    for (int i = 0; i < R.size(); i++) {
        if (i > 0) cout << " ";
        cout << R[i];
    }
    cout << endl;
}

int main() {
    input();
    solve();

    return 0;
}
