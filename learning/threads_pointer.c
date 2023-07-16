#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void*   MyTurn(void *arg)
{
    int i = 0;
    int *ptr_value = (int *)arg;

    while (i < 12)
    {
        sleep(1);
        printf("My turn - i: %d / ptrvalue; %d\n", i, *ptr_value);
        i++;
        (*ptr_value)++;
    }
    return (ptr_value);
}

void*   YourTurn()
{
    int i = 0;
    
    while (i < 5)
    {
        sleep(2);
        printf("Your turn - i: %d\n", i);
        i++;
    }
    return (NULL);
}

int main(void)
{
    pthread_t   my_thread;
    int         v = 20;

    pthread_create(&my_thread, NULL, MyTurn, &v);
    YourTurn();
    pthread_join(my_thread, NULL);
    printf("thread's done: v = %d\n", v);
    return (0);
}
