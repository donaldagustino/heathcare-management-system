all: sha256.o contract.o medical-contract.o patient-contract.o doctor-contract.o blockchain.o
	g++ out/sha256.o out/contract.o out/medical-contract.o out/patient-contract.o out/doctor-contract.o out/blockchain.o main.cpp -o main.exe -std=c++11

blockchain.o:
	g++ -c src/blockchain.cpp -o out/blockchain.o -std=c++11

medical-contract.o:
	g++ -c src/medical-contract.cpp -o out/medical-contract.o -std=c++11

patient-contract.o:
	g++ -c src/patient-contract.cpp -o out/patient-contract.o -std=c++11

doctor-contract.o:
	g++ -c src/doctor-contract.cpp -o out/doctor-contract.o -std=c++11

contract.o:
	g++ -c src/contract.cpp -o out/contract.o -std=c++11

sha256.o:
	g++ -c src/sha256.cpp -o out/sha256.o -std=c++11
