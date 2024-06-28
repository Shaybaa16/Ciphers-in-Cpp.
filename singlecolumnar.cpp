#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to perform single columnar transposition encryption
string encryptColumnarTransposition(const string &plaintext, const string &key) {
    int keyLength = key.length();
    int numRows = (plaintext.length() + keyLength - 1) / keyLength;

    vector<vector<char>> matrix(numRows, vector<char>(keyLength, ' '));

    // Fill the matrix with plaintext characters
    int index = 0;
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < keyLength; col++) {
            if (index < plaintext.length()) {
                matrix[row][col] = plaintext[index];
                index++;
            }
        }
    }

    // Create the ciphertext by reading columns based on the key
    string ciphertext = "";
    for (int col = 0; col < keyLength; col++) {
        int currentCol = key.find(col + '1');
        for (int row = 0; row < numRows; row++) {
            ciphertext += matrix[row][currentCol];
        }
    }

    return ciphertext;
}

int main() {
    string plaintext, key;

    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    cout << "Enter the columnar key (e.g., 3124 for a 4-column transposition): ";
    cin >> key;

    string ciphertext = encryptColumnarTransposition(plaintext, key);

    cout << "Encrypted ciphertext: " << ciphertext << endl;

    return 0;
}
