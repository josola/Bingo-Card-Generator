/*
 * Generate correct numbers for bingo cards and output to CSV file.
 * Jordan Sola 2019-2020 - MIT License
 */

#include <iostream>
#include <random>
#include <vector>
#include <numeric>
#include <fstream>

using std::ofstream;
using std::vector;
using std::cout;
using std::cin;
using std::numeric_limits;
using std::streamsize;
using std::random_device;
using std::mt19937;
using std::iota;
using std::shuffle;

int main()
{
	ofstream outFile;
	outFile.open("bingo-cards.csv");

	vector<int> a(15), b(15), c(15), d(15), e(15);
	int k = 0, card;

	cout << "This program prints randomized numbers ready to merge into bingo cards.\n"
		 << '\n';
	cout << "Please enter number of cards needed (eg. '42'): ";

	while (!(cin >> card))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Bad value! Please type an integer (eg. '42'): ";
	}

	outFile << "A" << ',' << "B" << ',' << "C" << ',' << "D" << ',' << "E" << '\n';

	while (k < card)
	{
		random_device rd;
		mt19937 gen(rd());

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
				outFile << a[i] << ", " << b[i] << ", FREE SPACE, " << d[i] << ", " << e[i] << '\n';
			}
			else
			{
				outFile << a[i] << ", " << b[i] << ", " << c[i] << ", " << d[i] << ", " << e[i] << '\n';
			}
		}
		k++;
	}

	outFile.close();

	return 0;
}
