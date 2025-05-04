#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream inFile("vehicles.txt");

    if (!inFile.is_open())
    {
        cout << "Error: Could not open the file 'vehicles.txt'." << endl;
        return 1;
    }

    string line;
    while (getline(inFile, line))
    {
        if (line.empty() || line[0] == '#')
        {
            continue;
        }

        string type = "", id = "", name = "", year = "", extraData = "", certification = "";

        int fieldIndex = 0;
        string current = "";

        for (int i = 0; i <= line.length(); i++)
        {
            char ch = line[i];

            if (ch == ',' || ch == '\0')
            {
                switch (fieldIndex)
                {
                case 0:
                    type = current;
                    break;
                case 1:
                    id = current;
                    break;
                case 2:
                    name = current;
                    break;
                case 3:
                    year = current;
                    break;
                case 4:
                    extraData = current;
                    break;
                case 5:
                    certification = current;
                    break;
                }
                current = "";
                fieldIndex++;
            }
            else
            {
                current += ch;
            }
        }

        cout << "Type: " << type << "\nID: " << id << "\nName: " << name
             << "\nYear: " << year << "\nExtraData: " << extraData
             << "\nCertification: " << certification << "\n----------------------\n";
    }

    inFile.close();
    return 0;
}
