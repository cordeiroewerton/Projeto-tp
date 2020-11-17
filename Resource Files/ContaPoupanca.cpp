#include "..\Header Files\ContaPoupanca.h"

ContaPoupanca::ContaPoupanca(const Usuario & user, const int & jurosExtra,const float & saldo):Conta(user,saldo){
  this->jurosExtra=jurosExtra;
}
void ContaPoupanca::setJurosExtra (const int & jurosExtra){
    this-> jurosExtra = jurosExtra;
}
//JUROS QUE A CONTA RENDE
//O JUROS É DETERMINADO EM %
//ESSE JUROS É ANUAL, POIS NAO TEMOS UM RELÓGIO PARA DESCONTÁ-LO MENSALMENTE
void ContaPoupanca::CalcularJurosExtra(){
    setSaldo(getSaldo()*(jurosExtra/100));
}
