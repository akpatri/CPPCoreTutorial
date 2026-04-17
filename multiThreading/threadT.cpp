#include <iostream>
#include <thread>
using namespace std;

// sample function for thread
void work() {
    cout << "Thread running\n";
}

int main()
{
    // ============================================================
    // 🔷 CONSTRUCTOR
    // creates and starts a thread immediately
    // ============================================================
    thread t1(work);   // starts execution of work()


    // ============================================================
    // 🔷 MEMBER TYPES
    // ============================================================

    thread::id id = t1.get_id();  
    // unique identifier of thread (used for comparison/logging)

    thread::native_handle_type nh = t1.native_handle();  
    // OS-level handle (platform dependent, rarely used directly)


    // ============================================================
    // 🔷 JOINABLE
    // checks if thread is associated with execution
    // true → must call join() or detach()
    // ============================================================
    if (t1.joinable()) {
        cout << "Thread is joinable\n";
    }


    // ============================================================
    // 🔷 JOIN
    // waits for thread to finish (blocking call)
    // after join → thread becomes non-joinable
    // ============================================================
    t1.join();


    // ============================================================
    // 🔷 DETACH
    // separates thread from object (runs independently)
    // ⚠️ no control after detach (danger if misused)
    // ============================================================
    thread t2(work);
    t2.detach();   // runs in background


    // ============================================================
    // 🔷 MOVE ASSIGNMENT (operator=)
    // threads are NON-COPYABLE but MOVEABLE
    // ============================================================
    thread t3(work);
    thread t4 = move(t3);   // ownership transferred


    // ============================================================
    // 🔷 SWAP (member)
    // exchange thread ownership
    // ============================================================
    thread t5(work);
    thread t6(work);
    t5.swap(t6);


    // ============================================================
    // 🔷 NATIVE HANDLE
    // gives underlying OS handle (advanced usage)
    // ============================================================
    auto handle = t5.native_handle();


    // ============================================================
    // 🔷 HARDWARE CONCURRENCY (static)
    // number of concurrent threads supported by system
    // hint only (may return 0 if unknown)
    // ============================================================
    unsigned int cores = thread::hardware_concurrency();
    cout << "Cores: " << cores << endl;


    // ============================================================
    // 🔷 NON-MEMBER SWAP
    // same as member swap
    // ============================================================
    swap(t5, t6);


    // ============================================================
    // 🔥 DESTRUCTOR (IMPORTANT RULE)
    // if thread is still joinable → program TERMINATES
    // MUST call join() or detach() before destruction
    // ============================================================

    if (t4.joinable()) t4.join();
    if (t5.joinable()) t5.join();
    if (t6.joinable()) t6.join();

    return 0;
}