all:
	arm-linux-gnueabi-g++ ./src/*.cpp -o ./bin/target -I ./include -lpthread