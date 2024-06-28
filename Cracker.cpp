//          Algorithm Cracked
/*
#include <iostream>
#include <string>
using namespace std;

int main() {
    string input = "";
    const int key = 3;
    int pt = 0;
    cout << "Enter the Encrypted string: ";
    getline(cin, input);
    int len = input.length();

    for (int i = 0; i < len; i++) {
        char c = input[i];
        if (isalpha(c)) {                                 // Check if the character is alphabetic
            char base = isupper(c) ? 'A' : 'a';          // Determine the base ('A' for uppercase, 'a' for lowercase)
            pt = c - base;
            input[i] = (pt - key) % 26 + base;          //Ceaser Cracking Formula
        }
    }

    cout << "Plain string: " << input << endl;

    return 0;
}
*/
//          Combination Usage
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string Alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char Alphabets[26], match[26];
    for (int i = 0; i < 26; i++)
    {
        Alphabets[i] = Alpha[i];
    }
    string match1;
    string combinations[26] = {""};

    for (int i = 0; i < 27; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            char c = Alphabets[i];
            if (isalpha(c))
            {
                char base = isupper(c) ? 'A' : 'a';
                int pt = c - base;
                if (i == 27)
                {
                    match[i] = (pt - j + 26) % 26 + base; // Caesar Cracking Formula (subtraction)
                    match1 += match[j];
                }
                else
                {
                    Alphabets[i] = (pt - j + 26) % 26 + base; // Caesar Cracking Formula (subtraction)
                }
            }
            combinations[i] += Alphabets[j];
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (match1 == combinations[i])
        {
            cout << "Key Found\n"
                 << match1 << endl;
            cout << combinations[i] << endl;
        }
    }

    return 0;
}
