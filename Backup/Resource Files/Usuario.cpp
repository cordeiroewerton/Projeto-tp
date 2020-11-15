#include "..\Header Files\Usuario.h"
Usuario::Usuario(const string & nomeDoUsuario,const int & idade,const long int & CPF,/*Recurso c++ 11 permite iniciar structs/classes dessa forma*/const Endereco & enderecoDoUsuario){
	this->nomeDoUsuario=nomeDoUsuario;
	this->idade=idade;
	this->CPF=CPF;
	this->enderecoDoUsuario=enderecoDoUsuario;
}

void Usuario::setIdade(const int & idade){
	this->idade=idade;
}

int Usuario::getIdade() const{
	return idade;
}

void Usuario::setCPF(const long int & CPF){
	this->CPF=CPF;
}

long int Usuario::getCPF() const{
	return CPF;
}

void Usuario::setEnderecoDoUsuario(const Endereco & enderecoDoUsuario){
	this->enderecoDoUsuario=enderecoDoUsuario;
}

string Usuario::getEnderecoDoUsuario() const{
	return enderecoDoUsuario.rua +","+enderecoDoUsuario.CEP+","+enderecoDoUsuario.cidade+","+enderecoDoUsuario.estado+".";
}

void Usuario::setNomeDoUsuario(const string & nomeDoUsuario){
	this->nomeDoUsuario=nomeDoUsuario;
}

string Usuario::getNomeDoUsuario() const{
	return nomeDoUsuario;
}
istream & operator<<(istream & is,Usuario & auxUsuario){
	cout<<"Nome: "<<auxUsuario.getNomeDoUsuario();
	cout<<"Idade: "<<auxUsuario.getIdade();
	cout<<"CPF: "<<auxUsuario.getCPF();
	cout<<"Endereco: "<<auxUsuario.getEnderecoDoUsuario();

	return is;
}
ostream & operator>>(ostream & os,Usuario & auxUsuario){
	string nome;
	int idade;
	long int CPF;
	Endereco endereco;
	cout<<"Nome: ";cin>>nome;
	cout<<"Idade: ";cin>>idade;
	cout<<"CPF: ";cin>>CPF;
	cout<<"Rua: ";cin>>endereco.rua;
	cout<<"Cep: ";cin>>endereco.CEP;
	cout<<"Cidade: ";cin>>endereco.cidade;
	cout<<"Estado: ";cin>>endereco.estado;
	auxUsuario.setNomeDoUsuario(nome);
	auxUsuario.setIdade(idade);
	auxUsuario.setCPF(CPF);
	auxUsuario.setEnderecoDoUsuario(endereco);
	return os;
}
