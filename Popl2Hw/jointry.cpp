#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void foo()
{
	// simulate expensive operation
	std::cout << "foo" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
}

void bar()
{
	// simulate expensive operation
	std::cout << "bar" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
}

int main_1()
{
	std::cout << "starting first helper...\n";
	std::thread helper1(foo);

	std::cout << "starting second helper...\n";
	std::thread helper2(bar);

	std::cout << "waiting for helpers to finish..." << std::endl;
	helper1.join();
	helper2.join();

	std::cout << "done!\n";

	system("pause");
	return 0;
}