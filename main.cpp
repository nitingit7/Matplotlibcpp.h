#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  // Create a vector of x-coordinates.
  vector<int> x = {1, 2, 3, 4, 5};

  // Create a vector of y-coordinates.
  vector<int> y = {2, 4, 6, 8, 10};

  // Create a line object.
  line line(x, y);

  // Plot the line.
  line.plot();

  // Wait for the user to press a key.
  cin.get();

  return 0;
}