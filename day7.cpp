# include <iostream>
using namespace std;
int main () {
  int a = 5;
  int& r = a;
  int* p =&a;
  *p = 30;
  r = 50;
  cout<<a<<endl;
  cout<<*p<<endl;
  cout<<r<<endl;
}
