#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n; cin.ignore();
    int maxLoss = 0;
    int max = 0;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v; cin.ignore();
        if (v > max)
            max = v;
        int loss = v - max;
        if (loss < maxLoss)
            maxLoss = loss;
    }

    cout << maxLoss << endl;
}
