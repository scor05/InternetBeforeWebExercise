/*
Compilador de brainf*ck para leer un input y printear el output del mismo.
*/

#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <locale.h>

std::vector<char> run_brainfck(std::string in, std::vector<uint8_t> mem, uint16_t index){
    std::vector<char> out;
    int jmpIndex = 0;

    // Safety checks no implementados porque no es necesario para los fines que se usará este programa.
    // Solo se revisa por la funcionalidad básica de brainfck
    for (int i = 0; i < in.length(); i++){
        switch(in[i]){
            case '+': mem[index]++; break;
            case '-': mem[index]--; break;
            case '>': index++; break;
            case '<': index--; break;
            case '.': out.push_back((char) mem[index]); break;
            // input ',' no implementado por los fines de uso del programa.
            case '[': {
                jmpIndex = i;
                break;
            }
            case ']': {
                if (mem[index] != 0){
                    i = jmpIndex;
                    jmpIndex = 0;
                }
            }
        }
    }
    for (uint8_t num : out){
        out.push_back((char) num);
    }
    return out;
}

int main() {
    setlocale(LC_ALL, "es_ES.UTF-8");
    std::vector<uint8_t> mem(30000);
    uint16_t cur = 0;
    std::string input = "";

    std::cout<<"Ingrese el código de Brainf*ck a compilar: \nR/ ";
    std::cin>>input;

    std::vector<char> out;

    if (input == ""){
        std::cout<<"No se ingresó ningún código.";
    } else{
        out = run_brainfck(input, mem, cur);
    }

    for (char c : out){
        std::cout<<c;
    }

    return 0;
}