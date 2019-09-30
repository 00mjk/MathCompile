# MathCompile

MathCompile is a package that translates *Wolfram Language* functions into C++ code. It is written mostly in *Wolfram Language* and utilize a C++ library for type deductiona and implementation of the supported functions. 

## In a nutshell

Load the package:
```
<<MathCompile`
```
Compile a function using `CompileToCode`:
```
CompileToCode[
    Function[{Typed[p,"Integer"]},
        Module[{f=If[p>0,#+1&,#-1&]},f[p]]
    ]
]
```
The output is a C++ function: 
```c++
auto main_function(int64_t v16) {
    auto v15 = [&] {
        const auto v17 = wl::greater(v16, int64_t(0));
        if (v17) {
        } else {
        }
        return [&, v17](auto&&... v18) {
            if (v17) {
                return [&](auto v14, auto...) {
                    return wl::plus(v14, int64_t(1));
                }(std::forward<decltype(v18)>(v18)...);
            } else {
                return [&](auto v13, auto...) {
                    return wl::plus(v13, int64_t(-1));
                }(std::forward<decltype(v18)>(v18)...);
            }
        };
    }();
    return v15(v16);
}
```

## Supported constants and functions

**Constants**
```
Null
Pi
E
Degree
EulerGamma
I
```
**Scope functions**
```
Module
```
**Arithmetic functions**
```
Plus
Subtract
Times
Divide
AddTo
SubtractFrom
TimesBy
DivideBy
```
**Numerical functions**
```
N
Round
```
**Functions with iterators**
```
Do
```

## Supported types

| *Wolfram Laguage*       | C++                       |
| ----------------------- | ------------------------- |
| `"Void"`                | `wl::void_type`           |
| `"Boolean"`             | `bool`                    |
| `"Integer"`             | `int64_t`                 |
| `"Integer8"`            | `int8_t`                  |
| `"Integer16"`           | `int16_t`                 |
| `"Integer32"`           | `int32_t`                 |
| `"Integer64"`           | `int64_t`                 |
| `"UnsignedInteger"`     | `uint64_t`                |
| `"UnsignedInteger8"`    | `uint8_t`                 |
| `"UnsignedInteger16"`   | `uint16_t`                |
| `"UnsignedInteger32"`   | `uint32_t`                |
| `"UnsignedInteger64"`   | `uint64_t`                |
| `"String"`              | `std::string`             |
| `"Array"[type_, rank_]` | `wl::ndarray<type, rank>` |