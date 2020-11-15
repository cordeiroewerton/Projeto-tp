#include "..\Header Files\ContaPoupanca.h"

ContaPoupanca::ContaPoupanca(const Usuario & user, const int & jurosExtra,const float & saldo){
  // setUser(user);
  // setSenha(senha);
  // setLogin(login);
  // setNumeroDoCartao(numeroDoCartao);
  // setSaldo(saldo);
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
void ContaPoupanca::CalcularJurosExtra(const float & jurosExtra)
{
    setSaldo(getSaldo()*(jurosExtra/100));
}
