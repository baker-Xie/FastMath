#include "fast_math.h"

using TFloat = double;

bool Check(double a, double b, double eps = 1e-5)
{
    double abs_err = std::abs(a - b);
    if (abs_err >= eps)
    {
        throw 0;
    }
    return true;
};


bool CheckTan(double a, double b, double eps = 1e-5)
{
    double abs_err = std::abs(a - b);
    double rel_err = std::abs(a - b) / std::abs(a);
    bool condition1 = abs_err < eps;
    bool condition2 = rel_err < eps;
    bool condition3 = (std::abs(a) > 1e5 and std::abs(b) > 1e5);
    if (condition1 or condition2 or condition3)
    {

    }
    else
    {
        throw 0;
    }
    return true;
};

int main()
{
    int ratio = 10000;
    for (int i = 0 * ratio + 10; i <= 90 * ratio - 10; i++)
    {
        auto v = (TFloat) i / ratio;
        v = (TFloat)(v * M_PI / 180);
        CheckTan(std::tan(v), FastMath::tan(v));

        Check(std::sin(v), FastMath::sin(v));
        Check(std::cos(v), FastMath::cos(v));
        auto [s, c] = FastMath::sincos(v);
        Check(std::sin(v), s);
        Check(std::cos(v), c);
        TFloat s2, c2;
        FastMath::sincos(v, s2, c2);
        Check(std::sin(v), s2);
        Check(std::cos(v), c2);
    }
}