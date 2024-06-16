#include "webserver.h"

/**
 * @brief Constructs a WebServer object.
 */
WebServer::WebServer() : isBusy(false), remainingTime(0) {}

/**
 * @brief Checks if the web server is available.
 * 
 * @return True if the web server is available, false otherwise.
 */
bool WebServer::isAvailable() const {
    return !isBusy;
}

/**
 * @brief Processes a request by setting the server as busy and initializing the remaining time.
 * 
 * @param request The request to be processed.
 */
void WebServer::processRequest(const Request& request) {
    isBusy = true;
    remainingTime = request.getTime();
}

/**
 * @brief Ticks the server's clock, decrementing the remaining processing time.
 *        If the remaining time reaches zero, the server becomes available.
 */
void WebServer::tick() {
    if (isBusy) {
        remainingTime--;
        if (remainingTime <= 0) {
            isBusy = false;
        }
    }
}
