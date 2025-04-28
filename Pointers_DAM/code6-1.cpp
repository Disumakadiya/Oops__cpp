#include <iostream>
using namespace std;

class DynamicArray
{
private:
    int *data;
    int size;
    int capacity;

    void resize()
    {
        int newCapacity = capacity * 2;
        int *newData = new int[newCapacity];

        for (int i = 0; i < size; ++i)
            newData[i] = data[i];

        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    DynamicArray()
    {
        size = 0;
        capacity = 4;
        data = new int[capacity];
    }

    ~DynamicArray()
    {
        delete[] data;
    }

    // Insert element at a specific index
    void insert(int index, int value)
    {
        if (index < 0 || index > size)
        {
            cout << "Index out of bounds.\n";
            return;
        }

        if (size == capacity)
            resize();

        for (int i = size; i > index; --i)
            data[i] = data[i - 1];

        data[index] = value;
        size++;
    }

    void remove(int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Index out of bounds.\n";
            return;
        }

        for (int i = index; i < size - 1; ++i)
            data[i] = data[i + 1];

        size--;
    }

    int get(int index) const
    {
        if (index < 0 || index >= size)
        {
            cout << "Index out of bounds.\n";
            return -1;
        }
        return data[index];
    }

    int getSize() const
    {
        return size;
    }

    void print() const
    {
        cout << "Array: ";
        for (int i = 0; i < size; ++i)
            cout << data[i] << " ";
        cout << "\n";
    }
};

int main()
{
    DynamicArray arr;

    // Inserting at the end using insert(size, value)
    arr.insert(arr.getSize(), 5);
    arr.insert(arr.getSize(), 15);
    arr.insert(arr.getSize(), 25);
    arr.insert(arr.getSize(), 35);

    arr.print();

    // Inserting at a specific index
    arr.insert(2, 20);
    arr.print();

    // Removing element
    arr.remove(3);
    arr.print();

    cout << "Element at index 1: " << arr.get(1) << "\n";

    cout<<"24CE062_DISU MAKADIYA";
    return 0;
}

// heap ma dam store thai ---static store thai stack ma
/*int *ptr=new int[10];
delete[] ptr;releases the space which is pointed by ptr*/