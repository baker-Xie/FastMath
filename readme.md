## A fast implementation of sin/cos/tan/atan2

## Installation
- copy fast_math.h into your project
- add the following line to your CMakeLists.txt
```cmake
find_package(OpenCV REQUIRED)
target_link_libraries(YOUR_PROJECT ${OpenCV_LIBS})
```

## Usage
```cpp
#include "fast_math.h"

int main()
{
    FastMath::sin(1);
    FastMath::cos(1);
    FastMath::tan(1);
    auto [s, c] = FastMath::sincos(1);
    FastMath::atan2(1, 1);
}
```

## Benchmark
- about 4x ~ 7x faster than std math function
```
---------------------------------------------------------
Benchmark               Time             CPU   Iterations
---------------------------------------------------------
TestFastTan        144015 ns       144012 ns         4866
TestSTDTan         587773 ns       587760 ns         1190
TestFastSin        144189 ns       144187 ns         4857
TestSTDSin         617861 ns       617853 ns         1133
TestFastCos        143166 ns       143163 ns         4889
TestSTDCos         632660 ns       632646 ns         1106
TestFastSinCos     144369 ns       144363 ns         4842
TestSTDSinCos      956463 ns       956441 ns          732
```

## Accuracy

| Function | Max Absolute Error                                                | Max Relative Error                                                    |
|----------|-------------------------------------------------------------------|-----------------------------------------------------------------------|
| sin      | 1e-5                                                              | not tested                                                            |
| cos      | 1e-5                                                              | not tested                                                            |
| sincos   | 1e-5                                                              | not tested                                                            |
| tan      | 1e-5 <br/> when abs(deg) belong [-89.9 ± n x 180, 89.9 ± n x 180] | not tested                                                            |
| tan      | not tested                                                        | 1e-5 <br/> when abs(deg) belong [-89.999 ± n x 180, 89.999 ± n x 180] |
| atan2    | not tested                                                        | not tested                                                            |


## Reference
- Qt
- OpenCV