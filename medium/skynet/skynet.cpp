#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Link
{
    size_t node1;
    size_t node2;
    Link(size_t node1 = 0, size_t node2 = 0) : node1(node1), node2(node2) {}
};

ostream& operator<<(ostream& os, const Link& link)
{
    return os << link.node1 << " " << link.node2;
}

class Game
{
public:
    Game(size_t nbNode, size_t nbLink, size_t nbGateway);
    Link getNextLink(size_t skynetNode);

private:
    void init();
    bool isGateway(size_t i);

    size_t m_nbNode;
    size_t m_nbGateway;
    vector<Link> m_link;
    vector<size_t> m_gateway;
};

Game::Game(size_t nbNode, size_t nbLink, size_t nbGateway) :
    m_nbNode(nbLink), m_link(nbLink), m_gateway(nbGateway)
{
    init();
}

void Game::init()
{
    for (size_t i = 0; i < m_link.size(); i++) {
        size_t node1, node2;
        cin >> node1 >> node2; cin.ignore();
        m_link[i] = Link(node1, node2, true);
        cerr << "i:" << i << ", node:" << m_link[i] << endl;
    }

    for (size_t i = 0; i < m_gateway.size(); i++) {
        cin >> m_gateway[i]; cin.ignore();
        cerr << m_gateway[i] << endl;
    }
}

bool Game::isGateway(size_t node)
{
    for (size_t i = 0; i < m_gateway.size(); ++i) {
        if (m_gateway[i] == node)
            return true;
    }

    return false;
}

Link Game::getNextLink(size_t skynetNode)
{
    Link nextLink;
    bool found = false;
    for (size_t i = 0; i < m_link.size(); ++i) {
        if (m_link[i].node1 == skynetNode || m_link[i].node2 == skynetNode) {
            if (m_link[i].node1 == skynetNode) {
                if (isGateway(m_link[i].node2)) {
                   nextLink = m_link[i];
                   m_link.erase(m_link.begin() + i);
                   found = true;
                   break;
                }
            }
            if (m_link[i].node2 == skynetNode) {
                if (isGateway(m_link[i].node1)) {
                   nextLink = m_link[i];
                   m_link.erase(m_link.begin() + i);
                   found = true;
                   break;
                }
            }
        }
    }

    // change this
    if (!found) {
        for (size_t i = 0; i < m_link.size(); ++i) {
            if (m_link[i].node1 == skynetNode || m_link[i].node2 == skynetNode) {
                nextLink = m_link[i];
                m_link.erase(m_link.begin() + i);
                break;
            }
        }
    }

    return nextLink;
}

int main()
{
    int nbNode, nbLink, nbGateway;
    cin >> nbNode >> nbLink >> nbGateway; cin.ignore();
    cerr << "nbNode:" << nbNode << ", "<< "nbLink:" << nbLink << ", "<< "nbGateway:" << nbGateway << endl;
    Game game = Game(nbNode, nbLink, nbGateway);

    // game loop
    while (1) {
        int skynetNode; // The index of the node on which the Skynet agent is positioned this turn
        cin >> skynetNode; cin.ignore();

        Link nextLink = game.getNextLink(skynetNode);

        cout << nextLink << endl; // Example: 0 1 are the indices of the nodes you wish to sever the link between
    }
}
