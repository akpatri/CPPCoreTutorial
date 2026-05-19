/*
std::thread complete reference

std::thread(): creates empty non-joinable thread object, returns std::thread object

std::thread(callable, args...): creates and starts new thread immediately, callable can be function/lambda/functor/member-function, returns std::thread object

bool joinable(): checks whether thread owns execution thread, returns true if active otherwise false

void join(): waits for thread completion, blocking operation, returns void

void detach(): separates thread from thread object and runs independently, returns void

std::thread::id get_id(): returns unique thread identifier

native_handle_type native_handle(): returns underlying OS thread handle

static unsigned int hardware_concurrency(): returns supported concurrent thread count hint

void swap(thread& other): exchanges ownership with another thread object

swap(thread& t1, thread& t2): non-member function exchanging ownership of two threads

std::this_thread::get_id(): returns current running thread id

std::this_thread::sleep_for(duration): suspends current thread for specified duration

std::this_thread::yield(): hints scheduler to run another thread

Important:
- std::thread is non-copyable but movable
- thread starts immediately after construction
- thread must be join()ed or detach()ed before destruction
- destroying joinable thread calls std::terminate()
*/

#include <iostream>      // cout
#include <thread>        // std::thread
#include <chrono>        // sleep_for()
#include <functional>    // ref()
#include <utility>       // move()

using namespace std;

// normal thread function
void normalFunction()
{
    cout << "normal thread\n";
}

// function with argument
void printNumber(int number)
{
    cout << "number = "
         << number
         << endl;
}

// function using reference
void increment(int &value)
{
    value++;

    cout << "incremented = "
         << value
         << endl;
}

// class with member function
class Worker
{
public:

    void memberTask()
    {
        cout << "member thread\n";
    }
};



int main()
{
    // default constructor -> empty non-joinable thread
    thread t0;

    cout << "t0 joinable = "
         << t0.joinable()
         << endl;


    // normal function thread
    thread t1(normalFunction);


    // thread with arguments
    thread t2(
        printNumber,
        100);


    // lambda thread
    thread t3([]()
    {
        cout << "lambda thread\n";
    });



    // member function thread
    Worker worker;

    thread t5(
        &Worker::memberTask, // member function pointer
        &worker); // object instance


    // pass by reference using ref()
    int value = 10;

    thread t6(
        increment,
        ref(value));


    // unique thread id
    cout << "t1 id = "
         << t1.get_id()
         << endl;


    // check if thread owns execution
    cout << "t1 joinable = "
         << t1.joinable()
         << endl;


    // underlying OS thread handle
    auto handle =
        t1.native_handle();

    (void)handle;


    // supported concurrent threads by CPU
    unsigned int cores =
        thread::hardware_concurrency();

    cout << "cores = "
         << cores
         << endl;


    // move constructor
    thread t7(normalFunction);

    thread t8(
        move(t7)); // ownership transferred

    cout << "t7 joinable = "
         << t7.joinable()
         << endl;

    cout << "t8 joinable = "
         << t8.joinable()
         << endl;


    // move assignment
    thread t9(normalFunction);

    thread t10;

    t10 = move(t9);


    // member swap()
    thread t11(normalFunction);

    thread t12([]()
    {
        cout << "swap thread\n";
    });

    t11.swap(t12); // exchange ownership


    // non-member swap()
    swap(t11, t12);


    // detached thread
    thread detachedThread([]()
    {
        cout << "detached thread start\n";

        this_thread::sleep_for(
            chrono::seconds(1));

        cout << "detached thread end\n";
    });

    detachedThread.detach(); // independent background execution


    // current thread id
    cout << "main thread id = "
         << this_thread::get_id()
         << endl;


    // pause current thread
    this_thread::sleep_for(
        chrono::milliseconds(500));

    cout << "main resumed\n";


    // hint scheduler to switch thread
    this_thread::yield();


    // join threads before destruction
    if (t1.joinable()) t1.join();

    if (t2.joinable()) t2.join();

    if (t3.joinable()) t3.join();

    //if (t4.joinable()) t4.join();

    if (t5.joinable()) t5.join();

    if (t6.joinable()) t6.join();

    if (t8.joinable()) t8.join();

    if (t10.joinable()) t10.join();

    if (t11.joinable()) t11.join();

    if (t12.joinable()) t12.join();


    // final reference value
    cout << "final value = "
         << value
         << endl;

    return 0;
}