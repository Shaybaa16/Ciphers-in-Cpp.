#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Example 3x3 key matrix for a Hill cipher
    vector<vector<int>> key = {{17, 17, 5}, {21, 18, 21}, {2, 2, 19}};

    string ciphertext;
    cout << "Enter the ciphertext (uppercase letters only): ";
    cin >> ciphertext;

    int n = key.size();
    int m = ciphertext.length();

    // Check if the key is invertible
    int determinant = key[0][0] * (key[1][1] * key[2][2] - key[1][2] * key[2][1]) -
                     key[0][1] * (key[1][0] * key[2][2] - key[1][2] * key[2][0]) +
                     key[0][2] * (key[1][0] * key[2][1] - key[1][1] * key[2][0]);

    int modInv = determinant % 26;
    if (modInv < 0) {
        modInv += 26;
    }

    if (modInv == 0 || modInv % 2 == 0 || modInv % 13 == 0) {
        cout << "Key is not invertible!" << endl;
        return 1;
    }

    string plaintext = "";

    for (int i = 0; i < m; i += n) {
        // Extract a block of n characters from the ciphertext
        string block = ciphertext.substr(i, n);

        // Multiply the key with the block and take modulo 26
        vector<int> result(n, 0);
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[j] += (key[j][k] * (block[k] - 'A')) % 26;
                result[j] = (result[j] + 26) % 26;
            }
            result[j] = (result[j] * modInv) % 26;
        }

        // Convert the result to characters and append to plaintext
        for (int j = 0; j < n; j++) {
            plaintext += char(result[j] + 'A');
        }
    }

    cout << "Decrypted plaintext: " << plaintext << endl;

    return 0;
}
