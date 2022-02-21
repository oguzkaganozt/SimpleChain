#include "../include/SimpleChain.hpp"

SimpleChain::SimpleChain(uint32_t difficulty) : _difficulty(difficulty) {
    _chain.emplace_back(Block(0, "Genesis Block"));
}

void SimpleChain::addBlock(Block block) {
    block.prevHash = _chain.back().getHash();
    block.mineBlock(this->_difficulty);
    _chain.push_back(block);    //hash successfully generated and block added to chain
}

Block SimpleChain::getLastBlock() const {
    return _chain.back();
}