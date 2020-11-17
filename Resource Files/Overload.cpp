#include "..\Header Files\Usuario.h"
#include "..\Header Files\Conta.h"
ostream & operator<<(ostream & os,Usuario & auxUsuario){
	cout<<"Nome: "<<auxUsuario.getNomeDoUsuario()<<endl;
	cout<<"Idade: "<<auxUsuario.getIdade()<<endl;
	cout<<"CPF: "<<auxUsuario.getCPF()<<endl;
	cout<<"Endereco: "<<auxUsuario.getEnderecoDoUsuario()<<endl;
	return os;
}
istream & operator>>(istream & is,Usuario & auxUsuario){
	string nome;
	int idade;
	long int CPF;
	Endereco endereco;
	cout<<"Nome: ";cin>>nome;
	cout<<"Idade: ";cin>>idade;
	cout<<"CPF: ";cin>>CPF;
	cout<<"Pressione Enter"<<endl;
	cout<<"Rua: ";cin>>endereco.rua;
	cout<<"Cep: ";cin>>endereco.CEP;
	cout<<"Cidade: ";cin>>endereco.cidade;
	cout<<"Estado: ";cin>>endereco.estado;
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
    cout<<"senha: ";cin>>senha;
   contaAux.setSenha(senha);
   contaAux.setSaldo(0);
    return in;
}
