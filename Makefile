
CXX = g++

CFLAGS = -Wall -O -g
TARGET = HttpTest

OBJS = http_get_post/HttpRequest.o main.o

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -ldl -o $(TARGET) $(CFLAGS) 
	#@clear
	
	
main.o: main.cpp http_get_post/HttpRequest.h
	$(CXX) $(CFLAGS) -c main.cpp
	
HttpRequest.o: http_get_post/HttpRequest.cpp http_get_post/HttpRequest.h
	$(CXX) $(CFLAGS) -c HttpRequest.cpp

clean:
	#@clear
	@echo 正在移除...
	rm -rf *.o 
	
