#pragma once

#include <cstdint>
#include <iostream>

using namespace std;

//Simple Blockchain Example
//Blockchain is made up of blocks which contain data and a hash of the previous block
//Blocks are linked together using hashes
//Miner creates a block and adds it to the chain by providing required cryptographic data
//Miner can also validate the chain by checking hashes of each block
//Generated has is valid if it contains more zeros than the difficulty set by the network
//If hash generated is not valid then the block is rejected and nonce is incremented so miner has to try again
//This process called Proof of Work(PoW)

class Block {
public:
    string prevHash;
    string getHash();
    void mineBlock(uint32_t difficulty);

    Block(uint32_t index, const string& data);

    Block() {
        this->_index = 0;
        this->_timestamp = 0;
        this->_nonce = 0;
        this->_hash = "";
        this->_data = "";
    }

    void print() {
        cout << "index: " << _index << endl;
        cout << "timestamp: " << _timestamp << endl;
        cout << "nonce: " << _nonce << endl;
        cout << "hash: " << _hash << endl;
        cout << "data: " << _data << endl;
    }

private:
    uint32_t _index;
    int64_t _nonce;
    string _data;
    string _hash;
    time_t _timestamp;

    //not change any data just calculate the hash
    string calculateHash() const;
};