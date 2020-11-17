#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;
#include "..\Resource Files\Usuario.cpp"
#include "..\Resource Files\Conta.cpp"
#include "..\Resource Files\ContaPoupanca.cpp"
#include "..\Resource Files\ContaCorrente.cpp"
#include "..\Resource Files\Overload.cpp"
#include "..\Resource Files\Banco.cpp"
int menu();
int subMenu();

template<typename T>
void gerenciadorDeCadastros(T &);

int main(){
    Banco < Conta > p;
    long int CPF;
    float valorSaque, valorDeposito;
    int senha, loopSistema;

    // // Usuario usuarioAuxTeste1(/*Nome*/"Valmir F",/*Idade*/21,/*CPF*/2,/*Endereço*/{/*RUA*/"qualquerRua",/*CEP*/"1415454CEP",/*cidade*/"qualquerCidade",/*estado*/"qualquerEstado"});
    // // Usuario usuarioAuxTeste2(/*Nome*/"Erwerton",/*Idade*/18,/*CPF*/2,/*Endereço*/{/*RUA*/"qualquerRua",/*CEP*/"1415454CEP",/*cidade*/"qualquerCidade",/*estado*/"qualquerEstado"});
    // // Conta contaAuxTeste1(usuarioAuxTeste1,/*senha*/1,/*login possível saida*/4,/*Saldo*/10000,/*Numero de cartao*/11313);
    // // Conta contaAuxTeste2(usuarioAuxTeste2,/*senha*/2,/*login possível saida*/5,/*Saldo*/10000,/*Numero de cartao*/11313);
    // // p.signUp(contaAuxTeste1);
    // // p.signUp(contaAuxTeste2);

    while(true){
      int op = menu();
      switch (op) {
        case 1:
          cout<<"[1] Conta Poupaca"<<endl;
          cout<<"[2] Conta Corrente"<<endl;
          cin>>op;
          switch (op) {
            case 1:
              //Lembrar de substuir o p
              cout<<"Insirar os dados da sua conta Poupanca"<<endl;
              gerenciadorDeCadastros(p);
              cout<<"Conta criada!"<<endl;
              break;
            case 2:
              //Lembrar de substuir o p
              cout<<"Insira os dados da sua conta Corrente"<<endl;
              gerenciadorDeCadastros(p);
              cout<<"Conta criada!"<<endl;
              break;
          }
        break;
        case 2:
          //O código precisa identificar o tipo de conta pelo CPF;
          cout<<"Informe seu CPF:";cin>>CPF;
          cout<<"Informe sua senha:";cin>>senha;
          loopSistema= p.login(CPF,senha);
          cout<<(loopSistema ? " ": "senha invalida")<<endl;
          while(loopSistema){
              op = subMenu();
              if(op > 6)
                break;
              switch (op) {
                  case 1:
                      cout<<"Informe o valor do saque[BRL]:";
                      cin>>valorSaque;
                      // p.sacar(valorSaque);
                      //ambiguidade erro
                      //cout<<"Saque "<<(p.sacar(valorSaque)?"realizado!":"recusado!")<<endl;
                      break;
                  case 2:
                      cout<<"Informe o valor do deposito[BRL]:";
                      cin>>valorDeposito;
                      //ambiguidade erro
                      //cout<<"Deposito "<<(p.depositar(valorDeposito)?"realizado!":" recusado!")<<endl;
                      break;
                  case 3:
                      cout<<"Ideia nao definida"<<endl;
                      break;
                  case 4:
                      cout<<"Ideia nao definida"<<endl;
                      if(p.login(CPF,senha)){
                          cout<<"deletando"<<endl;
                          p.deletarContas(CPF,senha);
                          cout<<"Login aceito";
                      }
                      break;
                  case 5:
                      p.consultarDados(CPF,senha);
                      break;
                  case 6:
                      cout<<"Ideia nao definiada"<<endl;
                      break;
              }
          }
          break;
      case 3:
        cout<<"Case 3"<<endl;
          p.signOut();
          return 0;
          break;
      }
    }
  return 0;
}
template<typename T>
void gerenciadorDeCadastros(T & bancoGenerico){
  Usuario userAux;
  Conta contaAux;
  cin>>userAux;
  cin>>contaAux;
  contaAux.setUser(userAux);
  bancoGenerico.signUp(contaAux);
}
//implementar as exceções
int menu(){
  int op;
  cout.fill('_');
  cout<<setw(40)<<" "<<endl;
  cout<<"Bem vindo"<<endl;
  cout<<setw(40)<<" "<<endl;
  cout<<"[1]Criar Conta"<<endl;
  cout<<"[2]Entrar"<<endl;
  cout<<"[3]Sair"<<endl;
  cout<<setw(40)<<" "<<endl;
  cin>>op;
  return op;
}
//implementar as exceções
int subMenu(){
  int op;
  cout.fill('_');
  cout<<setw(40)<<" "<<endl;
  cout<<"[1]Sacar"<<endl;
  cout<<"[2]Deposita"<<endl;
  cout<<"[3]Transferir"<<endl;
  cout<<"[4]Deletar Conta"<<endl;
  cout<<"[5]Consultar Dados"<<endl;
  cout<<"[6]Modificar Dados"<<endl;
  cout<<"[5]sair"<<endl;
  cout<<setw(40)<<" "<<endl;
  cin>>op;
  return op;
}
