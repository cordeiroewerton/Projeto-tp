#include <iostream>
using namespace std;
//Atenção estamos usando recursos do C++11 !
#include "..\Resource Files\ContaPoupanca.cpp"
#include "..\Resource Files\Usuario.cpp"
#include "..\Resource Files\Conta.cpp"
#include "..\Resource Files\Overload.cpp"
int main(){

    ContaPoupanca contP;
    contP.setSenha(123);
    cout<<contP.getSenha()<<endl;
    contP.setSaldo(100);
    cout<<contP.getSaldo()<<endl;
    contP.setJurosExtra(2);
    contP.CalcularJurosExtra();
    cout<<contP.getSaldo();

    return 0;
}
