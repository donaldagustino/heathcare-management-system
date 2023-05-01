#include "../include/contract.h"

// Initialize generator for random number generation
std::mt19937 generator{};

/**
 * @brief Function to generate random alphanumber based on the length given
 *
 * @param length int
 * @return std::string
 */
std::string generateString(int length)
{
  const std::string CHARACTERS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

  std::string randomString;

  for (std::size_t i = 0; i < length; ++i)
  {
    randomString += CHARACTERS[generator() % CHARACTERS.size()];
  }

  return randomString;
}

Contract::Contract(std::string type)
{
  this->id = generateString(32);
  this->type = type;
}

std::string Contract::getId()
{
  return this->id;
}
