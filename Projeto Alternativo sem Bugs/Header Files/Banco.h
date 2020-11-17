#include "..\Header Files\Conta.h"
#ifndef _BANCO_H
#define _BANCO_H
class Banco:public Conta{
    private:
      vector<Conta>listaDeContas;
      Conta auxConta;
      bool verificarLogin(long int, int);
      int encontarConta(long int);//Ok
      bool  carregarDados();
    public:
      Banco();
      bool login(long int,int);//OK
      bool signUp(Conta);//OK
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
