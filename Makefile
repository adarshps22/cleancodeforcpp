all:
	g++ -Wall -Wextra -o testcheck paramchecker.cpp testparamchecker.cpp -lgtest -lpthread -std=c++11
