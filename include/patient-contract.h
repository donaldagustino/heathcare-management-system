#ifndef PATIENT_CONTRACT_H
#define PATIENT_CONTRACT_H

#include "./contract.h"

/**
 * @brief PatientContract
 *
 * Child class of Contract
 * This class is used to create PatientContract object which consist the patient data inputed by the user.
 *
 */
class PatientContract : public Contract
{
private:
  std::string patientId;
  std::string name;
  int age;
  std::string birthPlace;
  std::string bloodType;
  std::string allergies;

public:
  PatientContract(std::string name, int age, std::string birthPlace, std::string bloodType, std::string allergies);

  std::string getPatientId();

  /**
   * @brief print PatientContract attributes details
   *
   */
  void print();
};

#endif