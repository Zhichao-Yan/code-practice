#include <iostream>
#include <pthread.h> // 使用POSIX的线程
#define NUM_THREADS 10

using namespace std;

void* hello(void *arg)//线程运行的例程
{
    cout << "hello world! ~yzc\n";
    return 0;
}
int main()
{
    pthread_t tids[NUM_THREADS];
    for(int i = 0; i < NUM_THREADS; i++)
    {
        if(pthread_create(&tids[i],NULL,hello,NULL)) //创建线程
        {
            cout << "Failed to create thread" << endl;
        }
    }
    pthread_exit(NULL);//主线程等待创建的子线程结束在结束，否则return 0 之后所有线程强制结束
    return 0;
}