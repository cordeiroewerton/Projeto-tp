#include "..\Header Files\ContaPoupanca.h"
#include "..\Header Files\ContaCorrente.h"
#include "..\Header Files\Conta.h"

#ifndef _BANCO_H
#define _BANCO_H

class Banco:public ContaPoupanca, public ContaCorrente{
    private:
      vector<ContaCorrente>listaDeContasC;
      vector<ContaPoupanca>listaDeContasP;
      ContaCorrente auxContaC;
      ContaPoupanca auxContaP;
      bool verificarLogin(long int, int);
      int encontarConta(long int);//Ok
      bool  carregarDados();
    public:
      Banco();
      bool login(long int,int);//OK
      bool signUp(ContaPoupanca);//OK
      bool signUp(ContaCorrente);
      bool signOut();//Ok
      bool deletarContas(long int, int);
      bool modificarDados(long int ,int );
      bool ordenarLista();
      bool transferencia(long int,int,long int, float);
      bool salvarDados();//OK
      void consultarDados(const long int &, const int &);//ok
      int menu();//Ok
      ~Banco();
};

#endif //_BANCO_H
