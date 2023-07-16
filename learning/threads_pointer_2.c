#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void*   MyTurn()
{
    int i = 0;
    int *ptr_value;

	ptr_value = malloc(sizeof(int));
	*ptr_value = 20;
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
	int 		*result;

    pthread_create(&my_thread, NULL, MyTurn, NULL);
    YourTurn();
	// This function (pthread_join) waits till receive something from the thread.
	//WARNING... As the function "MyTurn" (executed) is a void*, it is needed to
	// cast the return with a (void *) &result.
    pthread_join(my_thread, (void *) &result);
    printf("\x1b[33m" "thread's done: result = %d\n" "\x1b[0m", *result);
    return (0);
}
