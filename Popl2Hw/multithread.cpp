#include <iostream>
#include <thread>
#include <chrono>
#include <omp.h>
using namespace std;

int result[100];
int a[100], b[100];

void adder(int i) {
	for (int j = i; j < 100; j = j + 2) {
		result[j] = a[j] + b[j];
	}
}

void print_result() {
	cout << "The result array" << endl;
	for (int i = 0; i < 100; i++) {
		cout << result[i] << endl;
	}
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

	std::thread threads[2];
	auto start1 = chrono::steady_clock::now();
	for (int i = 0; i < 2; i++) {
		threads[i] = std::thread(adder, i);
	}
	for (auto &th : threads) th.join();
	auto end1 = chrono::steady_clock::now();
	

	cout << "Time for parallel  :" << chrono::duration_cast<chrono::microseconds>(end1 - start1).count() << endl;

	auto start2 = chrono::steady_clock::now();
#pragma omp parallel for
	{
		for (int i = 0; i < 100; i++) {
			result[i] = a[i] + b[i];
		}
	}

	auto end2 = chrono::steady_clock::now();

	cout << "Time by openMp :" << chrono::duration_cast<chrono::microseconds>(end2 - start2).count() << endl;

	//print_result();

	system("pause");
	return 0;
	
}