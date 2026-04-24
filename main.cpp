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


// criei a funcao pra pedir arquivo e mandar pra string arquivo
void pedirarquivo() {
    system("clear");
    std::cout << "\033[32mASL EDITOR\033[0m""\n";
    std::cout << "insira o nome do arquivo\n";
    std::getline(std::cin, arquivo);
}

//aqui crianos pra abrir arquivo e carregar linhas
void abrirarquivo(std::string arquivo) {
    std::fstream arquivo(std::string arquivo);
    while (std::fstream(arquivo, linha)) {
        std::getline(cin, linha);
    }
}











int main() {
    pedirarquivo();
    return 0;
} 
