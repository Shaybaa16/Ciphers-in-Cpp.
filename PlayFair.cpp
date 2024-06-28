#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string toUpperCase(string message)
{
    for (int i = 0; i < message.size(); i++)
    {
        if (message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = message[i] - 32;
        }
    }
    return message;
}

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

string padMessage(string message)
{
    if (message.size() % 2 != 0)
    {
        message += 'x';
    }
    return message;
}

vector<vector<char>> createPlayfairMatrix(string key)
{
    vector<vector<char>> matrix(5, vector<char>(5));
    string alphabets = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    int index = 0;

    for (int i = 0; i < key.size(); i++)
    {
        int row = index / 5;
        int col = index % 5;
        matrix[row][col] = key[i];
        alphabets.erase(remove(alphabets.begin(), alphabets.end(), key[i]), alphabets.end());
        index++;
    }

    for (int i = 0; i < alphabets.size(); i++)
    {
        int row = index / 5;
        int col = index % 5;
        matrix[row][col] = alphabets[i];
        index++;
    }

    return matrix;
}

void getPosition(vector<vector<char>> &matrix, char ch, int &row, int &col)
{
    if (ch == 'J')
    {
        ch = 'I';
    }

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

void encrypt(vector<vector<char>> &matrix, char a, char b, char &newA, char &newB)
{
    int row1 = 0, col1 = 0, row2 = 0, col2 = 0;

    getPosition(matrix, a, row1, col1);
    getPosition(matrix, b, row2, col2);

    if (row1 == row2)
    {
        newA = matrix[row1][(col1 + 1) % 5];
        newB = matrix[row2][(col2 + 1) % 5];
    }
    else if (col1 == col2)
    {
        newA = matrix[(row1 + 1) % 5][col1];
        newB = matrix[(row2 + 1) % 5][col2];
    }
    else
    {
        newA = matrix[row1][col2];
        newB = matrix[row2][col1];
    }
}

string encryptMessage(string message, string key)
{
    message = toUpperCase(message);
    message = removeSpaces(message);
    message = padMessage(message);

    vector<vector<char>> matrix = createPlayfairMatrix(key);

    string encryptedMessage = "";
    for (int i = 0; i < message.size(); i += 2)
    {
        char newA, newB;
        encrypt(matrix, message[i], message[i + 1], newA, newB);
        encryptedMessage += newA;
        encryptedMessage += newB;
    }

    return encryptedMessage;
}

int main()
{
    string message, key;
    cout << "Enter message to encrypt: ";
    getline(cin, message);
    cout << "Enter key: ";
    getline(cin, key);

    string encryptedMessage = encryptMessage(message, key);

    cout << "Encrypted message: " << encryptedMessage;

    return 0;
}
