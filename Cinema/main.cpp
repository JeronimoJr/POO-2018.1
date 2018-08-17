#include <iostream>
#include <list>
#include <vector>

using namespace std;

struct Cliente{
    bool existe;
    string id;
    string fone;

    Cliente(string id = "fulano", string fone = "0000", bool existe = false){
        this->existe = existe;
        this->id = id;
        this->fone = fone;
    }

};

struct Sala{
    vector<Cliente> cadeiras;

    Sala(int qtd){
        for(int i = 0; i < qtd; i++)
            cadeiras.push_back(Cliente("", "", false));
    }

    /*void reservar(Cliente cliente, int pos){
        if(cadeiras.at([pos] != nullptr){
            cout<"Reservada\n";
        }
    }*/



};
int main(){
    Cliente cliente;
    string id,op, fone;
    cliente = {"Jeronimo", "8569"};


    return 0;
}

