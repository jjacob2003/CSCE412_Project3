#include "requestqueue.h"
#include <stdexcept>

/**
 * @brief Adds a request to the queue.
 * 
 * @param request The request to be added.
 */
void RequestQueue::enqueue(const Request& request) {
    queue.push(request);
}

/**
 * @brief Removes and returns the request at the front of the queue.
 * 
 * @return The request at the front of the queue.
 * @throws std::out_of_range if the queue is empty.
 */
Request RequestQueue::dequeue() {
    if (!queue.empty()) {
        Request req = queue.front();
        queue.pop();
        return req;
    }
    throw std::out_of_range("Queue is empty");
}

/**
 * @brief Checks if the queue is empty.
 * 
 * @return True if the queue is empty, false otherwise.
 */
bool RequestQueue::isEmpty() const {
    return queue.empty();
}

/**
 * @brief Returns the number of requests in the queue.
 * 
 * @return The number of requests in the queue.
 */
int RequestQueue::size() const {
    return queue.size();
}
