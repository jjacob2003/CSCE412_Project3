 # compiler
CXX = g++
# compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra
# executable name
TARGET = load_balancer

# source files
SRCS = main.cpp loadbalancer.cpp webserver.cpp request.cpp requestqueue.cpp
# object files
OBJS = $(SRCS:.cpp=.o)
# header files
HEADERS = loadbalancer.h webserver.h request.h requestqueue.h

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
