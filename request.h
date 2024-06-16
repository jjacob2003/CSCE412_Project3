#ifndef REQUEST_H
#define REQUEST_H

#include <string>

/**
 * @brief Represents a web request with input and output IP addresses and processing time.
 */
class Request {
public:
    /**
     * @brief Constructs a Request with the given IP addresses and processing time.
     * 
     * @param ip_in IP address of the requester.
     * @param ip_out IP address for the results.
     * @param time Processing time for the request (in clock cycles).
     */
    Request(const std::string& ip_in, const std::string& ip_out, int time);

    /**
     * @brief Gets the IP address of the requester.
     * 
     * @return IP address of the requester.
     */
    std::string getIpIn() const;

    /**
     * @brief Gets the IP address for the results.
     * 
     * @return IP address for the results.
     */
    std::string getIpOut() const;

    /**
     * @brief Gets the processing time for the request.
     * 
     * @return Processing time for the request (in clock cycles).
     */
    int getTime() const;

private:
    std::string ip_in; 
    std::string ip_out; 
    int time; 
};

#endif // REQUEST_H
