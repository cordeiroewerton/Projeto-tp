#include <iostream>
using namespace std;
#include "..\Resource Files\ContaPoupanca.cpp"

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