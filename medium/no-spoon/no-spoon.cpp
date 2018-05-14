#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<vector<bool>> Map;
 
struct Point
{
    int i;
    int j;
    Point(int i, int j) : i(i), j(j) {};
    Point& operator+=(const Point& p) {
        i += p.i;
        j += p.j;
        return *this;
    }
    string to_string() const { return std::to_string(j) + string(" ") + std::to_string(i); };
};

ostream& operator<<(ostream& s, const Point& p)
{
    return s << p.to_string();    
}

Point getNext(const Map& map, Point p, const Point& dir)
{
    p += dir;
    while (true) {
        if (p.i < 0 || p.i >= map.size() || p.j < 0 || p.j >= map[p.i].size())
            return Point(-1, -1);
        else if (map[p.i][p.j])
            return p;
        
        p += dir;
    }
}

int main()
{
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    cerr << "width:" << width << endl;
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();
    cerr << "height:" << height << endl;
    vector<vector<bool>> map(height, vector<bool>(width));
    for (int i = 0; i < height; i++) {
        string line; // width characters, each either 0 or .
        getline(cin, line);
        for (int j = 0; j < width; j++)
            map[i][j] = (line[j] == '0'); 
    }

    for (size_t i = 0; i < map.size(); i++) {
        for (size_t j = 0; j < map[i].size(); j++) {
            if (map[i][j]) {
                Point p = Point(i, j);
                
                // right node
                Point right = getNext(map, p, Point(0, 1));
                
                // below node
                Point below = getNext(map, p, Point(1, 0));

                cout << p << " " << right << " " << below << endl;
            }
        }
    }
}
