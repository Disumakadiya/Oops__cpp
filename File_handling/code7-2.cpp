#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
    std::ifstream file("data.txt");
    if (!file)
     {
        std::cerr << "Error: File could not be opened!" << std::endl;
        return 1;
    }

    int lineCount = 0;
    int wordCount = 0;
    int charCount = 0;
    std::string line;

    while (std::getline(file, line)) 
    {
        lineCount++;
        charCount += line.length(); // Counts characters in the line (excluding newline)

        std::istringstream ss(line);
        std::string word;
        while (ss >> word) {
            wordCount++;
        }

        charCount++; // Account for the newline character
    }

    file.close();

    std::cout << "Lines: " << lineCount << std::endl;
    std::cout << "Words: " << wordCount << std::endl;
    std::cout << "Characters (including spaces and newlines): " << charCount << std::endl;

    return 0;
}