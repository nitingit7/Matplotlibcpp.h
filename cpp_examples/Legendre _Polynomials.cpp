#include <iostream>
#include <cmath>
#include <vector>
#include "matplotlibcpp.h"
double legendreSeriesExpansion(int n, double x) {
    if (n == 0) {
        return 1.0;
    } else if (n == 1) {
        return x;
    } else {
        double p0 = 1.0;
        double p1 = x;
        double p;
        for (int i = 2; i <= n; ++i) {
            p = ((2.0 * i - 1.0) * x * p1 - (i - 1.0) * p0) / i;
            p0 = p1;
            p1 = p;
        }
        return p;
    }
}

void verifyRecurrenceRelation() {
    const int MAX_DEGREE = 5;
    std::vector<double> xData;
    std::vector<std::vector<double>> yData(MAX_DEGREE + 1, std::vector<double>());

    for (double x = -1.0; x <= 1.0; x += 0.01) {
        xData.push_back(x);
        for (int n = 0; n <= MAX_DEGREE; ++n) {
            yData[n].push_back(legendreSeriesExpansion(n, x));
        }
    }

    namespace plt = matplotlibcpp;
    for (int n = 0; n <= MAX_DEGREE; ++n) {
        plt::plot(xData, yData[n]);
    }
    plt::show();
}
int main() {
    verifyRecurrenceRelation();
    return 0;
}
