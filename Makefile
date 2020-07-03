#flags passed to the g++ compiler
CXXFLAGS += -g -std=c++17
SOURCE_FILE += ccqueue.cpp dlinkedlist.cpp ticket.cpp

all:
  $(CXX) $(CXXFLAGS) -c $(SOURCE_FILE)
