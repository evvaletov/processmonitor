#include <string>
#include <sstream>
#include <iomanip>

#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) {
    int hh, mm, ss;
    string timestring;
    hh = seconds / 3600;
    ss = seconds - hh * 3600;
    mm = ss / 60;
    ss = ss - mm * 60;
    std::ostringstream out;
    out << std::setfill('0') << std::setw(2) << hh;
    out << ":";
    out << std::setfill('0') << std::setw(2) << mm;
    out << ":";
    out << std::setfill('0') << std::setw(2) << ss;
    return out.str();
}