#ifndef CONTRACT_H
#define CONTRACT_H

#include <string>
#include <random>

enum ContractEnum
{
  DOCTOR,
  PATIENT,
  MEDICAL
};

const std::string CONTRACT_TYPE[] = {"DOCTOR", "PATIENT", "MEDICAL"};

/**
 * @brief Function to generate random alphanumber based on the length given
 *
 * @param length int
 * @return std::string
 */
std::string generateString(int length);

/**
 * @brief Contract Class
 *
 * This class will be extended to create a more specific Contract class.
 *
 */
class Contract
{
protected:
  std::string id;
  std::string type;

public:
  Contract(std::string type);

  std::string getId();

  /**
   * @brief Virtual (abstract) function to print the contract details
   *
   */
  virtual void print() = 0;
};
#endif