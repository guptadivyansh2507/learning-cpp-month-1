#include <iostream>
#include <string>

using namespace std;

class Player{
private:

    int m_Health;

public:

    Player(int health)
        : m_Health(health)
    {
    }

    void PrintState(){

        string state =
            (m_Health > 0)
            ? "Alive"
            : "Dead";

        cout << state << endl;
    }

    int GetDamageMultiplier(){

        return (m_Health < 20)
            ? 2
            : 1;
    }
};

int main(){

    Player p(10);

    p.PrintState();

    cout << p.GetDamageMultiplier();
}
