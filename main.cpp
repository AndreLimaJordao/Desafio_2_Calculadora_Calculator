/*  
O programa em questão é um simples "calculadora" que permite o usuário realizar operações matemáticas básicas como adição, subtração, multiplicação, divisão, 
potenciação, modulo, entre outras.

A lógica do programa é a seguinte:

    1. Alocação de memória: São definidas duas variáveis constantes, uma para armazenar a quantidade de memória disponível para o software (memorySpace) e outra 
    para armazenar o valor de Pi com uma precisão de duas casas decimais (PiPrecision). Além disso, são criados dois vetores, um para armazenar os números (num) 
    e outro para armazenar os operadores (ope).
    2. Loop principal: É criado um loop principal para a reinicialização do software (rep).
    3. Interação com o usuário: O usuário é solicitado a inserir dois números e uma operação. A operação é armazenada no vetor "ope" e os números são armazenados
    no vetor "num". Em seguida, a função "calculator" é chamada para realizar a operação desejada com os números inseridos e o operador escolhido.
    4. Loop secundário: É criado um loop secundário para verificar se o usuário deseja realizar mais operações (rep2). Caso deseje, o processo de interação com o
    usuário é repetido (passos 3.1 a 3.3).
    5. Apresentação dos resultados: Após o usuário decidir não realizar mais operações, as operações realizadas são apresentadas na tela, juntamente com seus 
    resultados.
    6. Fim do programa: O programa é encerrado.
 */

#include <iostream>

using namespace std;

// Variáveis
const uint8_t memorySpace = 128; // Memória alocada para o software
double num[memorySpace];         // Vetor de números
char ope[memorySpace];           // Vetor de operadores
bool rep = true;                 // Repetição primária
bool rep2 = false;               // Repetição secundária
int counterOpe = 0;              // Contador de operadores
int counterNum = 1;              // Contador de números
double res;                      // Resultado final

// Funções
// Calculator: o input 'a' e 'b' são os números que serão calculados, o input 'c' é o operador que será usado para o cálculo (ex: '+', '-', '*', '/', '^', '[', ']', '|') e vai retornar o resultado do cálculo.
double calculator (double a, double b, char operation, float PiPrecision = 3.14);

int main() {
    // Loop para reinicialização do software.
    while (rep) {
        cout << "------------------" << " = Calculator (Mem: 64 numbers) = " << "------------------" << endl;

        // Parte dedicada a resetar as memórias alocadas.
        for (int i = 0; i <= counterNum; i++) {
            num[i] = 0;
        }
        for (int i = 0; i <= counterOpe; i++) {
            ope[i] = 0;
        }

        // Parte inicial com interação do usuário: vai ocorrer obrigatoriamente.
        cout << "Insira um numero: ";
        cin >> num[0];
        cout << "Insira a operacao (+, -, *, /, %, ^, [, ], |, c): ";
        cin >> ope[0];
        if (ope[counterOpe] != '+' && ope[counterOpe] != '-' && ope[counterOpe] != '*' && ope[counterOpe] != '/' && ope[counterOpe] != '^' && ope[counterOpe] != '|' && ope[counterOpe] != '[' && ope[counterOpe] != ']' && ope[counterOpe] != 'c') {
            cout << "Erro: valor digitado nao corresponde a umas das operacoes";
            return 0;
        }
        cout << "Insira um outro numero: ";
        cin >> num[1];
        res = calculator (num[0], num[1], ope[0]);

        // Loop dedicado a verificação e a adicionar mais operações
        do{
            cout << "Deseja calcular mais uma operacao? (1 - Sim / 0 - Nao): ";
            cin >> rep2;

            // Parte com interação do usuário: vai ocorrer facultativamente dependendo do valor de 'rep2'.
            if (rep2) {
                counterOpe++;
                counterNum++;
                cout << "Insira uma outra operacao (+, -, *, /, %, ^, [, ], |, c): ";
                cin >> ope[counterOpe];
                if (ope[counterOpe] != '+' && ope[counterOpe] != '-' && ope[counterOpe] != '*' && ope[counterOpe] != '/' && ope[counterOpe] != '^' && ope[counterOpe] != '|' && ope[counterOpe] != '[' && ope[counterOpe] != ']' && ope[counterOpe] != 'c') {
                    cout << "Erro: valor digitado nao corresponde a umas das operacoes";
                    return 0;
                }
                cout << "Insira um numero: ";
                cin >> num[counterNum];
                res = calculator (res, num[counterNum], ope[counterOpe]);
            }
        } while (rep2);

        // Parte final do sistema dedicado a apresentar as operações em ordem de execução e os resultados das operações.
        if (!rep2) {
            cout << "\n----------------------------------------------------------------------\n" << "Equacao em ordem de execucao: ";
            for (int i = 0; i <= counterNum; i++) {
                cout << num[i] << " ";
                if (i <= counterOpe) {
                    cout << ope[i] << " ";
                }
            }
            cout << "\nResultado final: " << res << "\n----------------------------------------------------------------------\n\n";

            // Parte dedicada a analisar se vai ser reinicializado o software.
            cout << "Deseja reiniciar a calculadora? (1 - Sim / 0 - Nao): ";
            cin >> rep;
            system ("cls");
            system ("pause");
            system ("cls");
        }
    }
    return 0;
}

double calculator (double a, double b, char operation, float PiPrecision) {
    double resul;
    double pot;

    switch (operation) {
        case '+':
            resul = a + b;
            break;

        case '-':
            resul = a - b;
            break;

        case '*':
            resul = a * b;
            break;

        case '/':
            resul = a / b;
            break;

        case '^':
            pot = 1;
            for (int i = 1; i <= b; i++) {
                pot = pot * a;
            }
            resul = pot;
            break;

        case '[':
            if (a < 0) {
                a = a * -1;
            }
            if (b < 0) {
                b = b * -1;
            }
            resul = a + b;

        case ']':
            if (a < 0) {
                a = a * -1;
            }
            if (b < 0) {
                b = b * -1;
            }
            resul = a - b;

        case '|':
            if (a < 0) {
                a = a * -1;
            }
            if (b < 0) {
                b = b * -1;
            }
            resul = a * b;

        case 'c':
            resul = PiPrecision * (a * b);
            break;

        default:
            resul = a;
            break;
    }
    cout << "Resultado atual: " << resul << endl;
    return resul;
}
