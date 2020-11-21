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
#include "..\Resource Files\Administrador.cpp"
int menu();
int subMenu();
int menuADM();
int subMenuADM();
int main(){
    Banco p;
    ContaPoupanca contaAuxP;
    ContaCorrente contaAuxC;
    Administrador adm;
    string nome;
    long int CPF1,CPF2;
    float valorSaque, valorDeposito,valor1;
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
                    cout<<(p.signUp(contaAuxP)?"sucesso":"falha, CPF ja cadastrado!")<<endl;
                    break;
                case 2:
                    cout<<"Insira os dados da sua Conta Corrente"<<endl;
                    cin>>contaAuxC;
                    cout<<(p.signUp(contaAuxC)?"sucesso":"falha, CPF ja cadastrado!")<<endl;
                    break;
            }
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
                      cout<<"Informe o CPF do destinatario: ";
                      cin>>CPF2;
                      cout<<"Informe o valor da transferencia [BRL]: ";
                      cin>>valorSaque;
                      cout<<"Transferencia "<<(p.transferencia(CPF1,CPF2,valorSaque)?"nao ":"realizada")<<endl;
                      break;
                  case 4:
                      if(p.login(CPF1,senha)){
                          cout<<"efetuando saque...";
                          loopSistema=not(p.deletarContas(CPF1,senha));
                          p.signOut();
                          cout<<"deletando"<<endl;
                      }
                      break;
                  case 5:
                      p.consultarDados(CPF1,senha);
                      break;
                  case 6:
                      cout<<"Informe seu CPF:";cin>>CPF1;
                      cout<<"Informe sua senha:";cin>>senha;
                     if(p.login(CPF1,senha))
                         p.modificarDados(CPF1,senha);
                      break;
                  default :
                      loopSistema = false;
                      p.signOut();
              }
          }
          break;
////////////////////////////////////////////pode melhorar?////////////////////////////////////////////////////////
        case 3:
            cout<<"Case 3"<<endl;
            p.signOut();
            return 0;
        case 4:
            op1=menuADM();
            switch(op1){
                case 1:
                    cout<<"Informe seu CPF:"; cin>>CPF1;
                    cout<<"Informe seu Nome:"; cin>>nome;
                    cout<<"Informe sua senha:"; cin>>senha;
                    adm.setCPF(CPF1);
                    adm.setNomeDoADM(nome);
                    adm.setSenha(senha);
                    p.signUp(adm);
                    break;
                case 2:
                    cout<<"Informe seu CPF:"; cin>>CPF1;
                    cout<<"Informe sua senha:"; cin>>senha;
                    loopSistema=p.login(CPF1,senha);
                    cout<<(loopSistema ? " ": "Senha invalida")<<endl;
                    while(loopSistema){
                        op1= subMenuADM();
                        switch(op1){
                            case 1:
                                cout<<"Digite o valor a ser cobrado:"; cin >> valor1;
                                p.cobrarManutencao(valor1);
                                cout<<"Cobranca realizada"<<endl;
                                break;
                            case 2:
                                p.calcularJuros();
                                cout<<"Juros Calculado"<<endl;
                                break;
                            case 3:
                                cout<<"Digite o valor, em porcentagem, do juros:"; cin >> valor1;
                                p.adicionarJuros(valor1);
                                cout<<"Valor alterado"<<endl;
                                break;
                            case 4:
                                p.signOut();
                                break;
                            default:
                                cout<<"Opcao nao encontrada";

                        }
                    }
            }

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
  cout<<"[4]Administrador"<<endl;
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

int menuADM(){
    int op;
    cout<<"[1]Cadastrar novo adm"<<endl;
    cout<<"[2]Entrar como adm"<<endl;
    cin>>op;
    return op;
}

int subMenuADM(){
    int op;
    cout<<"[1]Fazer cobranca de manutenção das contas correntes"<<endl;
    cout<<"[2]Adicionar juros nas contas poupancas"<<endl;
    cout<<"[3]Alterar a porcentagem de juros"<<endl;
    cout<<"[4]Sair"<<endl;
    cin>>op;
    return op;
}
