#include <iostream>
#include "processor.h"

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() { 
    // This function is based in part on https://stackoverflow.com/questions/23367857/accurate-calculation-of-cpu-usage-given-in-percentage-in-linux
    cpustrings = LinuxParser::CpuUtilization();
    Idle = std::stoi(cpustrings[3]) + std::stoi(cpustrings[4]);
    NonIdle = std::stoi(cpustrings[0]) + std::stoi(cpustrings[1]) + std::stoi(cpustrings[2]) +
        std::stoi(cpustrings[5]) + std::stoi(cpustrings[6]) + std::stoi(cpustrings[7]);
    Total = Idle + NonIdle;
    totald = Total - PrevTotal;
    idled = Idle - PrevIdle;
    PrevIdle = Idle;
    PrevNonIdle = NonIdle;
    PrevTotal = Total;
    return (float)(totald - idled)/(float)totald;
}