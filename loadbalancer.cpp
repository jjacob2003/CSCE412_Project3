#include "loadbalancer.h"
#include <cstdlib>
#include <iostream>
#include <fstream>

/**
 * @brief Constructs a LoadBalancer with the given number of web servers.
 * 
 * @param numServers Number of web servers managed by the load balancer.
 */
LoadBalancer::LoadBalancer(int numServers) : totalTime(0) {
    servers.resize(numServers);
}

/**
 * @brief Adds a request to the request queue.
 * 
 * @param request The request to be added.
 */
void LoadBalancer::addRequest(const Request& request) {
    requestQueue.enqueue(request);
}

/**
 * @brief Balances the load by assigning requests from the queue to available web servers.
 */
void LoadBalancer::balanceLoad() {
    for (auto& server : servers) {
        if (!server.isAvailable()) {
            server.tick(); 
        }
        if (server.isAvailable() && !requestQueue.isEmpty()) {
            Request req = requestQueue.dequeue();
            server.processRequest(req); 
        }
    }
}

/**
 * @brief Runs the load balancer for the specified number of clock cycles.
 * 
 * @param cycles Number of clock cycles to run the load balancer.
 */
void LoadBalancer::run(int cycles) {
    std::ofstream logfile("load_balancer_log.txt"); 

    if (!logfile.is_open()) {
        std::cerr << "Error: Unable to open log file!" << std::endl;
        return;
    }

    int startingQueueSize = requestQueue.size(); 

    logfile << "Load Balancer Simulation Log" << std::endl;
    logfile << "Starting with " << servers.size() << " servers running for " << cycles << " clock cycles." << std::endl;
    logfile << "Initial queue size: " << startingQueueSize << std::endl;
    logfile << "Task time range: 1 to 100 clock cycles" << std::endl;
    logfile << "------------------------------------------------------------------" << std::endl;

    for (int i = 0; i < cycles; ++i) {
        if (rand() % 2 == 0) {
            std::string ip_in = "192.168.0." + std::to_string(rand() % 256);
            std::string ip_out = "10.0.0." + std::to_string(rand() % 256);
            int time = rand() % 100 + 1;
            Request req(ip_in, ip_out, time);
            addRequest(req); 
        }
        balanceLoad(); 

        logfile << "Clock cycle: " << i + 1 << std::endl;
        logfile << "Starting queue size: " << startingQueueSize << std::endl;
        logfile << "Request queue size: " << requestQueue.size() << std::endl;
        for (size_t j = 0; j < servers.size(); ++j) {
            logfile << "Server " << j + 1 << " is " 
                    << (servers[j].isAvailable() ? "available" : "busy") 
                    << std::endl;
        }
        logfile << "Ending queue size: " << requestQueue.size() << std::endl;
        logfile << std::endl;
    }

    logfile << "------------------------------------------------------------------" << std::endl;
    logfile.close(); 
}
