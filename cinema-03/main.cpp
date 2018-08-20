#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct Cliente{
    int ide;
    string id;
    string fone;

    Cliente(string id = "", string fone = "", int ide = 0){
        this->id = id;
        this->fone = fone;
        this->ide = ide;
    }

    string toString(){

        stringstream ss;
        if(this->ide == 0)
            ss << "-";
        else
            ss << this->id << ":" << this->fone;
        return ss.str();
    }
};

struct Sala{
    vector<Cliente*> cadeiras;

    Sala(int qtd = 0){
        for(int i = 0; i < qtd; i++)
            cadeiras.push_back(new Cliente("","", 0));
    }

    bool reservar(string nome, string telefone, int indCadeira){
        int qtd = cadeiras.size();

        if(indCadeira >= qtd || indCadeira < 0){
            cout<<"Cadeira não existe\n";
            return false;
        }
         if(cadeiras[indCadeira]->ide != 0){
         cout<<"Já esta sendo usada\n";
          return false;
       }



         for(Cliente *clie : cadeiras){
             if(nome == clie->id ){
               cout<<"fail:ja esta no cinema\n";
                 return false;
             }
         }

         cadeiras[indCadeira]->id = nome;
         cadeiras[indCadeira]->fone = telefone;
        cadeiras[indCadeira]->ide = 1;
         /*cadeiras[indCadeira] = &cliente;*/
         cout<<"Done\n";
         return true;

       }

    bool cancelar(string iden){

        for(int i = 0; i < cadeiras.size(); i++){
            if((cadeiras[i]->ide != 0) && (cadeiras[i]->id == iden)){
                cadeiras[i] = new Cliente("","", 0);
            cout<<" Done\n";
            return true;
            }
        }
        cout<<"Pessoa não encotrada\n";
        return false;
   }


        string toString(){
            stringstream ss;
             ss<< "[";
             for(Cliente *cliente : cadeiras)
                 ss << cliente->toString() << " ";
             ss << " ]";
             return ss.str();
        }


};

int main(){
    Sala sala;
    string op;
    while(true){
        cin >> op;
        if(op == "show"){
            cout << sala.toString() << endl;
        }else if(op == "init"){
            int qtd;
            cin >> qtd;
            sala = Sala(qtd);
            cout << "sala criada com " << qtd << " cadeiras" << endl;
        }
        else if(op == "reservar"){
            Cliente cliente;
            int idcad;
            string nome;
            string telefone;
            int a = 0;
           cin >> nome >> telefone >> idcad;
            sala.reservar(nome,telefone, idcad);

        }
        else if(op == "cancelar"){
            string nome;
            cin>> nome;
            sala.cancelar(nome);
        }
    }
}

