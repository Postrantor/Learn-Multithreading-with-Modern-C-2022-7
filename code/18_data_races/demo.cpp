#include <chrono>
#include <iostream>
#include <string>
#include <thread>

using namespace std;
using namespace std::literals;

void print(string str)
{
  for (int i = 0; i < 5; i++) {
    cout << str[0] << str[1] << str[2] << endl;
    std::this_thread::sleep_for(50ms);
  }
}

int main(int argc, char const * argv[])
{
  std::thread t1{print, "qwe"};
  std::thread t2{print, "asd"};
  std::thread t3{print, "zxc"};
  t1.join();
  t2.join();
  t3.join();
  return 0;
}
