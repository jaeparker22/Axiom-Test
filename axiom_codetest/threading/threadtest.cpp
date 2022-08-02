#include <iostream>
#include <string>
#include <cstring>
#include <pthread.h>
#include <unistd.h>
#include <cmath>

using namespace std;

pthread_mutex_t MUTEX;

int value=-1;

void* work(void*);

int main(int argc, char* argv[])
{
    int numthreads, maxloop;

    //deal with command line variables
    if(argc != 3)
    {
        cerr << "Too few command line arguments." << endl
            << "Proper usage: " << argv[0] << " <number of threads> <number of loops>" << endl;
        return 1;
    }
    else
    {
        numthreads=stoi(argv[1]);
        if(numthreads <= 0)
        {
            cerr << "Must have a positive, non-zero number of threads" << endl;
            return 2;
        }
        maxloop=stoi(argv[2]);
        if(maxloop <= 0)
        {
            cerr << "Must have a positive, non-zero number of loops" << endl;
            return 3;
        }
 
    }

    pthread_t threads[numthreads];
    int errno;
    int args[numthreads]; //thread_id

    cout << "Sleeping for 10 seconds..." << endl;
    sleep(10);

    for(int n=0; n < maxloop; n++)
    {
        for(int i=0; i < numthreads; i++)
        {
            //spawn threads
            args[i]=i;
            errno=pthread_create(&threads[i], NULL, work, &args[i]);
            if(errno)
            {
                cerr << "Pthread Creation Error: " << strerror(errno) << endl;
                exit(1);
            }

        }
        for(int i=0; i < numthreads; i++)
        {
            errno=pthread_join(threads[i], NULL);
            if(errno)
            {
                cerr << "Pthread Join Error: " << strerror(errno) << endl;
                exit(1);
            }

        }
    }   

    return 0;
}

void *work(void* id)
{
    int tid=*((int*)id);

    //mutex lock to prevent race conditions with value and gross output
    pthread_mutex_lock(&MUTEX);
    value++;
    cout << "Thread #" << tid << ", value " << value << endl;
    pthread_mutex_unlock(&MUTEX);
    
    return NULL;
}
