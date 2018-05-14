#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int n;
    cin >> n; cin.ignore();
    vector<int> strength;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value; cin.ignore();
        strength.push_back(value);
    }

    sort(strength.begin(), strength.end());
    int min_diff = strength[1] - strength[0];
    for (size_t i = 0; i < strength.size() - 1; ++i) {
        int diff = strength[i+1] - strength[i];
        if (diff < min_diff)
            min_diff = diff;
    }
    cout << min_diff << endl;
}
