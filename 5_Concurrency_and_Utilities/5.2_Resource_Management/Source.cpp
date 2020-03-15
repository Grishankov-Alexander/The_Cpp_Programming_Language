#include <memory>
#include <mutex>
using namespace std;


// A thread will not proceed until lck’s constructor has acquired its mutex, m
// unique_lock’s destructor releases the mutex when the thread of control leaves f()
mutex m;  // used to protect access to shared data
void f()
{
	unique_lock<mutex> lck{ m };  // acquire the mutex m
	// ... manipulate shared data
}