CXX = g++
SRCS = $(wildcard src/*.cpp)
OBJS = $(patsubst src/%.cpp, obj/%.o, $(SRCS))


thumbnail_viewer : obj $(OBJS) main.cpp
	$(CXX) `pkg-config --cflags gtk+-3.0` $(OBJS) main.cpp -o $@ `pkg-config --libs gtk+-3.0`

obj : 
	mkdir  obj
	
obj/%.o : src/%.cpp
	$(CXX) `pkg-config --cflags gtk+-3.0` -c $< -o $@ `pkg-config --libs gtk+-3.0`

clean :
	rm -rf thumbnail_viewer obj 