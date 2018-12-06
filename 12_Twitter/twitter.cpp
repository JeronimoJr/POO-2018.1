#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

template <typename T>
class Repositorio{
    map<string, T> rep;
public:
    void add(string key, T t){
        if(rep.count(key) == 0)
            rep[key] = t;
        throw string("fail: " + key + " já existe");
    }

    void rm(string key){
        if(rep.count(key) != 0)
            rep.erase(key);
        throw string("fail: " + key + " já existe");
    }

    bool exists(string key){
        return rep.count(key) != 0;
    }
    T* get(string key){
        if(exists(key))
            return &re
    }
};

int main(){
    cout << "Vai vendo meu chapa" << endl;
    return 0;
}
