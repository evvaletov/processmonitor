#include <unistd.h>
#include <cstddef>
#include <set>
#include <string>
#include <vector>
#include <iostream>

#include "process.h"
#include "processor.h"
#include "system.h"

using std::set;
using std::size_t;
using std::string;
using std::vector;

// TODO: Return the system's CPU
Processor& System::Cpu() {     
    return cpu_;
}

// TODO: Return a container composed of the system's processes
vector<Process>& System::Processes() { 
    pids_ = LinuxParser::Pids();
    processes_new_ = {};
    // std::cout << "PIDS size: " << pids_.size() << std::endl;
    for (auto pid: pids_) {
        found_process_ = false;
        for (auto process: processes_)
            if (pid == process.Pid()) {
                found_process_ = true;
                processes_new_.push_back(process);
            }
        if (!found_process_) {
            Process new_process{pid};
            processes_new_.push_back(new_process);
        }
    }
    processes_ = processes_new_;
    // std::cout << "Processes size: " << processes_.size() << std::endl;
    return processes_;
}

// TODO: Return the system's kernel identifier (string)
std::string System::Kernel() { return LinuxParser::Kernel(); }

// TODO: Return the system's memory utilization
float System::MemoryUtilization() { return LinuxParser::MemoryUtilization(); }

// TODO: Return the operating system name
std::string System::OperatingSystem() { return LinuxParser::OperatingSystem(); }

// TODO: Return the number of processes actively running on the system
int System::RunningProcesses() { return LinuxParser::RunningProcesses(); }

// TODO: Return the total number of processes on the system
int System::TotalProcesses() { return LinuxParser::TotalProcesses(); }

// TODO: Return the number of seconds since the system started running
long int System::UpTime() { return LinuxParser::UpTime(); }