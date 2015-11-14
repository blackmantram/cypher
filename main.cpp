#include <iostream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

string sentence= "The quick brown fox jumps over the lazy old dog";

string removeSpaces(string);

string substitute() {
    string substituted;
    for(char character : sentence)
    {
        substituted += character != ' ' ?
            static_cast<char>(character+1) : character;
    }
    return substituted;
}

vector<vector<char> > transpose() {
    string nospacesentence = removeSpaces(sentence);
    int cols = ceil(nospacesentence.length() / 4.0);
    const int rows = 4;
    vector<vector<char> > tranposed;
    int currentChar = 0;
    for (int i=0; i<cols; i++)
    {
        vector<char> column;
        for(int j=0; j<rows; j++)
        {
            column.push_back(nospacesentence[currentChar]);
            currentChar++;
        }
        tranposed.push_back(column);
    }

    return tranposed;
}

string removeSpaces(string input)
{
    int length = input.length();
    for (int i = 0; i < length; i++) {
        if(input[i] == ' ')
            input.erase(i, 1);
    }
    return input;
}

void printTransposed(vector<vector<char>> transposed)
{
    unsigned int cols = transposed.size();
    unsigned int rows = transposed[0].size();
    for(unsigned int i=0; i < rows; i++)
    {
        string output = "   ";
        for(unsigned int j=0; j < cols; j++)
        {
            output += transposed[j][i];
        }
        cout << output << endl;
    }
}

int main()
{
    cout << "frase original: " << sentence << endl;
    cout << "substitución: " << substitute() << endl;
    cout << "transpocición: " << endl;
    printTransposed(transpose());
    return 0;
}
