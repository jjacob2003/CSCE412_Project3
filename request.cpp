#include "request.h"

/**
 * @brief Constructs a Request with the given IP addresses and processing time.
 * 
 * @param ip_in IP address of the requester.
 * @param ip_out IP address for the results.
 * @param time Processing time for the request (in clock cycles).
 */
Request::Request(const std::string& ip_in, const std::string& ip_out, int time)
    : ip_in(ip_in), ip_out(ip_out), time(time) {}

/**
 * @brief Gets the IP address of the requester.
 * 
 * @return IP address of the requester.
 */
std::string Request::getIpIn() const {
    return ip_in;
}

/**
 * @brief Gets the IP address for the results.
 * 
 * @return IP address for the results.
 */
std::string Request::getIpOut() const {
    return ip_out;
}

/**
 * @brief Gets the processing time for the request.
 * 
 * @return Processing time for the request (in clock cycles).
 */
int Request::getTime() const {
    return time;
}
