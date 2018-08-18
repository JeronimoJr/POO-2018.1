#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct Cliente{
    bool existe;
    string id;
    string fone;

    Cliente(string id = "", string fone = "", bool existe = false){
        this->existe = existe;
        this->id = id;
        this->fone = fone;
    }

    string toString(){
        stringstream ss;
        if(!existe)
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
            cadeiras.push_back(new(Cliente));
    }

    bool reservar(Cliente *cliente, int indCadeira){
        int qtd = cadeiras.size();

        if(indCadeira >= qtd || indCadeira < 0){
            cout<<"Cadeira não existe\n";
            return false;
        }
         if(cadeiras[indCadeira]->existe){
         cout<<"Já esta sendo usada\n";
          return false;
       }

         for(Cliente *clie : cadeiras){
             if(cliente->id == clie->id){
               cout<<"fail: davi ja esta no cinema\n";
                 return false;
             }
         }

         cadeiras[indCadeira]->id = cliente->id;
         cadeiras[indCadeira]->fone = cliente->fone;
         cadeiras[indCadeira]->existe = true;
         //cadeiras[indCadeira] = cliente;
         cout<<"Done\n";
         return true;

       }

    bool cancelar(string iden){

        for(int i = 0; i < cadeiras.size(); i++){
            if(cadeiras[i]->existe && cadeiras[i]->id == iden){
                cadeiras[i] = new(Cliente);
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
            int idcad;
            Cliente cliente;
            string nome;
            string telefone;
           cin >> nome >> telefone >> idcad;
           cliente.fone = telefone;
           cliente.id = nome;
            sala.reservar(&cliente,idcad);
            //sala.reservar(new(Cliente(nome,telefone)),idcad);
        }
        else if(op == "cancelar"){
            string nome;
            cin>> nome;
            sala.cancelar(nome);
        }
    }
}
