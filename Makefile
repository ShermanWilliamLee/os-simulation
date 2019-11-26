TARGET = sim1
LIBS = -lm 
#Math Library, just a placeholder
HEADERS = Simulator.h MetaData.h
SRCS = DisplayMetrics.cpp Simulator.cpp MetaData.cpp
OBJECTS := $(patsubst %.cpp,%.o,$(SRCS))
CXX = g++ 
CXX_FLAGS = -std=c++11 
#C++11 just for reference, not necessary

.PHONY: default all clean

all: depend $(TARGET)

#Rules to recompile template headers when they change
depend: .depend
.depend: $(HEADERS)
	rm -f ./.depend
	$(CXX) $(CXX_FLAGS) -MM $^ > ./.depend;
include .depend

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXX_FLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CXX) $(CXX_FLAGS) $(OBJECTS) $(LIBS) -o $@

clean:
	-rm -f *.o
	-rm -f ./.depend
	-rm -f $(TARGET)
