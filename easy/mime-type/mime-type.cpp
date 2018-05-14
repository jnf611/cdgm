#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

void toLower(string& str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

int main()
{
    int nbExtension; // Number of elements which make up the association table.
    cin >> nbExtension; cin.ignore();
    int nbFile; // Number of file names to be analyzed.
    cin >> nbFile; cin.ignore();

    map<string, string> mimeType;
    for (int i = 0; i < nbExtension; i++) {
        string ext; // file extension
        string mt; // MIME type.
        cin >> ext >> mt; cin.ignore();
        toLower(ext);
        mimeType.insert(pair<string, string>(ext, mt));
        cerr << "ext:" << ext << ", mt" << mt << endl;
    }

    for (int i = 0; i < nbFile; i++) {
        string filename; // One file name per line.
        getline(cin, filename);
        cerr << "filename:" << filename << endl;
        size_t index = filename.rfind('.');
        map<string, string>::iterator it =  mimeType.end();
        if (index != string::npos) {
            string ext = filename.substr(index + 1);
            toLower(ext);
            it = mimeType.find(ext);
        }
        string type = (it != mimeType.end()) ? it->second : "UNKNOWN";
        cout << type << endl;
    }
}
