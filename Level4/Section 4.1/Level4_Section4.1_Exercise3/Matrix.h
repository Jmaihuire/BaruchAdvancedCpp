#pragma once
#include <array>
#include <functional>

// All the functions are primarily the same but now we 
// iterate through the rows then columns 

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
  Matrix<T, NR, NC> friend operator*(const F& a, const Matrix<T, NR, NC>& pt) {
    Matrix<T, NR, NC> v_out;
    for (int r = 0; r < NR; r++) {
      for (int c = 0; c < NC; c++) {
        v_out[r][c] = pt.data[r][c] * a;
      };
    };
    return v_out;
  };
  // Part E:
  void modify(const std::function<T(T&)>& f) {
    for (auto& r : this->data) {
      for (auto& c : r) {
        c = f(c);
      };
    };
  };
};
