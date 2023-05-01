#include "include/contract.h"
#include "include/doctor-contract.h"
#include "include/patient-contract.h"
#include "include/medical-contract.h"
#include "include/sha256.h"
#include "include/blockchain.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <chrono>

void menu()
{
  std::cout << std::endl
            << "BLOCKHEALTH MENU" << std::endl;
  std::cout << "1. Input doctor" << std::endl;
  std::cout << "2. Input patient" << std::endl;
  std::cout << "3. Input medical report" << std::endl;
  std::cout << "4. View chain" << std::endl;
  std::cout << "5. Exit" << std::endl;
}

void inputDoctorMenu(BlockChain &chain)
{
  std::cout << std::endl
            << "Input DOCTOR data" << std::endl;

  std::string name;
  std::string specialization;
  std::string department;
  int age;
  int experience;

  std::cin.ignore();

  std::cout << "doctor name: ";
  getline(std::cin, name);

  std::cout << "doctor specialization: ";
  getline(std::cin, specialization);

  std::cout << "doctor department: ";
  getline(std::cin, department);

  while (true)
  {
    std::cout << "doctor age: ";
    std::cin >> age;

    if (std::cin.fail())
    {
      std::cout << "Please input a number!" << std::endl;
      std::cin.clear();
      std::cin.ignore(256, '\n');
    }
    else
    {
      break;
    }
  }

  while (true)
  {
    std::cout << "doctor experience: ";
    std::cin >> experience;

    if (std::cin.fail())
    {
      std::cout << "Please input a number!" << std::endl;
      std::cin.clear();
      std::cin.ignore(256, '\n');
    }
    else
    {
      break;
    }
  }

  DoctorContract *doctorContract = new DoctorContract(name, specialization, department, age, experience);
  chain.addBlock(doctorContract);
}

void inputPatientMenu(BlockChain &chain)
{
  std::cout << std::endl
            << "Input PATIENT data" << std::endl;

  std::string name;
  int age;
  std::string birthPlace;
  std::string bloodType;
  std::string allergies;

  std::cin.ignore();

  std::cout << "patient name: ";
  getline(std::cin, name);

  while (true)
  {
    std::cout << "patient age: ";
    std::cin >> age;

    if (std::cin.fail())
    {
      std::cout << "Please input a number!" << std::endl;
      std::cin.clear();
      std::cin.ignore(256, '\n');
    }
    else
    {
      break;
    }
  }

  std::cin.ignore();

  std::cout << "patient birth place: ";
  getline(std::cin, birthPlace);

  std::cout << "patient blood type: ";
  std::cin >> bloodType;

  std::cin.ignore();

  std::cout << "patient allergies: ";
  getline(std::cin, allergies);

  PatientContract *patientContract = new PatientContract(name, age, birthPlace, bloodType, allergies);
  chain.addBlock(patientContract);
}

void inputMedicalReportMenu(BlockChain &chain)
{
  std::cout << std::endl
            << "Input MEDICAL data" << std::endl;

  std::string patientId;
  std::string patientSickness;
  std::string patientTreatment;
  std::string patientMedication;
  float patientBill;
  float patientInsuranceCoverAmount;

  std::cin.ignore();

  do
  {
    std::cout << "patient id: ";
    std::cin >> patientId;

    if (!chain.isExist(chain, CONTRACT_TYPE[PATIENT], patientId))
    {
      std::cout << "Patient ID doesn't exist!" << std::endl;
    }
  } while (!chain.isExist(chain, CONTRACT_TYPE[PATIENT], patientId));

  std::cin.ignore();

  std::cout << "patient sickness: ";
  getline(std::cin, patientSickness);

  std::cout << "patient treatment: ";
  getline(std::cin, patientTreatment);

  std::cout << "patient medication: ";
  getline(std::cin, patientMedication);

  while (true)
  {
    std::cout << "patient bill: ";
    std::cin >> patientBill;

    if (std::cin.fail())
    {
      std::cout << "Please input a number!" << std::endl;
      std::cin.clear();
      std::cin.ignore(256, '\n');
    }
    else
    {
      break;
    }
  }

  while (true)
  {
    std::cout << "patient insurance cover amount: ";
    std::cin >> patientInsuranceCoverAmount;

    if (std::cin.fail())
    {
      std::cout << "Please input a number!" << std::endl;
      std::cin.clear();
      std::cin.ignore(256, '\n');
    }
    else
    {
      break;
    }
  }

  MedicalContract *medicalContract = new MedicalContract(patientId, patientSickness, patientTreatment, patientMedication, patientBill, patientInsuranceCoverAmount);
  chain.addBlock(medicalContract);
}

int main()
{
  auto start = std::chrono::high_resolution_clock::now(); // get start time

  BlockChain chain;
  while (true)
  {
    int choice;
    menu();
    std::cout << "Menu: ";
    std::cin >> choice;

    if (choice == 1)
    {
      inputDoctorMenu(chain);
    }
    else if (choice == 2)
    {
      inputPatientMenu(chain);
    }
    else if (choice == 3)
    {
      inputMedicalReportMenu(chain);
    }
    else if (choice == 4)
    {
      chain.traverse(chain);
    }
    else if (choice == 5)
    {
      break;
    }
    else
    {
      std::cout << "The menu that you choose doesn't exist. Please input a between (1 - 5)!" << std::endl;
    }
  }

  auto stop = std::chrono::high_resolution_clock::now(); // get stop time

  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start); // calculate duration

  double finalDuration = duration.count() / 1.0e6;

  std::cout << "Execution time: " << finalDuration << " seconds" << std::endl; // print duration

  return 0;
}
