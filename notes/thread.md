# Thread

Overview
- `main()` function is the single path of execution sequentially, line by line.
- Creating multiple processes by fork is not efficient
  - Cannot share data easily.
  - Code will be messay
- **Thread** allows you to start a separate task quickly and share current data.
- Threads are a way to divide a single process into sub-runnable parts
  - A separate path of execution inside a program
  - Called **lightweight processes**.
- A thread has its own unique ID, program counter (PC), a register set, and a stack space just like a process.
- Threads share memory across each thread by having the same address space.
- Several threads living inside the same process (program).
  - Each thread runs independently (**a thread of execution**)
- In a browser, multiple tabs can be dofferent threads
- Advantage
  - Less overhead than forking or spawning a new process, because the system doesn't initialize a new virtual memory space and environment
  - Efficient communication and dat exchange by the same address space
  - Creating of a thread is faster
  - Faster context switching
  - Faster termination of a thread
- Disadvantage
  - The potential for two or more threads attempting to access the same data at the same time in thread synchronization

C Multi-threading
- C is a language that runs on one thread by default by `main`
  - The code will only run one instruction at a time
- C doesn't contain any built-in support for multithreaded applications
- In 1995, POSIX became the standard interface for many system calls in UNIX including the threading environment
- **pthreads (POSIX threads)** is the standard multi-thread implementation available with the gcc compiler
  - pthread is the key model for programming with threads in python and JAVA.

pthread (POSIX thread) library
- A standard based thread API for C/C++
- Most effective on multi-processor or multi-core systems
- A thread is spawned by defining a function and it's arguments which will be processed in the thread.
- The purpose of using pthread is to execute software faster
- pthread functions are defined in `pthread.h` header/include file and implemented in a thread library

pthreads API
- pthreads API can be grouped into 3 major categories
  - Thread management
    - Creating, detaching, joining
  - Synchronization
    - Manage read/write locks, mutex functions for creating, destroying, locking
  - Condition variables
    - Address communications between threads that share a mutex.
- Threads are created with a **starting function** as the entry point.
  - `pthread_create`
  - `pthread_join` identifies when a thread has completed or exited.
    - A join is performed when one wants to wait for a thread to finish.
  - `pthread_exit`
    - threads can be terminated in many ways
      - Explicitly calling `pthread_exit`
      - Letting the thread function return
      - Calling the function exit
    - Typically, `pthread_exit()` is a routine to be called after a thread has completed its work and is no longer required to exist.
    - It's a good practice to call `pthread_exit()` at the end of the thread function, although it's not explicitly required.

Passing arguments to threads
- `pthread_create()` permits the programmer to pass one arguments
  - If multiple arguments, create **structure** containing arguments and pass a **pointer to the structure** in `pthread_create()`
  - All argument must be cast to `(void *)`

Common thread functions
- `pthread_self()` gets current thread ID
- `pthread_detach(<pthread-id>)`
  - When a thread is created, it's either joinable or detached.
  - By default, thread is joinable
  - If a thread is created as detached, it can never be joined
  - Consider creating it in a detached state, if you know in advance that a thread will never need to join with another thread
    - To detach the initial thread in processes that set up server threads
- `pthread_attr_getstacksize()`, `pthread_attr_setstacksize()` avoid stack overflow
- `pthread_equal()` compares 2 thread IDs
- `pthread_once()` executes the `init_routine` exactly once in a process.
- `pthread_cancel()`

Stack management
- The POSIX standard doesn't dictate the size of a thread's stack
- Exceeding the default stack limit is easy to do, resulting in termination and corrupted data
- But safe and portable programs should not depend on the default stack limit
  - **Explicitly allocate enough stack for each thread by using `pthread_attr_setstacksize` function.

Synchronization
- Goal is to write thread safe code
- **Thread synchronization is the concurrent execution of two or more threads that share critical resources**.
  - Race conditions
  - Deadlocks
- Race conditions
  - The code looks in the order you wish to execute, but the threads are scheduled by OS and executed at random
    - Cannot assume that threads are executed in the order they are created
    - Threads are executing (**racing to complete**)
  - Race condition occurs when two or more threads perform operations on the same memory area.
- Deadlocks
  - Deadlocks occur when multiple threads access a shared resource, and preventing each other from accessing this resource
  - Causes program execution to halt indefinitely.
  - Occur when one thread locks a resource and never unlocks that resource.
- **Thread safe code** manipulates shared data structures in a manner that ensures that all threads behave properly without unintended interaction.
- **Critical section of code** is code that contains a shared resource and is accessible by multiple processes or threads
- **Mutual exclusion** is when a process or a thread is prevented simultaneous access to a critical section
  - Mutual exclusion is the method of serializing access to shared resources.
- 3 synchronization mechanisms by `pthread.h`
  - mutexes - locks, block access to variables by other threads
  - joins - makes a thread wait till others are complete
  - condition variables - a way to communicate to other threads

Mutex
- **Mutex** is a lock
- Anytime a global resource is accessed by more than one thread, the resource should have a mutex associated with it
- First gain the lick, access the shared resource, unlock the mutex
- Often, the action by a thread owning a mutex is updating global variables
- Mutex variable is declared with type `pthread_mutex_t`
  - `pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;` macro to statically initialize.
  - `pthread_mutex_init(<mutex>, <mutex-attribute>)` to dynamically initialize
    - To specify default attributes, pass `NULL` as the second parameter
- `pthread_mutex_destroy(<mutex>)` to free a mutex object no longer needed
- `pthread_mutex_lock(<mutex>)` locks. If the mutex is already locked by another thread, it blocks (meaning program waits)
- `pthread_mutex_trylock(<mutex>)` locks. If the mutex is already locked by another thread, it doesn't blocks
- `pthread_mutex_unlock(<mutex>)` unlocks

Atomic operation
- Allows for concurrent algorithms and access to certain shared data types **without using mutexes**.

Condition variable
- **Condition variables** allow threads to synchronize based upon the actual value of data.
- Without condition variables, threads need to continually poll to check if a condition is met
  - It can consume too much resource because thread would be continuously busy
- Condition variables allow threads to suspend execution and relinquish the processor until some condition is true.
- **Condition variable must always be associated with a mutex**.
- Caller thread must first hold the mutex lock that is associated with that condition variable.
- `pthread_cond_t` is type for condition variables
- `pthread_cond_init()` dynamically creates
- `pthread_cond_t cond = PTHREAD_COND_INITIALIZER;` statically declares
- `pthread_cond_destroy()`
- `pthread_cond_wait` makes thread to sleep on the condition variable condition and **release the mutex lock**
  - Guaranteeing that when it wakes up, the tread will hold the mutex lock
- `pthread_cond_signal`
- `pthread_cond_broadcast` wakes up all threads blocked by a specified condition variable.
- Make thread wait
- Notify thread to wake up
- Broadcast

