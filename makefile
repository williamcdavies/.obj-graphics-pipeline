driver: driver.o
	g++ -std=c++11 -lncurses -o driver driver.o -g

driver.o: driver.cpp
	g++ -std=c++11 -c driver.cpp -g
	
clean:
	rm -f *.o driver

new:
	rm -f *.o driver
	make