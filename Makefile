CPPS=$(wildcard src/*.cpp)
OBJS=$(CPPS:src/%.cpp=obj/%.o)

all: $(OBJS)
	g++ -g $^ -o bin/SchoolMgmtSystem

obj/%.o: src/%.cpp
	g++ -g -c -I./include/entities -I./include/database -I./include/manager $< -o $@

clean:
	rm -f obj/*
