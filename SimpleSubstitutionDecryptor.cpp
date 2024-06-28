#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Function to reverse the substitution from QWERTYUIOPASDFGHJKLZXCVBNM to A to Z
string reverseSubstitution(const string &text) {
    // Define the reverse substitution map from QWERTYUIOPASDFGHJKLZXCVBNM to A to Z
    unordered_map<char, char> reverseSubstitutionMap;
    string originalAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string substitutedAlphabet = "QWERTYUIOPASDFGHJKLZXCVBNM";

    // Populate the reverse substitution map
    for (int i = 0; i < originalAlphabet.size(); ++i) {
        reverseSubstitutionMap[substitutedAlphabet[i]] = originalAlphabet[i];
    }

    // Perform the reverse substitution
    string result = "";
    for (char c : text) {
        char upperC = toupper(c);
        if (reverseSubstitutionMap.find(upperC) != reverseSubstitutionMap.end()) {
            // If the character is in the map, reverse substitute it
            char originalChar = reverseSubstitutionMap[upperC];
            if (islower(c)) {
                originalChar = tolower(originalChar);
            }
            result += originalChar;
        } else {
            // If the character is not in the map, keep it unchanged
            result += c;
        }
    }

    return result;
}

int main() {
    string input;
    cout << "Enter the substituted string: ";
    getline(cin, input);

    string decryptedText = reverseSubstitution(input);

    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}
