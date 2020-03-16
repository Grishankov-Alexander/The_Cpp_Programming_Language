#include <thread>
#include <mutex>
using namespace std;


mutex m;  // controlling mutex
int sh;  // shared data

void f()
{
	unique_lock<mutex> lck{ m };  // acquire mutex
	sh += 7;  // manipulate shared data
}  // release mutex implicitly

class Record {
public:
	// mutex that you are supposed to acquire before accessing the other data
	mutex rm;
	// ...
};

// acquiring several locks simultaneously:
void f()
{
	// defer_lock: don't yet try to acquire the mutex
	unique_lock<mutex> lck1{ m1, defer_lock };
	unique_lock<mutex> lck2{ m2, defer_lock };
	unique_lock<mutex> lck3{ m3, defer_lock };
	// ...
	lock(lck1, lck2, lck3);  // acquire all 3 locks
	// ... manipulate shared data
}  // implicitly release all mutexes