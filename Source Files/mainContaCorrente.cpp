#include <iostream>
using namespace std;
//Atenção estamos usando recursos do C++11 !
#include "..\Resource Files\Usuario.cpp"
#include "..\Resource Files\Conta.cpp"
#include "..\Resource Files\Overload.cpp"
#include "..\Resource Files\ContaCorrente.cpp"
int main(){

    ContaCorrente contC;
    contC.setSenha(123);
    cout<<contC.getSenha()<<endl;
    contC.setSaldo(100);
    cout<<contC.getSaldo()<<endl;
    contC.sacar(100);
    cout<<contC.getSaldo()<<endl;
    contC.depositar(100);
    cout<<contC.getSaldo()<<endl;


    return 0;
}
