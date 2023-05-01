# BlockHealth


How to compile the program

If you don't have make file, please execute this code on the terminal.
```
g++ include/sha256.h src/sha256.cpp include/contract.h src/contract.cpp include/doctor-contract.h src/doctor-contract.cpp include/patient-contract.h src/patient-contract.cpp include/medical-contract.h src/medical-contract.cpp include/blockchain.h src/blockchain.cpp main.cpp -o main.exe --std=gnu++11
```

If you have the `make` command. Then just simple run

```
make
```

How to run the program on Windows OS.

```
main.exe
```