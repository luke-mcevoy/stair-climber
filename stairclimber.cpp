/*******************************************************************************
 * Name        : stairclimber.cpp
 * Author      : Luke McEvoy
 * Date        : September 29th 2019
 * Description : Lists the number of ways to climb n stairs.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

vector<vector<int>> ways;
vector<int> steps;

vector< vector<int> > get_ways(int num_stairs) {
    // TODO: Return a vector of vectors of ints representing
    // the different combinations of ways to climb num_stairs
    // stairs, moving up either 1, 2, or 3 stairs at a time.

    if (num_stairs == 0) {
    	ways.push_back(steps);
    }

    if (num_stairs >= 1) {
    	steps.push_back(1);
    	get_ways(num_stairs - 1);
    }

    if (num_stairs >= 2) {
    	steps.push_back(2);
    	get_ways(num_stairs - 2);
    }

    if (num_stairs >= 3) {
    	steps.push_back(3);
    	get_ways(num_stairs - 3);
    }

    steps.pop_back();
    return ways;
}

void display_ways(const vector< vector<int> > &ways) {
    // TODO: Display the ways to climb stairs by iterating over
    // the vector of vectors and printing each combination.
	unsigned int ways_size = ways.size();
    // Stores ways.size() for speed purposes

  	for(unsigned int i = 0; i < ways_size; i++) {
      // For loop iterates through outer vector of ways
  		if(ways_size > 9) {
        // This set of if statements formats correctly in
        // cases where there are more than 9 ways
  			if(i < 9) {
          cout << " " << i + 1 << ". [";
        }
  			else {
  				cout << i + 1 << ". [";
        }
  		}
  		else {
  			cout << i + 1 << ". [";
      }

  		for(unsigned int j = 0; j < ways[i].size(); j++) {
        // This loop iterates through the inner ways vectors
  			if(j != ways[i].size() - 1) {
          // This if adds commas between vector components
  				cout << ways[i][j] << ", ";
        }
  			else {
  				cout << ways[i][j];
        }
  		}
  		cout << "]" << endl;
  	}

}

int main(int argc, char * const argv[]) {
	if (argc != 2) {
      cerr << "Usage: " << argv[0] << " <number of stairs>" << endl;
      return 1;
    }
    if (atoi(argv[1]) <= 0) {
      cerr << "Error: Number of stairs must be a positive integer." << endl;
      return 1;
    }

    vector<vector<int>> ways = get_ways(atoi(argv[1]));
    if (atoi(argv[1]) == 1) {
      cout << "1 way to climb 1 stair." << endl;
    }
    else {
      cout << ways.size() << " ways to climb " << argv[1] << " stairs." << endl;
    }
    display_ways(ways);
}
