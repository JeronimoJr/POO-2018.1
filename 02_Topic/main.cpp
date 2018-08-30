#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct Passageiro{
    string id;
    string idade;
    bool existe;

    Passageiro(string id = "fulano", string idade = "0000", bool existe = true){
        this->id = id;
        this->idade = idade;
        this->existe = existe;
    }

    string toString(){
        stringstream ss;
        ss << this->id << ":" << this->idade;
        return ss.str();
    }
};

struct Topic{
    vector<Passageiro> cadeiras;
    int pref;


    Topic(int qtd = 0){
        for(int i = 0; i < qtd; i++)
            cadeiras.push_back(Passageiro("","",false));
    }

private:

    bool meajuda(Passageiro pass){
        for(Passageiro passageiro: cadeiras){
            if(passageiro.id == pass.id)
                return false;
        }
        return true;
    }

public:

    bool embarcar(Passageiro  pass){
        int qtd = cadeiras.size();
        int disp = 0;

        if(!meajuda(pass)){
            cout << pass.id<<" Ja esta na topic\n";
            return false;
        }

        int aux = std::stoi(pass.idade);
        if(aux > 60){
            for(int i = 0; i < pref; i++){
                if(!cadeiras[i].existe){
                    cadeiras[i] = pass;
                    return true;
                }
            }
        }

        for(int i = 0 ;  i < qtd; i++){

            if(i+1 > pref && !cadeiras[i].existe){
                cadeiras[i] = pass;
                disp = 1;
                return true;
            }
        }
        if(disp == 0){
            for(int i = 0; i < pref; i++){
                if(!cadeiras[i].existe){
                    cadeiras[i] = pass;
                    return true;
                }
            }
        }
        cout <<"Lotacao maxima \n";
        return true;
    }

    bool desembarcar(string nome){
        for(int i = 0; i < (int) cadeiras.size(); i++){
            if(nome == cadeiras[i].id  && (cadeiras[i].existe)){
                cadeiras[i]  = Passageiro("","",false);
                return true;
            }
        }
        cout<<"fail: "<<nome<<" nao esta no trem\n";
        return false;
    }

    string toString(){
        stringstream ss;
        ss << "[ ";
        for(int j = 0; j < (int) cadeiras.size(); j++){

            if(cadeiras[j].existe == false){
                if(j < pref){
                    ss << "@ ";
                }else
                    ss << "= ";
            }
            else if(j < pref)
                ss <<"@"<<cadeiras[j].toString() << " ";
            else if(j >= pref)
                ss <<"#"<<cadeiras[j].toString() << " ";
        }
        ss << "]";
        return ss.str();
    }
};

int main(){
    Topic vagao;
    string op;

    while(true){
        cin >> op;
        if(op == "end")
            break;
        else if(op == "show"){
            cout << vagao.toString() << endl;
        }else if(op == "new"){
            int qtd;
            int prefe;
            cin >> qtd >> prefe;
            vagao = Topic(qtd);
            vagao.pref = prefe;
        }else if(op == "in"){
            string nome, idade;
            cin >> nome >> idade;
            vagao.embarcar(Passageiro(nome,idade,true));
        }else if(op == "out"){
            string nome;
            cin >> nome;
            vagao.desembarcar(nome);
        }
    }
}
