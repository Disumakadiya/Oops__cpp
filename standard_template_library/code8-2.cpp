#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

// Function to clean and normalize words (removes punctuation and converts to lowercase)
string normalize(const string& word)
{
    string result;
    for (char ch : word) 
    {
        if (isalpha(ch))
         {
            result += tolower(ch);
        }
    }
    return result;
}

int main()
 {
    string input;
    cout << "Enter a sentence: ";
    getline(cin, input);

    map<string, int> wordFreq;
    stringstream ss(input);
    string word;

    // Extract and normalize words, update frequency
    while (ss >> word) 
    {
        string cleanWord = normalize(word);
        if (!cleanWord.empty())
         {
            ++wordFreq[cleanWord];
        }
    }

    // Display word frequencies
    cout << "\nWord Frequency Distribution:\n";
    for (const auto& pair : wordFreq)
     {
        cout << pair.first << ": " << pair.second << '\n';
    }

    return 0;
}
