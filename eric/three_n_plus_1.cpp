#include <iostream>
#include <unordered_map>

using namespace std;

int three_n_plus_1(int n, unordered_map<int, int>& cache) {
	if (n == 1) {
		return 1;
	}

	if (cache.count(n) != 0) {
		return cache[n];
	}

	if (n % 2 == 1) {
		cache[n] = 1 + three_n_plus_1(3 * n + 1, cache);
	}
	else {
		cache[n] = 1 + three_n_plus_1(n / 2, cache);
	}

	return cache[n];
}

int max_cycle_length(int start, int end) {
	int max = 0;
	unordered_map<int, int> cache;

	for (int i = start; i <= end; ++i) {
		if (three_n_plus_1(i, cache) > max) {
			max = three_n_plus_1(i, cache);
		}
	}

	return max;
}

int main()
{
	int num_pairs;
	cout << "enter the number of pairs" << endl;
	cin >> num_pairs;


	for (int i = 0; i < num_pairs; ++i) {
		int start, end;
		cout << "enter start" << endl;
		cin >> start;
		cout << "enter end" << endl;
		cin >> end;
		cout << max_cycle_length(start, end) << endl;
	}

	return 0;
}