# Philosophers :

---

<p align="center">
<img src=https://github.com/Pix31P33p3r/Philosophers/blob/main/philosophersm.png width="150" height="150"/>
</p>

---
<p align="center">
<img src="https://upload.wikimedia.org/wikipedia/commons/4/49/%22The_School_of_Athens%22_by_Raffaello_Sanzio_da_Urbino.jpg" width="500">
</p>

In computer science, [The Dining Philosopher Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem) is an example problem often used in concurrent algorithm design to illustrate synchronization issues and techniques for resolving them.

---

### What is Philosophers ?

---

Philosophers is an individual project at 1337 school that requires us to solve [The Dining Philosopher Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem) problem using threads, processes, mutex and semaphores.
The mandatory part must be solved using [threads](https://man7.org/linux/man-pages/man7/pthreads.7.html) and [mutex](https://www.unix.com/man-page/linux/5/mutex/). The solution was implemented using a monitoring thread, which checks if any philosopher has died and warns others to stop ([locking mutex](https://linux.die.net/man/3/pthread_mutex_lock)).
The bonus consists of using [processes](https://stackoverflow.com/questions/200469/what-is-the-difference-between-a-process-and-a-thread#:~:text=A%20process%20is%20a%20collection,concurrently%20within%20the%20same%20process.) instead of threads and [semaphores](https://man7.org/linux/man-pages/man7/sem_overview.7.html) instead of mutex, to solve it the solution used was to implement the death check between the [sleeping](https://man7.org/linux/man-pages/man3/usleep.3.html) times, avoiding the problem of reporting the death of a philosopher with more than 10ms.

---

#### Problem :

---

<p>
<img src=https://github.com/Pix31P33p3r/Philosophers/blob/main/dining_philosophers_problem.png align="right" width="200px"/>
The problem was proposed by <a href="https://pt.wikipedia.org/wiki/Edsger_Dijkstra">Edsger W. Dijkstra</a> in 1965 and is considered one of the classic problems about operating systems.
The problem consists of five philosophers sitting around a circular dinner table, where each philosopher has a plate for eating spaghetti and a fork to his right. To eat they need 2 forks but there is only one fork between each pair of plates. A philosopher has three actions: eating, thinking, or sleeping. When a philosopher gets hungry he will try to take the fork to his right and to his left, one at a time. If he manages to get both forks, he will eat the food at a certain time and will put the forks on the table, going to sleep and then going to think again.
</p>

---

#### Arguments :

---

All arguments working with mandatory and bonus

<table>
    <thead>
        <tr>
            <th colspan=5><h4>Arguments Usage</h4></th>
        </tr>
        <tr>
            <th>#1</th>
            <th>#2</th>
            <th>#3</th>
            <th>#4</th>
            <th>#5</th>
        </tr>
        <tr>
            <td align="center">5</td>
            <td align="center">800</td>
            <td align="center">200</td>
            <td align="center">200</td>
            <td align="center">10</td>
        </tr>
        <tr>
            <td align="center"><strong>number_of_philosophers</strong></strong></td>
            <td align="center"><strong>time_to_die</strong></td>
            <td align="center"><strong>time_to_eat</strong></td>
            <td align="center"><strong>time_to_sleep</strong></td>
            <td align="center"><strong>*number_of_times_each_must_eat</strong></td>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td colspan=5>*The last argument, <strong>number_of_times_each_must_eat</strong> is optional.</td>
		 </tr>
    </tbody>
</table>

---

#### Allowed functions :

---

name  | prototype | description |
---|------|------|
[**usleep**](https://man7.org/linux/man-pages/man3/usleep.3.html) | int usleep(useconds_t usec); |shall cause the calling thread to be suspended from execution until either the number of realtime microseconds specified by the argument useconds has elapsed or a signal is delivered to the calling thread and its action is to invoke a signal-catching function or to terminate the process. The suspension time may be longer than requested due to the scheduling of other activity by the system.			|
[**gettimeofday**](https://c-for-dummies.com/blog/?p=4236) | int gettimeofday( struct timeval *, struct tzp * ); | fills two structures with details about the current time of day	|
[**pthread_create**](https://man7.org/linux/man-pages/man3/pthread_create.3.html) | int pthread_create(pthread_t * restrict thread, const pthread_attr_t * restrict attr, void *(* start_routine)(void *), void * restrict arg);| create a new thread |
[**pthread_detach**](https://man7.org/linux/man-pages/man3/pthread_detach.3.html) | int pthread_detach(pthread_t thread); | marks the thread identified by thread as detached.  When a detached thread terminates, its resources are automatically released back to the system without    the need for another thread to join with the terminated thread. Attempting to detach an already detached thread results in unspecified behavior.|
[**pthread_join**](https://man7.org/linux/man-pages/man3/pthread_join.3.html) | int pthread_join(pthread_t thread, void ** retval); | join with a terminated thread. The function waits for the thread specified by thread to terminate.  If that thread has already terminated, then      pthread_join() returns immediately.  The thread specified by thread must be joinable. |
[**pthread_mutex_init**](https://pubs.opengroup.org/onlinepubs/7908799/xsh/pthread_mutex_init.html) | int pthread_mutex_init(pthread_mutex_t * mutex, const pthread_mutexattr_t * attr); | initialises the mutex referenced by mutex with attributes specified by attr. If attr is NULL, the default mutex attributes are used; the effect is the same as passing the address of a default mutex attributes object. Upon successful initialisation, the state of the mutex becomes initialised and unlocked.	|
[**pthread_mutex_destroy**](https://pubs.opengroup.org/onlinepubs/7908799/xsh/pthread_mutex_init.html) | int pthread_mutex_destroy(pthread_mutex_t * mutex); |destroys the mutex object referenced by mutex; the mutex object becomes, in effect, uninitialised.|
[**pthread_mutex_lock**](https://pubs.opengroup.org/onlinepubs/7908799/xsh/pthread_mutex_lock.html) | int pthread_mutex_lock(pthread_mutex_t * mutex); | locks the object referenced by mutex. If the mutex is already locked, the calling thread blocks until the mutex becomes available. This operation returns with the mutex object referenced by mutex in the locked state with the calling thread as its owner			|
[**pthread_mutex_unlock**](https://pubs.opengroup.org/onlinepubs/7908799/xsh/pthread_mutex_lock.html) | int pthread_mutex_unlock(pthread_mutex_t * mutex); |releases the mutex object referenced by mutex.	|

---

## Study resources :

---

* [Unix Threads in C -playlist](https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2) by CodeVault
* [Multi Threaded Programming Video](https://www.youtube.com/watch?v=OgnLaXwLC8Y) by Arif Butt
* [Synchronization among Threads Video](https://www.youtube.com/watch?v=SvFr7rPWI3g&list=PL7B2bn3G_wfC-mRpG7cxJMnGWdPAQTViW&index=47) by Arif Butt
* [Multithreaded Programming](https://randu.org/tutorials/threads/)
* [ASCIImoji](http://asciimoji.com/)

---
