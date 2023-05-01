#ifndef MEDICAL_CONTRACT_H
#define MEDICAL_CONTRACT_H

#include "./contract.h"

/**
 * @brief MedicalContract
 *
 * Child class of Contract
 * This class is used to create MedicalContract object which consist the medical data inputed by the user.
 *
 */
class MedicalContract : public Contract
{
private:
  std::string medicalId;
  std::string patientId;
  std::string patientSickness;
  std::string patientTreatment;
  std::string patientMedication;
  float patientBill;
  float patientInsuranceCoverAmount;

public:
  MedicalContract(
      std::string patientId,
      std::string patientSickness,
      std::string patientTreatment,
      std::string patientMedication,
      float patientBill,
      float patientInsuranceCoverAmount);

  std::string getMedicalId();

  /**
   * @brief print MedicalContract attributes details
   *
   */
  void print();
};

#endif