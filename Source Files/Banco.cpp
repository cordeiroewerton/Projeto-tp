#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;
#include "..\Resource Files\Usuario.cpp"
#include "..\Resource Files\Conta.cpp"
#include "..\Resource Files\Overload.cpp"
#include "..\Resource Files\Banco.cpp"
#include "..\Resource Files\ContaPoupanca.cpp"
#include "..\Resource Files\ContaCorrente.cpp"
int menu();
int subMenu();
int main(){
    Banco p;
    ContaPoupanca contaAuxP;
    ContaCorrente contaAuxC;
    long int CPF1,CPF2;
    float valorSaque, valorDeposito;
    int senha, loopSistema;
    int op1,op2;
    while(true){
      int op(menu());
      switch (op) {
        case 1:
            cout<<"[1] Conta Poupanca"<<endl;
            cout<<"[2] Conta Corrente"<<endl;
            cin>>op2;
            switch (op2){
                case 1:
                    cout<<"Insira os dados da sua Conta Poupanca"<<endl;
                    cin>>contaAuxP;
                    p.signUp(contaAuxP);
                    break;
                case 2:
                    cout<<"Insira os dados da sua Conta Corrente"<<endl;
                    cin>>contaAuxC;
                    p.signUp(contaAuxC);
                    break;
            }
              /*  CASO COM IF, SE QUISEREM UTILIZAR.
                if(op2==1){
                    cout<<"Insirar os dados da sua Conta Poupanca"<<endl;
                    cin>>contaAuxP;
                    p.signUp(contaAuxP);
                }
                else if(op2==2){
                    cout<<"Insira os dados da sua Conta Corrente"<<endl;
                    cin>>contaAuxC;
                    p.signUp(contaAuxC);
                }
                else{
                    cout<<"Opcao nao encontrada";
                }
*/
            break;
        case 2:
          cout<<"Informe seu CPF:";cin>>CPF1;
          cout<<"Informe sua senha:";cin>>senha;
          loopSistema= p.login(CPF1,senha);
          cout<<(loopSistema ? " ": "senha invalida")<<endl;
          while(loopSistema){
              op1= subMenu();
              switch (op1) {
                  case 1:
                      cout<<"Informe seu CPF:";cin>>CPF1;
                      cout<<"Informe sua senha:";cin>>senha;
                      cout<<"Informe o valor do saque[BRL]:";
                      cin>>valorSaque;
                      cout<<"Saque "<<(p.sacar(valorSaque,CPF1)?"realizado!":"recusado!")<<endl;
                      break;
                  case 2:
                      cout<<"Informe seu CPF:";cin>>CPF1;
                      cout<<"Informe sua senha:";cin>>senha;
                      cout<<"Informe o valor do deposito    [BRL]:";
                      cin>>valorDeposito;
                      cout<<"Deposito "<<(p.depositar(valorDeposito,CPF1)?"realizado!":" recusado!")<<endl;
                      break;
                  case 3:
                      cout<<"Informe seu CPF:";cin>>CPF1;
                      cout<<"Informe sua senha:";cin>>senha;
                      if(not(p.login(CPF1,senha))) {
                          cout<<"senha invalida"<<endl;
                          break;
                      }
                      cout<<"Informe o cpf do destinatario: ";
                      cin>>CPF2;
                      cout<<"Informe o valor da transferencia: ";
                      cin>>valorSaque;
                      cout<<"Transferencia "<<(p.transferencia(CPF1,CPF2,valorSaque)?"nao ":"")<<"realizada"<<endl;
                      break;
                  case 4:
                      if(p.login(CPF1,senha)){
                          cout<<"efetuando saque...";
//                          p.deletarContas(CPF1,senha);
                          cout<<"deletando"<<endl;
                      }
                      break;
                  case 5:
                     p.consultarDados(CPF1,senha);
                      break;
                  case 6:
                      cout<<"Informe seu CPF:";cin>>CPF1;
                      cout<<"Informe sua senha:";cin>>senha;
 //                     if(p.login(CPF1,senha))
 //                         p.modificarDados(CPF1,senha);
                      break;
                  default :
                      loopSistema = false;
                      p.signOut();
              }
          }
          break;
      case 3:
        cout<<"Case 3"<<endl;
          p.signOut();
          return 0;
      }
    }
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
  cout<<"[7]sair"<<endl;
  cout<<setw(40)<<" "<<endl;
  cin>>op;
  return op;
}
