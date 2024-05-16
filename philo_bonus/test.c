#include "../philo/philo.h"
#include <semaphore.h>
int main()
{
    const char *semaphore_name = "./example_semaphore";

   
    sem_t *sem = sem_open(semaphore_name, O_CREAT, 0644, 1);

}