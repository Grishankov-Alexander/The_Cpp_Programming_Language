#include <chrono>
#include <thread>
#include <iostream>
using namespace std::chrono;

int main()
{
	auto t0 = high_resolution_clock::now();
	std::this_thread::sleep_for(milliseconds{ 1000 });
	auto t1 = high_resolution_clock::now();
	long duration = duration_cast<milliseconds>(t1 - t0).count();
	std::cout << duration << " msec\n";
}