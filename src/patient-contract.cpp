#include "../include/patient-contract.h"
#include <iostream>

PatientContract::PatientContract(std::string name, int age, std::string birthPlace, std::string bloodType, std::string allergies) : Contract(CONTRACT_TYPE[PATIENT])
{
  this->patientId = generateString(8);
  this->name = name;
  this->age = age;
  this->bloodType = bloodType;
  this->allergies = allergies;
}

std::string PatientContract::getPatientId()
{
  return this->patientId;
}

void PatientContract::print()
{
  std::cout << "\t" << this->type << " DETAILS" << std::endl;
  std::cout << "\tPatient ID: " << this->patientId << std::endl;
  std::cout << "\tName: " << this->name << std::endl;
  std::cout << "\tAge: " << this->age << " years old" << std::endl;
  std::cout << "\tBirth Place: " << this->birthPlace << std::endl;
  std::cout << "\tBlood Type: " << this->bloodType << std::endl;
  std::cout << "\tAllergies: " << this->allergies << std::endl;
}
