#include "..\Header Files\Administrador.h"
Administrador::Administrador(const Usuario & userM, const int & senha){
    setUser(userM);
    setSenha(senha);
}
void Administrador::setSenha(const int & senha){
    this->senha=senha;
}
void Administrador::setUser(const Usuario & userM){
    this->userM = userM;
}
Usuario Administrador::getUser()const{
    return userM;
}
int Administrador::getSenha()const{
    return senha;
}
Administrador::~Administrador(){

}