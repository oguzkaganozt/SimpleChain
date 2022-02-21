//Simple blockchain mining example
//Oguz Ozturk
#include "../include/SimpleChain.hpp"
#include "../include/Block.hpp"

int main(int argc, char** argv) {
    SimpleChain chain(1);

    cout << "Minining block 1..." << endl;
    chain.addBlock(Block(1,"Block 1 Hello World"));
    cout << "Added block 1" << endl;

    return 0;
}