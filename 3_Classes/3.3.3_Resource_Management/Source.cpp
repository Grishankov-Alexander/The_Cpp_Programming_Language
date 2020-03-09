#include <vector>
#include <thread>


std::vector<std::thread> my_threads;

Vector init(int n)
{
	std::thread t{ heartbeat };  // run heartbeat concurrently
	my_threads.push_back(std::move(t));  // move t into my_threads
	// ... more initialization ...
	Vector vec(n);
	for (int i = 0; i < vec.size(); ++i)
		vec[i] = 777;
	return vec;  // move vec out of init()
}

auto v = init(999999);  // start heartbeat and initialize v