#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    {
        ofstream outFile("data_records.txt");
        if (!outFile.is_open()) {
            cerr << "Error creating data_records.txt" << endl;
            return 1;
        }
        outFile << "Record 1\n";
        outFile << "Record 2\n";
        outFile << "Record 3\n";
        outFile << "Record 4\n";
        outFile.close();
    }

    ifstream inFile("data_records.txt");
    if (!inFile.is_open()) {
        cerr << "Error: Could not open file for reading." << endl;
        return 1;
    }

    int offset = 10 + 10;

    inFile.seekg(offset, ios::beg);

    string thirdRecord;
    getline(inFile, thirdRecord);
    cout << "Third record: " << thirdRecord << endl;

    inFile.close();

    return 0;
}
