#include <iostream>
#include <string>

using namespace std;

int main()
{
    string vehicleType = "AutonomousCar";
    string extraData = "SoftwareVersion:9.2";
    string vehicleId = "XYZ123";

    if (vehicleType == "AutonomousCar")
    {
        size_t colonPos = extraData.find(':');
        if (colonPos != string::npos)
        {
            string versionString = extraData.substr(colonPos + 1);
            float softwareVersion = stof(versionString);
            cout << "Vehicle ID: " << vehicleId << ", Software Version: " << softwareVersion << endl;
        }
        else
        {
            cerr << "Error: Colon not found in ExtraData for AutonomousCar." << endl;
        }
    }
    else if (vehicleType == "ElectricVehicle")
    {
        size_t colonPos = extraData.find(':');
        if (colonPos != string::npos)
        {
            string capacityString = extraData.substr(colonPos + 1);
            int batteryCapacity = stoi(capacityString);
            cout << "Vehicle ID: " << vehicleId << ", Battery Capacity: " << batteryCapacity << endl;
        }
        else
        {
            cerr << "Error: Colon not found in ExtraData for ElectricVehicle." << endl;
        }
    }
    else
    {
        cout << "Vehicle Type is not AutonomousCar or ElectricVehicle." << endl;
    }

    return 0;
}
