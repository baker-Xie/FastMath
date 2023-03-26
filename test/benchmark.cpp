#include <benchmark/benchmark.h>
#include <iostream>

#include "fast_math.h"

double result;
double result2;
using TFloat = double;

const int L = 900;

void TestFastTan(benchmark::State& state)
{
    for (auto _ : state)
    {
        double ratio = 100;
        for (int i = -L; i < L * ratio;i++)
        {
            auto v = (TFloat)i / ratio;
            v = static_cast<TFloat>(v / 180 * M_PI);
            result = FastMath::tan(v);
        }
    }
}
BENCHMARK(TestFastTan);


void TestSTDTan(benchmark::State& state)
{
    const int kTanTableSize = 256;
    for (auto _ : state)
    {
        double ratio = 100;
        for (int i = -L; i < L * ratio;i++)
        {
            auto v = (TFloat)i / ratio;
            v = static_cast<TFloat>(v / 180 * M_PI);
            result = std::tan(v);
        }
    }
}
BENCHMARK(TestSTDTan);

void TestFastSin(benchmark::State& state)
{
    for (auto _ : state)
    {
        double ratio = 100;
        for (int i = -L; i < L * ratio;i++)
        {
            auto v = (TFloat)i / ratio;
            v = static_cast<TFloat>(v / 180 * M_PI);
            result = FastMath::sin(v);
        }
    }
}
BENCHMARK(TestFastSin);


void TestSTDSin(benchmark::State& state)
{
    for (auto _ : state)
    {
        double ratio = 100;
        for (int i = -L; i < L * ratio;i++)
        {
            auto v = (TFloat)i / ratio;
            v = static_cast<TFloat>(v / 180 * M_PI);
            result = std::sin(v);
        }
    }
}
BENCHMARK(TestSTDSin);

void TestFastCos(benchmark::State& state)
{
    for (auto _ : state)
    {
        double ratio = 100;
        for (int i = -L; i < L * ratio;i++)
        {
            auto v = (TFloat)i / ratio;
            v = static_cast<TFloat>(v / 180 * M_PI);
            result = FastMath::cos(v);
        }
    }
}
BENCHMARK(TestFastCos);


void TestSTDCos(benchmark::State& state)
{
    const int kTanTableSize = 256;
    for (auto _ : state)
    {
        double ratio = 100;
        for (int i = -L; i < L * ratio;i++)
        {
            auto v = (TFloat)i / ratio;
            v = static_cast<TFloat>(v / 180 * M_PI);
            result = std::cos(v);
        }
    }
}
BENCHMARK(TestSTDCos);

void TestFastSinCos(benchmark::State& state)
{
    for (auto _ : state)
    {
        double ratio = 100;
        for (int i = -L; i < L * ratio;i++)
        {
            auto v = (TFloat)i / ratio;
            v = static_cast<TFloat>(v / 180 * M_PI);
            FastMath::sincos(v, result, result2);
        }
    }
}
BENCHMARK(TestFastSinCos);


void TestSTDSinCos(benchmark::State& state)
{
    for (auto _ : state)
    {
        double ratio = 100;
        for (int i = -L; i < L * ratio;i++)
        {
            auto v = (TFloat)i / ratio;
            v = static_cast<TFloat>(v / 180 * M_PI);
            sincos(v, &result, &result2);
        }
    }
}
BENCHMARK(TestSTDSinCos);


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
    if (condition1)// or condition2)// or condition3)
    {

    }
    else
    {
        throw 0;
    }
    return true;
};

BENCHMARK_MAIN();