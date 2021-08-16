/*
 * Bingo card CSV file creator.
 *
 * (c) 2021 Jordan Sola. All rights reserved. (MIT License)
 */

#include <iostream>
#include <random>
#include <vector>
#include <numeric>
#include <fstream>


int main()
{

	// Explanatory prompt

	std::cout << "This program prints randomized numbers ready to merge into bingo cards.";


	// Line seperator

	for (int i = 0; i < 2; i++) {
		std::cout << std::endl;
	}



	// --- Get card count from user ---



	// User input prompt

	std::cout << "Please enter number of cards needed (eg. '42'): ";


	// Get count from user, bad input correction

	int card_count;

	while (!(std::cin >> card_count)) {


		// Clear input stream

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


		// Prompt for input again

		std::cout << "Bad value! Please type an integer (eg. '42'): ";
	}



	// --- Card creation ---



	// Create an ouput file

	std::ofstream out_file;
	out_file.open("./output/test.csv");


	// Set csv file header

	out_file << "A" << ',' << "B" << ',' << "C" << ',' << "D" << ',' << "E" << std::endl;


	// Card columns container

	std::vector<int> a(15), b(15), c(15), d(15), e(15);


	// Create required number of cards

	for (int i = 0; i < card_count; i++) {


		// Set random seed for iota()

		std::random_device rd;
		std::mt19937 gen(rd());


		// Create columns, shuffle columns

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


		// Fill output file with prepared content

		for (int i = 0; i < 5; i++) {


			// "FREE SPACE" goes in the center of each card

			if (i == 2)
				out_file << a[i] << ", " << b[i] << ", FREE SPACE, " << d[i] << ", " << e[i] << std::endl;
				
			else
				out_file << a[i] << ", " << b[i] << ", " << c[i] << ", " << d[i] << ", " << e[i] << std::endl;
		}
	}


	// Close output file for safety

	out_file.close();


	return 0;
}