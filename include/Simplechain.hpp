#pragma once
#include <vector>
#include <cstdint>
#include "block.hpp"

using namespace std;

class SimpleChain {
public:
    SimpleChain(uint32_t difficulty);
    void addBlock(Block block);
private:
    uint32_t _difficulty;
    vector<Block> _chain;
    Block getLastBlock() const;
};
