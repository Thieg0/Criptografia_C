#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int mdc_estendido(int a, int b, int *x, int *y) 
{
    if (b == 0) 
    {
        *x = 1;
        *y = 0;
        return a;
    }
    
    int x1, y1;
    int mdc = mdc_estendido(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
    
    return mdc;
}

int encontrar_chave_privada(int p, int q, int e) 
{
    int n = p * q;
    int phi_n = (p - 1) * (q - 1);
    
    int d, x, y;
    mdc_estendido(e, phi_n, &x, &y);
    d = x < 0 ? x + phi_n : x;
    
    return d;
}

int contarCaracteres(char mensagem[]) 
{
   int contador = 0;
   for(int i = 0; mensagem[i] != '\0'; i++) 
   {
      contador++;
   }
   return contador;
}
int main() 
{
    //Declaração das variáveis.

    int x, p, q, e, m, n, i, a, b, resultado, letra_cifrada, letra, mensagem;
    int primo = 1;
    FILE *file;

    //Solicitar ao usuário que escolha uma opção (receber uma entrada/imput).

 do {
    printf("\nEscolha uma das opções abaixo:\n");
    printf("1 - Gerar chave pública.\n");
    printf("2 - Encriptar.\n");
    printf("3 - Desencriptar.\n");
    printf("4 - Sair.\n\n");  

    //Analisar a opção (entrada) escolhida pelo usuário e realizar a devida ação.

    scanf("%d", &x);

if (x != 1 && x != 2 && x != 3 && x != 4)
    {
        printf("Opção inexistente. Reiniciando o programa...\n\n");
    }
    else if (x == 4)
    {
        printf("Você escolheu a opção 4 - Sair.\n");
        printf("Até logo!\n\n");
        exit;
    }
    } while (x != 1 && x != 2 && x != 3 && x != 4);

    //OPÇÃO 1 - GERAR CHAVE PÚBLICA:

    if (x == 1)
    {
        printf("\nDigite dois números primos (p, q) e um expoente (e) que seja primo em relação a (p - 1) * (q - 1):\n");
        
        scanf("%d %d %d", &p, &q, &e);

     //VERIFICAÇÕES:

     //1) Verificar se o primeiro número fornecido pelo usuário é primo ou não.

     //1.1) Verificar se o número é menor ou igual a 1.
    
        if (p <= 1)
        {
            primo = 0;
            printf("%d não é um número primo.\n", p);
            printf("Execução interrompida.\n");
            exit(0);
        }
        else
        {
     //1.2) Verificar se o número é divisível por algum número de 2 até sua raiz quadrada.
        for (i = 2; i * i <= p; i++) 
            {
                if (p % i == 0) 
                {
                    primo = 0;
                    printf("%d não é um número primo.\n", p);
                    printf("Execução interrompida.\n");
                    break;
                    exit(0);
                }
                else if (p % i != 0)
                {
                }
            }
        }
        if (primo == 1) 
        {
        }
        else if (primo == 0)
        {
            exit(0);
        }
    

     //2) Verificar se o segundo número fornecido pelo usuário é primo ou não.

     //2.1) Verificar se o número é menor ou igual a 1.
    
        if (q <= 1)
        {
            primo = 0;
            printf("%d não é um número primo.\n", q);
            printf("Execução interrompida.\n");
            exit(0);
        }
        else 
        {
     //2.2) Verificar se o número é divisível por algum número de 2 até sua raiz quadrada.
        for (i = 2; i * i <= q; i++) 
            {
                if (q % i == 0) 
                {
                    primo = 0;
                    printf("%d não é um número primo.\n", q);
                    printf("Execução interrompida.\n");
                    break;
                    exit(0);
                }
                else if(q % i != 0)
                {
                }
            }
        }
        if (primo == 1) 
        {
        }
        else if (primo == 0)
        {
            exit(0);
        }
    

     //3) Verificar se o expoente "e" é primo ou não.

     //3.1) Verificar se o número é menor ou igual a 1.
    
        if (e <= 1)
        {
            primo = 0;
            printf("%d não é um número primo.\n", e);
            printf("Execução interrompida.\n");
            exit(0);
        }
        else 
        {
     //3.2) Verificar se o número é divisível por algum número de 2 até sua raiz quadrada.
        for (i = 2; i * i <= e; i++) 
            {
                if (e % i == 0) 
                {
                    primo = 0;
                    printf("%d não é um número primo.\n", e);
                    printf("Execução interrompida.\n");
                    break;
                    exit(0);
                }
                else if(e % i != 0)
                {
                }
            }
        }
        if (primo == 1) 
        {
        }
        else if (primo == 0)
        {
            exit(0);
        } 
    

     //4) Verificar se o expoente "e" fornecido pelo usuário é primo em relação a "(p - 1) * (q - 1)" utilizando o Algoritmo de Euclides.
    
        int mdc(int a, int b) 
        {
            int r = a % b;
            while (r != 0) 
            {
                a = b;
                b = r;
                r = a % b;
            }
            return b;
        }
        int euclides() 
        {
            int resultado = mdc(e, (p - 1) * (q - 1));

            if (resultado == 1) 
            {
            }
            else if (resultado != 1)
            {
                printf("%d não é primo em relação a (p - 1) * (q - 1).\n", e);
                printf("Execução interrompida.\n");
            }

            exit(0);
        }
    
     //Criação do arquivo .txt contendo a chave publica gerada.
     //Observação 1: se os dois primeiros números ("p" e "q") fornecidos pelo usuário forem primos e o terceiro número ("e") for 
     //              primo em relação a (p - 1) * (q - 1), o arquivo .txt é criado.
     //Observação 2: se um dos dois primeiros números ("p" e "q") fornecidos pelo usuário não for primo ou o terceiro número ("e") 
     //              não seja primo em relação a (p - 1) * (q - 1), a execução do programa é interrompida.
    
        if ((primo == 1)) 
        {
            int n = p * q;
            file = fopen("chave_pública.txt", "w");
            fprintf(file,"%d %d", n, e);
            fclose(file);

            printf("\n"); 
            printf("A chave pública é: %d %d\n\n", n, e);
            printf("n = %d , e = %d\n\n", n, e);
        }
        else
        {
            printf("Error.\n");
        }
        return main();
    }

    //OPÇÃO 2 - ENCRIPTAR:
    else if(x==2)
    {
        char mensagem[1000];
        int c;

        printf("\n");
        printf("Você escolheu a opção 2 - Encriptar.");
        printf("\n");
        printf("\n"); 
        printf("Digite a mensagem que deseja encriptar: ");
        printf("\n");
        while ((c = getchar()) != '\n' && c != EOF); // limpa o buffer de entrada.
        fgets(mensagem, sizeof(mensagem), stdin);
        mensagem[strcspn(mensagem, "\n")] = 0; // remove o caracter de nova linha.
        
        int tamanho = contarCaracteres(mensagem);
        int p, q, e;
        printf("\n");
        printf("Digite os números primos (p, q): ");
        printf("\n");
        scanf("%d %d", &p, &q);
        printf("\n");
        printf("Digite a chave pública (n, e): ");
        printf("\n");
        int n;
        scanf("%d %d", &n, &e);
        printf("\n");
        getchar(); // consome o caractere de quebra de linha deixado pelo scanf.
        printf("A mensagem digitada possui %d caracter(es).\n", tamanho);
        printf("\n");

        printf("Segue a mensagem encriptada:\n");   
        
        file = fopen("mensagem_e.txt", "w"); //cria o arquivo de texto.

        int i = 0;
        while (mensagem[i] != '\0') 
        {
            int letra;
            if (mensagem[i] == ' ') 
            {
                letra = 28;
            } 
            else 
            {
                letra = mensagem[i] - 'A' + 2;
            }
            
            int letra_cifrada = 1;
            for (int j = 0; j < e; j++) 
            {
                letra_cifrada = (letra_cifrada * letra) % n;
            }
            printf("%d  ", letra_cifrada);
            fprintf(file, "%d ", letra_cifrada); // escreve a letra cifrada no arquivo
            i++;
        }

        fclose(file); //fecha o arquivo.

        printf("\n");
        printf("\n");
        return main();
    }

    //OPÇÃO 3 - DESENCRIPTAR:
else if(x==3)
{
    int tamanho, d,r;
    printf("\n");
    printf("Você escolheu a opção 3 - Desencriptar.");
    printf("\n");
    printf("Digite os números primos (p, q) e o expoente e (e): ");
    printf("\n");
    scanf("%d %d %d", &p, &q, &e);
    printf("\n");
    d = encontrar_chave_privada(p, q, e);
    printf("Digite o tamanho da mensagem: ");
    printf("\n");
    scanf("%d", &tamanho);
        
    int mensagem_cifrada[tamanho];
    printf("\n");
    printf("Digite a mensagem que deseja desencriptar: ");
    printf("\n");
    for (int i = 0; i < tamanho; i++) 
    {
        scanf("%d", &mensagem_cifrada[i]);
    }
    int n= p*q;
    printf("\n");

    printf("Segue a mensagem desencriptada: ");
    printf("\n");

    int mensagem_desencriptada[tamanho];
      
    for (int i = 0; i < tamanho; i++) 
    {
        int letra_cifrada = mensagem_cifrada[i];
        int letra = 1;
        for (int j = 0; j < d; j++) 
        {
            letra = (letra * letra_cifrada) % n;
        }
        if (letra == 28) 
        {
            mensagem_desencriptada[i] = ' ';
        } 
        else 
        {
            mensagem_desencriptada[i] = letra + 'A' - 2;
        }
    }

    //Criação do arquivo .txt contendo a mensagem descriptografada.
    file = fopen("mensagem_d.txt", "w");
    for (int i = 0; i < tamanho; i++)
    {
        fprintf(file, "%c", mensagem_desencriptada[i]);
    }
    fclose(file);

    for (int i = 0; i < tamanho; i++)
    {
        printf("%c", mensagem_desencriptada[i]);
    }
    printf("\n");
    printf("\n");

    return 0;
}
}
