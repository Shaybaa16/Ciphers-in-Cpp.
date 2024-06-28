#include <iostream>
#include <vector>

using namespace std;

// Function to encrypt text using the Hill cipher
string encryptHillCipher(string plaintext, vector<vector<int>> key) {
    int n = key.size();
    int m = plaintext.length();

    string ciphertext = "";

    for (int i = 0; i < m; i += n) {
        // Extract a block of n characters from the plaintext
        string block = plaintext.substr(i, n);

        // Multiply the key with the block and take modulo 26
        vector<int> result(n, 0);
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[j] += (key[j][k] * (block[k] - 'A')) % 26;
                result[j] = (result[j] + 26) % 26;
            }
        }

        // Convert the result to characters and append to ciphertext
        for (int j = 0; j < n; j++) {
            ciphertext += char(result[j] + 'A');
        }
    }

    return ciphertext;
}

int main() {
    // Example 3x3 key matrix for a Hill cipher
    vector<vector<int>> key = {{17, 17, 5}, {21, 18, 21}, {2, 2, 19}};

    string plaintext;
    cout << "Enter the plaintext (uppercase letters only): ";
    cin >> plaintext;

    int n = key.size();

    // Pad the plaintext if its length is not a multiple of n
    int padding = n - (plaintext.length() % n);
    if (padding < n) {
        for (int i = 0; i < padding; i++) {
            plaintext += 'X';
        }
    }

    string ciphertext = encryptHillCipher(plaintext, key);
    cout << "Encrypted ciphertext: " << ciphertext << endl;

    return 0;
}
