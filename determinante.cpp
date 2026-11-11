#include <iostream>
#include <string>
#include <vector>

class Ponto{

    protected:
    double x;
    double y;

    public:
    Ponto(double pX, double pY) : x(pX), y(pY) {}

    void calcularDeterminante(const Ponto& pB, const Ponto& pC){
        std::vector <std::vector<double>> Matriz{3, std::vector<double>(3, 0.0)}; //std::vector<std::vector<double>> Matriz = std::vector<std::vector<double>>(3, std::vector<double>(3, 0.0));

        // Criando Vetores auxiliares para atribuir os dados a Matriz
        std::vector <double> tempX = {x, pB.x, pC.x};
        std::vector <double> tempY = {y, pB.y, pC.y};

        for (int i = 0; i <= 2; i++){
            for (int j = 0; j <= 2; j++){
                // A coluna de subscrito 0 representa a coluna no qual só tem valores de X
                if (j == 0){
                    Matriz[i][j] = tempX[i];

                // A coluna de subscrito 1 representa a coluna no qual só tem valores de Y
                } else if (j == 1){
                    Matriz[i][j] = tempY[i];

                // A ultima coluna só tem 0 número 1
                } else {
                    Matriz[i][j] = 1;

                }

            }
        }

        // Calculando o Minuendo e o subtraendo:
        double Minuendo = 0;
        double Subtraendo = 0;

        for (int k = 0; k <= 2; k++){
            double produto_ida = 1;
            double produto_volta = 1;

            for (int i = 0; i <= 2; i++){
                //Minuendo
                int j_ida = (k + i) % 3;
                produto_ida *= Matriz[i][j_ida];
              

                //Subtraendo:
                int j_volta = (k - i + 3) % 3;
                produto_volta *= Matriz[i][j_volta];
                
            }

              Minuendo += produto_ida;
              Subtraendo += produto_volta;

        }

        std::string resultado;
        double determinante = Minuendo - Subtraendo;

        if (determinante == 0){
            resultado = " Os 3 pontos sao colineares (Pertemcem a mesma reta).\n";

        } else {
            resultado = " Os 3 pontos nao sao colineares, eles formam um triangulo.\n";

        }

        std::cout << "A determinate e: " << determinante <<"." << resultado << '\n';

       

    };


    

};

int main(){

    Ponto A(0, 1);
    Ponto B(3, 2);
    Ponto C(-1, 2);

    A.calcularDeterminante(B, C);



    return 0;
}