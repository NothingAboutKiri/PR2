CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude
TARGET = pr2_variant5
SRC = src/main.cpp src/math_utils.cpp src/task1_fermat.cpp src/task2_euclid.cpp src/task3_inverse.cpp src/task4_shamir_file.cpp src/task5_text.cpp src/task6_fraction.cpp src/task7_text.cpp src/text_file.cpp

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
	rm -f data/encrypted_shamir.txt data/decrypted.txt
