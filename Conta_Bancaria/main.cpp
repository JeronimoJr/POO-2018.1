#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

class Operacao{
   public:
    string descricao;
    int valor;
    int saldo;

    Operacao(string descricao = "", int valor = 0, int saldo = 0){
        this->descricao = descricao;
        this->saldo = saldo;
        this->valor = valor;
    }
};

class Conta{
public:
    int numero_Conta;
    int saldo;
    vector<Operacao> extrato;

    Conta(int numero = 0, int saldo = 0): numero_Conta(numero),saldo(saldo)
    {
         extrato.push_back(Operacao("abertura",0,0));
    }

    bool depositar(int valor){
        if(valor > 0){
            saldo += valor;
            extrato.push_back(Operacao("depositar",valor,saldo));
            return true;
        }
        return false;
    }

    bool sacar(int valor){
     if(valor > saldo){
         cout << "Saldo insuficiente\n";
         return false;
     }
        saldo -= valor;
        extrato.push_back(Operacao("sacar",-valor,saldo));
        return true;
    }

    bool tarifa(int valor){
        saldo -= valor;
        extrato.push_back(Operacao("tarifa",-valor,saldo));
        return true;
    }

    bool extornar(int indice){
        for(int i = 0; i < extrato.size(); i++){
            if(indice == i){
                if(extrato[i].descricao == "tarifa"){
               saldo += (-1)*extrato[i].valor;
               extrato.push_back(Operacao("extornar",extrato[i].valor,saldo));
               cout << "Sucess: indice " << indice <<" extornado\n";
               return true;
                }else{
                    cout <<"failure: indice "<< indice << " nao e tarifa\n";
                    return false;
                }
            }
        }
        cout << "Failure: indice " << indice << " invalido\n";
        return false;
    }

    string historico(){
        stringstream ss;
        for(int i = 0; i < extrato.size(); i++){
            ss << setw(2) << i << ":";
            ss << setw(9) << extrato[i].descricao << ":";
            ss<< setw(5) << extrato[i].valor << ":";
            ss << setw(5) << extrato[i].saldo<<endl;

        }
        return ss.str();
    }

    string n_historico(int valor){
        stringstream ss;
        for(int i = extrato.size()-1; valor != 0; i--, valor--)
            ss << i << ": "<< setw(5) <<extrato[i].descricao << ":"<< setw(8) << extrato[i].valor <<":"<< setw(7) << extrato[i].saldo <<endl;
        return ss.str();
    }
    string toString(){
        stringstream ss;
        ss << "Conta: " <<numero_Conta<<" "<<"Saldo: "<<saldo<<endl;
        return ss.str();
    }
};


int main(){
    Conta conta;
    string op;

    while(true){
        cin >> op;
        if(op == "init"){
            int numero;
            cin >> numero;
            conta = Conta(numero,0);
        }else if(op == "dep"){
            int valor;
            cin >> valor;
            if(conta.depositar(valor))
                cout<<"Sucess\n";
            else
                cout << "Valor inválido\n";
        }else if(op == "saque"){
            int valor;
            cin >> valor;
            if(conta.sacar(valor))
                cout << "Sucess\n";
        }else if(op == "tarifa"){
            int valor;
            cin >> valor;
            conta.tarifa(valor);
            cout << "Sucess\n";
        }else if(op == "extrato"){
            cout << conta.historico();
        }else if(op == "extraton"){
            int valor;
            cin >> valor;
            cout << conta.n_historico(valor);
        }else if(op == "ext"){
            int valor;
            cin >> valor;
            conta.extornar(valor);
        }
        else if(op == "show"){
            cout<< conta.toString();
        }else if(op == "end")
            break;
        else if(op == "help")
            cout << "init; dep; saque; tarifa; extrato; extraton; ext; show; end; help"<<endl;
    }

    return 0;
}

