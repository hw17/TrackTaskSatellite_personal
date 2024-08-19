#ifndef TIME_H
#define TIME_H

#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <iomanip>
#include <chrono>
#include <vector>

std::string timeStamp(void);
//std::string printOut(char *out1, char *out2, char *out3);
std::string printOut(std::vector<std::string> out1, std::vector<std::string> out2, std::vector<std::string> out3);

#endif /* TIME_H */