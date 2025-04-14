#include <iostream>
using namespace std;

template <typename T>
class Collection
{
    T *arr;
    int size;

public:
    Collection(T *inputArr, int s)
    {
        size = s;
        arr = new T[size];
        for (int i = 0; i < size; i++)
            arr[i] = inputArr[i];
    }

    ~Collection() { delete[] arr; }

    T getMax()
    {
        T maxVal = arr[0];
        for (int i = 1; i < size; i++)
            if (arr[i] > maxVal)
                maxVal = arr[i];
        return maxVal;
    }

    void reverse()
    {
        for (int i = 0, j = size - 1; i < j; i++, j--)
            swap(arr[i], arr[j]);
    }

    void display()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    int intArr[] = {3, 1, 4, 1, 5};
    Collection<int> intCollection(intArr, 5);
    cout << "Max: " << intCollection.getMax() << endl;
    intCollection.reverse();
    intCollection.display();

    double floatArr[] = {2.5, 1.3, 4.7, 3.9};
    Collection<double> floatCollection(floatArr, 4);
    cout << "Max: " << floatCollection.getMax() << endl;
    floatCollection.reverse();
    floatCollection.display();

    char charArr[] = {'a', 'z', 'm', 'd'};
    Collection<char> charCollection(charArr, 4);
    cout << "Max: " << charCollection.getMax() << endl;
    charCollection.reverse();
    charCollection.display();

    cout << "24CE062-DISU MAKADIYA" << endl;
    return 0;
}
