#include <iostream>
#include <cmath>



class Ponto{

    protected:

    double x;
    double y;

    public:

    Ponto(double pX, double pY) : x(pX), y(pY) {};

    Ponto() : x(0), y(0) {};

    void definir_ponto( double pXdef, double pYdef){
        x = pXdef;
        y = pYdef;
    }

    void obter_ponto(){
        std::cout << "[Abscissa]: " << x << '\n';
        std::cout << "[Ordenadas]: " << y << '\n';
        std::cout << "P(" << x << "," << y << ")" << '\n';
    }

    void calcular_distancia_entre_pontos(const Ponto& outroPonto){
        double d = sqrt(std::pow(outroPonto.x - x, 2) + std::pow(outroPonto.y - y, 2));
        std::cout << "[Distancia]: " << d << '\n';
    }

    void calcular_distancia(double x2, double y2){
        double d = sqrt(std::pow(x2 - x, 2) + std::pow(y2 - y, 2));
        std::cout << "[Distancia]: " << d << '\n';
    }


};


class Circulo : public Ponto {
    protected:
    double raio;

    public:
    Circulo(double pRaio, double pX, double pY) : Ponto(pX, pY), raio(pRaio) {};

    Circulo() : Ponto(0, 0), raio(0) {};

    void calcular_area(){
        double area = 3.1415926535897932 * std::pow(raio, 2);
        std::cout << "[Area]: " << area << '\n';
    }

    void comprimento_circunferencia(){
        double comprimento = 2 * 3.1415926535897932 * raio;
        std::cout << "[Comprimento]: " << comprimento << '\n';
    }
};

class Roda : public Circulo {
    protected:

    std::string Material;
    int Aro;
    std::string Fabricante;
    double Largura;
    int Perfil;
    std::string Modelo;

    public:

    Roda(std::string pMaterial, int pAro, std::string pFabricante,
         double pLargura, int pPerfil, std::string pModelo, double pRaio,
        double pX, double pY) : 
        Circulo(pRaio, pX, pY), Material(pMaterial), Aro(pAro), Fabricante(pFabricante),
        Largura(pLargura), Perfil(pPerfil), Modelo(pModelo)  {};

    
    void mostrar_roda(){
        std::cout << "[Material]: " << Material << '\n';
        std::cout << "[Aro]: " << Aro << '\n';
        std::cout << "[Fabricante]: " << Fabricante << '\n';
        std::cout << "[Largura]: " << Largura << '\n';
        std::cout << "[Perfil]: " << Perfil << '\n';
        std::cout << "[Modelo]: " << Modelo << '\n';
    }



};


int main(){

// Testando a Definição e a Obtenção das Cordenadas dos pontos
    Ponto p1;
    p1.obter_ponto();
    p1.definir_ponto(5 ,10);
    p1.obter_ponto();

// Testando os Calculos
    Ponto p2(10, 56);
    p1.calcular_distancia_entre_pontos(p2);
    p1.calcular_distancia(10, 20);

// Testando a Classe Circulo
Circulo c1(5, 0, 0);
c1.calcular_area();
c1.comprimento_circunferencia();

// Testando a Classe Roda
Roda MyRoda("Borracha", 17, "Michelin", 225, 45, "Pilot Sport 4", 5, 0, 0);
MyRoda.mostrar_roda();

    return 0;
}