#include <iostream>
#include <string>
#include <map>
using namespace std;

class Credenziali{
private:
    string username;
    string password;
    string data;
public:
    Credenziali(const string& u, const string& p, const string& d): username(u), password(p), data(d){};
    ~Credenziali(){};
    const string& getUsername() const {return username;}
    void setUsername(const string& u) {username=u;}
    const string& getData() const {return data;}
    void setData(const string& d) {data=d;}
    const string& getPassword() const {return password;}
    void setPassword(const string& p, const string& newdata){
        if (password != p) {
            password = p;
            setData(newdata);
        } else
            cout << "Password uguale alla precedente" << endl;
    }
};
class Password{
private:
    map <string, Credenziali*> psw;
public:
    ~Password(){};
    void addPassword(const string& url, Credenziali* a){
        psw.insert({url, a});
    }
    void removePassword(const string& url){
        psw.erase(url);
    }
    void searchPassword(const string& url){
        auto i=psw.find(url);
        if(i==psw.end()){
            cout << "URL non trovato" << endl;
        }
        else {
            cout << "URL: " << url << endl;
            cout << "Username: " << (i->second)->getUsername() << endl;
            cout << "Password: " << (i->second)->getPassword() << endl;
            cout << "Ultima Data di modifica: " << (i->second)->getData() << endl;
        }
    }
    void changePassword(const string& url, const string& p, const string& d){
        auto i=psw.find(url);
        (i->second)->setPassword(p, d);
    }
};

int main(){
    Credenziali* credenziali1 = new Credenziali("pippo", "pluto", "01/01/2021");
    Credenziali* credenziali2 = new Credenziali("paperino", "topolino", "02/01/2021");
    Credenziali* credenziali3 = new Credenziali("minnie", "paperina", "03/01/2021");
    Password* password = new Password();
    password->addPassword("www.google.com", credenziali1);
    password->addPassword("www.facebook.com", credenziali2);
    password->addPassword("www.instagram.com", credenziali3);
    password->searchPassword("www.google.com");
    password->searchPassword("www.facebook.com");
    password->searchPassword("www.instagram.com");
    password->changePassword("www.google.com", "pluto2", "04/01/2021");
    password->searchPassword("www.google.com");
    password->removePassword("www.google.com");
    password->searchPassword("www.google.com");
    return 0;
}