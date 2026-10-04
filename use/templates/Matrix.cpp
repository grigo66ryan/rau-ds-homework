#include <iostream>
#include <string>
#include <cassert>
template <typename T, int N, int M>
class Matrix {
private:
    T data[N][M];
public:
    Matrix() : data{} {}
    void print() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                std::cout << data[i][j];
                if (j != M - 1) std::cout << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    void set(int row, int col, T value) {
        data[row][col] = value;
    }
    T get(int row, int col) {
        return data[row][col];
    }
    Matrix operator+(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                result.data[i][j] = this->data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
};
void testMatrix() {
    Matrix<int, 2, 2> m1;
    assert(m1.get(0, 0) == 0);
    m1.set(0, 0, 5);
    m1.set(1, 1, 2);
    assert(m1.get(0, 0) == 5);
    assert(m1.get(1, 1) == 2);
    Matrix<int, 2, 2> m2;
    m2.set(0, 0, 10);
    m2.set(1, 1, 7);
    Matrix<int, 2, 2> m3 = m1 + m2;
    assert(m3.get(0, 0) == 15);
    assert(m3.get(1, 1) == 9);
    assert(m3.get(0, 1) == 0);
    Matrix<double, 1, 2> d1;
    Matrix<double, 1, 2> d2;
    d1.set(0, 0, 1.5);
    d2.set(0, 0, 3.5);
    Matrix<double, 1, 2> d3 = d1 + d2;
    assert(d3.get(0, 0) == 5.0);
}
int main() {
    testMatrix();
    std::cout << "All tests passed!" << std::endl;
}
