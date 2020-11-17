#include "..\Header Files\Conta.h"
Conta::Conta(const Usuario &user,const int & senha,const float & saldo){
  setUser(user);
  setSenha(senha);
  setSaldo(saldo);
}
void Conta::setUser(const Usuario & user){
  this->user = user;
}
void Conta::setSenha(const int & senha){
  this->senha = senha;
}
void Conta::setSaldo(const float & saldo){
  this->saldo = saldo;
}
float Conta::getSaldo()const{
	return saldo;
}
Usuario Conta::getUser()const{
  return user;
}
int Conta::getSenha()const{
  return senha;
}
bool Conta::sacar(const float & valorDoSaque){
  if(valorDoSaque > saldo){
    return false;
  }
  saldo -= valorDoSaque;
  return true;
}
bool Conta::depositar(const float & valorDoDeposito){
  if(valorDoDeposito < 0){
    return false;
  }
  saldo += valorDoDeposito;
  return true;
}
Conta::~Conta(){
}
