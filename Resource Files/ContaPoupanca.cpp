#include "..\Header Files\ContaPoupanca.h"

ContaPoupanca::ContaPoupanca(const Usuario & user, const float & jurosExtra,const float & saldo):Conta(user,saldo){
  this->jurosExtra=jurosExtra;
}
void ContaPoupanca::setJurosExtra (const float & jurosExtra){
    this-> jurosExtra = jurosExtra;
}
//JUROS QUE A CONTA RENDE
//O JUROS É DETERMINADO EM %
//ESSE JUROS DEVERAR SER DESCONTADO PELO ADM
void ContaPoupanca::CalcularJurosExtra(){
    setSaldo((getSaldo()*(jurosExtra/100))+getSaldo());
}
