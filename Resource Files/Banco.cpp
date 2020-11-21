#include "..\Header Files\Banco.h"
Banco::Banco(){
  carregarDados();
}
bool  Banco::salvarDados(){
    fstream arq1("../DadosContaPoupanca.bin",ios::out);
    fstream arq2("../DadosContaCorrente.bin",ios::out);
    fstream arq3("../DadosADM.bin",ios::out);
    if(!arq1.is_open() or !arq2.is_open() or !arq3.is_open()){
      return false;
    }
    for(int i (0); i < listaDeContasP.size(); i++){
      auxContaP = listaDeContasP[i];
      arq1.write(reinterpret_cast<char *>(&auxContaP),sizeof(auxContaP));
    }
    for(int i (0); i < listaDeContasC.size(); i++){
      auxContaC = listaDeContasC[i];
      arq2.write(reinterpret_cast<char *>(&auxContaC),sizeof(auxContaC));
    }
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
  fstream arq3("../DadosADM.bin");
  if(!arq1.is_open() or !arq2.is_open() or !arq3.is_open()){
    return false;
  }
  while(arq1.read(reinterpret_cast<char *>(&auxContaP),sizeof(auxContaP))){
    listaDeContasP.push_back(auxContaP);
  }
  while(arq2.read(reinterpret_cast<char *>(&auxContaC),sizeof(auxContaC))){
    listaDeContasC.push_back(auxContaC);
  }
  while(arq3.read(reinterpret_cast<char *>(&auxADM),sizeof(auxADM))){
    listaDeADM.push_back(auxADM);
  }
  arq1.close();
  arq2.close();
  arq3.close();
  return true;
}
//Buscar por cadastro no sistema de gerenciamento
int Banco::encontarConta(long int CPF){
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
      if(listaDeADM[i].getCPF()==CPF){
        tipoDeConta = 3;
        return i + 2;
      }
  return 0;
}

bool Banco::login(long int CPF, int senha){
  return verificarLogin(CPF, senha);
}

bool Banco::verificarLogin(long int CPF, int senha){
    int idConta = encontarConta(CPF);
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
  if(encontarConta(contaAux.getUser().getCPF()))
    return false;
  listaDeContasP.push_back(contaAux);
  return true;
}
bool Banco::signUp(ContaCorrente contaAux){
  if(encontarConta(contaAux.getUser().getCPF()))
    return false;
  listaDeContasC.push_back(contaAux);
  return true;
}
bool Banco::signUp(Administrador admAux){
  listaDeADM.push_back(admAux);
  return true;
}

bool Banco::signOut(){
  salvarDados();
  return 0;
}

bool Banco::deletarContas(long int CPF,int senha){
  int idConta(encontarConta(CPF));
  if(not(verificarLogin(CPF,senha)) and not(idConta))
    return false;
  if(tipoDeConta == 1){
      listaDeContasP.erase(listaDeContasP.begin()+(idConta-2),listaDeContasP.begin()+(idConta-2)+1);
      return true;
  }else if(tipoDeConta == 2){
      listaDeContasC.erase(listaDeContasC.begin()+(idConta-2),listaDeContasC.begin()+(idConta-2)+1);
      return true;
  }else{
    cout<<"Erwerton termina a parte de administrador!"<<endl;
  }
  return false;
}

bool Banco::modificarDados(long int CPF, int senha){
  int idConta(encontarConta(CPF));
  if(not(idConta))
    return false;
  cout<<"Dados antigos:"<<endl;
  if(tipoDeConta ==1){
    cout<<listaDeContasP[idConta-2];
    cin>>listaDeContasP[idConta-2];
    return true;
  }else if(tipoDeConta ==2){
    cout<<listaDeContasC[idConta-2];
    cin>>listaDeContasC[idConta-2];
    return true;
  }else{
    cout<<"Erwerton termina a parte de administrador!"<<endl;
  }
  return false;
}
 bool Banco::transferencia(long int CPF1,long int CPF2, float valor){

     int idConta1(encontarConta(CPF1));
     int idConta2;
     if(not(idConta1))
         return false;
     if(tipoDeConta == 1){
         idConta2 = encontarConta(CPF2);
         if(not(idConta2))
             return false;
         if(tipoDeConta == 1)
              transferirContaPoupanca2Poupanca(idConta1-2,idConta2-2,valor);
          else
              transferirContaPoupanca2Corrente(idConta1-2,idConta2-2,valor);
     }else{
         idConta2=encontarConta(CPF2);
         if(not(idConta2))
             return false;
         if(tipoDeConta == 1)
             transferirContaCorrente2Corrente(idConta1-2,idConta2-2,valor);
         else
             transferirContaCorrente2Poupanca(idConta1-2,idConta2-2,valor);
     }
     return true;
 }
bool Banco::transferirContaPoupanca2Poupanca(int idConta1,int idConta2, float valor){
    listaDeContasP[idConta1].setSaldo(listaDeContasP[idConta1].getSaldo() - valor);
    listaDeContasP[idConta2].setSaldo(listaDeContasP[idConta2].getSaldo() + valor);
    return true;
}
bool Banco::transferirContaPoupanca2Corrente(int idConta1,int idConta2,float valor){
    listaDeContasP[idConta1].setSaldo(listaDeContasP[idConta1].getSaldo() - valor);
    listaDeContasC[idConta2].setSaldo(listaDeContasC[idConta2].getSaldo() + valor);
    return true;

}
bool Banco::transferirContaCorrente2Corrente(int idConta1,int idConta2,float valor){
    listaDeContasC[idConta1].setSaldo(listaDeContasC[idConta1].getSaldo() - valor);
    listaDeContasC[idConta2].setSaldo(listaDeContasC[idConta2].getSaldo() + valor);
    return true;

}
bool Banco::transferirContaCorrente2Poupanca(int idConta1,int idConta2,float valor){
    listaDeContasC[idConta1].setSaldo(listaDeContasC[idConta1].getSaldo() - valor);
    listaDeContasP[idConta2].setSaldo(listaDeContasP[idConta2].getSaldo() + valor);
    return true;
}

 bool Banco::sacar(const float & valorDoSaque,const long int & CPF){
     int idConta(encontarConta(CPF));
     if(not(idConta))
         return false;
     if(tipoDeConta == 1) {
         if (valorDoSaque > listaDeContasP[encontarConta(CPF) - 2].getSaldo()) {
             return false;
         }
         listaDeContasP[idConta- 2].setSaldo(listaDeContasP[idConta- 2].getSaldo() - valorDoSaque);
     }else{
         if (valorDoSaque > listaDeContasC[encontarConta(CPF) - 2].getSaldo()) {
             return false;
         }
         listaDeContasC[idConta- 2].setSaldo(listaDeContasC[idConta- 2].getSaldo() - valorDoSaque);
     }
     return true;
 }
 bool Banco::depositar(const float & valorDoDeposito,const long int & CPF){
     int idConta(encontarConta(CPF));
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
         listaDeContasP[idConta - 2].setSaldo(listaDeContasP[idConta - 2].getSaldo() + valorDoDeposito);
     }
     return true;
 }

 void Banco::consultarDados(const long int & CPF, const int & senha){
     int idConta=(encontarConta(CPF))-2;
     if(tipoDeConta == 1) {
         cout << "Nome:" << listaDeContasP[idConta].getUser().getNomeDoUsuario() << endl;
         cout << "Idade: " << listaDeContasP[idConta].getUser().getIdade() << endl;
         cout << "CPF: " << listaDeContasP[idConta].getUser().getCPF() << endl;
         cout << "Saldo: " << listaDeContasP[idConta].getSaldo() << endl;
         cout << "endereco: " << listaDeContasP[idConta].getUser().getEnderecoDoUsuario() << endl;
     }else{
         cout << "Nome:" << listaDeContasC[idConta].getUser().getNomeDoUsuario() << endl;
         cout << "Idade: " << listaDeContasC[idConta].getUser().getIdade() << endl;
         cout << "CPF: " << listaDeContasC[idConta].getUser().getCPF() << endl;
         cout << "Saldo: " << listaDeContasC[idConta].getSaldo() << endl;
         cout << "endereco: " << listaDeContasC[idConta].getUser().getEnderecoDoUsuario() << endl;
     }

 }

void Banco::cobrarManutencao(float taxa){
  for(int i=0;i<listaDeContasC.size();i++){
    listaDeContasC[i].setTaxaDeManutencao(taxa);
  }
}

void Banco::adicionarJuros(float Juros){
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
