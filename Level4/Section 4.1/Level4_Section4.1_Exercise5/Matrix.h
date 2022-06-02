#pragma once
#ifndef __MATRIX_
#define __MATRIX_

#include <array>
#include <complex>
#include <functional>

template <typename T, int NR, int NC>
class Matrix {
 private:
  // Part A:
  using NestedMatrix = std::array<std::array<T, NC>, NR>;
  NestedMatrix data;

 public:
  Matrix() {
    // default constructor sets data to 0
    for (std::array<T, NC>& row : data) {
      for (T& el : row) {
        el = 0;
      }
    }
  };  // default
  Matrix(T val) {
    for (int i = 0; i < NR; i++) {
      for (T& el : data[i]) {
        el = val;
      };
    };
  };  // value as argument
  Matrix(Matrix& v) {
    for (int r = 0; r < NR; r++) {
      for (int c = 0; c < NC; c++) {
        data[r][c] = v.data[r][c];
      };
    };
  };  // copy constructor
  std::array<T, NC>& operator[](int row) {
    return this->data[row];
  };  // accessing elements
  const std::array<T, NC>& operator[](int row) const {
    return this->data[row];
  };  // accessing elements

  Matrix operator+(Matrix& v) {
    Matrix v_out(v);
    for (int r = 0; r < NR; r++) {
      for (int c = 0; c < NC; c++) {
        v_out.data[r][c] = v.data[r][c] + this->data[r][c];
      };
    };
    return v_out;
  };  // addition
  Matrix operator-(Matrix& v) {
    Matrix v_out(this->data);
    for (unsigned r : indices(v_out)) {
      for (unsigned c : indices(r)) {
        v_out[r][c] -= v[r][c];
      };
    };
    return v_out;
  };  // subtraction
  Matrix operator-() {
    for (auto& r : this->data) {
      for (auto& c : r) {
        c = -c;
      };
    };
  };  // unary minus
  Matrix operator*(int i) {
    Matrix<T, NR, NC> v_out;
    for (auto& r : v_out) {
      for (auto& c : r) {
        c = i * c;
      };
    };
    return v_out;
  };  // scalar multiplication
  void print() {
    for (auto& r : this->data) {
      for (auto& c : r) {
        std::cout << c << " ";
      };
      std::cout << std::endl;
    };
    std::cout << std::endl;
  }
  
  // Part D
  template <typename T, int NR, int NC, typename F>
  Matrix<T, NR, NC> friend operator*(const F& a, const Matrix<T, NR, NC>& pt);
  
  // Part E:
  void modify(const std::function<T(T&)>& f) {
    for (auto& r : this->data) {
      for (auto& c : r) {
        c = f(c);
      };
    };
  };

  // Adding functions for 4.1.5 to get outter product
  static Matrix outer_product(Vector<T, NR> v1, Vector<T, NC> v2) {
    Matrix<T, NR, NC> out_product;
    for (int r = 0; r < NR; r++) {
      for (int c = 0; c < NC; c++) {
        out_product[r][c] = v1[r] * v2[c];
      };
    };
    return out_product;
  };

  // Overloading to accomodate for complex numbers
  static Matrix outer_product(Vector<std::complex<T>, NR> v1,
                              Vector<std::complex<T>, NC> v2) {
    Matrix<T, NR, NC> out_product;
    for (int r = 0; r < NR; r++) {
      for (int c = 0; c < NC; c++) {
        out_product[r][c] =
            v1[r] * std::conj(v2[c]);  // this function takes the complex
                                       // conjugate of the transpose vector
      };
    };
    return out_product;
  };
};
#endif
