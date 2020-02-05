#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <string>
#include "linux_parser.h"

using std::string;

class Processor {
 public:
  float Utilization();  // TODO: See src/processor.cpp

  // TODO: Declare any necessary private members
 private:
  std::vector<string> cpustrings;
  int PrevIdle = 0, Idle, PrevNonIdle = 0, NonIdle, PrevTotal = 0, Total, totald, idled;
};

#endif