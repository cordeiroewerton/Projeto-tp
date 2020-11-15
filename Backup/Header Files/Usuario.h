#ifndef USUARIO_H
#define USUARIO_H
struct Endereco{
    string rua;
    string CEP;
    string cidade;
    string estado;
};
class Usuario{
  private:
        string nomeDoUsuario;
        int idade;
        long int CPF;
        Endereco enderecoDoUsuario;
  public:

        Usuario(const string & = "0",const int & = 0,const long int & = 0,/*Recurso c++ 11 permite iniciar structs/classes dessa forma*/const Endereco& = {"0","0","0","0"});
        void setIdade(const int &);
        void setCPF(const long int &);
        void setEnderecoDoUsuario(const Endereco &);
        void setNomeDoUsuario(const string &);
        string getNomeDoUsuario()const;
        long int getCPF()const;
        int getIdade()const;
        string getEnderecoDoUsuario()const;
        friend istream & operator>>(istream &, Usuario &);
        friend ostream & operator<<(ostream &, Usuario &);

};

#endif
