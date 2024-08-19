#include "time.h"

std::string timeStamp(){
    std::ostringstream strStream;
    std::time_t t = std::time(nullptr); //get EPOCH time
    //strStream<< "[" << std::put_time(std::localtime(&t), "%T") << "] ";
    strStream << "timestamp: " << t << " ";
    return strStream.str();
}

std::string printOut(std::vector<std::string> out1, std::vector<std::string> out2, std::vector<std::string> out3){
    std::ostringstream strOutput;
    //std::time_t t = std::time(nullptr); //get EPOCH time
    double now = std::chrono::duration_cast<std::chrono::milliseconds> (std::chrono::system_clock::now().time_since_epoch()).count(); //get EPOCH time
    //Print the recent value in the buffer
    strOutput << std::fixed << std::setprecision(0) \
              << "{\"timeStamp\": "<< now << ", "  \
              << "\"-out1\": \""<< out1.front().substr(0,out1.front().find('\n')) <<"\", " \
              << "\"-out2\": \""<< out2.front().substr(0,out2.front().find('\n')) <<"\", " \
              << "\"-out3\": \""<< out3.front().substr(0,out3.front().find('\n')) <<"\"}";

    return strOutput.str();
}