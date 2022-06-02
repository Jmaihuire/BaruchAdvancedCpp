// Level4_Section4.1_Exercise4
// Fiona Ross 
// Bitmap Class
#include <iostream>
#include "BitMap.h"
#include "Proposition.h"

// Templates
using value_type = Proposition;
template <int NR, int NC>
using BitMap = Matrix<value_type, NR, NC>;
template <int NR, int NC>
using BitMap2 = std::array<std::bitset<NC>, NR>;

// Part A: Printing proposition
std::ostream& operator<<(std::ostream& os, Proposition& p) {
  os << p();
  return os;
}

// Printing BitMap2
template <int NR, int NC>
void print(BitMap2<NR, NC>& bm2) {
  for (auto& r : bm2) {
    for (int i = 0; i < r.size(); i++) {
      std::cout << r[i] << " ";
    };
    std::cout << std::endl;
  };
  std::cout << std::endl;
}

// Part B: Superimpose 
using BitFunction =
    std::function<Proposition(const Proposition&, const Proposition&)>;

// merging bitmaps 
template <int NR, int NC>
BitMap<NR, NC> mask(const BitMap<NR, NC>& bm1, const BitMap<NR, NC>& bm2,
                    const BitFunction& masker) {
  BitMap<NR, NC> bm;
  for (int r = 0; r < NR; r++) {
    for (int c = 0; c < NC; c++) {
      // Proposition mask_result(masker(bm1, bm2)());
      Proposition p1 = bm1[r][c];
      Proposition p2 = bm2[r][c];
      bm[r][c] = masker(bm1[r][c], bm2[r][c])();
    };
  };

  return bm;
};

// Conditional 
Proposition operator%(Proposition p1, Proposition p2) {
  return new Proposition((!p1() || p2()));  //(!A or B)
};

// Biconditional
Proposition operator%=(Proposition p1, Proposition p2) {
  // This is where returning propositions instead of bools would be helpful
  Proposition aImpliesb(p1 % p2);
  Proposition bImpliesa(p2 % p1);
  Proposition result(aImpliesb() & bImpliesa());
  return result;  //(A->B)&(B->A)
};

// Part C: BitMap2 row setting function
template <int P, int Q>
void initialize(BitMap2<P, Q>& bm2, int row, std::string bitstring) {
  bm2[row] = {bitstring};
};

int main() {
  // Part A: Making instance of bitmaps 
  BitMap<4, 4> bm1;  
  BitMap2<4, 4> bm2;  
  bm1.print();
  print(bm2);

  // Part B: Superimpose & merge 
  BitMap<4, 4> bm(true);
  bm[3][3] = false;

  BitMap<4, 4> bm3(true);
  bm3[1][3] = false;

  // Conditional
  auto COND = [](const Proposition& p1, const Proposition& p2) {
    return p1 % p2;
  };
  // Biconditional
  auto BICOND = [](const Proposition& p1, const Proposition& p2) {
    return p1 %= p2;
  };
  // AND
  auto AND = [](const Proposition& p1, const Proposition& p2) {
    Proposition p1_temp = p1;
    return p1_temp & p2;
  };
  // OR
  auto OR = [](const Proposition& p1, const Proposition& p2) {
    Proposition p1_temp = p1;
    return p1_temp | p2;
  };
  // XOR
  auto XOR = [](const Proposition& p1, const Proposition& p2) {
    Proposition p1_temp = p1;
    return p1_temp ^ p2;
  };
  mask(bm, bm3, XOR).print();  // XOR

  mask(bm, bm3, COND).print();  // Conditional

  mask(bm, bm3, BICOND).print();  // biconditional

  mask(bm, bm3, OR).print();  // OR

  mask(bm, bm3, AND).print();

  // Part C: Bitmap2 to set rows 
  BitMap<4, 4> bitblt(false);
  bitblt[1][1] = true;
  bitblt[1][2] = true;
  bitblt[1][3] = true;
  bitblt[3][3] = true;
  bitblt.print();

  // From exercise 
  const int P = 8;
  const int Q = 8;
  BitMap2<P, Q> bitblt2;
  initialize(bitblt2, 0, std::string("01111100"));
  print(bitblt2);

 }