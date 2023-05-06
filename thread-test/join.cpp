#include <iostream>
#include <thread>
using namespace std;
void thread_1()
{
  while(1)
  {
    cout<<"子线程1"<<endl;
  }
}
void thread_2()
{
  while(1)
  {
    cout<<"子线程2"<<endl;
  }
}
int main()
{
    thread first ( thread_1); // 开启线程，调用：thread_1()
    thread second (thread_2); // 开启线程，调用：thread_2(100)

    first.join(); // pauses until first finishes 这个操作完了之后才能destroyed
    second.join(); // pauses until second finishes//join完了之后，才能往下执行。
    while(1)
    {
      std::cout << "主线程\n";
    }
    return 0;
}