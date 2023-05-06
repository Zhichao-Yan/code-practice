#include <iostream>
#include <pthread.h> // 使用POSIX的线程
#define NUM_THREADS 10
using namespace std;

void* hello(void *pid)//线程运行的例程
{
    int id = *((int*)pid);
    string str = "hello world!thread:" + to_string(id) + '\n';
    cout << str;
    pthread_exit(NULL);
}
int main()
{
    pthread_t tids[NUM_THREADS];
    int indexes[NUM_THREADS];
    for(int i = 0; i < NUM_THREADS; i++)
    {
        indexes[i] = i;
        int rc = pthread_create(&tids[i],NULL,hello,(void*)&indexes[i]);
        if (rc){
            cout << "无法创建线程,错误代码" << rc << endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
    return 0;
}
// $ g++ -o ../bin/posix1 posix_thread1.cpp -lpthread