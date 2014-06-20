// ----------------------------------------------------------------------------
//
// Grid class
//    Header
//
// This program will allow for the Grid class to be implemented in order to play ape
// egboard problem game//
// ----------------------------------------------------------------------------
//
// Generating using Edward Aryee Class Generator
// Author: 
// Date: 
// Modified: 
//
// ----------------------------------------------------------------------------

#ifndef _Grid_
#define _Grid_

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

using namespace std;
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

class Grid
{
public:
		// ------------------------------------------------------
		// ----- Constructors -----------------------------------
		// ------------------------------------------------------

			Grid();
			Grid(const unsigned int& rows, const unsigned int& columns);
			Grid(const vector< vector<bool> >& inputGrid);

		// ------------------------------------------------------
		// ----- Destructor -------------------------------------
		// ------------------------------------------------------

			~Grid();

		// ------------------------------------------------------
		// ----- Inspectors -------------------------------------
		// ------------------------------------------------------
//Note for vector types, the inspectors will need to be corrected

		bool getElement(const unsigned int& i, const unsigned int& j) const;

		// ------------------------------------------------------
		// ----- Mutators ---------------------------------------
		// ------------------------------------------------------
//Note for vector types, the mutators will need to be corrected
		
		void fromFile(const string &fileName);
		bool setElement(const unsigned int& i, const unsigned int& j, bool& value);
		bool floodFill(const unsigned int& row, const unsigned int& column);
		bool animatedFill(const unsigned int& row, const unsigned int& column, const double& delay);
	
		// ------------------------------------------------------
		// ----- Facilitators -----------------------------------
		// ------------------------------------------------------

		void output(ostream& out);

	// ----------------------------------------------------------
	// ----------------------------------------------------------

private:
	vector< vector<bool> > grid_;
};

#endif

	// ------------------------------------------------------
	// ----- SubPrograms -----------------------------------
	// ------------------------------------------------------

	void delay(double seconds);

// ------------------------------------------------------
// ----- Operators --------------------------------------
// ------------------------------------------------------

	ostream& operator<< (ostream& out,Grid& inputGrid);