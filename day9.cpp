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
