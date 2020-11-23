#include "..\Header Files\Conta.h"
#ifndef CONTACORRENTE_H
#define CONTACORRENTE_H

class ContaCorrente:public Conta{

    private:
      float taxaDeManutencao;
    public:
      //RETIRE AS CHAVES QUANDO FOR DEFINIR O CONSTRUTOR
      ContaCorrente(const Usuario & = {"0",0,0,{"0","0","0","0"}},const float &  = 0,const float & = 0);
      void setTaxaDeManutencao(const float &); //desconto para a manutenção da conta corrente (geralmente 15 reais por mes)
      void CalcularTaxaDeManutencao(const float &);
};

#endif
