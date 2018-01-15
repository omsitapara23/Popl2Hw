#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

std::mutex mx;
int a;

void print_thread_id(int id) {
	//mx.lock();
	a = id;
	//mx.unlock();
}

int main() {
	std::thread threads[10];
	for (int i = 0; i<10; ++i)
		threads[i] = std::thread(print_thread_id, i + 1);

	for (auto& th : threads) th.join();
	cout << a << endl;
	system("pause");

	return 0;
}