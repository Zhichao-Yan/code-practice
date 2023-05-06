#include <iostream>
#include <thread>
#include <mutex>
using namespace std;


struct Num{
    explicit Num(int num):n(num){}
    int n;
    mutex m;
};

void transfer(Num &from, Num &to, int num)
{
    unique_lock<mutex> l1(from.m,defer_lock);// 推迟上锁，手动上锁
    unique_lock<mutex> l2(to.m,defer_lock);
    lock(l1,l2);
    from.n -= num;
    to.n += num;
    return;
}

int main()
{
    Num a(100);
    Num b(80);
    thread t1(transfer,ref(a),ref(b),20);
    thread t2(transfer,ref(b),ref(a),30);
    t1.join();
    t2.join();
    cout << "a:" << a.n << endl;
    cout << "b:" << b.n << endl;
}