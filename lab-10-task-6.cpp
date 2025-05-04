#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct InventoryItem
{
    int itemID;
    char itemName[20];
};

int main()
{
    InventoryItem item1;
    item1.itemID = 1001;
    strcpy(item1.itemName, "Hammer");

    {
        ofstream outFile("inventory.dat", ios::binary);
        if (!outFile.is_open())
        {
            cerr << "Error: Could not open file for writing." << endl;
            return 1;
        }

        outFile.write(reinterpret_cast<char *>(&item1), sizeof(item1));

        outFile.close();
        if (outFile.fail())
        {
            cerr << "Error: Problem occurred while writing to file." << endl;
            return 1;
        }
    }

    {
        InventoryItem item2;

        ifstream inFile("inventory.dat", ios::binary);
        if (!inFile.is_open())
        {
            cerr << "Error: Could not open file for reading." << endl;
            return 1;
        }

        inFile.read(reinterpret_cast<char *>(&item2), sizeof(item2));

        inFile.close();
        if (inFile.fail())
        {
            cerr << "Error: Problem occurred while reading from file." << endl;
            return 1;
        }

        cout << "Loaded Item ID: " << item2.itemID << endl;
        cout << "Loaded Item Name: " << item2.itemName << endl;
    }

    return 0;
}
