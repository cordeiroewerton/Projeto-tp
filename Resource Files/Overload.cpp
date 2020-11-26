#include "..\Header Files\Usuario.h"
#include "..\Header Files\Conta.h"
#include <stdexcept>
#include<cmath>
ostream & operator<<(ostream & os,Usuario & auxUsuario){
	cout<<"Nome: "<<auxUsuario.getNomeDoUsuario();
	cout<<"Idade: "<<auxUsuario.getIdade();
	cout<<"CPF: "<<auxUsuario.getCPF();
	cout<<"Endereco: "<<auxUsuario.getEnderecoDoUsuario();
	return os;
}
istream & operator>>(istream & is,Usuario & auxUsuario){
	string nome;
	int idade;
	long int CPF;
	Endereco endereco;
	cin.ignore(256,'\n');
	try{
			cout<<"Nome: ";getline(cin,nome);
			cout<<"Idade: ";cin>>idade;
			if(cin.fail())
				throw "idade invalida";
			cout<<"CPF: ";cin>>CPF;
			if(cin.fail())
				throw "CPF invalida";
			cin.ignore(256,'\n');
			cout<<"Rua: ";getline(cin,endereco.rua);
			cout<<"Cep: ";getline(cin,endereco.CEP);
			cout<<"Cidade: ";getline(cin,endereco.cidade);
			cout<<"Estado: ";getline(cin,endereco.estado);
	}catch(const char * e){
			cin.clear();
			cin.ignore(256,'\n');
			cout<<e<<endl;
			cin>>auxUsuario;
	}
		auxUsuario.setNomeDoUsuario(nome);
		auxUsuario.setIdade(idade);
		auxUsuario.setCPF(CPF);
		auxUsuario.setEnderecoDoUsuario(endereco);
		return is;
}
ostream & operator<<(ostream & os,Conta & auxUsuario){
	cout<<"Nome: "<<auxUsuario.getUser().getNomeDoUsuario()<<endl;
	cout<<"Idade: "<<auxUsuario.getUser().getIdade()<<endl;
	cout<<"CPF: "<<auxUsuario.getUser().getCPF()<<endl;
	cout<<"Endereco: "<<auxUsuario.getUser().getEnderecoDoUsuario()<<endl;
	return os;
}

istream & operator>>(istream & in, Conta & contaAux){
    int senha;
    Usuario auxUser;
    cin>>auxUser;
    cout<<"senha: ";
		try{
			cin>>senha;
			if(cin.fail())
				throw "Senha constituida apenas de numeros";
		}catch(const char * e){
			cout<<e<<endl;
			while(cin.fail()){
				cin>>senha;
			}
		}
    contaAux.setSenha(senha);
    contaAux.setSaldo(0);
    contaAux.setUser(auxUser);
    return in;
}
