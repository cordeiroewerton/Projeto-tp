//main teste para a classe usuario
#include <iostream>
using namespace std;
#include "..\Resource Files\Usuario.cpp"

int main(){
    
    Usuario user;
    user.setIdade(20);
    cout<<user.getIdade()<<endl;
    user.setCPF(123123);
    cout<<user.getCPF()<<endl;
    user.setNomeDoUsuario("Jose");
    cout<<user.getNomeDoUsuario()<<endl;
    cout>>user;

    return 0;
}