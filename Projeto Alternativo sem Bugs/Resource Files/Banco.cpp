#include "..\Header Files\Banco.h"

Banco::Banco(){
  carregarDados();
}
bool  Banco::salvarDados(){
  fstream arq("../BancoDeDados.bin",ios::out);
  if(!arq.is_open()){
    return false;
  }
  for(int i = 0; i < listaDeContas.size(); i++){
    auxConta = listaDeContas[i];
    arq.write(reinterpret_cast<char *>(&auxConta),sizeof(auxConta));
  }
    arq.close();
    return true;
}
bool Banco::carregarDados(){
  fstream arq("../BancoDeDados.bin",ios::in);
  if(!arq.is_open()){
    return false;
  }
  while(arq.read(reinterpret_cast<char *>(&auxConta),sizeof(auxConta))){
    listaDeContas.push_back(auxConta);
  }
  arq.close();
  return true;
}

bool Banco::login(long int CPF, int senha){
  return verificarLogin(CPF, senha);
}

bool Banco::verificarLogin(long int CPF, int senha){
    int idConta = encontarConta(CPF);
    if(idConta)
        if(listaDeContas[idConta-2].getSenha() == senha){
          return true;
        }
    return false;
}

bool Banco::signUp(Conta contaAux){
  listaDeContas.push_back(contaAux);
  return true;
}

bool Banco::signOut(){
  salvarDados();
  return 0;
}

bool Banco::deletarContas(long int CPF,int senha){
  if(not(verificarLogin(CPF,senha)))
    return false;
  int idConta(encontarConta(CPF));
  if(idConta){
      listaDeContas[idConta-2] = listaDeContas[listaDeContas.size()-1];
      listaDeContas.pop_back();
      cout<<"Não conseguir usar o erase"<<endl;
      return true;
  }
  return false;
}

bool Banco::modificarDados(long int CPF, int senha){
  int idConta(encontarConta(CPF));
  if(idConta){
    cout<<"Dados antigos:"<<endl;
    cout<<listaDeContas[idConta-2];
    cin>>listaDeContas[idConta-2];
    return true;
  }
  return false;
}
//Buscar por cadastro no sistema de gerenciamento

int Banco::encontarConta(long int CPF){
  for(int i(0);i < listaDeContas.size();i++)
    if(listaDeContas[i].getUser().getCPF() == CPF)
        return i+2;
  return 0;
}

bool Banco::ordenarLista(){
  //sort(listaDeContas.begin(),listaDeContas.end());
  return true;
}
//

bool Banco::transferencia(long int CPF1,long int CPF2, float valor){
    int idConta1(encontarConta(CPF1));
    int idConta2(encontarConta(CPF2));
    if(idConta1 and idConta2 != 0){
      if(sacar(valor,CPF1) and depositar(valor,CPF2) != 0)
          return false;
      return true;
    }
    return false;
}
bool Banco::sacar(const float & valorDoSaque,const long int & CPF){
    if(valorDoSaque > listaDeContas[encontarConta(CPF)-2].getSaldo()){
        return false;
    }
    listaDeContas[encontarConta(CPF)-2].setSaldo(listaDeContas[encontarConta(CPF)-2].getSaldo()-valorDoSaque);
    return true;
}
bool Banco::depositar(const float & valorDoDeposito,const long int & CPF){
    if(valorDoDeposito < 0){
        return false;
    }
    listaDeContas[encontarConta(CPF)-2].setSaldo(listaDeContas[encontarConta(CPF)-2].getSaldo()+valorDoDeposito);
    return true;
}

void Banco::consultarDados(const long int & CPF, const int & senha){
    int idConta=(encontarConta(CPF))-2;
    cout<<"Nome:"<<listaDeContas[idConta].getUser().getNomeDoUsuario()<<endl;
    cout<<"Idade: "<<listaDeContas[idConta].getUser().getIdade()<<endl;
    cout<<"CPF: "<<listaDeContas[idConta].getUser().getCPF()<<endl;
    cout<<"Saldo: "<<listaDeContas[idConta].getSaldo()<<endl;
    cout<<"endereco: "<<listaDeContas[idConta].getUser().getEnderecoDoUsuario()<<endl;
}

Banco::~Banco(){

}
