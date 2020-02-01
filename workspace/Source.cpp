#include <iostream>
#include <string>

using namespace std;

int main() {
	int i = 1;
	int j = 10;
	cin >> i >> j;

	int max_cycles = 1;

	int current_cycles = 1;
	for (int k = i; k <= j; ++k) {
		current_cycles = 1;
		int num_to_check = k;

		while (num_to_check != 1) {
			if (num_to_check % 2 == 1) {
				num_to_check = 3 * num_to_check + 1;
			}
			else {
				num_to_check = num_to_check / 2;
			}
			current_cycles++;
		}

		if (current_cycles > max_cycles) {
			max_cycles = current_cycles;
		}
	}

	cout << i << " " << j << " " << max_cycles << endl;
	return 0;
}
