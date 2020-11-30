#include "..\Header Files\Banco.h"
Banco::Banco(){
  carregarDados();
}
bool  Banco::salvarDados(){
    fstream arq1("../DadosContaPoupanca.bin",ios::out);
    fstream arq2("../DadosContaCorrente.bin",ios::out);
    fstream arq3("../DadosADM.bin",ios::out);
    if(arq1.is_open())
      for(int i (0); i < listaDeContasP.size(); i++){
        auxContaP = listaDeContasP[i];
        arq1.write(reinterpret_cast<char *>(&auxContaP),sizeof(auxContaP));
      }
    if(arq2.is_open())
      for(int i (0); i < listaDeContasC.size(); i++){
        auxContaC = listaDeContasC[i];
        arq2.write(reinterpret_cast<char *>(&auxContaC),sizeof(auxContaC));
      }
    if(arq3.is_open())
      for(int i (0); i < listaDeADM.size(); i++){
        auxADM = listaDeADM[i];
        arq3.write(reinterpret_cast<char *>(&auxADM),sizeof(auxADM));
      }
    arq1.close();
    arq2.close();
    arq3.close();
    return true;
}
bool Banco::carregarDados(){
  fstream arq1("../DadosContaPoupanca.bin",ios::in);
  fstream arq2("../DadosContaCorrente.bin",ios::in);
  fstream arq3("../DadosADM.bin",ios::in);
  if(arq1.is_open())
    while(arq1.read(reinterpret_cast<char *>(&auxContaP),sizeof(auxContaP))){
      listaDeContasP.push_back(auxContaP);
    }
  if(arq2.is_open())
    while(arq2.read(reinterpret_cast<char *>(&auxContaC),sizeof(auxContaC))){
      listaDeContasC.push_back(auxContaC);
    }
  if(arq3.is_open())
    while(arq3.read(reinterpret_cast<char *>(&auxADM),sizeof(auxADM))){
      listaDeADM.push_back(auxADM);
    }
  arq1.close();
  arq2.close();
  arq3.close();
  return true;
}
//Buscar pelo cadastro nos vectos
int Banco::localizarIndeceDaContaNosVectos(const long int & CPF){
  for(int i(0);i < listaDeContasP.size();i++)
    if(listaDeContasP[i].getUser().getCPF() == CPF) {
        tipoDeConta = 1;
        return i + 2;
    }
  for(int i(0);i < listaDeContasC.size();i++)
      if(listaDeContasC[i].getUser().getCPF() == CPF) {
          tipoDeConta = 2;
          return i + 2;
      }
  for(int i(0);i < listaDeADM.size();i++)
      if(listaDeADM[i].getUser().getCPF()==CPF){
        tipoDeConta = 3;
        return i + 2;
      }
  return 0;
}
int Banco::login(const long int & CPF,const int & senha){
  int vLogin(verificarLogin(CPF, senha));
  if(!(tipoDeConta == 3))
    return vLogin;
  return vLogin?vLogin+1:vLogin;
}
bool Banco::verificarLogin(const long int & CPF,const int & senha){
    int idConta = localizarIndeceDaContaNosVectos(CPF);
    if(idConta and tipoDeConta == 1)
        if(listaDeContasP[idConta-2].getSenha() == senha){
          return true;
        }
    if(idConta and tipoDeConta == 2)
        if(listaDeContasC[idConta-2].getSenha() == senha){
          return true;
        }
    if(idConta and tipoDeConta == 3){
      if(listaDeADM[idConta-2].getSenha() == senha){
        return true;
      }
    }
    return false;
}

bool Banco::signUp(ContaPoupanca contaAux){
  if(localizarIndeceDaContaNosVectos(contaAux.getUser().getCPF()))
    return false;
  listaDeContasP.push_back(contaAux);
  return true;
}
bool Banco::signUp(ContaCorrente contaAux){
  if(localizarIndeceDaContaNosVectos(contaAux.getUser().getCPF()))
    return false;
  listaDeContasC.push_back(contaAux);
  return true;
}
bool Banco::signUp(Administrador admAux){
  if(localizarIndeceDaContaNosVectos(admAux.getUser().getCPF()))
      return false;
  listaDeADM.push_back(admAux);
  return true;
}

bool Banco::signOut(){
  salvarDados();
  return 0;
}

bool Banco::deletarContas(const long int & CPF,const int & senha){
  int idConta(localizarIndeceDaContaNosVectos(CPF));
  if(not(verificarLogin(CPF,senha)) and not(idConta))
    return false;
  if(tipoDeConta == 1){
      listaDeContasP.erase(listaDeContasP.begin()+(idConta-2),listaDeContasP.begin()+(idConta-2)+1);
      return true;
  }else if(tipoDeConta == 2){
      listaDeContasC.erase(listaDeContasC.begin()+(idConta-2),listaDeContasC.begin()+(idConta-2)+1);
      return true;
  }else{
  }
  return false;
}
bool Banco::imprimir()const{
  cout.fill('_');
  cout << "Lista de Contas Poupancas" << endl;
  if(!listaDeContasP.size())
      cout << "Lista Vazia" << endl;
  for (int i(0); i < listaDeContasP.size(); i++){
    cout << setw(70) << " "<< endl;
    cout << "[" << i << "]" << "Nome: " << listaDeContasP[i].getUser().getNomeDoUsuario() << "| Idade:" << listaDeContasP[i].getUser().getIdade() << "| Saldo:" << listaDeContasP[i].getSaldo() << endl;
    cout << setw(70) << " " << endl;
  }
  cout << "Lista de Contas Correntes" << endl;
  if(!listaDeContasP.size())
      cout << "Lista Vazia" << endl;
  for(int i(0); i < listaDeContasC.size(); i++){
    cout << setw(70) << " " << endl;
    cout << "["<< i << "]" << "Nome: " << listaDeContasC[i].getUser().getNomeDoUsuario()<<"| Idade:"<<listaDeContasC[i].getUser().getIdade()<<"| Saldo:"<<listaDeContasC[i].getSaldo()<<endl;
    cout << setw(70)<<" "<< endl;
  }
  return true;
}
bool Banco::modificarDados(const long int & CPF,const int & senha){
  int idConta(localizarIndeceDaContaNosVectos(CPF));
  if(not(idConta) or not(login(CPF,senha)))
    return false;
  cout << "Dados antigos:" << endl;
  if(tipoDeConta == 1){
    cout<<listaDeContasP[idConta-2];
    cin>>listaDeContasP[idConta-2];
    return true;
  }else if(tipoDeConta ==2){
    cout<<listaDeContasC[idConta-2];
    cin>>listaDeContasC[idConta-2];
    return true;
  }
  return false;
}
 bool Banco::transferencia(const long int & CPF1,const long int& CPF2, const float & valor){
     if(CPF1 == CPF2 or not(localizarIndeceDaContaNosVectos(CPF2))) {
         return false;
     }
    if(!sacar(valor, CPF1))
        return false;
    depositar(valor,CPF2);
    return true;
 }
bool Banco::verComprovanteDeTransferencia(const long int & CPF1,const long int& CPF2, const float & valor){
  int idConta1 = (localizarIndeceDaContaNosVectos(CPF1));
  int idConta2;
  if(tipoDeConta == 1){
    idConta2 = (localizarIndeceDaContaNosVectos(CPF2));
    if(tipoDeConta == 1){
      cout<<listaDeContasP[idConta1-2].getUser().getNomeDoUsuario()<<" transferiu R$ "<<valor<<" para "<<listaDeContasP[idConta2-2].getUser().getNomeDoUsuario()<<endl;
    }else{
      cout<<listaDeContasP[idConta1-2].getUser().getNomeDoUsuario()<<" transferiu R$ "<<valor<<" para "<<listaDeContasC[idConta2-2].getUser().getNomeDoUsuario()<<endl;
    }
  }else{
    idConta2 = (localizarIndeceDaContaNosVectos(CPF2));
    if(tipoDeConta == 1){
      cout<<listaDeContasC[idConta1-2].getUser().getNomeDoUsuario()<<" transferiu R$ "<<valor<<" para "<<listaDeContasP[idConta2-2].getUser().getNomeDoUsuario()<<endl;
    }else{
      cout<<listaDeContasC[idConta1-2].getUser().getNomeDoUsuario()<<" transferiu R$ "<<valor<<" para "<<listaDeContasC[idConta2-2].getUser().getNomeDoUsuario()<<endl;
    }
  }
  return true;
}
 bool Banco::sacar(const float & valorDoSaque,const long int & CPF){
     int idConta(localizarIndeceDaContaNosVectos(CPF));
     if(not(idConta) or valorDoSaque < 0)
         return false;
     if(tipoDeConta == 1) {
         if (valorDoSaque > listaDeContasP[idConta - 2].getSaldo()) {
             return false;
         }
         listaDeContasP[idConta- 2].setSaldo(listaDeContasP[idConta- 2].getSaldo() - valorDoSaque);
     }else{
         if (valorDoSaque > listaDeContasC[idConta - 2].getSaldo()) {
             return false;
         }
         listaDeContasC[idConta- 2].setSaldo(listaDeContasC[idConta- 2].getSaldo() - valorDoSaque);
     }
     return true;
 }
 bool Banco::depositar(const float & valorDoDeposito,const long int & CPF){
     int idConta(localizarIndeceDaContaNosVectos(CPF));
     if(not(idConta))
         return false;
     if(tipoDeConta == 1) {
         if (valorDoDeposito < 0) {
             return false;
         }
         listaDeContasP[idConta - 2].setSaldo(listaDeContasP[idConta - 2].getSaldo() + valorDoDeposito);
     }else{
         if (valorDoDeposito < 0) {
             return false;
         }
         listaDeContasC[idConta - 2].setSaldo(listaDeContasC[idConta - 2].getSaldo() + valorDoDeposito);
     }
     return true;
 }
 float Banco::getSaldoDoUsuarioLogado(const long int& CPF){
   int idConta(localizarIndeceDaContaNosVectos(CPF));
   if(tipoDeConta == 1)
    return listaDeContasP[idConta-2].getSaldo();
  return listaDeContasC[idConta-2].getSaldo();
 }
 string Banco::getNomeDoUsuarioLogado(const long int& CPF){
   int idConta(localizarIndeceDaContaNosVectos(CPF));
   if(tipoDeConta == 1)
    return listaDeContasP[idConta-2].getUser().getNomeDoUsuario();
  if(tipoDeConta == 2)
    return listaDeContasC[idConta-2].getUser().getNomeDoUsuario();
  return listaDeADM[idConta-2].getUser().getNomeDoUsuario();
 }
 void Banco::consultarDados(const long int & CPF, const int & senha){
     int idConta=(localizarIndeceDaContaNosVectos(CPF))-2;
     cout.fill('_');
     cout << setw(40) << " " << endl;
     if(tipoDeConta == 1) {
         cout << "Nome:" << listaDeContasP[idConta].getUser().getNomeDoUsuario() << endl;
         cout << "Idade: " << listaDeContasP[idConta].getUser().getIdade() << endl;
         cout << "CPF: " << listaDeContasP[idConta].getUser().getCPF() << endl;
         cout << "Saldo: " << listaDeContasP[idConta].getSaldo() << endl;
         cout << "Endereco: " << listaDeContasP[idConta].getUser().getEnderecoDoUsuario() << endl;
     }else{
         cout << "Nome:" << listaDeContasC[idConta].getUser().getNomeDoUsuario() << endl;
         cout << "Idade: " << listaDeContasC[idConta].getUser().getIdade() << endl;
         cout << "CPF: " << listaDeContasC[idConta].getUser().getCPF() << endl;
         cout << "Saldo: " << listaDeContasC[idConta].getSaldo() << endl;
         cout << "Endereco: " << listaDeContasC[idConta].getUser().getEnderecoDoUsuario() << endl;
     }

 }

void Banco::cobrarManutencao(const float & taxa){
  for(int i=0;i<listaDeContasC.size();i++){
    listaDeContasC[i].CalcularTaxaDeManutencao(taxa);
  }
}

void Banco::adicionarJuros(const float & Juros){
  for(int i=0;i<listaDeContasP.size();i++){
    listaDeContasP[i].setJurosExtra(Juros);
  }
}
void Banco::calcularJuros(){
  for(int i=0;i<listaDeContasP.size();i++){
    listaDeContasP[i].CalcularJurosExtra();
  }
}
 Banco::~Banco(){
 }
