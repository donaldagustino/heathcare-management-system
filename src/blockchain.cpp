#include "../include/blockchain.h"
#include "../include/doctor-contract.h"
#include "../include/patient-contract.h"
#include "../include/medical-contract.h"
#include <iostream>

BlockChain::BlockChain()
{
  this->head = nullptr;
  this->tail = nullptr;
  this->countBlocks = 0;
  std::cout << "BLOCKCHAIN INITIALIZATION..." << std::endl;
}

/**
 * @brief function to add a new block node with the given contract to the chain.
 *
 * @param contract Contract*
 */
void BlockChain::addBlock(Contract *contract)
{
  Block *block = new Block();

  block->contract = contract;
  block->next = nullptr;
  block->timestamp = std::time(nullptr);

  if (this->head == nullptr)
  {
    this->head = block;
    this->tail = block;

    block->number = 0;
    block->actualHash = sha256(block->contract->getId());
    block->prevHash = block->actualHash;

    std::cout << std::endl
              << "First block added!" << std::endl;
  }
  else
  {
    this->tail->next = block;
    block->prev = this->tail;
    this->tail = block;

    block->number = block->prev->number + 1;
    block->actualHash = sha256(block->contract->getId() + block->prev->contract->getId());
    block->prevHash = block->prev->actualHash;

    std::cout << std::endl;
  }

  std::cout << "New block added!" << std::endl;
  std::cout << "Actual Hash: " << block->actualHash << std::endl;
  std::cout << "Previous Hash: " << block->prevHash << std::endl;

  this->countBlocks++;
}

/**
 * @brief function to print out the block node and it's data details from the 0 block to the n block
 *
 * @param chain BlockChain&
 */
void BlockChain::traverse(BlockChain &chain)
{

  Block *blockPtr = chain.head;
  int currentBlock = this->countBlocks;

  while (blockPtr != NULL)
  {
    std::cout << std::endl
              << "=======================================================================" << std::endl;
    std::cout << "BLOCK: " << blockPtr->number << std::endl;
    std::cout << "TIMESTAMP: " << blockPtr->timestamp << " " << std::asctime(std::localtime(&blockPtr->timestamp)) << std::endl;
    std::cout << "DATA:" << std::endl;
    blockPtr->contract->print();
    std::cout << std::endl;
    std::cout << "ACTUAL HASH: " << blockPtr->actualHash << std::endl;
    std::cout << "PREVIOUS HASH: " << blockPtr->prevHash << std::endl;
    blockPtr = blockPtr->next;
    std::cout << "=======================================================================" << std::endl;
  }
}

/**
 * @brief function to check whether a contract exist or not based on the contract type and the specific contract type id
 *
 * @param chain BlockChain&
 * @param contractType std::string
 * @param id std::string
 * @return bool
 */
bool BlockChain::isExist(BlockChain &chain, std::string contractType, std::string id)
{
  Block *blockPtr = chain.head;

  while (blockPtr != NULL)
  {
    if (contractType == CONTRACT_TYPE[DOCTOR])
    {
      if (id == ((DoctorContract *)blockPtr->contract)->getDoctorId())
      {
        return true;
      }
    }

    if (contractType == CONTRACT_TYPE[PATIENT])
    {
      if (id == ((PatientContract *)blockPtr->contract)->getPatientId())
      {
        return true;
      }
    }

    if (contractType == CONTRACT_TYPE[MEDICAL])
    {
      if (id == ((MedicalContract *)blockPtr->contract)->getMedicalId())
      {
        return true;
      }
    }

    blockPtr = blockPtr->next;
  }

  return false;
}
