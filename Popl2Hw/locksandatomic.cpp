#include<iostream>
#include<thread>
#include<chrono>
#include<mutex>
using namespace std;

std::mutex mx;

int a = 2;
int y;


void print_thread(int id) {
	//mx.lock();
	cout << endl;
	cout <<"I am currently thread number id :" << id << endl;
	a++;
	/*if u comment the below cout line then the value of y will be 0 else possibly 6 due to race conditions*/
	//cout << "value of a = " << a << endl;
	if (a == 3) {

		y = a * 2;
	}
	/*if (id == 0) {
		cout << "going to sleep :)" << endl;
		std::this_thread::sleep_for(2s);
	}*/
	cout << "Exiting the thread with id ::" << id << endl;
	//mx.unlock();
}

int main() {
	std::thread threads[2];
	for (int i = 0; i < 2; i++) {
		threads[i] = std::thread(print_thread, i);
	}
	for (auto &th : threads) th.join();
	cout << "The value of y is :" << y << endl;
	system("pause");
	return 0;
}