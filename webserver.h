#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "request.h"

/**
 * @brief Represents a web server that can process requests.
 */
class WebServer {
public:
    /**
     * @brief Constructs a WebServer object.
     */
    WebServer();

    /**
     * @brief Checks if the web server is available.
     * 
     * @return True if the web server is available, false otherwise.
     */
    bool isAvailable() const;

    /**
     * @brief Processes a request by setting the server as busy and initializing the remaining time.
     * 
     * @param request The request to be processed.
     */
    void processRequest(const Request& request);

    /**
     * @brief Ticks the server's clock, decrementing the remaining processing time.
     *        If the remaining time reaches zero, the server becomes available.
     */
    void tick();

private:
    bool isBusy; 
    int remainingTime; 
};

#endif // WEBSERVER_H
