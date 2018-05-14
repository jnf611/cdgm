#include <iostream>
#include <string>
#include <list> // TODO: deque better than list

using namespace std;
 
class Card
{
public:
    Card(const string& name) : m_name(name) {}
    int value() const;
    string to_string() const { return m_name; }

private:
    string m_name;
};

int Card::value() const
{
    string value = m_name.substr(0, m_name.size() - 1);
    switch (value[0]) {
    case 'J': return 11;
    case 'Q': return 12;
    case 'K': return 13;
    case 'A': return 14;
    default: return stoi(value);
    }
}

ostream& operator<<(ostream& os, const Card& card)
{
    return os << card.to_string();
}

class Player
{
public:
    Player();
    bool draw(unsigned int nb = 1);
    size_t size() const { return m_deck.size(); }
    string to_string() const;
    int value() const { return m_table.back().value(); }
    void pickUpGain(Player& p1, Player& p2);
    list<Card>& getTable() { return m_table; }

private:
    list<Card> m_deck;
    list<Card> m_table;
};

Player::Player()
{
    int n; // the number of cards for player x
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        string card; // the n cards of player x
        cin >> card; cin.ignore();
        m_deck.push_back(Card(card));
    }
}

bool Player::draw(unsigned int nb)
{
    for (unsigned int i = 0; i < nb; ++i) {
        if (m_deck.size() == 0)
            return false;
        m_table.push_back(m_deck.front());
        m_deck.pop_front();
    }
    return true;
}

void Player::pickUpGain(Player& p1, Player& p2)
{
    while (p1.m_table.size()) {
        m_deck.push_back(p1.m_table.front());
        p1.m_table.pop_front();
    }
    while (p2.m_table.size()) {
        m_deck.push_back(p2.m_table.front());
        p2.m_table.pop_front();
    }
}

string Player::to_string() const
{
    string res("deck:");
    for (auto card : m_deck)
        res += card.to_string() + string(", ");
    res += string("table:");
    for (auto card : m_table)
        res += card.to_string() + string(", ");
    return res;
}

ostream& operator<<(ostream& os, const Player& player)
{
    return os << player.to_string();
}

void logGame(const Player& p1, const Player& p2, int nbRound)
{
    cerr << "nbRound:" << nbRound << endl;
    cerr << "p1:" << p1 << endl;
    cerr << "p2:" << p2 << endl;
}

Player* battle(Player& p1, Player& p2)
{
    p1.draw();
    p2.draw();
    if (p1.value() > p2.value())
        return &p1;
    else if (p2.value() > p1.value())
        return &p2;
    else
        return nullptr;
}

Player* war(Player& p1, Player& p2)
{
    Player* winner = nullptr;
    while (!winner) {
        if (!p1.draw(3) || !p2.draw(3))
            break;
        else
            winner = battle(p1, p2);
    }
    return winner;
}

int main()
{
    Player p1, p2;
    
    int nbRound = 0;
    Player* winner = nullptr;
    while (!winner) {
        logGame(p1, p2, nbRound);
        
        nbRound ++;
        winner = battle(p1, p2);
        if (!winner)
            winner = war(p1, p2);
        
        if (!winner) {
            break; // tie
        } else {
            Player* loser = (winner == &p1) ? &p2 : &p1;
            winner->pickUpGain(p1, p2);
            if (loser->size() > 0)
                winner = nullptr;
        }
    }
    
    if (winner)
        cout << ((winner == &p1) ? string("1") : string("2")) << string(" ") << nbRound << endl;
    else
        cout << "PAT" << endl;
}
