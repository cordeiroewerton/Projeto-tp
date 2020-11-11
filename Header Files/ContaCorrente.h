#include "..\Header Files\Conta.h"
#ifndef CONTACORRENTE_H
#define CONTACORRENTE_H

class ContaCorrente:public Conta{

    private:
      vector<ContaCorrente>listaDeContasCorrente;
      int taxaDeManuntencao;
    public:

      ContaCorrente(const Usuario & = {"0",0,0,{"0","0","0","0"}},const int&  = 0,const long int & = 0,const float & = 0,const long int & = 0, const in&);
      void setTaxaDeManuntencao(const int&); //desconto para a manutenção da conta corrente (geralmente 15 reais por mes)
      bool salvarDados();
      bool cadastroUsuario(const ContaCorrente&);

};

#endif