#include <iostream>
#include <string>
using namespace std;
class Player{
  private:
  string m_Name;
  int m_Health;
  int m_Defence;
public:
  Player(string name){
    m_Name = name;
    m_Health = 100;
    m_Defence = 10;
  }
  void TakeDamage(int damage){
    damage -= m_Defence;
    if (damage < 0)
        damage =0;
    m_Health-= damage;
    if (m_Health < 0)
      m_Health = 0;
  }
  void Heal(int amount){
    m_Health += amount;
    if(m_Health >= 100)
      m_Health = 100; 
  }
  void IncreaseDefence(int amount){
    m_Defence += amount;
  }
  int GetHealth() const{
    return m_Health;
  }
  int GetDefence() const{
    return m_Defence;
  }
  string GetName() const{
    return m_Name;
  }
};

class Item{
public: 
  virtual void Use(Player& player) = 0;
  virtual ~Item(){}
};

class Sword : public Item{
private:
  int m_Damage;
public:
  Sword(int damage){
    m_Damage = damage;
  }
  void Use(Player& player) override{
    player.TakeDamage(m_Damage);
  }
};

class Potion : public Item{
private:
  int m_HealAmount;
public:
  Potion(int heal){
    m_HealAmount = heal;
  }
  void Use(Player& player) override{
    player.Heal(m_HealAmount);
  }
};

class Shield : public Item{
private:
  int m_DefenceBoost;
public:
  Shield(int boost){
    m_DefenceBoost = boost;
  }
  void Use(Player& player) override{
    player.IncreaseDefence(m_DefenceBoost);
  }
};

void ApplyItem(Item& item, Player& player){
  item.Use(player);
}
int main(){
  Player p("Divyansh");
  Sword sword(40);
  Potion potion(25);
  Shield shield(15);
  ApplyItem(sword, p);
  ApplyItem(potion, p);
  ApplyItem(shield, p);
  cout << p.GetName() << endl;
  cout << p.GetHealth() << endl;
  cout << p.GetDefence() << endl;
}
