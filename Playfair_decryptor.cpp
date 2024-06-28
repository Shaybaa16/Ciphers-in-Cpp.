#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Function to convert a string to uppercase
string toUpperCase(string message)
{
    for (int i = 0; i < message.size(); i++)
    {
        if (message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = message[i] - 32; // Convert to uppercase by subtracting 32 from ASCII value
        }
    }
    return message;
}

// Function to remove spaces from a string
string removeSpaces(string message)
{
    string newMessage = "";
    for (int i = 0; i < message.size(); i++)
    {
        if (message[i] != ' ')
        {
            newMessage += message[i];
        }
    }
    return newMessage;
}

// Function to create the Playfair matrix from a keyword
vector<vector<char>> createPlayfairMatrix(string key)
{
    vector<vector<char>> matrix(5, vector<char>(5));
    string alphabets = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    int index = 0;

    // Loop to initialize the matrix with the key
    for (int i = 0; i < key.size(); i++)
    {
        int row = index / 5;
        int col = index % 5;
        matrix[row][col] = key[i];
        alphabets.erase(remove(alphabets.begin(), alphabets.end(), key[i]), alphabets.end()); // Erasing the used character from alphabets
        index++;
    }

    // Loop to fill the remaining cells of the matrix with the alphabet
    for (int i = 0; i < alphabets.size(); i++)
    {
        int row = index / 5;
        int col = index % 5;
        matrix[row][col] = alphabets[i];
        index++;
    }

    return matrix;
}

// Function to get the position of a character in the matrix
void getPosition(vector<vector<char>> &matrix, char ch, int &row, int &col)
{
    if (ch == 'J')
    {
        ch = 'I';
    }

    // Loop to find the position of the character in the matrix
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (matrix[i][j] == ch)
            {
                row = i;
                col = j;
                return;
            }
        }
    }
}

// Function to decrypt a pair of characters
void decrypt(vector<vector<char>> &matrix, char a, char b, char &originalA, char &originalB)
{
    int row1 = 0, col1 = 0, row2 = 0, col2 = 0;

    getPosition(matrix, a, row1, col1);
    getPosition(matrix, b, row2, col2);

    // Loop to apply Playfair decryption rules
    if (row1 == row2)
    {
        originalA = matrix[row1][(col1 + 4) % 5]; // Decrement by 1 to reverse circular shift
        originalB = matrix[row2][(col2 + 4) % 5];
    }
    else if (col1 == col2)
    {
        originalA = matrix[(row1 + 4) % 5][col1];
        originalB = matrix[(row2 + 4) % 5][col2];
    }
    else
    {
        originalA = matrix[row1][col2];
        originalB = matrix[row2][col1];
    }
}

// Function to decrypt a Playfair-encrypted message
string decryptMessage(string message, string key)
{
    message = toUpperCase(message);
    message = removeSpaces(message);

    vector<vector<char>> matrix = createPlayfairMatrix(key);

    string decryptedMessage = "";

    // Loop to decrypt the message in pairs
    for (int i = 0; i < message.size(); i += 2)
    {
        char originalA, originalB;
        decrypt(matrix, message[i], message[i + 1], originalA, originalB);
        decryptedMessage += originalA;
        decryptedMessage += originalB;
    }

    return decryptedMessage;
}

int main()
{
    string message, key;
    cout << "Enter message to decrypt: ";
    getline(cin, message);
    cout << "Enter key: ";
    getline(cin, key);

    string decryptedMessage = decryptMessage(message, key);

    cout << "Decrypted message: " << decryptedMessage;

    return 0;
}
