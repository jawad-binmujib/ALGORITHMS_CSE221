#include <iostream>
using namespace std;

long long MOD = 1e9 + 7; 
struct Matrix {
    long long mat[2][2];
};
Matrix multiply(Matrix A, Matrix B) {
    Matrix C; 

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            long long sum = 0;
            for (int k = 0; k < 2; k++) {
                long long prod = (A.mat[i][k] * B.mat[k][j]) % MOD;
                sum = (sum + prod) % MOD;
            }
            C.mat[i][j] = sum;
        }
    }
    return C;
}

Matrix matrixPower(Matrix A, long long X) {

    Matrix result;
    result.mat[0][0] = 1; result.mat[0][1] = 0;
    result.mat[1][0] = 0; result.mat[1][1] = 1;
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            A.mat[i][j] %= MOD;
        }
    }

    while (X > 0) {
        if (X & 1) {
            result = multiply(result, A);
        }
        
        A = multiply(A, A);
        X >>= 1;
    }
    
    return result;
}

void printMatrix(Matrix A) {
    cout << A.mat[0][0] << " " << A.mat[0][1] << endl;
    cout << A.mat[1][0] << " " << A.mat[1][1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_cases;
    cin >> test_cases;
    while (test_cases--) {

        Matrix A;
        cin >> A.mat[0][0] >> A.mat[0][1];
        cin >> A.mat[1][0] >> A.mat[1][1];

        long long X;
        cin >> X;
        Matrix result = matrixPower(A, X);
        printMatrix(result);
    }
    
    return 0;
}