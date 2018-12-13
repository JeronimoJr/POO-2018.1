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
            return &rep[key];
        throw string("fail: " + key + " não existe");
    }
    vector<T*> getValues(){
        vector<T*> aux;
        for(auto elem : rep)
            aux.push_back(elem.second);
        return aux;
    }
    string toString(){
        stringstream ss;
        for(auto elem : rep)
            ss << elem.second.toString();
        return ss.str();
    }
};

class Tweet{
    int id;
    string username, msg;
    vector<string> likes;
public:
    Tweet(int id = 0, string username = "", string msg = ""){
       this->id = id;
       this->username = username;
       this->msg = msg; 
    }

    void like(string username){
        auto it = find(likes.begin(), likes.end(), username);
        if(it == likes.end())
            likes.push_back(username);
        else
            likes.erase(it);
    }

    string toString(){
        stringstream ss;
        ss << to_string(id) << ": " << username << ": msg" << endl;
        ss << "{";
        for(auto it = likes.begin(); it != likes.end(); it++){
            if(it != likes.end()-1)
                ss << (*it) << " ";
            else
                ss << (*it);
        }
        ss << "}" << endl;
        return ss.str();
    }

};

class User{
    string username;
    int aux;
    vector<Tweet*> timeline;
    vector<Tweet*> tweets;
    vector<User*> seguidores;
    vector<User*> seguindo;
public:
    User(string username = ""):
        username(username), aux(0)
    {}

    void seguir(User * aux){
        seguindo.push_back(aux);
        aux->seguidores.push_back(this);
    }
    string getUnread(){
        stringstream ss;
        if(aux == 0)
    }
}































int main(){
    cout << "Vai vendo meu chapa" << endl;
    return 0;
}
