#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, k, nk, nok;
    cin >> n >> k;
    nk = n * k;
    set<int> nums;
    for (int i = 1; i <= nk; i++) {
        nums.insert(i);
    }

    int oranges[k];
    for (int i = 0; i < k; i++) {
        cin >> oranges[i];
        set<int>::iterator it = nums.find(oranges[i]);
        nums.erase(*it);
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            if (j == 0)
                cout << oranges[i] << " ";
            else {
                cout << *(nums.begin()) << " ";
                nums.erase(nums.begin());
            }
        }
        cout << endl;
    }

    return 0;
}
