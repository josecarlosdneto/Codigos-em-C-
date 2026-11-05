#include <iostream>
#include <string>

class Funcionario {

    protected:

    std::string nome;
    double salario_base;

    public:

    Funcionario(std::string pNome, double pSalario_Base) : nome(pNome), salario_base(pSalario_Base) {};


    void exibir_Dados_Basicos(){
        std::cout << "[Dono Da Conta]: " << nome << '\n';
        std::cout << "[Salario Base]: " << salario_base << '\n';
    }


};

class Gerente : public Funcionario{
    
    protected:
    double bonus;

    public:

    Gerente(std::string pNome, double pSalario_Base, double pBonus) : Funcionario(pNome, pSalario_Base), bonus(pBonus) {};

    void Calcular_Salariio_Total(){
        std::cout << "[Salario Total]: " << salario_base + bonus << '\n';
        
    }

};

class Desenvolvedor : public Funcionario{
    
    protected:

    std::string linguagem_principal;

    public:

    Desenvolvedor(std::string pNome, double pSalario_Base, std::string pLinguagem_Principal)
     : Funcionario(pNome, pSalario_Base), linguagem_principal(pLinguagem_Principal){};


     void Exibir_Linguagem(){
        std::cout << "[A Linguagem do programador]: " << linguagem_principal << '\n';
     }

};

class Estagiario : public Funcionario{  
    protected:
    
    int horas_semanais;

    public:

    Estagiario(std::string pNome, double pSalario_Base, int pHoras) 
    : Funcionario(pNome, pSalario_Base), horas_semanais(pHoras) {};

    void exibirHoras(){
        std::cout << "[Horas Trabalhadas]: " << horas_semanais << '\n';
    }



};


int main(){

    Gerente novoGerente("Gabriel", 8000.0, 800.0);
    Desenvolvedor meuDev("Bruno Lima", 5000.0, "C++");
    Estagiario meuEstagiario("Carlos Silva", 1500.0, 30);

    novoGerente.exibir_Dados_Basicos();
    meuDev.exibir_Dados_Basicos();
    meuEstagiario.exibir_Dados_Basicos();

    novoGerente.Calcular_Salariio_Total();
    meuDev.Exibir_Linguagem();
    meuEstagiario.exibirHoras();


    return 0;
}