cmake_minimum_required(VERSION 3.25)
project(Philosophers C)

set(CMAKE_C_STANDARD 11)

include_directories(inc)

add_executable(Philosophers
        inc/philo.h
        learning/first_thread.c learning/threads_pointer.c learning/first_mutex.c learning/first_semaphore.c src/philo.c src/utils.c src/checks.c src/philo_utils.c)
