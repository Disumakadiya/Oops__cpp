#include <iostream>
#include <queue>
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

    operator Fahrenheit();

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

    operator Celsius()
    {
        return Celsius((tempF - 32) * 5.0 / 9);
    }

    bool operator==(const Fahrenheit& other) const
    {
        return abs(tempF - other.tempF) < 0.001;
    }
};

// Celsius to Fahrenheit conversion
Celsius::operator Fahrenheit()
{
    return Fahrenheit(tempC * 9.0 / 5 + 32);
}

// Struct to store conversion result
struct TemperatureConversion
{
    string fromUnit;
    string toUnit;
    float originalValue;
    float convertedValue;
};

int main()
{
    queue<TemperatureConversion> conversionQueue;
    int n;

    cout << "How many conversions do you want to perform? ";
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        float value;
        char fromUnit;

        cout << "\nEnter temperature value: ";
        cin >> value;

        cout << "Convert from (C for Celsius, F for Fahrenheit): ";
        cin >> fromUnit;

        if (fromUnit == 'C' || fromUnit == 'c')
         {
            Celsius c(value);
            Fahrenheit f = c;
            conversionQueue.push({"Celsius", "Fahrenheit", c.getTemp(), f.getTemp()});
        } 
        else if (fromUnit == 'F' || fromUnit == 'f')
         {
            Fahrenheit f(value);
            Celsius c = f;
            conversionQueue.push({"Fahrenheit", "Celsius", f.getTemp(), c.getTemp()});
        } 
        else
         {
            cout << "Invalid unit entered. Please enter 'C' or 'F'." << endl;
            --i; // retry current iteration
        }
    }

    // Display results
    cout << "\nTemperature Conversion Results:\n";
    int size = conversionQueue.size();
    for (int i = 0; i < size; ++i)
    {
        TemperatureConversion t = conversionQueue.front();
        cout << t.originalValue << " " << t.fromUnit << " = " 
             << t.convertedValue << " " << t.toUnit << endl;
        conversionQueue.pop();
    }

    return 0;
}
