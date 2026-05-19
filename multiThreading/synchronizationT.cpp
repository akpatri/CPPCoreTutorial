/*
Multithreading Synchronization Reference

Synchronization:
    Technique used to safely access shared resources between threads.

Race Condition:
    Multiple threads accessing/modifying shared data simultaneously causing unpredictable result.

Critical Section:
    Code region accessing shared resource.

std::mutex:
    Mutual exclusion lock allowing only one thread at a time.

void lock(): locks mutex, thread waits if already locked

void unlock(): releases mutex

bool try_lock(): tries locking mutex without blocking, returns true on success

std::lock_guard<mutex>:
    RAII wrapper automatically locking/unlocking mutex.

lock_guard(mutex& m): locks mutex immediately and unlocks automatically at scope end

std::unique_lock<mutex>:
    Flexible mutex wrapper supporting manual lock/unlock, move semantics and condition_variable.

unique_lock(mutex& m): locks mutex immediately

void lock(): manually locks mutex

void unlock(): manually unlocks mutex

bool owns_lock(): checks ownership of mutex

condition_variable:
    Thread signaling mechanism used for waiting and notification between threads.

void wait(unique_lock<mutex>& lock): suspends thread until notified

void notify_one(): wakes one waiting thread

void notify_all(): wakes all waiting threads

Important:
- mutex prevents race condition
- lock_guard simplest and safest locking mechanism
- unique_lock more flexible than lock_guard
- condition_variable requires unique_lock
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;

mutex mtx; // protects shared resource

condition_variable cv; // thread signaling object

int sharedCounter = 0; // shared data between threads

bool ready = false; // synchronization flag

// race condition example without synchronization
void unsafeIncrement()
{
    for (int i = 0; i < 100000; i++)
    {
        sharedCounter++; // unsafe shared access
    }
}

// mutex lock/unlock example
void safeIncrement()
{
    for (int i = 0; i < 100000; i++)
    {
        mtx.lock(); // acquire mutex lock

        sharedCounter++; // protected critical section

        mtx.unlock(); // release mutex
    }
}

// lock_guard example
void lockGuardExample()
{
    lock_guard<mutex> lock(mtx); // creates lock_guard object and immediately locks mtx, mutex automatically unlocked when lock object goes out of scope, safest RAII-style mutex handling

    cout << "lock_guard thread\n"; // protected critical section, only one thread can execute this section while mutex locked

} // lock_guard destructor automatically unlocks mutex here, manual unlock() not possible with lock_guard

// unique_lock example
void uniqueLockExample()
{
    unique_lock<mutex> lock(mtx); // creates unique_lock object and immediately locks mtx, unlike lock_guard it supports manual lock/unlock operations

    cout << "unique_lock acquired\n"; // critical section protected by mutex, only one thread can execute this section at a time

    lock.unlock(); // manually releases mutex before scope ends, other waiting threads can now acquire mutex

    cout << "mutex released\n"; // this line executes without mutex protection because mutex already unlocked

    lock.lock(); // locks mutex again manually, thread blocks here if another thread currently owns mutex

    cout << "mutex locked again\n"; // mutex protection restored for this critical section

} // unique_lock destructor automatically unlocks mutex if still locked

// try_lock example
void tryLockExample()
{
    if (mtx.try_lock()) // attempts to lock mutex without blocking, returns true immediately if mutex free otherwise false if already locked by another thread
    {
        cout << "try_lock success\n"; // this thread successfully acquired mutex and entered protected critical section

        mtx.unlock(); // manually releases mutex so other waiting threads can acquire it
    }
    else
    {
        cout << "mutex busy\n"; // mutex already owned by another thread so current thread could not enter critical section
    }
}

// producer thread
void producer()
{
    this_thread::sleep_for(chrono::seconds(2)); // pauses producer thread for 2 seconds simulating delayed work or data preparation

    unique_lock<mutex> lock(mtx); // locks mutex using unique_lock because condition_variable requires unique_lock not lock_guard

    ready = true; // shared synchronization flag updated indicating data/resource now ready for consumer thread

    cout << "producer ready\n"; // producer completed work and updated shared state

    lock.unlock(); // manually unlock mutex before notification allowing waiting thread to acquire mutex immediately after wakeup

    cv.notify_one(); // wakes one thread waiting on condition_variable cv
}

// consumer thread
void consumer()
{
    unique_lock<mutex> lock(mtx); // locks mutex protecting shared variable ready during wait/check operations

    cv.wait(lock, []() // thread sleeps here until notified and lambda condition becomes true
            {
                return ready; // predicate repeatedly checked after wakeup preventing false wakeup/spurious wakeup issues
            });

    cout << "consumer proceeding\n"; // executes only after producer sets ready=true and sends notification
}

int main()
{
    // race condition demo
    thread t1(unsafeIncrement);
    thread t2(unsafeIncrement);

    t1.join();
    t2.join();

    cout << "unsafe counter = "
         << sharedCounter
         << endl;

    // synchronized demo
    sharedCounter = 0;

    thread t3(safeIncrement);
    thread t4(safeIncrement);

    t3.join();
    t4.join();

    cout << "safe counter = "
         << sharedCounter
         << endl;

    // lock_guard example
    thread t5(lockGuardExample);

    t5.join();

    // unique_lock example
    thread t6(uniqueLockExample);

    t6.join();

    // try_lock example
    thread t7(tryLockExample);

    t7.join();

    // condition_variable example
    thread producerThread(producer);

    thread consumerThread(consumer);

    producerThread.join();

    consumerThread.join();

    return 0;
}