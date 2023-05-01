#include "../include/medical-contract.h"
#include <iostream>
#include <string>

MedicalContract::MedicalContract(
    std::string patientId,
    std::string patientSickness,
    std::string patientTreatment,
    std::string patientMedication,
    float patientBill,
    float patientInsuranceCoverAmount) : Contract(CONTRACT_TYPE[MEDICAL])
{
  this->medicalId = generateString(8);
  this->patientId = patientId;
  this->patientSickness = patientSickness;
  this->patientTreatment = patientTreatment;
  this->patientMedication = patientMedication;
  this->patientBill = patientBill;
  this->patientInsuranceCoverAmount = patientInsuranceCoverAmount;
}

std::string MedicalContract::getMedicalId()
{
  return this->medicalId;
}

void MedicalContract::print()
{
  std::cout << "\t" << this->type << " DETAILS" << std::endl;
  std::cout << "\tPatient ID: " << this->patientId << std::endl;
  std::cout << "\tMedical ID: " << this->medicalId << std::endl;
  std::cout << "\tPatient Sickness: " << this->patientSickness << std::endl;
  std::cout << "\tPatient Treatment: " << this->patientTreatment << " years old" << std::endl;
  std::cout << "\tPatient Medication: " << this->patientMedication << std::endl;
  std::cout << "\tPatient Bill: $" << this->patientBill << std::endl;
  std::cout << "\tPatient Insurance Cover Amount: $" << this->patientInsuranceCoverAmount << std::endl;
}
