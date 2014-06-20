#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include "Grid.h"

using namespace std;
void floodFill(Grid& fillerGrid, const unsigned int& row, const unsigned int& column);
void animatedFloodFill(Grid& fillerGrid, const unsigned int& row, const unsigned int& column, double delayTime);

int main()
{
	int rows, columns;
	string fileName;
	int fillRow, fillColumn;
	char animated;
	ofstream fout("filledGridOutput.txt");

		cout << "Enter the size of your Grid (e.g. 5 5): ";
			cin >> rows;
			cin >> columns;
		cout << endl;

	Grid fillerGrid(rows, columns);
		cout << "Enter the name of the file to load grid from(e.g gridFile.txt): ";
			cin >> fileName;

	fillerGrid.fromFile(fileName);
		cout << endl;
		cout << fillerGrid << endl;
	
		cout << "Enter point to begin filling (e.g. 3 5): ";
			cin >> fillRow;
			cin >> fillColumn;
			
		cout << endl;

	cout << "Would you like to have an animated fill? (y or n): ";
		cin >> animated;
	cout << endl;

	if(animated == 'y')
	{
		double delayTime;
		cout << "Enter delay time in seconds (greater than .5 is best): ";
			cin >> delayTime;

	animatedFloodFill(fillerGrid, fillRow, fillColumn, delayTime);
	fout << fillerGrid;
	}

	else if(animated != 'y')
	{
		floodFill(fillerGrid, fillRow, fillColumn);
		cout << fillerGrid << endl;
		fout << fillerGrid;
	}

	cout << endl;

	fout.close();
	system("PAUSE");
	return 0;
}

void floodFill(Grid& fillerGrid, const unsigned int& row, const unsigned int& column)
{
	fillerGrid.floodFill(row, column);
}

void animatedFloodFill(Grid& fillerGrid, const unsigned int& row, const unsigned int& column, double delayTime)
{
	fillerGrid.animatedFill(row, column, delayTime);
}
