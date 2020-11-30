#include "..\Header Files\Conta.h"
template<typename  T>
void exceptInput(T & auxT, string auxTemp){
    bool loop = true;
    while(loop){
        try {
            cin >> auxT;
            if (cin.fail())//retorna true se  ocorrer uma falha de entrada
                throw "Caracter invalido, informe novamente ";
            loop = false;
        }catch(const char * e){
            cout<<e<<auxTemp + ": ";
            cin.clear();//limpar o status de erro do buffer
            cin.ignore(256,'\n');//ignora o resto da linha após a primeira instância do erro pula/passa para a próxima linha.
        }
    }
    //...
}
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
	cout<<"Nome: ";getline(cin,nome);
	cout<<"Idade: ";
	exceptInput(idade,"sua idade");
	cout<<"CPF: ";
  exceptInput(CPF, "seu CPF");
  cin.ignore();
  cout<<"Rua: ";getline(cin,endereco.rua);
  cout<<"Cep: ";getline(cin,endereco.CEP);
  cout<<"Cidade: ";getline(cin,endereco.cidade);cout<<"Estado: ";getline(cin,endereco.estado);
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
    exceptInput(senha,"sua senha");
    contaAux.setSenha(senha);
    contaAux.setUser(auxUser);
    system("cls");
    return in;
}
