#include <iostream>

using namespace std;

struct Calc{
    int bateria;
    int limite_bateria;

    void clear(){
        for(int i = 0; i < 30; i++){
            cout<<endl;
        }
    }
    void charge(int carga){
            bateria += carga;
        if(bateria > limite_bateria)
            bateria = limite_bateria;
    }

    bool gastar_bateria(){
        if(bateria > 0){
            bateria -= 1;
            return true;
        }
        cout<<"Fail: Bateria insuficiente\n";
        return false;
    }

    float fatorial(float a, bool * deu_certo){
        int fat =  1;
        * deu_certo = false;
        if(!gastar_bateria())
            return 0;
       for(int i = 1; i <= a; i++)
            fat *= i;
       * deu_certo = true;
        return fat;
    }

    float soma(float a, float b, bool * deu_certo){
       *deu_certo = false;
        if(!gastar_bateria())
            return 0;
        *deu_certo = true;
        return a+b;
    }

    float sub(float a, float b, bool * deu_certo){
        *deu_certo = false;
        if(!gastar_bateria())
            return 0;
        * deu_certo = true;
        return a-b;
    }

    float div(float a, float b, bool * deu_certo){
        *deu_certo = false;
        if(b == 0){
            cout<<"Fail: Não posso dividir por 0\n";
            return 0;
        }
        if(!gastar_bateria())
            return 0;
        *deu_certo = true;
        return a/b;
    }
    float multi(float a, float b, bool * deu_certo){
        *deu_certo = false;
        if(!gastar_bateria())
            return 0;
        *deu_certo = true;
        return a*b;
    }

};

int main(){
    string op;
    Calc calc = {2,5};
    float a, b;
    bool deu_certo;

    while(true){
        cin>> op;
        if(op == "help")
            cout<<"soma; sub; multi; div; fat; charge; show; limpar; sair; \n";
        else if(op == "soma"){
            cin>>a>>b;
            float res = calc.soma(a,b,&deu_certo);
            if(deu_certo)
                cout<<" = "<<res<<endl;
        }
        else if(op == "multi"){
            cin >>a>>b;
            float res = calc.multi(a,b,&deu_certo);
            if(deu_certo)
                cout<<" = "<<res<<endl;
        }
        else if(op == "div"){
            cin>>a>>b;
            float res = calc.div(a,b,&deu_certo);
            if(deu_certo)
                cout<<" = "<<res<<endl;
        }
        else if(op == "sub"){
            cin >>a>>b;
            float res = calc.sub(a,b, &deu_certo);
            if(deu_certo)
                cout<<" = "<<res<<endl;
        }
        else if(op == "fat"){
            cin>>a;
            float res = calc.fatorial(a,&deu_certo);
            if(deu_certo)
                cout<<" = "<<res<<endl;
        }
        else if(op == "limpar"){
            system("clear");
        }
        else if(op == "charge"){
            int d;
            cin >>d;
            calc.charge(d);
        }
        else if(op == "show"){
            cout<< calc.bateria <<"\n";
        }
        else if(op == "sair"){
            break;
        }

    }
    return 0;
}

