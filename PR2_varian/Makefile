CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude
TARGET = pr2_variant5
SRC = src/main.cpp src/math_utils.cpp src/fermat.cpp src/euclid.cpp src/inverse.cpp src/shamir_file.cpp src/mitm_attack.cpp src/fraction_equation.cpp src/rf_crypto_standards.cpp src/text_file.cpp

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
	rm -f data/encrypted_shamir.txt data/decrypted.txt
