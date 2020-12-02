#include "..\Header Files\Usuario.h"
#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
class Administrador{
private:
    Usuario userM;
    int senha;
public:
    Administrador(const Usuario & = {"0",0,0,{"0","0","0","0"}},const int & = 0);
    void setSenha(const int&);
    int getSenha()const;
    void setUser(const Usuario & userM);
    Usuario getUser()const;
    friend istream &operator>>(istream &, Administrador &);
    friend ostream &operator<<(ostream &, Administrador &);
    ~Administrador();
};
#endif
