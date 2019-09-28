#include <iostream>
#include <random>
#include <vector>
#include <numeric>
#include <fstream>

//Create five rows and five columns of randomly generated numbers following bingo card guidlines.

int main() {

	std::ofstream outFile;
	outFile.open("randomNumbers.csv");

	std::vector<int> a(15), b(15), c(15), d(15), e(15);
	int i, j, k = 0, card;

	std::cout << "This program prints randomized numbers ready to merge into bingo cards." << std::endl << std::endl;
	std::cout << "Please enter number of cards needed (eg. '42'): ";
	std::cin >> card;

	outFile << "A" << ',' << "B" << ',' << "C" << ',' << "D" << ',' << "E" << std::endl;

	while (k < card) {

		std::iota(a.begin(), a.end(), 1);
		std::shuffle(a.begin(), a.end(), std::mt19937_64{ std::random_device{}() });

		std::iota(b.begin(), b.end(), 16);
		std::shuffle(b.begin(), b.end(), std::mt19937_64{ std::random_device{}() });

		std::iota(c.begin(), c.end(), 31);
		std::shuffle(c.begin(), c.end(), std::mt19937_64{ std::random_device{}() });

		std::iota(d.begin(), d.end(), 46);
		std::shuffle(d.begin(), d.end(), std::mt19937_64{ std::random_device{}() });

		std::iota(e.begin(), e.end(), 61);
		std::shuffle(e.begin(), e.end(), std::mt19937_64{ std::random_device{}() });

		for (i = 0; i <= 2; i++) {
			if (i == 2 && c[2]) {
				outFile << a[i] << ", " << b[i] << ", FREE SPACE, " << d[i] << ", " << e[i] << '\n';
			}
			else {
				outFile << a[i] << ", " << b[i] << ", " << c[i] << ", " << d[i] << ", " << e[i] << '\n';
			}
		}
		for (j = 3; j < 5; j++) {
			outFile << a[j] << ", " << b[j] << ", " << c[j] << ", " << d[j] << ", " << e[j] << '\n';
		}
		k++;
	}

	std::cout << std::endl << "done." << std::endl;

	return 0;
}