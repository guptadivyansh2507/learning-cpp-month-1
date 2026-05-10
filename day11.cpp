#include <iostream>
#include <string>
using namespace std;
class Player{
private:
  string m_Name;
  int m_Health;
  int m_Level;

public:
  //constructor
  Player(string name, int health, int level){
    m_Name = name;
    m_Health = health;
    m_Level = level;
    cout<< "Player Created:" << m_Name << endl;
  }
  ~Player(){
    cout<< "Player Destroyed: " << m_Name <<endl;
  }
  void PrintInfo(){
    cout << "Name: " << m_Name << endl;
    cout << "Health: " << m_Health << endl;
    cout << "Level: " << m_Level << endl;
    cout << "-------------" << endl;
  }
  void Takedamage(int damage){
    m_Health-= damage;
    if(m_Health < 0)
      m_Health = 0;
    cout << m_Name << "took Damage"<< endl;
  }
  void Heal(int heal){
    m_Health+= heal;
    cout << m_Name << "Has healed" << endl;
  }
  void LevelUp(){
    m_Level++;
    cout << m_Name << "leveled up" << endl;
  }
};
void Battle(){
  Player Goblin("goblin", 50, 1);
  Goblin.PrintInfo();
  Goblin.Takedamage(20);
  Goblin.PrintInfo();
  cout << " Battle Ending.." << endl;
}
int main(){
  Player player1("Bruh", 100 , 5);
  player1.PrintInfo();
  player1.Takedamage(30);
  player1.Heal(10);
  player1.LevelUp();
  player1.PrintInfo();
  cout << "Entering battle" << endl;
  Battle();
  cout << "back to main" << endl;
}
