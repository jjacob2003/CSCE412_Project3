#ifndef REQUESTQUEUE_H
#define REQUESTQUEUE_H

#include <queue>
#include "request.h"

/**
 * @brief Manages a queue of web requests.
 */
class RequestQueue {
public:
    /**
     * @brief Adds a request to the queue.
     * 
     * @param request The request to be added.
     */
    void enqueue(const Request& request);

    /**
     * @brief Removes and returns the request at the front of the queue.
     * 
     * @return The request at the front of the queue.
     * @throws std::out_of_range if the queue is empty.
     */
    Request dequeue();

    /**
     * @brief Checks if the queue is empty.
     * 
     * @return True if the queue is empty, false otherwise.
     */
    bool isEmpty() const;

    /**
     * @brief Returns the number of requests in the queue.
     * 
     * @return The number of requests in the queue.
     */
    int size() const;

private:
    std::queue<Request> queue; 
};

#endif // REQUESTQUEUE_H
