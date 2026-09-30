#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Device {
private:
    string deviceId;
    string deviceName;
    string location;
    string status;
    string lastUpdated;

public:
    Device(string id, string name, string loc)
        : deviceId(id), deviceName(name), location(loc),
          status("OFF"), lastUpdated("Not updated") {}

    void switchOn(string time) {
        status = "ON";
        lastUpdated = time;
    }

    void switchOff(string time) {
        status = "OFF";
        lastUpdated = time;
    }

    void display() const {
        cout << "Device ID: " << deviceId
             << " | Device: " << deviceName
             << " | Location: " << location
             << " | Status: " << status
             << " | Last Updated: " << lastUpdated << endl;
    }
};

int main() {
    vector<Device> devices;

    devices.emplace_back("D001", "Light", "Bedroom");
    devices.emplace_back("D002", "Thermostat", "Living Room");
    devices.emplace_back("D003", "Camera", "Main Door");
    devices.emplace_back("D004", "Door Lock", "Main Door");

    devices[0].switchOn("08:00 AM");
    devices[1].switchOn("08:05 AM");
    devices[2].switchOn("08:10 AM");
    devices[3].switchOff("08:15 AM");

    cout << "=== Smart Home Dashboard ===" << endl;

    for (const auto& device : devices) {
        device.display();
    }

    return 0;
}