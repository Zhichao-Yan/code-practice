#include <iostream>
#include <thread>

using namespace std;

void foo1(int n)
{
    for (int i = 0; i < n; i++) {
        cout << "线程使用函数指针作为可调用参数\n";
    }
}
class foo2 {
public:
    void operator()(int n)
    {
        for (int i = 0; i < n; i++)
            cout << "线程使用函数对象作为可调用参数\n";
    }
};

auto foo3 = [](int n) {
        for (int i = 0; i < n; i++)
            cout << "线程使用 lambda 表达式作为可调用参数\n";
    };

int main()
{
    cout << "线程 1 、2 、3 "
         "独立运行" << endl;
    thread t1(foo1,1);
    thread t2(foo2(),1);
    thread t3(foo3,1);
    t1.join();
    t2.join();
    t3.join();
}