#include <iostream>
#include <string>
using namespace std;
struct Vector2{
  float x, y;
  Vector2(float x, float y)
  : x(x), y(y){}
  Vector2 Add (const Vector2& other) const{
    return Vector2(x + other.x, y + other.y);
  }
  Vector2 operator+(const Vector2& other) const{
    return Add(other);
  }
  Vector2 Multiply(const Vector2& other) const{
    return Vector2(x *other.x, y * other.y);
  }
  Vector2 operator*(const Vector2& other) const{
    return Multiply(other);
  }
  bool operator==(const Vector2& other) const{
    return x== other.x && y == other.y;
  }
};
std::ostream& operator << (std::ostream& stream, const Vector2& other){
  stream << other.x << ", " << other.y;
  return stream;
}

int main(){
  Vector2 position(4.0f, 4.0f);
  Vector2 speed(0.5f, 0.5f);
  Vector2 powerup(1.1f, 1.1f );

  Vector2 result1 = position + speed * powerup;
  Vector2 result2 = position.Add(speed.Multiply(powerup));
  if(result1 == result2);
  cout << result1 << endl;
}
