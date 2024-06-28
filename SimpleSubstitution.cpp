#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string substituteAlphabet(const string &text) {
    // Define the substitution map from A to Z to QWERTYUIOPASDFGHJKLZXCVBNM
    unordered_map<char, char> substitutionMap;
    string originalAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string substitutedAlphabet = "QWERTYUIOPASDFGHJKLZXCVBNM";

    // Populate the substitution map
    for (int i = 0; i < originalAlphabet.size(); ++i) {
        substitutionMap[originalAlphabet[i]] = substitutedAlphabet[i];
    }

    // Perform the substitution
    string result = "";
    for (char c : text) {
        char upperC = toupper(c);
        if (substitutionMap.find(upperC) != substitutionMap.end()) {
            // If the character is in the map, substitute it
            char substitutedChar = substitutionMap[upperC];
            if (islower(c)) {
                substitutedChar = tolower(substitutedChar);
            }
            result += substitutedChar;
        } else {
            // If the character is not in the map, keep it unchanged
            result += c;
        }
    }

    return result;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    string substitutedText = substituteAlphabet(input);

    cout << "Substituted text: " << substitutedText << endl;

    return 0;
}
