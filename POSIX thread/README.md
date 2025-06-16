**Process** - Independent program in execution
- Its own address space
- Its own memory (heap, stack)
- File descriptors
- One or more threads, Atleast one main thread for execution.

**Thread** - a lightweight unit of a process, A single process can have multiple threads that share
- same memory space
- same file descriptors
- but each thread has its own stack and program counter

| Feature       | Process (`fork`)                     | Thread (`pthread`)                     |
| ------------- | ------------------------------------ | -------------------------------------- |
| Memory        | Separate address spaces              | Shared memory                          |
| Creation time | Slower (new memory, resources)       | Faster (shares memory)                 |
| Communication | IPC required                         | Shared variables                       |
| Isolation     | Strong (crashes don’t affect others) | Weak (one thread crash may affect all) |
| Use case      | Multi-programming                    | Multi-tasking within a program         |

---
**Multithreading** - a programming technique where a process is divided into multiple smaller units called threads, which can run simultaneously.

###  **Interview Questions
####  Basic Questions

1. **What is a thread and how is it different from a process?**
2. **What is the use of the pthread library in C?**
3. **How do you create a thread using `pthread_create`?**
4. **What are the arguments to `pthread_create()`?**
5. **How do you wait for a thread to complete?**
6. **How can you pass data to a thread function?**
7. **What is `pthread_join()` and why is it used?**
8. **What is the return type of a thread function?**
9. **Can you explain thread synchronization?**
10. **What is a race condition?**

####  Intermediate-Level Questions

11. **How do you avoid race conditions in threads?**
12. **Explain mutexes and how they are used.**
13. **What is a deadlock and how can it occur in pthreads?**
14. **What is the difference between mutex and semaphore?**
15. **What are condition variables in pthreads?**
16. **How do you cancel a thread?**
17. **What is thread-safe code?**
18. **What is the difference between `pthread_exit()` and `return` in a thread?**

####  Advanced Questions

19. **How do you implement a producer-consumer problem using pthreads?**
20. **Can you write a multithreaded program where multiple threads write to a shared log file safely?**
21. **How does `pthread_detach()` work and why would you use it?**
22. **What are barriers in pthreads and when are they useful?**
23. **What are the potential issues with using global variables in multithreaded programs?**

---

###  Example Pthread Programs in C
####  **1. Basic Thread Creation**

```c
#include <pthread.h>
#include <stdio.h>

void* threadFunc(void* arg) {
    printf("Hello from thread!\n");
    return NULL;
}

int main() {
    pthread_t tid;
    pthread_create(&tid, NULL, threadFunc, NULL);
    pthread_join(tid, NULL);
    return 0;
}
```

---

####  **2. Passing Arguments to Thread**

```c
#include <pthread.h>
#include <stdio.h>

void* printMessage(void* arg) {
    char* message = (char*) arg;
    printf("Message: %s\n", message);
    return NULL;
}

int main() {
    pthread_t tid;
    char* msg = "Hello from argument!";
    pthread_create(&tid, NULL, printMessage, (void*)msg);
    pthread_join(tid, NULL);
    return 0;
}
```

---

####  **3. Using Mutex for Synchronization**

```c
#include <pthread.h>
#include <stdio.h>

int counter = 0;
pthread_mutex_t lock;

void* increment(void* arg) {
    for (int i = 0; i < 100000; i++) {
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_mutex_init(&lock, NULL);
    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);

    printf("Final counter value: %d\n", counter);
    return 0;
}
```

---

####  **4. Producer-Consumer using Condition Variables**

```c
#include <pthread.h>
#include <stdio.h>

int buffer = 0;
int full = 0;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void* producer(void* arg) {
    pthread_mutex_lock(&lock);
    while (full) {
        pthread_cond_wait(&cond, &lock);
    }
    buffer = 1; // Produce item
    printf("Produced item\n");
    full = 1;
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* consumer(void* arg) {
    pthread_mutex_lock(&lock);
    while (!full) {
        pthread_cond_wait(&cond, &lock);
    }
    buffer = 0; // Consume item
    printf("Consumed item\n");
    full = 0;
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, producer, NULL);
    pthread_create(&t2, NULL, consumer, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
```
---
#### Where `pthread` **is** used in Embedded:
In embedded C programming, `pthread` (POSIX Threads) is used for **multithreading**—enabling concurrent execution of code in separate threads. However, its usage depends heavily on the **operating system** or **RTOS** (Real-Time Operating System) being used in the embedded environment.

---

1. **Embedded Linux Systems**:

   * **Example**: Raspberry Pi, BeagleBone, or any embedded board running Linux.
   * `pthread` is available as part of the POSIX API provided by the Linux kernel.
   * Common use cases:

     * Concurrent sensor reading and data processing.
     * Separating UI and background processing threads.
     * Real-time control loops running independently from communication threads.

2. **RTOS with POSIX Support**:

   * Some RTOSes provide partial POSIX compliance and include support for `pthread`.
   * Examples:

     * **VxWorks**
     * **QNX**
     * **RTEMS** (Real-Time Executive for Multiprocessor Systems)
     * **ThreadX with POSIX layer**
   * In these, `pthread` APIs are used to make code portable across embedded Linux and RTOS platforms.

---

### ❌ Where `pthread` is **not** typically used:

* **Bare-metal programming** (no OS): You manually manage timing, interrupts, and task switching, so `pthread` is unavailable.
* **RTOS without POSIX support**: Systems like FreeRTOS or Zephyr may use their own threading APIs (e.g., `xTaskCreate()` in FreeRTOS) instead of `pthread`.

---


## **1. Process in C (Operating System Context)**

A **process** is an instance of a program in execution. In the context of C and operating systems (especially UNIX/Linux), processes are central to multitasking and resource management.

### **Creating and Managing Processes in C**

In C (especially on UNIX/Linux), processes are typically handled using system calls like:

* `fork()`
* `exec()` family (`execl()`, `execp()`, etc.)
* `wait()`
* `exit()`

### **Process Lifecycle in C**

1. **Parent Process**:
   This is the process that creates another process using `fork()`.

2. **Creating a Child Process**:

   ```c
   pid_t pid = fork();
   if (pid == 0) {
       // Child process code
   } else if (pid > 0) {
       // Parent process code
   } else {
       // Error occurred
   }
   ```

3. **Replacing Process Image (exec)**:

   * Used to replace the current process image with a new one.

   ```c
   execl("/bin/ls", "ls", NULL);
   ```

4. **Waiting for Child (wait)**:

   * Parent waits for child to finish.

   ```c
   wait(NULL);
   ```

5. **Process Termination**:

   * Done using `exit(status);`.

---

## **2. IPC (Inter-Process Communication)**

**IPC** refers to mechanisms that allow processes to communicate and synchronize their actions.

### **Types of IPC in UNIX/Linux**

| IPC Method              | Description                                                             |
| ----------------------- | ----------------------------------------------------------------------- |
| **Pipes**               | Unidirectional communication between related processes                  |
| **Named Pipes (FIFOs)** | Like pipes, but with a name and can be used between unrelated processes |
| **Message Queues**      | Allow messages to be sent between processes via a queue                 |
| **Shared Memory**       | Allows multiple processes to access the same memory region              |
| **Semaphores**          | Used to control access to shared resources (used with shared memory)    |
| **Sockets**             | Communication over a network or between unrelated processes             |
| **Signals**             | Asynchronous notifications sent to a process to notify events           |

---

### **Examples**

#### **1. Pipe Example**

```c
int fd[2];
pipe(fd); // create pipe
pid_t pid = fork();
if (pid == 0) {
    close(fd[0]); // close read
    write(fd[1], "Hello", 5);
} else {
    close(fd[1]); // close write
    char buffer[6];
    read(fd[0], buffer, 5);
    buffer[5] = '\0';
    printf("Received: %s\n", buffer);
}
```

#### **2. Shared Memory Example**

Using `shmget`, `shmat`, and `shmdt`:

```c
key_t key = ftok("shmfile",65);
int shmid = shmget(key,1024,0666|IPC_CREAT);
char *str = (char*) shmat(shmid,(void*)0,0);
strcpy(str,"Shared Memory Example");
shmdt(str);
```

---

### **Choosing the Right IPC**

* Use **pipes** or **FIFOs** for simple parent-child communication.
* Use **shared memory + semaphores** for high-speed communication with synchronization.
* Use **message queues** when you need structured message passing.
* Use **sockets** for network or distributed processes.

---

