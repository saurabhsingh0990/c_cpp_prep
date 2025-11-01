#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

/*
 * 🔹 Thread function declaration
 * - Accepts a void pointer (generic type).
 * - Should return void* according to pthread standards.
 */
void* increment(void *num);

int main() {
    printf("\n🔸 Demo: Multithreading using pthreads in C\n");
    printf("🔸 Goal: Run a background thread alongside main program to increment the same variable\n");

    int num = 10;
    pthread_t thread1;

    /*
     * 🔹 Creating a new thread:
     * - pthread_create(thread_id, attributes, start_routine, arguments)
     * - Here: Passing address of `num` as shared data.
     */
    if (pthread_create(&thread1, NULL, increment, (void*) &num) != 0) {
        perror("\n❌ Error creating thread");
        return 1;
    }

    // 🔄 Main thread also increments the same variable
    for (int i = 1; i < 10; i++) {
        printf("\nMain Thread : num = %d", num++);
        sleep(1);  // simulate work
    }

    /*
     * 🔹 pthread_join blocks the main thread until thread1 finishes.
     * - Ensures that the created thread completes before main exits
     */
    pthread_join(thread1, NULL);

    printf("\n\n✅ Both threads completed execution.\n");
    printf("⚠️ Note: No synchronization is used → This is a race condition demo.\n");
    return 0;
}

/*
 * 🔹 Thread function to increment the same shared integer
 * - Accepts void* as argument (need to cast back to proper type)
 */
void* increment(void *num) {
    for (int i = 0; i < 10; i++) {
        int *var = (int *) num;
        printf("\nChild Thread : num = %d", (*var)++);
        sleep(1);  // simulate work
    }
    return NULL;
}
