# Interprocess communication (IPC)

Process
- A **process** is a program in execution
- A **program** is a file containing the information of a process
  - When you start execution of a program, it's loaded into RAM and starts executing
- Each process has its own address space and usually one thread of control
- You can have multiple processes executing the same program.
  - Each process has its own copy of the program
  - Each process has its own address space
  - It executes independently of the other copies.
- Processes are organized hierarchically
  - Each process has a parent process
  - A process created by a given parent process is called child process
  - A child process inherits many of its attributes from the parent process.
- A **system call (kernel call)** is a request that a program mekes for service of the kernel.
  - Usually only kernel has access to service.
  - GNU C Library functions do what the system calls do, so programmers do not need to be concerned with system calls
- Each process is identified with a unique positive integer called a **process ID (PID)**.
  - `getpid()`
  - `#include <sys/types.h>`
  - `#include <unistd.h>`
- A process can be of 2 types
  - Independent process
  - Co-operating process
- Interprocess communication lets processes work together.

```
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int mypid, myppid;
mypid = getpid();
myppid = getppid();
printf("Process ID: %d\n", mypid);
printf("Parent process ID: %d\n", myppid);
```

Interprocess communication
- If any process wants to communicate with some information from its own address space to other processes, it's only possible with IPC techniques
- Communication can be of 2 types
  - Between processes initiating from only one process, such as parent and child processes
  - Between unrelated processes of two or more different processes.
- Many different ways for a process to communicate with another process
  - **Pipes (same process)**
    - Allows flow of data in one direction (half duplex)
  - **Names pipes (different processes)**
    - One process can communicate with another process and vice cersa at the same time (full duplex)
  - **Message queues**
  - **Shared memory**
  - **Sockets**
    - Mainly used between 2 different computers over a network.
    - Between client and server
  - **Signals**
    - Source process will send a signal (number) to destination process

Pipes
- Can be thought of filling water with a pipe into a bucket
- The filling process is like writing into the pipe, and the reading process is like retrieving from the pipe
- Water is one outout, and bucket is input for the other
- Named pipe is also called FIFO
- System calls are used for creating and using pipes

Message queue
- The sending process places a message via OS message-passing module onto a queue which can be read by another process
- Each message is given an identification or type so that processes can select the appropriate message
- Process must share a common key to gain access to the queue
- System calls are used for creating and using message queues
- `ftok()`, `msgget()`, `msgsnd()`, `msgrcv()`, `msgctl()`

Shared memory
- Memory is shared between two or more processes
- `shmget()`, `shmat()`, `shmdt()`, `shmctl()`

Signal
- A notification to a process indicating the occurrence of an event
- Signal is a way to communicate information to a process about the state of other processes
- A process can receive a particular signal asynchronously
- There are fix set of signals that can be sent to a process defined by the operating system.
- A signal is a short message which contains a single integer value
- `SIGTERM` kill, terminate
- `Ctrl-c` is `SIGINT`
- `Ctrl-z` is `SIGTSTP`
- `fg` or `bg` is `SIGCONT`
- Whenever a signal is raised by program or system, a default action is performed for some signals
  - **Term** is terminate
  - **Core** terminates and produce a core dump file
  - **Ign** ignores the signal
  - **Stop** stop process like `Ctrl-z`
  - **Cont** the process will continue from being stopped
- `kill -l` lists signal names

Raising a signal
- `signal.h`
- `raise()` sends a signal to the current process
- `kill()` sends a signal to a specific process
- `alarm()` interrupt itself in future by a timer
  - `SIGALARM`
  - One alarm clock per process

Handling a signal
- Handle/catch, actions performed for signals
  - Default action
  - Handle the signal
  - Ignore the signal
- `SIGKILL`, `SIGABRT`, `SIGSTOP` cannot be ignored.
- `kill 9` is ultimate kill statement
- `signal()`
- `sigaction()`

fork system call
- Process creates a new process to run a different branch of the existing program
- `<unistd.h>` `fork()` system call creates a copy of itself.
- When a process calls fork, a child process has an exact copy of all the memory segments of the parent process.
- Fork operation creates a separate address space for the child.
- Updating a variable in one process will not affect the other.
- Child and parent processes run in parallel.