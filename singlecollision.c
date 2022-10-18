#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

void *collide(void *varpg)
{
    char a = 'a', b = 'b';
    a = b;
}
void *collide2(void *varpg)
{
    char a = 'a', b = 'b';
    b = a;
}
void *callit(void *varpg)
{
    pthread_t thread_id;
    pthread_t thread_id2;
    pthread_create(&thread_id, NULL, collide, NULL);
    pthread_create(&thread_id2, NULL, collide2, NULL);
    pthread_join(thread_id, NULL);
    pthread_join(thread_id2, NULL);
}

int main()
{
    printf("Firing 4 electrons at each other.\n");
    pthread_t thread_id3;
    pthread_t thread_id4;
    pthread_create(&thread_id3, NULL, callit, NULL);
    pthread_create(&thread_id4, NULL, callit, NULL);
    pthread_join(thread_id3, NULL);
    pthread_join(thread_id4, NULL);
}