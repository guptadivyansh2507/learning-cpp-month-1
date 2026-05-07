/**
#include <iostream>
using namespace std;
class Player{
  public:
  int x, y;
  int speed;
  void Move(int xa , int ya){
  x+=xa *speed;
  y+=ya *speed;
}
};
int main(){
  Player player;
  player.Move( 1 , -1);
}
*/


/*
#include <iostream>
using namespace std;
class Test{
  public:
  int value;
  Test(){
    value = 10;
  }
  void Add(){
    value+=5;

  }
};
int main(){
  Test t1;
  Test* ptr = &t1;
  Test& ref = t1;
  ptr-> Add();
  ref.value+=10;
  cout<<t1.value<<endl;
}
*/
#include <iostream>
using namespace std;
class Box{
public:

    int value;

    Box(){
        value = 5;
    }

    void Double(){
        value *= 2;
    }
};

int main(){

    Box b1;

    Box b2 = b1;

    Box& ref = b1;

    Box* ptr = &b2;

    ref.Double();

    ptr->Double();

    cout << b1.value << endl;
    cout << b2.value << endl;
}
