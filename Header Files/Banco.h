#include "..\Header Files\ContaPoupanca.h"
#include "..\Header Files\ContaCorrente.h"
#include "..\Header Files\Administrador.h"
#ifndef _BANCO_H
#define _BANCO_H
class Banco/*:public ContaPoupanca,public ContaCorrente*/{
    private:
      vector<ContaPoupanca>listaDeContasP;
      vector<ContaCorrente>listaDeContasC;
      vector<Administrador>listaDeADM;
      ContaPoupanca auxContaP;
      ContaCorrente auxContaC;
      Administrador auxADM;
      int tipoDeConta;
      bool verificarLogin(long int, int);
      int  encontarConta(long int);//Ok
      bool carregarDados();
    public:
      Banco();
      bool login(long int,int);//OK
      bool signUp(ContaCorrente);//OK
      bool signUp(ContaPoupanca);//OK
      bool signUp(Administrador);
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
      void cobrarManutencao(float);
      void adicionarJuros(float);
      void calcularJuros();
      ~Banco();
};

#endif //_BANCO_H
