#include "..\Header Files\ContaCorrente.h"


ContaCorrente::ContaCorrente(const Usuario & user,const int & taxaDeManutencao,const float & saldo):Conta(user,saldo){
  this-> taxaDeManutencao=taxaDeManutencao;
}


void ContaCorrente::setTaxaDeManutencao (const int & taxaDeManutencao){
    this-> taxaDeManutencao = taxaDeManutencao;
}
void ContaCorrente::CalcularTaxaDeManutencao(const float & taxaDeManutencao){
    this->taxaDeManutencao=taxaDeManutencao;
    /* Como o programa irá funcionar em um tempo menor do que um mês, foi determinado uma única cobrança para
    a taxa de manutenção visto que o programa só irá ficar aberto poucos minutos, e por mais que tivessemos
    criado um relógio, ele seria reiniciado toda vez que abrisse o programa, por tanto não faz sentido cria-lo*/
	setSaldo(getSaldo() -taxaDeManutencao);
}
