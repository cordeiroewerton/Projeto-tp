#include < iostream >
#include < fstream >
using namespace std;
#include " ..\Resource Files\Conta.cpp "
#include " ..\Resource Files\Overload.cpp "
#include " ..\Resource Files\Usuario.cpp "
//Necessário implementação
//#include " ..\Resource Files\ContaPoupanca.cpp "
//#include " ..\Resource Files\ContaCorrente.cpp "
int main(){
  //Erro, falta de implmentação do Usuario.cpp
  //Padrão de inicialização do construtor de Usuario
   // Usuario usuarioAuxTeste(/*Nome*/"Valmir",/*Idade*/21,/*CPF*/15652145,/*Endereço*/{/*RUA*/"qualquer",/*CEP*/"1415454",/*cidade*/"qualquer",/*estado*/"qualquer"});
   Conta contaAuxTeste({/*Nome*/"Valmir",/*Idade*/21,/*CPF*/15652145,/*Endereço*/{/*RUA*/"qualquer",/*CEP*/"1415454",/*cidade*/"qualquer",/*estado*/"qualquer"}},/*senha*/1231124,/*Saldo*/10000);
  //teste dos métodos
  //falta a implementação da sobrecarga
   cout<<contaAuxTeste<<endl;
   cout<<"Teste getSenha"<<endl;
   cout<<contaAuxTeste.getSenha()<<endl;
   cout<<"Teste getSaldo"<<endl;
   cout<<contaAuxTeste.getSaldo()<<endl;
   // cout<<"Teste getNumeroDoCartao"<<endl;
   // cout<<contaAuxTeste.getNumeroDoCartao()<<endl;
   cout<<"Teste Sacar"<<endl;
   cout<<contaAuxTeste.sacar(10)<<endl;
   cout<<"Teste Saldo"<<endl;
   cout<<contaAuxTeste.getSaldo()<<endl;
   cout<<"Teste Depositar"<<endl;
   cout<<contaAuxTeste.depositar(10)<<endl;
   cout<<"Teste Saldo"<<endl;
   cout<<contaAuxTeste.getSaldo()<<endl;
   cout<<"Teste Senha"<<endl;
   cout<<contaAuxTeste.getSenha()<<endl;
   cout<<"Class Conta OK"<<endl;
   return 0;
}
