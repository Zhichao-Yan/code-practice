#include <iostream> // std::cout
#include <thread> // std::thread
#include <mutex> // std::mutex

std::mutex mtx_1; // mutex for critical section
std::mutex mtx_2;  // mutex for critical section
int test_num;

void print_block_1 (int n, char c) 
{
    mtx_1.lock();
    for (int i=0; i<n; ++i) 
    {
        //std::cout << c;
        test_num = 1;
        std::cout<<test_num<<std::endl;
    }
    std::cout << "thread1 over" << std::endl;
    mtx_1.unlock();
}
void print_block_2 (int n, char c) 
{// critical section (exclusive access to std::cout signaled by locking mtx):
    mtx_2.lock();
    for (int i=0; i<n; ++i) 
    {
    //std::cout << c;
      test_num = 2;
      std::cout<<test_num<<std::endl;
    }
    std::cout << "thread2 over" << std::endl;
    mtx_2.unlock();
}
int main ()
{
    std::thread th1 (print_block_1,500,'*');
    std::thread th2 (print_block_2,500,'$');

    th1.join();
    th2.join();
    return 0;
}