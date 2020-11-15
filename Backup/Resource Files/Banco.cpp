#include "..\Header Files\Banco.h"
template <class T>
Banco<T>::Banco(){
  carregarDados();
}
template <class T>
bool  Banco<T>::salvarDados(){
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

template <class T>
bool Banco<T>::carregarDados(){
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
template <class T>
bool Banco<T>::login(long int CPF, int senha){
  return verificarLogin(CPF, senha);
}
template <class T>
bool Banco<T>::verificarLogin(long int CPF, int senha){
    int idConta = encontarConta(CPF);
    if(idConta)
        if(listaDeContas[idConta-2].getSenha() == senha){
          return true;
        }
    return false;
}
template <class T>
bool Banco<T>::signUp(T contaGenerica){
  listaDeContas.push_back(contaGenerica);
  return true;
}
template <class T>
bool Banco<T>::signOut(){
  salvarDados();
  return 0;
}
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
template <class T>
int Banco<T>::encontarConta(long int CPF){
  for(int i(0);i < listaDeContas.size();i++){
    if(listaDeContas[i].getUser().getCPF() == CPF){
        return i+2;
    }
  }
  return 0;
}
template <class T>
bool Banco<T>::ordenarLista(){
  sort(listaDeContas.begin(),listaDeContas.end());
  return true;
}
//
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
