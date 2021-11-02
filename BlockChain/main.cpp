#include <iostream>
#include <vector>
using namespace std;
struct TransactionData
{
    double amount;
    std::string senderKey;
    std::string receiverKey;
    time_t timestamp;

    TransactionData(){};

    TransactionData(double amt, std::string sender, std::string receiver, time_t time)
    {
        amount = amt;
        senderKey = sender;
        receiverKey = receiver;
        timestamp = time;
    };
};
class Block
{
private:
    int index;
    size_t blockHash;
    size_t previousHash;
    size_t generateHash();

public:
    Block(int idx, TransactionData d, size_t prevHash);

    int getIndex();

    size_t getHash();

    size_t getPreviousHash();

    TransactionData data;

    bool isHashValid();
};


class Blockchain
{
private:
    Block createGenesisBlock();
    std::vector<Block> chain;

public:
    Blockchain();

    std::vector<Block> getChain();
    Block *getLatestBlock();
    bool isChainValid();
    void addBlock(TransactionData data);
    void printBlockchain();
};
Block::Block(int idx, TransactionData d, size_t prevHash)
{
    index = idx;
    data = d;
    previousHash = prevHash;
    blockHash = generateHash();
}

int Block::getIndex()
{
    return index;
}


size_t Block::generateHash()
{
    std::string toHashS = std::to_string(data.amount) + data.receiverKey + data.senderKey + std::to_string(data.timestamp);

    std::hash<std::string> tDataHash; // hashes transaction data string
    std::hash<std::string> prevHash; // re-hashes previous hash (for combination)

    return tDataHash(toHashS) ^ (prevHash(std::to_string(previousHash)) << 1);
}

size_t Block::getHash()
{
    return blockHash;
}

size_t Block::getPreviousHash()
{
    return previousHash;
}

bool Block::isHashValid()
{
    return generateHash() == getHash();
}
Blockchain::Blockchain()
{
    Block genesis = createGenesisBlock();
    chain.push_back(genesis);
}

std::vector<Block> Blockchain::getChain() {
    return chain;
}

Block Blockchain::createGenesisBlock()
{
    time_t current;

    TransactionData d(0, "Genesis", "Genesis", time_t(&current));

    Block genesis(0, d, 0);
    return genesis;
}
Block *Blockchain::getLatestBlock()
{
    return &chain.back();
}

void Blockchain::addBlock(TransactionData d)
{
    int index = (int)chain.size();
    size_t previousHash;
if((int)chain.size() > 0){
     previousHash =  getLatestBlock()->getHash();
}
else {
     previousHash = 0;
}
    Block newBlock(index, d, previousHash);
    chain.push_back(newBlock);
}

bool Blockchain::isChainValid()
{
    std::vector<Block>::iterator it;

    for (it = chain.begin(); it != chain.end(); ++it)
    {
        Block currentBlock = *it;
        if (!currentBlock.isHashValid())
        {
            return false;
        }

        // Don't forget to check if this is the first item
        if (it != chain.begin())
        {
            Block previousBlock = *(it - 1);
            if (currentBlock.getPreviousHash() != previousBlock.getHash())
            {
                return false;
            }
        }
    }

    return true;
}

void Blockchain::printBlockchain() {
    std::vector<Block>::iterator it;

    for (it = chain.begin(); it != chain.end(); ++it)
    {
        Block currentBlock = *it;
        cout<<"\n\nBlock ===================================\n"
            <<"Index: "<<currentBlock.getIndex()
            <<"\nAmount: "<<currentBlock.data.amount
            <<endl<<"SenderKey: "<<currentBlock.data.senderKey.c_str()
            <<endl<<"ReceiverKey: "<<currentBlock.data.receiverKey.c_str()
            <<endl<<"Timestamp: "<<currentBlock.data.timestamp
            <<endl<<"Hash: "<<currentBlock.getHash()
            <<endl<<"Previous Hash: "<<currentBlock.getPreviousHash()
            <<endl<<"Is Block Valid?: "<<currentBlock.isHashValid();
    }
}
int main()
{

    Blockchain awesomeCoin;

    time_t data1Time;
    TransactionData data1(1.5, "Joe", "Sally", time_t(&data1Time));
    awesomeCoin.addBlock(data1);

    time_t data2Time;
    TransactionData data2(0.2233, "Martha", "Fred", time_t(&data2Time));
    awesomeCoin.addBlock(data2);

    awesomeCoin.printBlockchain();


    printf("\nIs chain still valid? %d\n", awesomeCoin.isChainValid());

    Block *hackBlock = awesomeCoin.getLatestBlock();
    hackBlock->data.amount = 10000;
    hackBlock->data.receiverKey = "Jon";


    awesomeCoin.printBlockchain();

    printf("\nIs chain still valid? %d\n", awesomeCoin.isChainValid());

    return 0;
}