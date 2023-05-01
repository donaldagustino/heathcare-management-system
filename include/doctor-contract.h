#ifndef DOCTOR_CONTRACT_H
#define DOCTOR_CONTRACT_H

#include "./contract.h"

/**
 * @brief DoctorContract
 *
 * Child class of Contract
 * This class is used to create DoctorContract object which consist the doctor data receive from user input.
 *
 */
class DoctorContract : public Contract
{
private:
  std::string doctorId;
  std::string name;
  std::string specialization;
  std::string department;
  int age;
  int experience;

public:
  DoctorContract(std::string name, std::string specialization, std::string department, int age, int experience);

  std::string getDoctorId();

  /**
   * @brief print DoctorContract attributes details
   *
   */
  void print();
};
#endif