#include "..\Header Files\Conta.h"
#include "..\Header Files\Usuario.h"
#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H
class ContaPoupanca:public Conta{
    private:
        float jurosExtra;
    public:
      //RETIRE AS CHAVES QUANDO FOR DEFINIR O CONSTRUTOR
      ContaPoupanca(const Usuario & = {"0",0,0,{"0","0","0","0"}}, const float &  = 0, const float & = 0);
      void setJurosExtra(const int &);
      void CalcularJurosExtra();
};
#endif
