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
std::string pch[10] = {"int", "float", "string", "double", "if", "else", "break", "while"};
bool higl = false;
std::string palavra;
int tamanho = 10;
int total = 0;

// criei a funcao pra pedir arquivo e mandar pra string arquivo
void pedirarquivo() {
    system("clear");
    std::cout << "\033[32mASL EDITOR\n\033[0m\n";
    std::cout << "\033[33m" << arquivo << "\033[0m\n";
    std::cout << "_________________________\n";
    std::cout << "\ninsira o nome do arquivo:\n";
    std::getline(std::cin, arquivo);
}

// aqui crianos pra abrir arquivo e carregar linhas
void abrirarquivo(std::string arquivo) {
    system("clear");
    std::cout << "\033[32mASL EDITOR\n\033[0m\n";
    std::cout << "arquivo:\033[33m" << arquivo << "\033[0m\n";
    std::cout << "_________________________\n";

    std::ifstream meuarquivo(arquivo);
    while (std::getline(meuarquivo, linha)) {
        linhas.push_back(linha);
    }

    total = linhas.size();
}

// tentando fazer uma funcao pra ativar highlight
void higlight(bool highl) {
    for (int n = 0; n < tamanho; n++) {
        if (palavra == pch[n]) {
            std::cout << "\033[34m" << palavra << "\033[0m]";
        }
    }
}

// carrega as linhas pa nois
void mostrar() {
    for (std::string linha : linhas) {
        std::cout << linha << "\n";
    }
}

// salvar arquivo
void salvar() {
    std::ofstream meuarquivo(arquivo);

    for (std::string linha : linhas) {
        meuarquivo << linha << "\n";
    }

    meuarquivo.close();
}

// funcao importante faz editar arquivo
void editar() {
    std::getline(std::cin, linha);

    if (linha == ":q") {
        exit(0);
    }
    else if (linha == ":wq") {
        salvar();
        exit(0);
    }
    else {
        linhas.push_back(linha);
    }
}

int main() {
    pedirarquivo();
    abrirarquivo(arquivo);
    mostrar();

    while (true) {
        editar();
    }

    return 0;
}



