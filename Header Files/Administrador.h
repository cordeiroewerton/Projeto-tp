#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
//ERWERTON TERMINA O ADMINISTRADOR!
class Administrador{
private:
    long int CPF;
    int senha;
    string nomeDoADM;
public:
    Administrador(long int=0,int=0,string="");
    void setCPF(long int);
    void setSenha(int);
    void setNomeDoADM(string);
    long int getCPF();
    int getSenha();
    string getNomeDoADM();

};
#endif
