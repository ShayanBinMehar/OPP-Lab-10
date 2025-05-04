#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream outFile("sensorLog.txt");
    if (!outFile.is_open())
    {
        cerr << "Error: Could not open file for writing." << endl;
        return 1;
    }

    string data1 = "Sensor1: 25.5 C\n";
    outFile << data1;
    cout << "After writing data1, write position: " << outFile.tellp() << endl;

    string data2 = "Sensor2: 78% RH\n";
    outFile << data2;
    cout << "After writing data2, write position: " << outFile.tellp() << endl;

    string data3 = "Sensor3: 1013 hPa\n";
    outFile << data3;
    cout << "After writing data3, write position: " << outFile.tellp() << endl;

    outFile.close();

    cout << "Finished writing to file.\n";
    return 0;
}
