#include <iostream>
#include <Eigen/Dense>
#include "matplotlibcpp.h"
#include <cmath>

namespace plt = matplotlibcpp;

int main() {
  // Set the desired range and step size for x values
  double start = 0.0;
  double end = 4 * M_PI;
  double step = 0.001;

  // Calculate the number of points based on the range and step size
  int numPoints = static_cast<int>((end - start) / step) + 1;

  // Generate x values from start to end with the specified step size
  Eigen::VectorXd x(numPoints);
  for (int i = 0; i < numPoints; ++i) {
    x[i] = start + i * step;
  }

  // Calculate corresponding y values as sin(x)
  Eigen::VectorXd y = x.array().sin();

  // Convert Eigen vectors to std::vector for plotting
  std::vector<double> xData(x.data(), x.data() + x.size());
  std::vector<double> yData(y.data(), y.data() + y.size());

  // Plot the sine graph
  plt::plot(xData, yData);
  plt::show();

  return 0;
}
