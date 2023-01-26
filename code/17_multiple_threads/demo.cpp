#include <iostream>
#include <thread>

void hello(int num)
{
  std::this_thread::sleep_for(std::chrono::seconds(num));
  std::cout << "Hello from thread " << num << std::endl;
}

int main(int argc, char const * argv[])
{
  // create multiple thread
  std::thread t_1{hello, 1};
  std::thread t_2{hello, 2};
  std::thread t_3{hello, 4};
  t_1.join();
  t_2.join();
  t_3.join();

  return 0;
}
