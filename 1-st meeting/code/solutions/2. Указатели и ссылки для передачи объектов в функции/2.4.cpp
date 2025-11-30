#include <string>
#include <iostream>
#include <cmath>

struct Coefficients {
    double c;
    double b;
    double a;
};

double getAt(Coefficients& coefficients, double x) {
    return coefficients.a * x * x +
           coefficients.b * x     +
           coefficients.c;
}

Coefficients extractCoefficients(const std::string& eq) {
    Coefficients coefficients{};
    std::string delim = " +-=";

    double curCoefficient = 0, curPow = 0;
    bool afterX = false, flushed = false, updatedCoef = false;
    int sign = 1;

    for (const char sym : eq + std::string(" ")) {
        if (sym >= '0' && sym <= '9') {
            updatedCoef |= !afterX;
            double& p = afterX ? curPow : curCoefficient;
            p = p * 10 + sym - '0';
            flushed = false;
        }
        if (sym >= 'a' && sym <= 'z') {
            flushed = false;
            afterX = true;
        }
        if (sym == '-')
            sign = -1;
        if (!flushed && (updatedCoef || afterX)
            && delim.find(sym) != std::string::npos) {
            curPow = std::max(int(afterX), int(curPow));
            if (!updatedCoef)
                curCoefficient = 1;
            switch (int(curPow)) {
                case 0:
                    coefficients.c = sign*curCoefficient;
                    break;
                case 1:
                    coefficients.b = sign*curCoefficient;
                    break;
                case 2:
                    coefficients.a = sign*curCoefficient;
                    break;
            }

            afterX = updatedCoef = false;
            flushed = true;
            curCoefficient = curPow = 0;
            sign = 1;
        }
        if (sym == '=')
            break;
    }
    return coefficients;
}

double getAt(const std::string& eq, double x) {
    size_t index = eq.find('=');
    auto coefficients = extractCoefficients(eq.substr(index));
    //std::cout << coefficients.a << ' ' << coefficients.b << ' ' << coefficients.c << '\n';
    return getAt(coefficients, x);
}

int main() {
    double res1 = getAt("f(x) = x^2 + 4x + 78x - 34", 12);
    double res2 = getAt("g(y) = y^2 - 4y - 13", 4);
    std::cout << res1 << ' ' << res2 << '\n';
    return 0;
}
