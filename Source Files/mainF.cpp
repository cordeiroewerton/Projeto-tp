#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;
#include "..\Resource Files\Usuario.cpp"
#include "..\Resource Files\Conta.cpp"
#include "..\Resource Files\Overload.cpp"
#include "..\Resource Files\Banco.cpp"
int main(){
    Banco bc;
    bc.signUp();
    bc.signOut();
}