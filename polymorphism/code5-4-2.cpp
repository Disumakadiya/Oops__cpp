#include <iostream>
#include <cmath>
using namespace std;

class Fahrenheit; // Forward declaration

class Celsius {
    float tempC;
public:
    Celsius(float t = 0.0) : tempC(t) {}

    float getTemp() const
     {
        return tempC;
    }

    // Convert Celsius to Fahrenheit
    operator Fahrenheit();

    // Compare two Celsius objects
    bool operator==(const Celsius& other) const 
    {
        return abs(tempC - other.tempC) < 0.001;
    }
};

class Fahrenheit 
{
    float tempF;
public:
    Fahrenheit(float t = 32.0) : tempF(t) {}

    float getTemp() const 
    {
        return tempF;
    }

    // Convert Fahrenheit to Celsius
    operator Celsius()
     {
        return Celsius((tempF - 32) * 5.0 / 9);
    }

    // Compare two Fahrenheit objects
    bool operator==(const Fahrenheit& other) const 
    {
        return abs(tempF - other.tempF) < 0.001;
    }
};

// Define the conversion from Celsius to Fahrenheit
Celsius::operator Fahrenheit() 
{
    return Fahrenheit(tempC * 9.0 / 5 + 32);
}

// Struct to hold conversion result
struct TemperatureConversion 
{
    string fromUnit;
    string toUnit;
    float originalValue;
    float convertedValue;
};

int main() 
{
    const int MAX_CONVERSIONS = 5;
    TemperatureConversion conversions[MAX_CONVERSIONS];
    int count = 0;

    // Example conversions
    Celsius c1(100);               // 100°C
    Fahrenheit f1 = c1;            // Convert to Fahrenheit

    conversions[count++] = {"Celsius", "Fahrenheit", c1.getTemp(), f1.getTemp()};

    Fahrenheit f2(32);             // 32°F
    Celsius c2 = f2;               // Convert to Celsius

    conversions[count++] = {"Fahrenheit", "Celsius", f2.getTemp(), c2.getTemp()};

    // Optional: compare temperatures
    if (c1 == c2) {
        cout << "Temperatures are equal in Celsius.\n";
    } else {
        cout << "Temperatures are not equal in Celsius.\n";
    }

    // Display all stored conversions
    cout << "\nStored Temperature Conversions (Static Array):\n";
    for (int i = 0; i < count; ++i) {
        cout << conversions[i].originalValue << " " << conversions[i].fromUnit
             << " = " << conversions[i].convertedValue << " " << conversions[i].toUnit << endl;
    }

    return 0;
}