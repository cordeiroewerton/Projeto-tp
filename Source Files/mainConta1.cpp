#include <iostream>
#include <fstream>
//Atenção estamos usando recursos do C++11 !
using namespace std;
#include "..\Resource Files\Conta.cpp"
#include "..\Header Files\ContaPoupanca.h"
int main(){
    Endereco p = {"13737838374","Alagoas","Arapiraca","rt"};
    Conta *b = new ContaPoupanca("Valmir Ferreira da Silva",1289373876,21,300000,p);

}
