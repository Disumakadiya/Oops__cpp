#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class DirectoryManager
{
private:
    map<string, vector<string>> directory;

public:
    // Add a new folder
    void addFolder(const string& folderName)
    {
        directory[folderName]; // Automatically creates an empty vector if it doesn't exist
    }

    // Add a file to an existing folder
    void addFileToFolder(const string& folderName, const string& fileName)
     {
        directory[folderName].push_back(fileName); // Adds file even if folder was just created
    }

    // Display the directory structure
    void displayStructure() const 
    {
        cout << "\nDirectory Structure:\n";
        for (auto it = directory.begin(); it != directory.end(); ++it)
         {
            cout << "[" << it->first << "]\n";
            for (const auto& file : it->second)
            {
                cout << "  - " << file << "\n";
            }
        }
    }
};

int main() 
{
    DirectoryManager dm;
    int choice;
    string folder, file;

    do {
        cout << "\n--- Directory Management Menu ---\n";
        cout << "1. Add Folder\n2. Add File to Folder\n3. Display Directory\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
         {
            case 1:
                cout << "Enter folder name: ";
                cin >> folder;
                dm.addFolder(folder);
                break;
            case 2:
                cout << "Enter folder name: ";
                cin >> folder;
                cout << "Enter file name: ";
                cin >> file;
                dm.addFileToFolder(folder, file);
                break;
            case 3:
                dm.displayStructure();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
