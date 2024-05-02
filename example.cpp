#include "fmt_eigen.h"
#include "fmt/color.h"
int main() {
    Eigen::Matrix<double, 2, 2> matrix;
    matrix << 1.234567, 2.345678, 3.456789, 4.567890;

    Eigen::Matrix<double, 2, 2> transposed = matrix.transpose();
    Eigen::Vector3d vec(1, 2, 3);

    fmt::print("Matrix:\n{}\n vector:\n{}\n", matrix, vec);
    fmt::print("Matrix:\n{0:.3f}\n vector:\n{1:.4f}\n", matrix, vec); // Specify precision of 4

    fmt::print("Matrix Transposed:\n{:.4f}\n", transposed); // Specify precision of 4
    fmt::print("Matrix col or row:\n{:.4f}\n", matrix.col(0)); // Specify precision of 4
    fmt::print("Matrix Bolck:\n{}\n", matrix.block<1,1>(0,0)); // Specify precision of 4
    fmt::print("Matrix Diagonal:\n{}\n", matrix.diagonal()); // Specify precision of 4

    fmt::print(fg(fmt::color::steel_blue), "Matrix:\n{}\n vector:\n{}\n", matrix, vec);
    fmt::print(bg(fmt::color::lime_green)|fg(fmt::color::indian_red),
               "Matrix:\n{0:.3f}\n vector:\n{1:.4f}\n", matrix, vec);
    fmt::print(fg(fmt::color::gold)|fmt::emphasis::blink, "Matrix Transposed:\n{:.4f}\n", transposed);
    fmt::print(fg(fmt::color::steel_blue)|fmt::emphasis::bold, "Matrix Transposed:\n{:.4f}\n", transposed);

    getchar();
    return 0;
}
