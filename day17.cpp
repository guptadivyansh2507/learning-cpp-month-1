#include <iostream>
#include <string>
#include <array>
using namespace std;
class IUsable{
public:
  virtual void Use() = 0;
  virtual ~IUsable(){}
};

class Entity{
protected:
  string m_Name;
  int m_Health;
public:
  enum class State{
    Idle, Fighting, Dead
  };
protected: 
  State m_State;
  static int s_EntityCount;
public:
  Entity(const string& name, int health) :
    m_Name(name), m_Health(health), m_State(State::Idle){
      s_EntityCount++;
      cout << "Entity created: " << m_Name << endl;
    }
  virtual ~Entity(){
    cout << "Entity Destroyed: " << m_Name << endl;
  }
  virtual void Attack(){
    cout << m_Name << "attacks weakly" << endl;
  }
  void TakeDamage(int amount){
    m_Health -= amount;
    if(m_Health <= 0){
      m_Health = 0;
      m_State = State::Dead;
    }
    else{
      m_State = State::Fighting;
    }
  }
  void Heal(int amount){
    m_Health += amount;
    if(m_Health > 100)
      m_Health = 100;
  }
  const string& GetName() const{
    return m_Name;
  }
  int GetHealth() const{
    return m_Health;
  }
  void PrintInfo() const{
    cout << "Name: " << m_Name << endl;
    cout << "Health: " << m_Health << endl;
    cout << "State: "; 
    string stateText = (m_State == State::Idle)
      ?"Idle" : (m_State == State::Fighting) ?"Fighting" : "Dead";
    cout << stateText << endl;
  }
  static void PrintEntityCount(){
    cout << "Total Entities: " << s_EntityCount << endl;
  }
};

int Entity::s_EntityCount = 0;

class Weapon : public IUsable{
private:
  string m_WeaponName;
  int m_Damage;
public:
  explicit Weapon(int damage)
    : m_WeaponName("Basic Sword"), m_Damage(damage){}
  Weapon(const string& name, int damage): m_WeaponName(name), m_Damage(damage){}
  void Use() override{
    cout << m_WeaponName << "used" << endl;
  } 
  int GetDamage() const{
    return m_Damage;
  }
  const string& GetWeaponName() const{
    return m_WeaponName;
  }
};

class Player : public Entity{
private:
  Weapon* m_Weapon;
  array<int, 5> m_Inventory;
  const int m_MaxInventory;
public:
  Player(const string& name, int health) : Entity(name, health), m_Weapon(nullptr), m_MaxInventory(5){
    for(int i = 0; i<m_Inventory.size(); i++){
      m_Inventory[i] = 0;
    }
    cout << "Player Constructed" << endl;
  }
  ~Player(){
    delete m_Weapon;
    cout << "Palyer Destroyed" << endl;
  } 
  void EquipWeapon(Weapon* weapon){
    m_Weapon = weapon;
  }
  void Attack() override{
    if(m_Weapon){
      cout << m_Name << "attacks with" << m_Weapon->GetWeaponName() << endl;
    }
    else{
      cout << m_Name << "Punches" << endl;
    }
  }
  void AddItem(int slot, int amount){
    if(slot < 0 || slot >=m_MaxInventory) return;
    m_Inventory[slot] += amount;
  }
  void RemoveItem(int slot , int amount){
    if (slot < 0 || slot >= m_MaxInventory) return;
    m_Inventory[slot] -= amount;
    if(m_Inventory[slot] < 0)
      m_Inventory[slot] = 0;
  }
  void PrintInventory() const{
    cout << "Inventory" << endl;
    for(int i = 0; i < m_Inventory.size(); i++){
      cout << "Slot " << i << ": " << m_Inventory[i] << endl;
    }
    cout << "-------------------" << endl;
  }
};
class Enemy : public Entity{
private:
  int m_Damage;
public:
  Enemy(const string& name, int health, int damage)
    :Entity(name, health), m_Damage(damage){
      cout << "Enemy constructed" << endl;
    }
  ~Enemy(){
    cout << "Enemy destroyed" << endl;
  }
  void Attack() override{
    cout << m_Name << " attacks for " << m_Damage << " damage" << endl; 
  }
};

void Battle(Entity& attacker, Entity& target){
  attacker.Attack();
  target.TakeDamage(20);
  target.PrintInfo();
}

void AnalyzeName(const string& name){
  cout << "Analyzing Name: " << name << endl;
  
  cout << "Length: " << name.size() << endl;
  
  bool containsA = name.find("a") != string::npos;
  
  cout << "Contains 'a': " << ((containsA) ? "yes" : "No") << endl;
  for (int i = 0; i < name.size(); i++){
    cout << name[i] << " ";
  }
  cout << endl;
  cout << "-------------------" << endl;
}

int main(){
  Player player("Rahul" , 100);

  Weapon* sword = new Weapon("Dragon Sword", 50);
  
  player.EquipWeapon(sword);
  
  player.AddItem(0, 5);
  
  player.AddItem(1, 10);
  
  player.RemoveItem(1, 3);
  
  player.PrintInventory();
  
  Enemy enemy("Goblin", 60 , 15);
  
  Battle(player, enemy);
  
  Battle(enemy, player);
  
  AnalyzeName(player.GetName());
  
  Entity* ptr = &player;
  
  ptr->PrintInfo();
  
  Entity::PrintEntityCount();
  
  Entity temp("Temporary", 20);
  
  cout << "Program Ending" << endl;
  
  cout << "Rahul Saved the world from goblins" << endl;  
}
