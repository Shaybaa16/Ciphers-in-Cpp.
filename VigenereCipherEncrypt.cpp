#include <iostream>
#include <string>

using namespace std;

string encryptVigenere(const string &plaintext, const string &key) {
    string ciphertext = "";
    int keyLength = key.length();
    int keyIndex = 0;

    for (int i = 0; i < plaintext.length(); i++) {
        char plainChar = plaintext[i];
        char keyChar = key[keyIndex % keyLength];

        if (isalpha(plainChar)) {
            char base = islower(plainChar) ? 'a' : 'A';
            char encryptedChar = (plainChar + keyChar - 2 * base) % 26 + base;
            ciphertext += encryptedChar;
            keyIndex++;  // Move to the next character in the key
        } else {
            // Preserve non-alphabetic characters
            ciphertext += plainChar;
        }
    }

    return ciphertext;
}

int main() {
    string plaintext, key;

    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    cout << "Enter the Vigenère key: ";
    cin >> key;

    string ciphertext = encryptVigenere(plaintext, key);

    cout << "Encrypted ciphertext: " << ciphertext << endl;

    return 0;
}
