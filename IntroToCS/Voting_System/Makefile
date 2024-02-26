application:
	rm -rf build/
	mkdir build
	cd build && cmake ..
	cd build && cmake --build .

clean:
	rm -rf build/
	mkdir build

run:
# 	CHANGE THIS LINE 
	cd app && ./VotingSystem Tyler Brian Vanissa Jacob Daniel

debug:
	rm -rf build/
	mkdir build
	cd build && cmake .. -DDEBUG=ON
	cd build && cmake --build .