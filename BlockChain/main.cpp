#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <ctime>
#include <mutex>
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
mutex Mutex;
class Miner{


    bool checkCaptcha(string &captcha, string &user_captcha)
    {
        return captcha.compare(user_captcha) == 0;
    }
    string generateCaptcha(int n)
    {
        time_t t;
        srand((unsigned)time(&t));
        // Characters to be included
        char *chrs = "abcdefghijklmnopqrstuvwxyzABCDEFGHI"
                     "JKLMNOPQRSTUVWXYZ0123456789";
        // Generate n characters from above set and
        // add these characters to captcha.
        string captcha = "";
        while (n--)
            captcha.push_back(chrs[rand()%62]);
        return captcha;
    }
    void Captcha(){
        string s = generateCaptcha(56);
        cout<<"input the captcha:";
        string s1;
        cin>>s1;
       if(checkCaptcha(s , s1 )){
           cout<<"Incorrect";
       }
       else {
           cout<<"Correct! Good Luck!";
       }
    }
    void mine(TransactionData data , Blockchain blockchain){
        srand(time(0));
        for(int j = 0; j < 100000;j++)
        for(int i = 0; i < 100000;i++)
            for(int k =0; k < 10000;k++)
                for(int h = 0; h < 100000;h++);


    }
};


double getTotalVolume(Blockchain& chain) {
    double total = 0;
    for (auto iter = chain.begin(); iter != chain.end(); ++iter) {
        total = total + iter->getTransaction_data().amount;
    }
    return total;
}

void shared_mine(Miner& miner, TransactionData& tt, Blockchain& blockchain) {
    lock_guard<mutex> guard(Mutex);
Miner miner1;
    miner1.mine(tt, blockchain);
}

void func(Miner& miner, TransactionData& tt, Blockchain& blockchain) {
    for (int i = 0; i < 3; ++i) {
        shared_mine(miner, tt, blockchain);
    }
}

int main()
{
    Blockchain blockchain;
    future<double> ref = async(launch::deferred, getTotalVolume, ref(blockchain));
    time_t current;
    TransactionData act( 9, "Kainar", "Dastan", time(&current));
    TransactionData act1(666, "Edilbek", "Yernur", time(&current));
    Miner miner1;
    Miner miner2;

    blockchain.printBlockchain();
    thread thread1(func, ref(miner1), ref(act), ref(blockchain));
    thread thread2(func, ref(miner2), ref(act1), ref(blockchain));

    thread1.join();
    thread2.join();
    blockchain.printBlockchain();


    if (blockchain.isBlockchainValid()) {
        cout << "Work" << endl;
    }
    cout << ref.get() << endl;
    cout << getTotalVolume(blockchain) << endl;
    Blockchain awesomeCoin;
    time_t data1Time;
    TransactionData data1(1.5, "Kainar", "Edilbek", time_t(&data1Time));
    awesomeCoin.addBlock(data1);
    time_t data2Time;
    TransactionData data2(0.2233, "Dastan", "Nurzhas", time_t(&data2Time));
    awesomeCoin.addBlock(data2);
    awesomeCoin.printBlockchain();
    cout<<endl<<"Is chain valid?\n";
    if(awesomeCoin.isChainValid()){
        cout<<"Valid";
    }
    else {
        cout<<"Invalid";
    }
    Block *hackBlock = awesomeCoin.getLatestBlock();
    hackBlock->data.amount = 10000;
    hackBlock->data.receiverKey = "Kainar";
    awesomeCoin.printBlockchain();
    cout<<endl<<"Is chain valid?\n";
    if(awesomeCoin.isChainValid()){
        cout<<"Valid";
    }
    else {
        cout<<"Invalid";
    }


    return 0;
}