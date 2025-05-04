#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    
    {
        ofstream outFile("large_log.txt");
        if (!outFile.is_open()) {
            cerr << "Error creating large_log.txt" << endl;
            return 1;
        }
        outFile << "This is the first line.\n";
        outFile << "This is the second line.\n";
        outFile << "This is the third line.\n";
        outFile.close();
    }

    ifstream inFile("large_log.txt");
    if (!inFile.is_open()) {
        cerr << "Error: Could not open file for reading." << endl;
        return 1;
    }

    char buffer1[11];
    inFile.read(buffer1, 10);
    buffer1[10] = '\0'; 
    cout << "Read: " << buffer1 << endl;
    cout << "Current read position: " << inFile.tellg() << endl;

    char buffer2[11];
    inFile.read(buffer2, 10);
    buffer2[10] = '\0';
    cout << "Read: " << buffer2 << endl;
    cout << "Current read position: " << inFile.tellg() << endl;

    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    cout << "Current read position: " << inFile.tellg() << endl;

    inFile.close();

    return 0;
}
