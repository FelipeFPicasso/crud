#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

struct CityTemp {
    string name;
    double temp;
};

class HashTable {
    private:
        static const int tableSize = 10;
        CityTemp *hashTable[tableSize];

    public:
        HashTable() {
            for (int i = 0; i < tableSize; i++) {
                hashTable[i] = NULL;
            }
        }

        int hashFunction(string name) {
            int index = 0;
            for (int i = 0; i < name.length(); i++) {
                index += (int)name[i];
            }
            return index % tableSize;
        }

        
        void insertCity(string name, double temp) {
            int index = hashFunction(name);
            while (hashTable[index] != NULL) {
                index++;
                index %= tableSize;
            }
            CityTemp *cityTemp = new CityTemp;
            cityTemp->name = name;
            cityTemp->temp = temp;
            hashTable[index] = cityTemp;
        }

        void removeCity(string name) {
            int index = hashFunction(name);
            while (hashTable[index] != NULL) {
                if (hashTable[index]->name == name) {
                    hashTable[index] = NULL;
                    cout << "Cidade " << name << " removida com sucesso." << endl;
                    return;
                }
                index++;
                index %= tableSize;
            }
            cout << "Cidade " << name << " nao encontrada na tabela." << endl;
        }

        void getTemp(string name) {
            int index = hashFunction(name);
            while (hashTable[index] != NULL) {
                if (hashTable[index]->name == name) {
                    cout << "A temperatura de " << name << " eh " << hashTable[index]->temp << " graus Celsius." << endl;
                    return;
                }
                index++;
                index %= tableSize;
            }
            cout << "Cidade " << name << " nao encontrada na tabela." << endl;
        }

        void listCities() {
            for (int i = 0; i < tableSize; i++) {
                if (hashTable[i] != NULL) {
                    cout << "Cidade: " << hashTable[i]->name << ", Temperatura: " << hashTable[i]->temp << " graus Celsius." << endl;
                }
            }
        }
};

int main() {
    HashTable hashTable;
    ifstream file("cities.txt");
    string line;
    while (getline(file, line)) {
        char *cstr = new char
    }
}