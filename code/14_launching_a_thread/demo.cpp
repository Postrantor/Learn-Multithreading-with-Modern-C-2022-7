#include <iostream>
#include <thread>

// callable object - thread entry point
// 1. 无参数的调用
void hello() { std::cout << "Hello, Thread!" << std::endl; }
// 2. 有参数的调用，不能重载，因此需要修改函数名
// 为啥不能重载？
void hello2(std::string str) { std::cout << str << std::endl; }
// 3. 引用参数
void hello3(std::string & str) { str = "hello3"; }
void hello4(std::string && str)
{
  str = "hello4";
  std::cout << "in hello4()" << str << std::endl;
}
// 4. 类中成员函数
class greeter
{
public:
  void hello() { std::cout << " Hello, member function!" << std::endl; }
};

void func_4()
{
  greeter greet;
  // function name to get the member function pointer
  // and then the address of the object
  std::thread thread_4{&greeter::hello, &greet};
  // you need to call join() on the new thread,
  // to make the existing thread stop and wait for it.
  // if you dont do that, it could finish before the new thread does.
  thread_4.join();
}

int main(int argc, char const * argv[])
{
  /* 
  // 创建一个线程实例
  // std::thread my_thread{hello};
  // std::thread my_thread{hello2, "Hello, Thread2!"};
  std::string str{"hello2"};
  // 通过std::ref转换为左值引用
  // std::thread my_thread{hello3, std::ref(str)};
  // 通过std::move转换为右值引用
  // 此后不能访问str，因为已经move到了hello4
  std::thread my_thread{hello4, std::move(str)};
  std::cout << str << std::endl;  // hello2
  std::cout << "Doing some work..." << std::endl;
  // 调用join()函数，不加的话会出异常
  // terminate called without an active exception
  my_thread.join();
  // 这里不会打印出hello4，因为前面使用的是move
  std::cout << str << std::endl;  // hello3
  */
  func_4();

  return 0;
}
