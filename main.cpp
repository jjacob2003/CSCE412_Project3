#include <iostream>
#include <cstdlib>
#include <ctime>   

#include "loadbalancer.h"

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int numServers, runTime;

    std::cout << "Enter the number of servers: ";
    std::cin >> numServers;
    std::cout << "Enter the total runtime (in clock cycles): ";
    std::cin >> runTime;

    LoadBalancer lb(numServers);

    for (int i = 0; i < numServers * 100; ++i) {
        std::string ip_in = "192.168.0." + std::to_string(rand() % 256);
        std::string ip_out = "10.0.0." + std::to_string(rand() % 256);
        int time = rand() % 100 + 1;
        Request req(ip_in, ip_out, time);
        lb.addRequest(req);
    }

    lb.run(runTime);

    return 0;
}
