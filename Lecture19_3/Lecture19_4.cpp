//#include <iostream>
//#include <string>
//#include <thread>
//#include <chrono>
//#include <mutex>
//#include <atomic>
//
//using namespace std;
//
//mutex mtx;
//
//int main()
//{
//	//atomic<int>	shared_memory(0);
//	int	shared_memory(0);
//
//	auto num_thread = thread::hardware_concurrency();
//	
//	auto count_func = [&]() {
//		for (int i = 0; i < 1000; ++i)
//		{
//			this_thread::sleep_for(chrono::milliseconds(1));
//			//mtx.lock();
//			std::scoped_lock lock(mtx);
//			//shared_memory++;
//			//mtx.unlock();
//		}
//	};
//
//	thread t1 = thread(count_func);
//	thread t2 = thread(count_func);
//	t1.join();
//	t2.join();
//	
//	cout << "After " << endl;
//	cout << shared_memory << endl;
//
//	return (0);
//}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <mutex>
#include <atomic>

using namespace std;

mutex mtx;

int main()
{
	//atomic<int>	shared_memory(0);
	int	shared_memory(0);

	auto num_thread = thread::hardware_concurrency();

	auto count_func = [&]() {
		for (int i = 0; i < 1000; ++i)
		{
			this_thread::sleep_for(chrono::milliseconds(1));
			//mtx.lock();
			std::scoped_lock lock(mtx);
			//shared_memory++;
			//mtx.unlock();
		}
	};

	thread t1 = thread(count_func);
	thread t2 = thread(count_func);
	t1.join();
	t2.join();

	cout << "After " << endl;
	cout << shared_memory << endl;

	return (0);
}