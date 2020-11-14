#include "..\Header Files\Usuario.h"
#include "..\Header Files\Conta.h"
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

istream & operator>>(istream & in, Conta & contaAux){
    int senha;
    cout<<"senha: ";cin>>senha;
    contaAux.setSenha(senha);
    contaAux.setSaldo(0);
    return in;
}
