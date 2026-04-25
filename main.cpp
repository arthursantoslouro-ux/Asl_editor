#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include <thread>
#include <chrono>

std::string arquivo = "";
std::string linha;
std::vector<std::string> linhas;
std::string pch[10] = {"int", "float", "string", "double", "if", "else if", "else", "break", "while"};
bool higl = false;
std::string palavra;
int tamanho = 10;

// criei a funcao pra pedir arquivo e mandar pra string arquivo
void pedirarquivo() {
    system("clear");
    std::cout << "\033[32mASL EDITOR\n\033[0m""\n";
    std::cout << "\033[33m" << arquivo << "\033[0m\n""";
    std::cout << "_________________________\n"; 
    std::cout << "\ninsira o nome do arquivo:\n";
    std::getline(std::cin, arquivo);
}

//aqui crianos pra abrir arquivo e carregar linhas
void abrirarquivo(std::string arquivo) {
    system("clear");
    std::cout << "\033[32mASL EDITOR\n\033[0m""\n";
    std::cout << "arquivo:\033[33m" << arquivo << "\033[0m\n""";
    std::cout << "_________________________\n";
    std::ifstream meuarquivo(arquivo);
    while (std::getline(meuarquivo, linha)) {
        std::cout << linha << std::endl;

    }


}



// tentando fazer uma funcao pra ativar highlight
void higlight(bool highl) {
    
    


    for (int n = 0; n < tamanho; n++) {
        if (palavra == pch[n]) {
            std::cout << "\033[34m" << palavra << "\033[0m]";
        }
    }
}






int main() {
    pedirarquivo();
    abrirarquivo(arquivo);
    higlight(true);
    return 0;
} 
