#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "./contract.h"
#include "./sha256.h"
#include <string>
#include <ctime>

/**
 * @brief Block class
 *
 * the Block inside the chain of the Blockchain system.
 * The data structure used is Double Linked List.
 */
class Block
{
public:
  Block *next;
  Block *prev;
  int number;
  std::time_t timestamp;
  std::string actualHash;
  std::string prevHash;
  Contract *contract;
};

/**
 * @brief BlockChain class
 *
 * the BlockChain class holds the Block node information starting from the head node to the tail node.
 */
class BlockChain
{
private:
  Block *head;
  Block *tail;
  int countBlocks;

public:
  BlockChain();

  void addBlock(Contract *contract);

  void traverse(BlockChain &chain);

  bool isExist(BlockChain &chain, std::string contractType, std::string id);
};

#endif