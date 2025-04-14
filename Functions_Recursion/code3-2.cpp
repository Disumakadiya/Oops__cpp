#include <iostream>
#include <vector>
#include <chrono> //for storing high resolution time

using namespace std;
using namespace std::chrono;

int recursive_Sum(const vector<int> &arr, int a)
{
    if (a == 0)
        return 0;
    else
        return arr[a - 1] + recursive_Sum(arr, a - 1);
}

int iterative_Sum(const vector<int> &arr)
{
    int sum = 0;
    /* for (size_t i = 0; i < arr.size(); ++i) // size_t for unsigned integer
     {
         sum += arr[i];
     }*/
    for (int num : arr) // starts when index arr starts.no need to make 2 loops for counting index and putting in the loop
    {
        sum += num;
    }
    return sum;
}
int main()
{
    int size_array;
    cout << "Enter the size of the array---";
    cin >> size_array;

    vector<int> arr(size_array);
    cout << "Enter" << size_array << "integer::" << endl;
    for (int i = 0; i < size_array; ++i)
    {
        cin >> arr[i];
    }

    // Measure recursive sum time
    auto startRecursion = high_resolution_clock::now(); // best precision
    int sumRecursion = recursive_Sum(arr, arr.size());
    auto endRecursion = high_resolution_clock::now();

    // Measure iterative sum time
    auto startIterative = high_resolution_clock::now(); // best precision
    int sumIterative = iterative_Sum(arr);
    auto endIterative = high_resolution_clock::now();

    // Output results
    auto durationRec = duration_cast<nanoseconds>(endRecursion - startRecursion);
    auto durationItr = duration_cast<nanoseconds>(endIterative - startIterative);

    cout << "\nResults:\n";
    cout << "Recursive Sum: " << sumRecursion << endl;
    cout << "Time taken (Recursive): " << durationRec.count() << " ns\n";

    cout << "Iterative Sum: " << sumIterative << endl;
    cout << "Time taken (Iterative): " << durationItr.count() << " ns\n";

    cout << "24CE062_Disu Makadiya";
    return 0;
}
