#include <iostream>
#include <pthread.h> // 使用POSIX的线程
#define NUM_THREADS 10
using namespace std;

typedef struct data{
    string name = "yan";
    string msg = "hello";
    int id;
}element;

void* hello(void *arg)//线程运行的例程
{
    element e = *((element*)arg);
    cout << e.name + " says " + e.msg + " to thread" + to_string(e.id) + "\n";
    pthread_exit(NULL);
}
int main()
{
    pthread_t tids[NUM_THREADS];
    element index[NUM_THREADS];
    for(int i = 0; i < NUM_THREADS; i++)
    {
        index[i].id = i;
        int rc = pthread_create(&tids[i],NULL,hello,(void*)&index[i]);
        if (rc){
            cout << "无法创建线程,错误代码" << rc << endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
    return 0;
}
// $ g++ -o ../bin/posix2 posix_thread2.cpp -lpthread