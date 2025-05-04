#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int BLOCK_SIZE = 5;
const int MAX_FILE_SIZE = 100;

int main()
{
    {
        ofstream outFile("config.txt");
        if (!outFile.is_open())
        {
            cerr << "Error: Could not create/open file for writing." << endl;
            return 1;
        }
        outFile << "AAAAA" << "BBBBB" << "CCCCC";
        outFile.close();
    }

    fstream file("config.txt", ios::in | ios::out | ios::binary);
    if (!file.is_open())
    {
        cerr << "Error: Could not open file for reading and writing." << endl;
        return 1;
    }

    int secondBlockPosition = BLOCK_SIZE;
    file.seekp(secondBlockPosition);

    string newData = "XXXXX";
    file.write(newData.c_str(), BLOCK_SIZE);

    file.close();

    {
        ifstream inFile("config.txt");
        if (!inFile.is_open())
        {
            cerr << "Error: Could not open file for reading." << endl;
            return 1;
        }

        char fileContent[MAX_FILE_SIZE];
        inFile.read(fileContent, MAX_FILE_SIZE);
        if (inFile.gcount() > 0)
        {
            cout.write(fileContent, inFile.gcount());
        }
        cout << endl;
        inFile.close();
    }

    return 0;
}
