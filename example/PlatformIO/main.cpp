

#include <Arduino.h>

extern "C"
{
    #include <gcov_public.h>
}

//*******************************************************************
// Functions
//*******************************************************************

void GcovInit()
{
    // want this as early as possible,
    // but cannot call this until after
    // the trap table and system stuff are set up
    // may not be needed in all systems, depending on startup code
    // __gcov_call_constructors();
}

void GcovEnd()
{
    __gcov_exit(); // dumps the data
}

//*******************************************************************
// Setup and loop
//*******************************************************************

bool g_dumpGcov = true;
uint32_t g_uptime_s = 30;  // generates the gcov dump at 30 s of uptime

void setup()
{
    Serial.begin(115200);
    while (!Serial)
    {
        delay(10);
    }

    setupFs();
    GcovInit();

    Serial.println();
    Serial.println("Hello from Arduino!");
    Serial.println();
}

void loop()
{
    if (g_dumpGcov && millis() > (g_uptime_s * 1000))
    {
        Serial.println("Dumping Gcov data");
        delay(1000);
        GcovEnd();
        Serial.println("Dump Gcov finished");
        g_dumpGcov = false;
    }
}
