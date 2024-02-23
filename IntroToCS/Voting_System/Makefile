application:
	rm -rf build/
	mkdir build
	cd build && cmake ..
	cd build && cmake --build .

clean:
	rm -rf build/
	mkdir build

run:
	cd app && ./VotingSystem Tyler Bill Eli Bob

debug:
	rm -rf build/
	mkdir build
	cd build && cmake .. -DDEBUG=ON
	cd build && cmake --build .