#include <vector>
#include <sstream>
#include "../include/Block.hpp"
#include "../include/sha256.hpp"

using namespace std;

//implementation of Block class
Block::Block(uint32_t index, const string& data) : _index(index), _data(data) {
    this->_timestamp = time(NULL);
    this->_nonce = -1;
}

//try to calculate hash until it is valid
void Block::mineBlock(uint32_t difficulty) {
    // vector<char> zeros(difficulty, '0');
    // zeros.push_back('\0');

    // string str(zeros.begin(), zeros.end());
    string str(difficulty, '0');
    str.push_back('\0'); // ?

    do
    {
        _nonce++;
        _hash = this->calculateHash();
    } while (_hash.substr(0, difficulty) != str);
    
    cout << "Block mined: " << _hash << endl;
}

//calculate hash of the block
inline string Block::calculateHash() const {
    stringstream ss;
    ss << _index << _timestamp << _nonce << _data << prevHash;

    return sha256(ss.str());
}

string Block::getHash() {
    return this->_hash;
}