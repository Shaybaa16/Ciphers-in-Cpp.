#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input = "";
    const int key = 3;
    int pt = 0;
    cout << "Enter the string: ";
    getline(cin, input);
    int len = input.length();

    for (int i = 0; i < len; i++)
    {
        char c = input[i];
        if (isalpha(c))
        {                                       // Check if the character is alphabetic
            char base = isupper(c) ? 'A' : 'a'; // Determine the base ('A' for uppercase, 'a' for lowercase)
            pt = c - base;
            input[i] = (pt + key) % 26 + base; // Ceaser Formula
        }
    }

    cout << "Encrypted string: " << input << endl;

    return 0;
}
