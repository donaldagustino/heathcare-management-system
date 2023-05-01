#include "../include/doctor-contract.h"
#include <iostream>

DoctorContract::DoctorContract(std::string name, std::string specialization, std::string department, int age, int experience) : Contract(CONTRACT_TYPE[DOCTOR])
{
  this->doctorId = generateString(8);
  this->name = name;
  this->specialization = specialization;
  this->department = department;
  this->age = age;
  this->experience = experience;
}

std::string DoctorContract::getDoctorId()
{
  return this->doctorId;
}

void DoctorContract::print()
{
  std::cout << "\t" << this->type << " DETAILS" << std::endl;
  std::cout << "\tDoctor ID: " << this->doctorId << std::endl;
  std::cout << "\tName: " << this->name << std::endl;
  std::cout << "\tSpecialization: " << this->specialization << std::endl;
  std::cout << "\tDepartment: " << this->department << std::endl;
  std::cout << "\tAge: " << this->age << " years old" << std::endl;
  std::cout << "\tExperience: " << this->experience << " years" << std::endl;
}