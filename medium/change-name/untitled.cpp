#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Don't let the machines win. You are humanity's last hope...
 **/
int main()
{
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();
    vector<vector<bool>> map;
    for (int i = 0; i < height; i++) {
        string line; // width characters, each either 0 or .
        getline(cin, line);
        cerr << line << endl;
        for (int j = 0; j < height; ++)
            map[i][j] = (line[j] == "0"); 
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;


    // Three coordinates: a node, its right neighbor, its bottom neighbor
    cout << "0 0 1 0 0 1" << endl;
    cout << "1 0 -1 -1 -1 -1" << endl;
    cout << "0 1 -1 -1 -1 -1" << endl;
}
