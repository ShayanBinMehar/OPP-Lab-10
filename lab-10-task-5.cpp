#include <iostream>
#include <string>

using namespace std;

int main()
{
    string vehicleType = "HybridTruck";
    string extraData = "Cargo:500|Battery:24";
    string vehicleId = "HT123";

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
    else if (vehicleType == "HybridTruck")
    {
        size_t colonPos = extraData.find(':');
        size_t pipePos = extraData.find('|');

        if (colonPos != string::npos && pipePos != string::npos)
        {
            string cargoString = extraData.substr(colonPos + 1, pipePos - (colonPos + 1));
            int cargoWeight = stoi(cargoString);

            size_t batteryColonPos = extraData.find("Battery:");
            string batteryString = extraData.substr(batteryColonPos + 8);
            int batteryCapacity = stoi(batteryString);

            cout << "Vehicle ID: " << vehicleId << ", Cargo Weight: " << cargoWeight << ", Battery Capacity: " << batteryCapacity << endl;
        }
        else
        {
            cerr << "Error: Colon or pipe not found in ExtraData for HybridTruck." << endl;
        }
    }
    else
    {
        cout << "Vehicle Type " << vehicleType << " is unknown." << endl;
    }

    return 0;
}
