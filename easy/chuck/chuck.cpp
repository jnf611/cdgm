#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

enum bit {
    ZERO,
    ONE
};

void toChuck(string& chuckMessage, const string& message)
{
    char mask = 0b01000000;
    bit previous = (message[0] & mask) ? ONE : ZERO;
    if (previous == ONE)
        chuckMessage.append("0 ");
    else
        chuckMessage.append("00 ");

    for (size_t i = 0; i < message.size(); ++i) {
        char c = message[i];
        for (size_t j = 0; j < 7; ++j) {

            bit current = (c & mask) ? ONE : ZERO;
            
            if (previous != current) {
                if (current == ONE)
                    chuckMessage.append(" 0 0");
                else
                    chuckMessage.append(" 00 0");
            } else {
                chuckMessage.append("0");
            }

            previous = current;
            c <<= 1;
        }
    }
}
 
int main()
{
    string message = "CC";
    string chuckMessage;
    
    toChuck(chuckMessage, message);

    cout << "message: \"" << message << "\"" << endl;
    cout << "chuckMessage: \"" << chuckMessage << "\"" << endl;
}
