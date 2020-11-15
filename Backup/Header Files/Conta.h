#include "..\Header Files\Usuario.h"
#ifndef _CONTA_H
#define _CONTA_H
class Conta{

  private:
      Usuario user;
      int senha; //senha feita apenas de numeros
      float saldo;
  public:
      Conta(const Usuario & = {"0",0,0,{"0","0","0","0"}},const int &  = 0,const float & = 0);

      void setUser(const Usuario &);
      void setSenha(const int&);
      void setSaldo(const float &);

      Usuario getUser()const;
      int getSenha()const;
      float getSaldo()const;

      //sobrecarregar do operador >> para ajudar nos cadastros
      friend istream &operator>>(istream &, Conta &);
      friend ostream &operator<<(ostream &, Conta &);

      bool sacar(const float&);
      bool depositar(const float&);

      ~Conta();
};
#endif //_Conta_H
