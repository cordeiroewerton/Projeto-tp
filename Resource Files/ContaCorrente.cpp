#include "..\Header Files\ContaCorrente.h"


ContaCorrente::ContaCorrente(const Usuario & user,const int & taxaDeManutencao,const float & saldo):Conta(user,saldo){
  this-> taxaDeManutencao=taxaDeManutencao;
}


void ContaCorrente::setTaxaDeManutencao (const int & taxaDeManutencao){
    this-> taxaDeManutencao = taxaDeManutencao;
}
void ContaCorrente::CalcularTaxaDeManutencao(const float & taxaDeManutencao){
  this->taxaDeManutencao=taxaDeManutencao;
	setSaldo(getSaldo() -taxaDeManutencao);
}
