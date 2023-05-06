#include <thread>
#include <mutex>
#include <iostream>
int g_i = 0;
std::mutex g_i_mutex;  // protects g_i，用来保护g_i

void safe_increment()
{
    const std::lock_guard<std::mutex> lock(g_i_mutex);
    ++g_i;
    // 当前线程的id和g_is
    std::cout << std::this_thread::get_id() << ": " << g_i << '\n';// g_i_mutex自动解锁
}
int main(){
    std::cout << "线程id: " <<std::this_thread::get_id()<<std::endl;

    std::cout << "运行id: " << g_i << '\n';

    std::thread t1(safe_increment);
    std::thread t2(safe_increment);

    t1.join();
    t2.join();

    std::cout << "运行id: " << g_i << '\n';
}