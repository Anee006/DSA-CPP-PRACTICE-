// prints both length of LCS and the LCS string

// Here,
// c[i][j] -> DP table storing LCS length
// b[i][j] -> to store directions: 
// "↖" (diagonal, match)
// "↑" (from top)
// "←" (from left)

#include <iostream>
#include <vector>
using namespace std;

// to reconstruct the actual subsequence
void printLCS(vector<vector<char>>& b, string X, int i, int j) {
    if(i == 0 || j == 0) return;

    if(b[i][j] == 'd') {
        printLCS(b, X, i-1, j-1); // diagonal
        cout << X[i-1]; // print only the diagonal 
    }
    else if(b[i][j] == 'u') {
        printLCS(b, X, i-1, j); // ↑
    }
    else {
        printLCS(b, X, i, j-1); // ←
    }
}

int main() {
    string X = "abcde";
    string Y = "ace"; // this is also the LCS

    int n = X.length(), m = Y.length();

    vector<vector<int>> c(n+1, vector<int>(m+1, 0));
    vector<vector<char>> b(n+1, vector<char>(m+1));

    // build tables
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {

            if(X[i-1] == Y[j-1]) {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 'd'; // diagonal ↖
            }
            else if(c[i-1][j] >= c[i][j-1]) {
                c[i][j] = c[i-1][j];
                b[i][j] = 'u'; // up ↑ 
            }
            else {
                c[i][j] = c[i][j-1];
                b[i][j] = 'l'; // left ←
            }
        }
    }

    cout << "Length of LCS = " << c[n][m] << endl;

    cout << "LCS: ";
    printLCS(b, X, n, m);

    return 0;
}

// TC = O(n * m), SC = O(n * m)