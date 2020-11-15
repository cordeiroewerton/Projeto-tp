#include "ContaPoupanca.h"


ContaPoupanca::ContaPoupanca(const Usuario &user,const int &senha,const long int & login,const float & saldo, const long int & numeroDoCartao){
  setUser(user);
  setSenha(senha);
  setLogin(login);
  setNumeroDoCartao(numeroDoCartao);
  setSaldo(saldo);
}
//SALVAR DADOS
/*
ContaPoupanca::~ContaPoupanca()
{
    salvarDados();
}
*/

void ContaPoupanca::setJurosExtra (const int & jurosExtra)
{
    this-> jurosExtra = jurosExtra;
}

//JUROS QUE A CONTA RENDE
//O JUROS É DETERMINADO EM % 
//ESSE JUROS É ANUAL, POIS NAO TEMOS UM RELÓGIO PARA DESCONTÁ-LO MENSALMENTE
void ContaPoupanca::JurosExtra(float jurosExtra)
{
    saldo+=(saldo*(jurosExtra/100));
}
