#include "..\Header Files\ContaPoupanca.h"
#include "..\Header Files\ContaCorrente.h"
#include "..\Header Files\Administrador.h"
#ifndef _BANCO_H
#define _BANCO_H
class Banco/*:public ContaPoupanca,public ContaCorrente*/{
    private:

      int tipoDeConta;
      vector<ContaPoupanca>listaDeContasP;
      vector<ContaCorrente>listaDeContasC;
      vector<Administrador>listaDeADM;
      ContaPoupanca auxContaP;
      ContaCorrente auxContaC;
      Administrador auxADM;
      bool verificarLogin(const long int &,const int&);
      int  encontarConta(const long int &);//Ok
      bool salvarDados();//OK
      bool carregarDados();
public:
      Banco();
      bool login(const long int &,const int &);//OK
      bool signUp(ContaCorrente);//OK
      bool signUp(ContaPoupanca);//OK
      bool signUp(Administrador);//ok
      bool signOut();//Ok

      bool deletarContas(const long int &, const int&);
      bool modificarDados(const long int & ,const int&);
      void consultarDados(const long int &, const int &);//ok

      bool sacar(const float &,const long int &);
      bool depositar(const float &,const long int &);
      bool transferencia(const long int &,const long int&,const float&);

      void cobrarManutencao(const float &);
      bool imprimir()const;
      void adicionarJuros(const float &);
      void calcularJuros();
      ~Banco();
};

#endif //_BANCO_H
