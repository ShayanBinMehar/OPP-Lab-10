#include <iostream>
#include <string>

using namespace std;

int main()
{
    string yearString = "2023";

    int yearInteger;

    try
    {
        yearInteger = stoi(yearString);
        cout << "Year as integer: " << yearInteger << endl;
    }
    catch (const std::invalid_argument &e)
    {
        cerr << "Error: Invalid argument for stoi.  The string could not be converted to an integer." << endl;
        return 1;
    }
    catch (const std::out_of_range &e)
    {
        cerr << "Error: stoi: The value is out of the range of representable integers." << endl;
        return 1;
    }

    return 0;
}
