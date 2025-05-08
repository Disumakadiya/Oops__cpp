#include <iostream>
#include <vector>
#include <algorithm> // for reverse()
using namespace std;

 void reverseWithStd(vector<int>& seq)
{
    
     reverse(seq.begin(), seq.end());
}

// Function to reverse using iterators manually
void reverseWithIterators(vector<int>& seq)
 {
    auto left = seq.begin();
    auto right = seq.end() - 1;
    while (left < right)
     {
        
         iter_swap(left, right);
        ++left;
        --right;
    }
}

// Utility function to print the sequence
void printSequence(const vector<int>& seq)
      {
     for (int num : seq)
    {
        cout << num << " ";
    }
    
     cout << endl;
}

int main()
 {
    
    vector<int> sequence;
    int n, value;

    
     cout << "Enter number of elements: ";
    
     cin >> n;

    
     cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) 
    {
        
         cin >> value;
        sequence.push_back(value);
    }

    
     vector<int> sequenceCopy = sequence;

    
     cout << "\nOriginal sequence:\n";
    printSequence(sequence);

    // Reversal using 
     reverseWithStd(sequence);
    
     cout << "\nReversed using reverse:\n";
    printSequence(sequence);

    // Reversal using manual iterator method
    reverseWithIterators(sequenceCopy);
    
     cout << "\nReversed using manual iterator method:\n";
    printSequence(sequenceCopy);

    return 0;
}