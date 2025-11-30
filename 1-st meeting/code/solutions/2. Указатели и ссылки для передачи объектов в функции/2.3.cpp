#include <string>
#include <exception>
#include <cmath>
#include <stdexcept>
#include <iostream>

struct Coefficients {
    double c;
    double b;
    double a;
};

std::string findRoots(Coefficients& coefficients, double& r1, double& r2) {
    if (std::abs(coefficients.a) > 1e-12) {
        double D = std::pow(coefficients.b, 2) - 4*coefficients.a*coefficients.c;
        if (D < 0)
            return "0";
        r1 = (-coefficients.b + sqrt(D))/(2*coefficients.a);
        r2 = (-coefficients.b - sqrt(D))/(2*coefficients.a);
    } else {
        if (std::abs(coefficients.b) < 1e-12) {
            return std::abs(coefficients.c) < 1e-12 ? "inf" : "0";
        }
        r1 = r2 = -coefficients.c / coefficients.b;
    }
    return std::to_string((r1 != r2) + 1);
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

std::string findRoots(const std::string& eq, double& r1, double& r2) {
    auto coefficients = extractCoefficients(eq);
    return findRoots(coefficients, r1, r2);
}

struct Test {
    std::string eq;
    std::string ans;
    double r1;
    double r2;

    bool estimate(const std::string& inpAns, double inpR1, double inpR2) const {
        bool res = true;
        res &= inpAns == ans;
        if (ans != "inf" && ans != "0") {
            res &= std::abs(std::min(inpR1, inpR2) - std::min(r1, r2)) < 1e-12;
            res &= std::abs(std::max(inpR1, inpR2) - std::max(r1, r2)) < 1e-12;
        }
        return res;
    }
};

auto tests = {
    Test{"x^2 + 2x - 3 = 0", "2", -3, 1},
    Test{" x^2 - 2x = 0 ", "2", 0, 2},
    Test{"-x^2 + 3x + 4 = 0 ", "2", -1, 4},
    Test{"-x - 4 = 0", "1", -4, -4},
    Test{"0x = 0 ", "inf", 0, 0},
    Test{"0x + 4 = 0 ", "0", 0, 0.}
};
int main() {
    for (const Test& test : tests) {
        double r1 = 0, r2 = 0;
        std::string ans = findRoots(test.eq, r1, r2);
        if (!test.estimate(ans, r1, r2)) {
            throw std::runtime_error("Wrong answer with " + test.eq + ". Expected " + test.ans + ", " +
                std::to_string(test.r1) + ", " + std::to_string(test.r2) + ", but got " + ans + ", " + std::to_string(r1) + ", " + std::to_string(r2));
        }
    }
}
