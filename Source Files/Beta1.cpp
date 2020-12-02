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
int subMenuADM();
int main() {
    Banco p;
    ContaPoupanca contaAuxP;
    ContaCorrente contaAuxC;
    Administrador adm;
    Usuario userAux;
    string nome;
    cin>>adm;p.signUp(adm);
    long int CPF1, CPF2;
    float valorSaque, valorDeposito, valor1;
    int senha , loopSistema;
    int op1  = 0, op2 = 0;
    bool auxTransferencia;

    while (true) {
        int op(menu());
        switch (op) {
            case 1:
                cout.fill('_');
                cout << setw(40) << " " << endl;
                cout << "[1] Conta Poupanca" << endl;
                cout << "[2] Conta Corrente" << endl;
                cout << setw(40) << " " << endl;
                cout<<">>";
                exceptInput(op2,"a opcao");
                system("cls");
                switch (op2) {
                    case 1:
                        cout << "Insira os dados da sua Conta Poupanca" << endl;
                        cin >> contaAuxP;
                        cout << (p.signUp(contaAuxP) ? "sucesso" : "falha, CPF ja cadastrado!") << endl;
                        break;
                    case 2:
                        cout << "Insira os dados da sua Conta Corrente" << endl;
                        cin >> contaAuxC;
                        cout << (p.signUp(contaAuxC) ? "sucesso" : "falha, CPF ja cadastrado!") << endl;
                        break;
                    default:
                        cout << "Opcao nao encontrada";
                }
                break;
            case 2:
                cout << "Informe seu CPF:";
                exceptInput(CPF1,"seu CPF");
                cout << "Informe sua senha:";
                exceptInput(senha,"sua senha");
                loopSistema = p.login(CPF1, senha);
                system("cls");
                cout << (loopSistema == 1 ? " " : "senha invalida") << endl;
                while (loopSistema == 1) {
                    cout<<"Bem vindo(a) "<<p.getNomeDoUsuarioLogado(CPF1)<<endl;
                    op1 = subMenu();
                    switch (op1) {
                        case 1:
                            cout<<"Saldo Atual: "<<p.getSaldoDoUsuarioLogado(CPF1)<<" [BRL]"<<endl;
                            break;
                        case 2:
                            cout << "Informe o valor do saque [BRL]:";
                            exceptInput(valorSaque,"o valor do saque  [BRL]");
                            cout << "Informe sua senha:";
                            exceptInput(senha,"sua senha");
                            cout << "Saque " << (p.sacar(valorSaque, CPF1) ? "realizado!" : "recusado!") << endl;
                            break;
                        case 3:
                            cout << "Informe o valor do deposito    [BRL]:";
                            exceptInput(valorDeposito,"Valor do deposito  [BRL]");
                            cout << "Informe sua senha:";
                            exceptInput(senha,"sua senha");
                            cout << "Deposito " << (p.depositar(valorDeposito, CPF1) ? "realizado!" : " recusado!")
                                 << endl;
                            break;
                        case 4:
                            cout << "Informe o CPF do destinatario: ";
                            exceptInput(CPF2,"o CPF do destinatario ");
                            cout << "Informe o valor da transferencia [BRL]: ";
                            exceptInput(valorSaque,"o valor da transferencia [BRL]");
                            cout << "Informe sua senha:";
                            exceptInput(senha,"sua senha");
                            if (not(p.login(CPF1, senha))) {
                                cout << "senha invalida" << endl;
                                break;
                            }
                            cout << "Transferencia ";
                            auxTransferencia = p.transferencia(CPF1, CPF2, valorSaque);
                            cout << ((!auxTransferencia) ? "nao ":"")<<"realizada." << endl;
                            if(auxTransferencia){
                              cout<<"Ver comprovante?"<<endl;
                              cout<<"[1] Sim"<<endl;
                              cout<<"[2] Nao"<<endl;
                              exceptInput(op,"a opcao");
                              while(op > 2 or op < 1)
                                exceptInput(op,"a opcao");
                              if(op == 1)
                                p.verComprovanteDeTransferencia(CPF1,CPF2,valorSaque);
                            }
                            break;
                        case 5:
                            cout << "Informe sua senha:";
                            exceptInput(senha,"sua senha");
                            if (p.login(CPF1, senha)) {
                                cout << "efetuando saque...";
                                loopSistema = not(p.deletarContas(CPF1, senha));
                                p.signOut();
                                cout << "deletando" << endl;
                            }
                            break;
                        case 6:
                            p.consultarDados(CPF1, senha);
                            break;
                        case 7:
                            cout << "Informe sua senha:";
                            exceptInput(senha,"sua senha");
                            if (p.login(CPF1, senha))
                                p.modificarDados(CPF1, senha);
                                cout<<"Dados modificados"<<endl;
                                cout<<"Saindo do sistema para efetuar as alteracoes"<<endl;
                                loopSistema = false;
                            break;
                        case 8:
                            loopSistema = false;
                            p.signOut();
                            break;
                        default :
                            cout << "Opcao nao encontrada!"<<endl;
                    }
                }
                break;
            case 3:
                system("cls");
                cout << "Informe seu CPF:";
                exceptInput(CPF1,"seu CPF");
                cout << "Informe sua senha:";
                exceptInput(senha,"sua senha");
                system("cls");
                loopSistema = p.login(CPF1, senha);
                cout << (loopSistema == 2 ? " " : "Senha invalida") << endl;
                while (loopSistema) {
                    op1 = subMenuADM();
                    switch (op1) {
                        case 1:
                            cout << "Insira os dados do Administrador" << endl;
                            cin >> adm;
                            cout << (p.signUp(adm) ? "sucesso" : "falha, CPF ja cadastrado!") << endl;
                            break;
                        case 2:
                            cout << "Digite o valor a ser cobrado:";
                            exceptInput(valor1,"o valor a ser cobrado");
                            p.cobrarManutencao(valor1);
                            cout << "Cobranca realizada" << endl;
                            break;
                       case 3:
                            cout << "Digite o valor, em porcentagem, do juros:";
                            exceptInput(valor1,"o valor, em porcentagem, do juros");
                            p.adicionarJuros(valor1);
                            cout << "Valor alterado" << endl;
                            break;
                        case 4:
                            p.calcularJuros();
                            cout << "Juros Calculado" << endl;
                            break;
                        case 5:
                            p.imprimir();
                            cout << "Fim" << endl;
                            break;
                        case 6:
                            loopSistema = false;
                            p.signOut();
                            break;
                        default:
                            cout << "Opcao nao encontrada!"<<endl;
                        }
                }
            break;
            case 4:
                cout << "Saindo..." << endl;
                p.signOut();
                return 0;
          default:
                cout << "Opcao nao encontrada!"<<endl;;
        }
    }
}
int menu(){
  int op;
  cout.fill('_');
  cout <<  setw(40) <<" " << endl;
  cout << "Bem vindo"<< endl;
  cout << setw(40)<<" " << endl;
  cout << "[1]Criar Conta" << endl;
  cout << "[2]Entrar" << endl;
  cout << "[3]Entrar como administrador" << endl;
  cout << "[4]Sair" << endl;
  cout<<setw(40)<<" "<<endl;
  cout<<">>";
  exceptInput(op,"a opcao");
  system("cls");
  return op;
}
int subMenu(){
  int op;
  cout.fill('_');
  cout << setw(40) << " " << endl;
  cout << "[1]Saldo"<<endl;
  cout << "[2]Sacar" << endl;
  cout << "[3]Deposita" << endl;
  cout << "[4]Transferir" << endl;
  cout << "[5]Deletar Conta" << endl;
  cout << "[6]Consultar Dados" << endl;
  cout << "[7]Modificar Dados" << endl;
  cout << "[8]sair"<< endl;
  cout << setw(40) << " " << endl;
  cout<<">>";
  exceptInput(op,"a opcao");
  system("cls");
  return op;
}
int subMenuADM(){
    int op;
    cout.fill('_');
    cout << setw(40)<<" " << endl;
    cout << "[1]Cadastrar novo administrador" << endl;
    cout << "[2]Fazer cobranca de manutencao das contas correntes" << endl;
    cout << "[3]Alterar a porcentagem de juros" << endl;
    cout << "[4]Adicionar juros nas contas poupancas" << endl;
    cout << "[5]Imprimir Lista de Contas" << endl;
    cout << "[6]Sair" << endl;
    cout << setw(40) << " " << endl;
    cout<<">>";
    exceptInput(op,"a opcao");
    system("cls");
    return op;
}
