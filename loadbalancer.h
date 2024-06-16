#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include <vector>
#include "webserver.h"
#include "requestqueue.h"

/**
 * @brief Manages a set of web servers and a request queue to balance incoming web requests.
 */
class LoadBalancer {
public:
    /**
     * @brief Constructs a LoadBalancer with the given number of web servers.
     * 
     * @param numServers Number of web servers managed by the load balancer.
     */
    LoadBalancer(int numServers);

    /**
     * @brief Adds a request to the request queue.
     * 
     * @param request The request to be added.
     */
    void addRequest(const Request& request);

    /**
     * @brief Balances the load by assigning requests from the queue to available web servers.
     */
    void balanceLoad();

    /**
     * @brief Runs the load balancer for the specified number of clock cycles.
     * 
     * @param cycles Number of clock cycles to run the load balancer.
     */
    void run(int cycles);

private:
    std::vector<WebServer> servers; 
    RequestQueue requestQueue; 
    int totalTime; 
};

#endif // LOADBALANCER_H
