#include "..\Header Files\ContaPoupanca.h"
#include "..\Header Files\ContaCorrente.h"
#ifndef _BANCO_H
#define _BANCO_H
class Banco/*:public ContaPoupanca,public ContaCorrente*/{
    private:
      vector<ContaPoupanca>listaDeContasP;
      vector<ContaCorrente>listaDeContasC;
      ContaPoupanca auxContaP;
      ContaCorrente auxContaC;
      int tipoDeConta;
      bool verificarLogin(long int, int);
      int  encontarConta(long int);//Ok
      bool carregarDados();
      bool transferirContaPoupanca2Poupanca(int,int,float);
      bool transferirContaPoupanca2Corrente(int,int,float);
      bool transferirContaCorrente2Corrente(int,int,float);
      bool transferirContaCorrente2Poupanca(int,int,float);
    public:
      Banco();
      bool login(long int,int);//OK
      bool signUp(ContaCorrente);//OK
      bool signUp(ContaPoupanca);//OK
      bool signOut();//Ok
      bool deletarContas(long int, int);
      bool modificarDados(long int ,int );
      bool ordenarLista();
      bool transferencia(long int,long int, float);
      bool salvarDados();//OK
      void consultarDados(const long int &, const int &);//ok
      int menu();//Ok
      bool sacar(const float &,const long int &);
      bool depositar(const float &,const long int &);
      ~Banco();
};

#endif //_BANCO_H
