// ----------------------------------------------------------------------------
//
// Grid class
//    Implementation
//
//    Version: 
// //
// ----------------------------------------------------------------------------
//
// Generating using Edward Aryee Class Generator
// Author: Edward Aryee
// Date: April 30, 2014
// Modified: --
//
// ----------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <assert.h>
#include <sstream>
#include "Grid.h"

using namespace std;

//----------------------------------------------------------------------------
//----- Constructors----------------------------------------------------------
//----------------------------------------------------------------------------

Grid::Grid()
{
//Add null constructor
}

Grid::Grid(const unsigned int& rows, const unsigned int& columns)
{
	for(unsigned int i=0; i < rows; i++)
	{
	 grid_.push_back(vector<bool>(columns, false));
	}
}

Grid::Grid(const vector< vector<bool> >& inputGrid)
{
	for(unsigned int i = 0; i <= inputGrid.size(); i++)
	{
		for(unsigned int j = 0; j <= inputGrid[i].size(); i++)
		{
		 grid_[i][j] = inputGrid[i][j];
		}
	}
}

//----------------------------------------------------------------------------
//----- Destructor----------------------------------------------------------
//----------------------------------------------------------------------------

Grid::~Grid()
	{

	}

//----------------------------------------------------------------------------
//----- Inspectors----------------------------------------------------------
//----------------------------------------------------------------------------
//Note for vector types, the inspectors will need to be corrected

bool Grid::getElement(const unsigned int& i, const unsigned int& j) const
{
	return grid_[i][j];
}

//----------------------------------------------------------------------------
//----- Mutators----------------------------------------------------------
//----------------------------------------------------------------------------
//Note for vector types, the mutators will need to be corrected

void Grid::fromFile(const string &fileName)
{
	ifstream gridFile(fileName);

	int rows = 0;
	string lineString;
	bool element;
	getline(gridFile, lineString);
	
	if(grid_[0].size() <= lineString.length())
	{
		for(unsigned int j = 0; j < grid_.size(); j++)
		{
			for(unsigned int k = 0; k <= (lineString.length()- grid_[0].size()); k++)
			{
				grid_[j].push_back(false);
			}
		}
	}

	while(! gridFile.eof())
	{
		if(static_cast<unsigned int>(rows) >= grid_.size())
		{
			grid_.push_back(vector<bool>(grid_[0].size(), false));
		}

		grid_[rows].resize(lineString.length());

		for(unsigned int columns = 0; columns < lineString.length(); columns++)
		{
			if(lineString.at(columns) == '1'){element = true;}
			else if(lineString.at(columns) == '0'){element = false;}
			
			grid_[rows][columns] = element;			
		}

	getline(gridFile,lineString);
	rows++;
	}

	grid_.resize(rows);
	gridFile.close();
}

bool Grid::floodFill(const unsigned int& row, const unsigned int& column)
{
	bool filled = true;
	bool unfilled = false;

	if(row < 0 || row >= grid_.size())
	{
		cout << "Input row is outside of grid. No elements will changed" << endl << endl;
		return false;
	}

	if(column < 0 || column >= grid_[0].size())
	{
		cout << "Input column is outside of grid. No elements will be changed" << endl << endl;
		return false;
	}

	if(grid_[row][column] == unfilled)
	{
		grid_[row][column] = filled;

		if(row < grid_.size()-1){
		(*this).floodFill(row+1, column);
		}
		if(row > 0){
		(*this).floodFill(row-1, column);
		}
		if(column < grid_[0].size()-1){
		(*this).floodFill(row, column+1);
		}
		if(column > 0){
		(*this).floodFill(row, column-1);
		}
		
		return true;
	}

	return true;
}

bool Grid::animatedFill(const unsigned int& row, const unsigned int& column, const double& delayTime)
{
	bool filled = true;
	bool unfilled = false;

	if(row < 0 || row >= grid_.size())
	{
		cout << "Input row is outside of grid. No elements will changed" << endl << endl;
		return false;
	}

	if(column < 0 || column >= grid_[0].size())
	{
		cout << "Input column is outside of grid. No elements will be changed" << endl << endl;
		return false;
	}

	if(grid_[row][column] == unfilled)
	{
		delay(delayTime);
		cout << (*this) << endl;

		grid_[row][column] = filled;

		if(row < grid_.size()-1){
		(*this).animatedFill(row+1, column, delayTime);
		}
		if(row > 0){
		(*this).animatedFill(row-1, column, delayTime);
		}
		if(column < grid_[0].size()-1){
		(*this).animatedFill(row, column+1, delayTime);
		}
		if(column > 0){
		(*this).animatedFill(row, column-1, delayTime);
		}
		
		return true;
	}

	return true;
}

//----------------------------------------------------------------------------
//----- Facilitators----------------------------------------------------------
//----------------------------------------------------------------------------

void Grid::output(ostream& out)
{
	string XO;

	out << endl;
	int count = 0;
	for(unsigned int i = 0; i < grid_.size(); i++)
	{

		for(unsigned int j = 0; j < grid_[0].size(); j++) // for setting up grid
		{
			if((j+1)%grid_[0].size() == 0)// when a new line is neccessary
			{ 
				if( grid_[i][j] == false){XO = "-";}
				else if( grid_[i][j] == true){XO = "0";}
				out << XO <<endl; 
			}
			else // output regular array to the grid
			{
				if( grid_[i][j] == false){XO = "-";}
				else if( grid_[i][j] == true){XO = "0";}
				out << XO ;
			}

		}
	}
}

void delay(double seconds)
{
	clock_t time1 = clock();
	clock_t time2 = clock();

	while(time2-time1 < seconds*1000)
	{
		time2 = clock();
	}
}


//----------------------------------------------------------------------------
//----- Operators----------------------------------------------------------
//----------------------------------------------------------------------------
// fill in everything in quotation marks

ostream& operator<< (ostream& out,Grid& inputGrid)
	{
		inputGrid.output(out) ;
		return out;
	}
