
#include <iostream>
#include <string>
using namespace std;
class Character{
public:
  enum class State{
    Idle, Fighting, Dead
  };
protected:
  string m_Name;
  int m_Health;
  State m_State;

  static int s_CharacterCount;
public:
  Character(string name, int health){
    m_Name = name;
    m_Health = health;
    m_State = State::Idle;
    s_CharacterCount++;
    cout << "Character Created: " << m_Name << endl;
  }
  ~Character(){
    cout << "Character Destroyed: " << m_Name << endl;
  }
  void TakeDamage(int damage){
    m_Health-= damage;
    if(m_Health <= 0){
      m_Health = 0;
      m_State = State::Dead;
    }
    cout << m_Name << "took damage" << endl;
  }
  void PrintInfo(){
    cout << "Name: "
             << m_Name << endl;

        cout << "Health: "
             << m_Health << endl;

        cout << "State: ";

        if(m_State == State::Idle)
            cout << "Idle";

        else if(m_State == State::Fighting)
            cout << "Fighting";

        else if(m_State == State::Dead)
            cout << "Dead";

        cout << endl;

        cout << "-------------------"
             << endl;
  }
  static void PrintCharacterCount(){
    cout << "Total Characters: " << s_CharacterCount << endl;
  }
};

int Character::s_CharacterCount = 0;
class Warrior : public Character{
private:
  int m_Strength;
public:
  Warrior( string name, int health, int strength) : Character(name, health){
    m_Strength = strength;
    cout << "Warrior Ready! " << endl;
  }
  ~Warrior(){
    cout << "Warrior Destoryed: " << endl;
  }
  void Attack(){
    m_State = State::Fighting;
    cout << m_Name << " attacks with strength " << m_Strength << endl;
  }
};
class Mage : public Character{
private: 
  int m_Mana;
public: 
  Mage(string name, int health, int mana) : Character(name, health){
    m_Mana = mana;
    cout << "Mage Ready" << endl;
  }
  ~Mage(){
    cout << "Mage Destroyed" << endl;
  }
  void CastSpell(){
    m_State = State::Fighting;
    m_Mana -= 10;
    cout << m_Name << " casts spell!" << endl;
  }
};
void Battle(Character& c){
  c.TakeDamage(30);
  c.PrintInfo();
}
int main(){
  Warrior w("Thor", 100 , 50);
  Mage m("Merlin", 80 , 100);
  Character::PrintCharacterCount();
  w.PrintInfo();
  m.PrintInfo();
  w.Attack();
  m.CastSpell();
  Battle(w);
  Battle(m);
  Character* ptr =&w;
  ptr -> PrintInfo();
  cout << "Main Ending.." << endl;
}
