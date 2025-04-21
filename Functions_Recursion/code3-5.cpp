#include <iostream>
#include <string>

using namespace std;

int superDigit(string n)
{
    // Base case: if single digit
    if (n.length() == 1)
        return n[0] - '0';

    // Sum the digits
    long long sum = 0;
    for (char c : n)
    {
        sum += c - '0';
    }

    // Call recursively
    return superDigit(to_string(sum));
}

// Overloaded version to handle repetition factor k
int superDigit(string n, int k)
{
    // First, compute sum of digits of n
    long long initialSum = 0;
    for (char c : n)
    {
        initialSum += c - '0';
    }

    // Multiply by k and compute super digit
    long long totalSum = initialSum * k;
    return superDigit(to_string(totalSum));
}

int main()
{
    string n;
    int k;

    cout << "Enter number n (as string): ";
    cin >> n;

    cout << "Enter repetition factor k: ";
    cin >> k;

    int result = superDigit(n, k);
    cout << "Super Digit: " << result << endl;

    return 0;
}