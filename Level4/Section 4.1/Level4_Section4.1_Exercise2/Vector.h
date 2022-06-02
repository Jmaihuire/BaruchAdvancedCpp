#pragma once

#pragma once
#include <functional>
#include <iostream>

template <typename T, int N>
class Vector {
 private:
  T data[N];

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
  }
  // Part D: Scalar multiplication
  template <typename T, int N, typename F>
  Vector<T, N> friend operator*(const F& a, const Vector<T, N>& pt) {
    Vector<T, N> v_out;
    for (int i = 0; i < N; i++) {
      v_out[i] = pt.data[i] * a;
    };
    return v_out;
  };


  // Part E: modifying elements of vector
  void modify(const std::function<T(T&)>& f) {
    for (T& el : this->data) {
      el = f(el);
    }
  };
};
