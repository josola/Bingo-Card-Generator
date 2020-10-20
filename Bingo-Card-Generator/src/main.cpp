#include <iostream>
#include <random>
#include <vector>
#include <numeric>
#include <fstream>

//Create five rows and five columns of randomly generated numbers following bingo card guidlines.

int main() {

	//file creation
	std::ofstream outFile;
	outFile.open("bingo-cards.csv");

	std::vector<int> a(15), b(15), c(15), d(15), e(15);
	int i, k = 0, card;

	//user prompt
	std::cout << "This program prints randomized numbers ready to merge into bingo cards." << std::endl << std::endl;
	std::cout << "Please enter number of cards needed (eg. '42'): ";
	
	//error handling
	while (!(std::cin >> card)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Bad value! Please type an integer (eg. '42'): ";
	}

	//data merge headers added to CSV
	outFile << "A" << ',' << "B" << ',' << "C" << ',' << "D" << ',' << "E" << std::endl;

	//card generator
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

		for (i = 0; i < 5; i++) {
			if (i == 2) {
				outFile << a[i] << ", " << b[i] << ", FREE SPACE, " << d[i] << ", " << e[i] << '\n';
			}
			else {
				outFile << a[i] << ", " << b[i] << ", " << c[i] << ", " << d[i] << ", " << e[i] << '\n';
			}
		}
		k++;
	}
	//file close
	outFile.close();
	return 0;
}
