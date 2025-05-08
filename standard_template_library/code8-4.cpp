#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    // Vector to store name-score pairs
    vector<pair<string, int>> studentRecords;

    // Input number of students
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    // Input student names and scores
    for (int i = 0; i < n; ++i)
    {
        string name;
        int score;
        cout << "Enter name and score of student " << i + 1 << ": ";
        cin >> name >> score;
        studentRecords.push_back({name, score});
    }

    // Sort by score in descending order using a custom comparator
    sort(studentRecords.begin(), studentRecords.end(),
         [](const pair<string, int>& a, const pair<string, int>& b)
          {
             return a.second > b.second;
});

    // Display ranked list
    cout << "\nStudent Ranking:\n";
    int rank = 1;
    for (auto it = studentRecords.begin(); it != studentRecords.end(); ++it)
    {
        cout << "Rank " << rank << ": " << it->first << " (Score: " << it->second << ")\n";
        ++rank;
    }

    return 0;
}
