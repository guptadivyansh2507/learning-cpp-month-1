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


#include <iostream>
using namespace std;
class Log{
public:
  const int LogLevelError = 0;
  const int LogLevelWarning = 1;
  const int LogLevelInfo = 2;
private:
  int m_LogLevel = LogLevelInfo;
public:
  void SetLevel(int level){
    m_LogLevel = level;
  }
  void warn(const char* message){
    if (m_LogLevel >= LogLevelWarning)
    cout<<"[WARNING]:" << message <<endl;
  }
  void Error(const char* message){
    if (m_LogLevel >= LogLevelError)
    cout<<"[ERROR]:" << message <<endl;
  }
  void Info(const char* message){
    if (m_LogLevel >= LogLevelInfo)
    cout<<"[Info]:" << message <<endl;
  }
};1
int main(){
  Log log;
  log.SetLevel(log.LogLevelError);
  log.warn("Hello!");
  log.Error("Hello!");
  log.Info("Hello!");
  cin.get();
}





#include <iostream>
using namespace std;
class test{
public:
  static int x;
  test(){
    x++;
  }
};
int test::x=0;
int main(){
  test t1;
  test t2;
  t1.x = 100;
  cout<<t2.x<<endl;
}



#include <iostream>
using namespace std;
class test{
public:
  static int count;
  test(){
  count++;
  }
};
int test::count = 0;
void Function(){
  static int x= 1;
  x++;
  test t;
  cout << x << " " << test::count << endl;
}
int main(){
  Function();
  Function();
  Function();
}



#include <iostream>
using namespace std;
class visitor{
public:
  static int id;
  visitor(){
    id++;
  }
};
int visitor::id = 0;
void Function(){
  visitor t;
  cout<<"Visitor ID: "<< visitor::id<< endl;
}
int main(){
  Function();
  Function();
  Function();
  cout << "Total Visitors: " << visitor::id<< endl;
}
*/

#include <iostream>
using namespace std;

class Player {
  public:
  static int count;
  int id;
  Player(){
    count++;
    id = count;
  }
  static Getcount(){
    return count;
  }
};
int Player::count = 0;
int main(){
  Player p1, p2 ,p3;
  cout<<p1.id<<endl;
  cout<<p2.id<<endl;
  cout<<p3.id<<endl;
  cout<<"Player count: " << Player::count<< endl;
}
