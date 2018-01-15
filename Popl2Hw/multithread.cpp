#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

int result[100];
int a[100], b[100];

void adder(int i) {
	result[i] = a[i] + b[i];
}


int main() {

	for (int i = 0; i < 100; i++) {
		a[i] = i;
		b[i] = i;
	}

	auto start = chrono::steady_clock::now();

	for (int i = 0; i < 100; i++) {
		result[i] = a[i] + b[i];
	}

	auto end = chrono::steady_clock::now();
	
	cout << "Time for sequential  :" << chrono::duration_cast<chrono::microseconds>(end - start).count() << endl;

	std::thread threads[100];
	auto start1 = chrono::steady_clock::now();
	for (int i = 0; i < 100; i++) {
		threads[i] = std::thread(adder, i);
	}
	for (auto &th : threads) th.join();
	auto end1 = chrono::steady_clock::now();
	

	cout << "Time for parallel  :" << chrono::duration_cast<chrono::microseconds>(end1 - start1).count() << endl;
	cout << "The End" << endl;


	system("pause");
	return 0;
	
}