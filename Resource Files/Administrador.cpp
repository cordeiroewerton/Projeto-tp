#include "..\Header Files\Administrador.h"

Administrador::Administrador(long int CPF,int senha,string NomeDoADM){
    this->CPF=CPF;
    this->senha=senha;
    this->nomeDoADM=NomeDoADM;
}

void Administrador::setCPF(long int CPF){
    this->CPF=CPF;
}

void Administrador::setSenha(int senha){
    this->senha=senha;
}

void Administrador::setNomeDoADM(string nomeDoADM){
    this->nomeDoADM=nomeDoADM;
}

long int Administrador::getCPF(){
    return CPF;
}

int Administrador::getSenha(){
    return senha;
}

string Administrador::getNomeDoADM(){
    return nomeDoADM;
}
