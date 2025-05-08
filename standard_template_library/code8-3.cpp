#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() 
{
    vector<int> transactionIDs = {101, 204, 101, 305, 204, 500, 305, 600, 700};

    // Use set to automatically store only unique, sorted values
    set<int> uniqueTransactions(transactionIDs.begin(), transactionIDs.end());

    // Display 
    cout << "Unique Transaction IDs (sorted):\n";
    for (auto it = uniqueTransactions.begin(); it != uniqueTransactions.end(); ++it) 
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
