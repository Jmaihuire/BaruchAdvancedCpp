#pragma once
#include <iostream>
#include <concepts>

// Interface contract specification

template <typename T, typename Data>

concept IDiffusion = requires(T c, Data t, Data x)

{
  c.diffusion(t, x);
};

template <typename T, typename Data>

concept IDrift = requires(T c, Data t, Data x)

{
  c.drift(t, x);
};

template <typename T, typename Data>

concept IDriftDiffusion = IDiffusion<T, Data> && IDrift<T, Data>;

template <typename T, typename Data>
requires IDriftDiffusion<T, Data>

class SDEAbstract

{  // System under discussion, using composition

  // Really a Bridge pattern

 private:
  T _t;

 public:
  SDEAbstract(const T& t) : _t(t) {}

  Data diffusion(Data t, Data x)

  {
    return _t.diffusion(t, x);
  }

  Data drift(Data t, Data x)

  {
    return _t.drift(t, x);
  }
};
