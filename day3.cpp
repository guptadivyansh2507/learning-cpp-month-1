#include <bits/stdc++.h>
using namespace std;
int Multiply(int a , int b){
  return a*b;
}
void MultiplyAndlog(int a, int b){
  int result = Multiply(a,b);
  cout << result <<endl;
}
int main(){
  MultiplyAndlog(3,2);
  MultiplyAndlog(57,35);
  MultiplyAndlog(35,35);
}
