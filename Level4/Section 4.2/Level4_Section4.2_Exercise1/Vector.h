#pragma once
#include <array>
#include <functional>
#include <iostream>

template <typename T, int N>
// Including Templates
class Vector {
 private:
  std::array<T, N> data;

 public:
  Vector(){};  // default
  Vector(T arr[]) {
    for (int i = 0; i < N; i++) {
      data[i] = arr[i];
    };
  };  // value as argument
  Vector(Vector& v) {
    for (int i = 0; i < N; i++) {
      data[i] = v.data[i];
    };
  };                                                   // copy constructor
  T& operator[](int pos) { return this->data[pos]; };  // accessing elements
  Vector operator+(Vector& v) {
    Vector v_out(v);
    for (int i = 0; i < N; i++) {
      v_out.data[i] = v.data[i] + this->data[i];
    };
    return v_out;
  };  // addition
  Vector operator-(Vector& v) {
    Vector v_out(this->data);
    for (unsigned i : indices(v_out)) {
      v_out[i] -= v[i];
    };
    return v_out;
  };  // subtraction
  Vector operator-() {
    for (T el : this->data) {
      el = -el;
    };
  };  // unary minus

  Vector operator*(int i) {
    Vector<T, N> v_out;
    for (T el : v_out.data) {
      el = i * el;
    };
    return v_out;
  };  // scalar multiplication


  void print() {
    for (T el : this->data) {
      std::cout << el << " ";
    }
    std::cout << std::endl;
  };

  // Part E: modifying elements of vector
  void modify(const std::function<T(T&)>& f) {
    for (T& el : this->data) {
      el = f(el);
    }
  };

  // Getting begin() / end() grabbers so can do inner_product
  auto begin() const { return data.begin(); };

  auto end() const { return data.end(); };
};
