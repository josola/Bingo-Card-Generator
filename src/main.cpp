/* src/main.cpp
 * Generates prepress ready bingo card files.
 * (c) Jordan Sola 2020 - 2021
 * Written by Jordan Sola 2020 - 2021 */

#include <iostream>
#include <random>
#include <vector>
#include <numeric>
#include <fstream>

int main()
{
	std::ofstream outFile;
	
	// Change this to whatever filename/directory you need.
	outFile.open("./output/sample.csv");

	std::vector<int> a(15), b(15), c(15), d(15), e(15);
	int k = 0, card;

	std::cout << "This program prints randomized numbers ready to merge into bingo cards.";

	for (int i = 0; i < 2; i++)
	{
		std::cout << std::endl;
	}

	std::cout << "Please enter number of cards needed (eg. '42'): ";

	while (!(std::cin >> card))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Bad value! Please type an integer (eg. '42'): ";
	}

	outFile << "A" << ',' << "B" << ',' << "C" << ',' << "D" << ',' << "E" << std::endl;

	while (k < card)
	{
		std::random_device rd;
		std::mt19937 gen(rd());

		iota(a.begin(), a.end(), 1);
		shuffle(a.begin(), a.end(), gen);

		iota(b.begin(), b.end(), 16);
		shuffle(b.begin(), b.end(), gen);

		iota(c.begin(), c.end(), 31);
		shuffle(c.begin(), c.end(), gen);

		iota(d.begin(), d.end(), 46);
		shuffle(d.begin(), d.end(), gen);

		iota(e.begin(), e.end(), 61);
		shuffle(e.begin(), e.end(), gen);

		for (int i = 0; i < 5; i++)
		{
			if (i == 2)
			{
				outFile << a[i] << ", " << b[i] << ", FREE SPACE, " << d[i] << ", " << e[i] << std::endl;
			}
			else
			{
				outFile << a[i] << ", " << b[i] << ", " << c[i] << ", " << d[i] << ", " << e[i] << std::endl;
			}
		}
		k++;
	}

	outFile.close();

	return 0;
}