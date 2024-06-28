#include <iostream>
#include <string>

using namespace std;

string decryptVigenere(const string &ciphertext, const string &key) {
    string plaintext = "";
    int keyLength = key.length();
    int keyIndex = 0;

    for (int i = 0; i < ciphertext.length(); i++) {
        char cipherChar = ciphertext[i];
        char keyChar = key[keyIndex % keyLength];

        if (isalpha(cipherChar)) {
            char base = islower(cipherChar) ? 'a' : 'A';
            char decryptedChar = (cipherChar - keyChar + 26) % 26 + base;
            plaintext += decryptedChar;
            keyIndex++;  // Move to the next character in the key
        } else {
            // Preserve non-alphabetic characters
            plaintext += cipherChar;
        }
    }

    return plaintext;
}

int main() {
    string ciphertext, key;

    cout << "Enter the ciphertext: ";
    cin.ignore();
    getline(cin, ciphertext);

    cout << "Enter the Vigenère key: ";
    cin >> key;

    string plaintext = decryptVigenere(ciphertext, key);

    cout << "Decrypted plaintext: " << plaintext << endl;

    return 0;
}
