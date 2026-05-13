/*
#include <iostream>
#include <array>
using namespace std;
class Entity{
public:
  static const int size = 5;
  int example[size];
  array<int, 5> another;

  Entity(){
    for (int i = 0; i < another.size(); i++)
      example[i] = 2;
  }
};
int main(){
  Entity e;
}


#include <iostream>
#include <array>
using namespace std;
class Inventory{
public:
  int item[5];
  Inventory(){
    for(int i = 0;i < 5; i++){
      item[i] = 0;
    }
  }

  void AddItem(int slot,int amount){
    item[slot] += amount;
  }
  void RemoveItem(int slot, int amount){
    item[slot] -= amount;
    if(item[slot] < 0){
      item[slot] = 0;
    }
  }
};
int main(){
  Inventory inv;
  inv.AddItem(3,5);
  inv.AddItem(2,6);
  inv.RemoveItem(2,3);
  for(int i = 0; i < 5; i++){
    cout << inv.item[i] << endl;
  }
}


#include <iostream>
#include <string>
using namespace std;
void PrintString(const string& string){
  cout << string << endl;
}
int main(){
  string name = string("cherno") + "hello";
  PrintString(name);
  bool contains = name.find("no") != string::npos;
}

*/

#include <iostream>
#include <string>
using namespace std;
void PrintProfile(const string& username, const string& bio){
  cout << "Username: " << username << endl;
  cout << "Bio: " << bio << endl;
  cout << "---------------"<< endl;
}
int main(){
  string username = "bruh";
  string bio = "i love cpp and quant trading";
//concantenation
  username += "_gamer";
//append
  bio.append(" everyday");

  PrintProfile(username, bio);
  //string size
  cout << "Username Length: " << username.size() << endl;
  //access characters
  cout << "First Character: " << username[0] << endl;
  //modify characters
  username[0] = 'B';
  cout << "Modified Username: " << username << endl;
  //Find word
  size_t position = bio.find("quant");
  if(position != string::npos){
    cout << "'quant' found at index: " << position << endl;
  }
  //substring
  string extracted = bio.substr(7,3);
  cout << "substring: " << extracted << endl;
  //Replace text
  bio.replace(7,3,"c++");
  cout << "After replace: " << bio << endl;
  //erase text
  bio.erase(0,2);
  cout << "After Erase: " << bio << endl;
  //string comparision
  if(username == "Bruh_gamer"){
    cout << "Username matched!" << endl;
  }
  //loop through string
  cout << "Characters in username: " << endl;
  for (int i = 0;i < username.size();i++){
    cout << username[i] << endl;
  }
  //capitalizing all letters
  for(int i =0; i < username.size();i++){
    if(username[i]>= 'a' && username[i] <= 'z'){
      username[i] = username[i] - 32;
    }
  }
  cout << "Capitalized Username: " << username << endl;
}
