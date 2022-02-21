#Simple Test Blockchain
TARGET_EXE := SimpleChain.exe
BUILD_DIR := build
SRC_DIR := src
INC_DIR := include

all: SimpleChain.exe

SimpleChain.exe: $(BUILD_DIR)/SimpleChain.o $(BUILD_DIR)/Block.o $(BUILD_DIR)/sha256.o $(BUILD_DIR)/main.o
	g++ -o SimpleChain.exe $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ -c -o $@ $<

clean:
	rm -f $(BUILD_DIR)/*.o
	rm -f SimpleChain.exe