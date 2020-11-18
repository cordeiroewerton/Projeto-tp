#include "..\Header Files\Banco.h"

Banco::Banco(){
  carregarDados();
}

bool Banco::salvarDados(){
  fstream arq("../BancoDeDados.bin",ios::out);
  if(!arq.is_open()){
    return false;
  }
  //primeiro salvar as contas corrente
  for(int i = 0; i < listaDeContasC.size(); i++){
    auxContaC = listaDeContasC[i];
    arq.write(reinterpret_cast<char *>(&auxContaC),sizeof(auxContaC));
  }
  //segundo salvar as contas poupança
  for(int i=0;i<listaDeContasP.size();i++){
    auxContaP = listaDeCOntasP[i];
    arq.write(reinterpret_cast<char *>(&auxContaP),sizeof(auxContaP));
  }
    arq.close();
    return true;
}

bool Banco::carregarDados(){
  fstream arq("../BancoDeDados.bin",ios::in);
  if(!arq.is_open()){
    return false;
  }
  //primeiro a leitura das contas correrntes
  while(arq.read(reinterpret_cast<char *>(&auxContaC),sizeof(auxContaC))){
    listaDeContasC.push_back(auxContaC);
  }
  //segundo a leitura das contas poupança
  while(arq.read(reinterpret_cast<char *>(&auxContaP),sizeof(auxCOntaP))){
    listaDeContasP.push_back(auxContaP)
  }
  arq.close();
  return true;
}

bool Banco::login(long int CPF, int senha){
  return verificarLogin(CPF, senha);
}

bool Banco<T>::verificarLogin(long int CPF, int senha){
    int idConta = encontarConta(CPF);
    if(idConta)
        if(listaDeContasC[idConta-2].getSenha() == senha || listaDeContasP[odCpmta-2].getSenha() == senha){
          return true;
        }
    return false;
}

bool Banco::signUp(ContaCorrente contaGenerica){
  listaDeContasC.push_back(contaGenerica);
  return true;
}
bool Banco::signUp(ContaPoupanca contaGenerica){
  listaDeContasP.push_back(contaGenerica);
  return true;
}

bool Banco::signOut(){
  salvarDados();
  return 0;
}
//esse aqui eu n entendi direito n
template <class T>
bool Banco<T>::deletarContas(long int CPF,int senha){
  if(not(verificarLogin(CPF,senha)))
    return false;
  int idConta(encontarConta(CPF));
  if(idConta){
      //listaDeContas.erase(listaDeContas.begin(),listaDeContas.end());
      cout<<"Não conseguir usar o erase"<<endl;
      return true;
  }
  return false;
}

template <class T>
bool Banco<T>::modificarDados(long int CPF, int senha){
  int idConta(encontarConta(CPF)-1);
  if(idConta){
    //
    //Preciso de um método para modificar os atributos da conta
    //
    return true;
  }
  return false;
}
//Buscar por cadastro no sistema de gerenciamento


int Banco::encontarConta(long int CPF){
  for(int i(0);i < listaDeContasC.size();i++){
    if(listaDeContasC[i].getUser().getCPF() == CPF){
        return i+2;
    }
  }
  return 0;
}
int Banco::encontarConta(long int CPF){
  for(int i=0;i<listaDeContasP.size();i++){
    if(listaDeContasP[i].getUser().getCPF()==CPF){
      return i+2;
    }
  }
  return 0;
}

bool Banco::ordenarLista(){
  sort(listaDeContasC.begin(),listaDeContasC.end());
  sort(listaDeContasP.begin(),listaDeContasP.end());
  return true;
}
//rever essa parte, acho que tenha uma maneira mais facil de fazer isso
template <class T>
bool Banco<T>::transferencia(long int CPF1, int senha, long int CPF2, float valor){
    if(not(verificarLogin(CPF1,senha)))
      return false;
    int idConta1(encontarConta(CPF1));
    int idConta2(encontarConta(CPF2));
    if(idConta1 and idConta2 != 0){
      listaDeContas[idConta1-2].sacar(valor);
      listaDeContas[idConta2-2].depositar(valor);
      return true;
    }
    return false;
}
//rever essa parte tbm
template <class T>
void Banco<T>::consultarDados(const long int & CPF, const int & senha){
    int idConta=(encontarConta(CPF))-2;
    cout<<"Nome:"<<listaDeContas[idConta].getUser().getNomeDoUsuario()<<endl;
    cout<<"Idade: "<<listaDeContas[idConta].getUser().getIdade()<<endl;
    cout<<"CPF: "<<listaDeContas[idConta].getUser().getCPF()<<endl;
    cout<<"Saldo: "<<listaDeContas[idConta].getSaldo()<<endl;
    cout<<"endereco: "<<listaDeContas[idConta].getUser().getEnderecoDoUsuario()<<endl;
}
template <class T>
Banco<T>::~Banco(){

}
