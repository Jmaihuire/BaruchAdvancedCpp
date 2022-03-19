//Alex Moody: Exercise 2.8.5
//Objective: Data structure for bit matrix 
#include <iostream>
#include <bitset>
#include <array>

template<int N, int M>
class BitMatrix {
	std::array<std::bitset<M>, N> matrix;
public:

	BitMatrix() {
		for (std::bitset<M> bitsetcnt : matrix) {
			bitsetcnt = std::bitset<M>(0);
		};
	}; //default constructor

	BitMatrix(unsigned long val) {
		for (int i = 0; i < matrix.size(); ++i) {
			matrix[i] = std::bitset<M>(val);
		};
	}; //constructor with value

	BitMatrix(BitMatrix<N, M>& bitmatrix) {
		matrix = bitmatrix.matrix;
	}; //copy constructor

	BitMatrix(BitMatrix<N, M>&& bitmatrix) {
		matrix = bitmatrix.matrix;
	};

	void print() {
		for (int i = 0; i < matrix.size(); ++i) {
			std::cout << matrix[i] << "\n";
		};
		std::cout << std::endl;
	}

	//Set bits for all rows
	void set() {
		for (int i = 0; i < matrix.size(); ++i) {
			matrix[i].set();
		};
	}
	//Set bits for single row
	void set(int row) {
		matrix[row].set();
	}
	//Reset bits for all rows
	void reset() {
		for (int i = 0; i < matrix.size(); ++i) {
			matrix[i].reset();
		};
	}	//Reset bits for single row
	void reset(int row) {
		matrix[row].reset();
	};

	//Flip the bits for all rows
	void flip() {
		for (int i = 0; i < matrix.size(); ++i) {
			matrix[i].flip();
		};
	}
	//Flip the bits for single row
	void flip(int row) {
		matrix[row].flip();
	};

	//Test set bits all rows
	bool all() {
		int sum = 0;
		for (int i = 0; i < matrix.size(); ++i) {
			sum += matrix[i].all();
		};
		if (sum == N) {
			return true;
		}
		return false;
	};
	//All bits in row
	bool all(int row) {
		matrix[row].all();
	}

	//Test if no bits all rows
	bool none() {
		int sum = 0;
		for (int i = 0; i < matrix.size(); ++i) {
			sum += matrix[i].none();
		};
		if (sum == N) {
			return true;
		}
		return false;
	};
	//All bits in row
	bool none(int row) {
		matrix[row].none();
	}

	//Test any set bits all rows
	bool any() {
		int sum = 0;
		for (int i = 0; i < matrix.size(); ++i) {
			sum += matrix[i].any();
		};
		if (sum > 0) {
			return true;
		}
		return false;
	};
	//All bits in row
	bool any(int row) {
		matrix[row].any();
	}

	//Accessing elements
	bool operator ()(std::size_t row, std::size_t col) {
		return matrix[row][col];
	}
	//Accessing rows
	bool operator ()(std::size_t row) {
		return matrix[row];
	}

	//Count number of set bits total:
	int count() {
		int sum = 0;
		for (int i = 0; i < matrix.size(); ++i) {
			sum += matrix[i].count();
		};
		return sum;
	}
	//Count number set bits row
	int count(int row) {
		return matrix[row].count();
	}

	//PART D:
	//XOR operation performs bitwise XOR between every row on the two bitmatrices
	BitMatrix<N, M> operator ^ (BitMatrix<N, M>& bm2) {
		BitMatrix<N, M> out;
		for (int i = 0; i < this->matrix.size(); ++i) {
			out.matrix[i] = this->matrix[i] ^ bm2.matrix[i];
		};
		return out;
	}

	//OR operation performs bitwise OR between every row on the two bitmatrices
	BitMatrix<N, M> operator | (BitMatrix<N, M>& bm2) {
		BitMatrix<N, M> out;
		for (int i = 0; i < this->matrix.size(); ++i) {
			out.matrix[i] = this->matrix[i] | bm2.matrix[i];
		};
		return out;
	}

	//AND operation performs bitwise AND between every row on the two bitmatrices
	BitMatrix<N, M> operator & (BitMatrix<N, M>& bm2) {
		BitMatrix<N, M> out;
		for (int i = 0; i < this->matrix.size(); ++i) {
			out.matrix[i] = this->matrix[i] & bm2.matrix[i];
		};
		return out;
	}
};

