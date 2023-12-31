#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void*   MyTurn(void *arg)
{
    int i = 0;
    int *ptr_value = arg;

    while (i < 12)
    {
        sleep(1);
		//write(1, "\x1b[31m", 8);
        printf("\x1b[31m" "My turn - i: %d / ptrvalue; %d\n" "\x1b[0m", i, *ptr_value);
		//printf("\x1b[0m");
		//write(1, "\x1b[0m", 8);
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
