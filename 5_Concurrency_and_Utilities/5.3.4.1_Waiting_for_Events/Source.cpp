#include <mutex>
#include <chrono>
#include <thread>
#include <condition_variable>
#include <iostream>
#include <queue>
using namespace std;


void time_passing()
{
	using namespace std::chrono;
	auto t0 = high_resolution_clock::now();
	this_thread::sleep_for(milliseconds{ 20 });
	auto t1 = high_resolution_clock::now();
	cout << duration_cast<nanoseconds>(t1 - t0).count();
	cout << " nanoseconds passed\n";
}

// classical example of two threads communicating by
// passing messages through a queue
class Message {  // object to be communicated
	// ...
};

queue<Message> mqueue;  // the queue of messages
condition_variable mcond;  // the variable communicating events
mutex mmutex;  // the locking mechanism

void consumer()
{
	while (true) {
		unique_lock<mutex> lck{ mmutex };  // acquire mutex
		// release lck and wait
		while (mcond.wait(lck)) /* do nothing */;
		// re-acquire lck upon wakeup
		auto m = mqueue.front();  // get the message
		mqueue.pop();
		lck.unlock();  // release lck
		// ... process m
	}
}

void producer()
{
	while (true) {
		Message m;
		// ... fill the message
		unique_lock<mutex> lck{ mmutex };  // protect operations
		mqueue.push(m);
		mcond.notify_one();  // notify
	}  // release lock (at end of scope)
}