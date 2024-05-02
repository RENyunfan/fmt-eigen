# fmt-eigen
A header-only formatter function customized for the Eigen library.

## Why fmt

The `fmt` library offers several advantages over traditional methods of formatting and printing data in C++. In this chapter, we will explore why `fmt` is preferred for these tasks.

#### Easy to Format

With `fmt`, formatting and printing data becomes simple and intuitive. Using the `fmt::print` function, you can easily format output by providing values and placeholders within the format string.

#### Type-Safe and Type-Free Printing

`fmt` supports a wide range of data types, making it type-safe and eliminating the need for explicit format specifiers. It automatically handles the formatting based on the provided arguments.

#### Fast Print Performance

`fmt` is highly optimized for speed, often surpassing the performance of `cout`  by more than **10 times**. Its efficient implementation and utilization of modern techniques contribute to its superior performance.

## Usage

Copy the header file `fmt_eigen.h`  to your project or copy to the `fmt` library path

```bash
sudo cp ./fmt_eigen.h /usr/local/include/fmt
```

Include the header file `fmt_eigen.h`  in your code

```cpp
#include "fmt_eigen.h"
```

Then you can easily print `Eigen` types with `fmt::print` function

```cpp
    fmt::print("Matrix:\n{}\n vector:\n{}\n", matrix, vec);
```

Control the printing precision:

```
    fmt::print("Matrix:\n{0:.3f}\n vector:\n{1:.4f}\n", matrix, vec); // Specify precision of 4
```

and also support the `block`, `Diagonal`, `Transpose` functions.

```cpp
    fmt::print("Matrix Transposed:\n{:.4f}\n", transposed); // Specify precision of 4
    fmt::print("Matrix col or row:\n{:.4f}\n", matrix.col(0)); // Specify precision of 4
    fmt::print("Matrix Bolck:\n{}\n", matrix.block<1,1>(0,0)); // Specify precision of 4
    fmt::print("Matrix Diagonal:\n{}\n", matrix.diagonal()); // Specify precision of 4
```

Take advantage of the colorful printing inherent to `fmt::print`:

```cpp
    fmt::print(fg(fmt::color::steel_blue), "Matrix:\n{}\n vector:\n{}\n", matrix, vec);
    fmt::print(bg(fmt::color::lime_green)|fg(fmt::color::indian_red),
               "Matrix:\n{0:.3f}\n vector:\n{1:.4f}\n", matrix, vec);
    fmt::print(fg(fmt::color::gold)|fmt::emphasis::blink, "Matrix Transposed:\n{:.4f}\n", transposed);
    fmt::print(fg(fmt::color::steel_blue)|fmt::emphasis::bold, "Matrix Transposed:\n{:.4f}\n", transposed);
```

For more details and examples, please refer to the `example.cpp` file and the user guide of fmt at https://hackingcpp.com/cpp/libs/fmt.html.

## Install fmt

There are three ways to include `libfmt` in your project.

### Use with ROS and catkin

For ROS users (tested with ROS Noetic), the easiest way to install `fmt` is by installing `rosfmt`:

```bash
sudo apt-get install ros-noetic-rosfmt
```

To link `fmt` in your project, there are two ways provided. The first way is to use `catkin`:

```cmake
find_package(catkin REQUIRED COMPONENTS
        roscpp
        rosfmt)
include_directories(${catkin_INCLUDE_DIRS})
add_executable(example example.cpp)
target_link_libraries(example
        ${catkin_LIBRARIES}
)
```

The second way is to use pure CMake:

```cmake
set(rosfmt_DIR /opt/ros/noetic/share/rosfmt/cmake)
find_package(rosfmt REQUIRED)
include_directories(${rosfmt_INCLUDE_DIRS})
add_executable(example example.cpp)
target_link_libraries(example
  ${rosfmt_LIBRARIES}
)
```

### ROS-free

For non-ROS users, you can install `libfmt` using the following commands:

```bash
sudo add-apt-repository universe
sudo apt update
sudo apt install libfmt-dev
```

Alternatively, you can download the source code and compile it:

```bash
git clone https://github.com/fmtlib/fmt.git
cd fmt
mkdir build
cd build
cmake ..
make
sudo make install
```

To add `libfmt` to your project's `CMakelists.txt`, use the following:

```cmake
find_package(fmt REQUIRED)
add_executable(example example.cpp)
target_link_libraries(example
        fmt::fmt
)
```
