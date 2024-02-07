#include <stdio.h> // Biblioteca para entrada/sa�da padr�o
#include <stdlib.h> // Biblioteca para fun��es de aloca��o de mem�ria
#include <locale.h> // Biblioteca para configura��o de localidade
#include <string.h> // Biblioteca para manipula��o de strings

int main() {
    // Vari�veis de controle
    int opcao = 0; // Op��o do menu
    int x = 1; // Vari�vel de controle do loop

    for (x = 1; x = 1;) { // Loop principal

        system("cls"); // Limpa a tela

        setlocale(LC_ALL, "portuguese"); // Configura a localidade para portugu�s

        // Exibe o menu
        printf("\t---  Cart�rio da EBAC  ---\n\n");
        printf(" Escolha a op��o desejada abaixo: \n\n");
        printf("\t1 - Novo registro \n");
        printf("\t2 - Consultar registro \n");
        printf("\t3 - Deletar registro \n\n");
        printf("\t4 - Sair do sistema \n\n");
        printf("Op��o: ");
        
        scanf("%d", &opcao); // Recebe a op��o do usu�rio

        system("cls"); // Limpa a tela

        switch (opcao) {  // Conduz o usu�rio � op��o escolhida 
            
            case 1:
                Registro(); // Op��o 1 direciona para a fun��o Registro
                break;
                
            case 2:
                Consultar(); // Op��o 2 direciona para a fun��o Consultar
                break;
                
            case 3:
                Deletar(); // Op��o 3 direciona para a fun��o Deletar
                break;
                
            case 4: // Op��o 4 fecha o programa
            	printf("Obrigado por utilizar o sistema");
				return 0;
                break;                   
				    
            default:
                printf("Essa op��o � inv�lida \n"); // Qualquer outra op��o indica erro
                system("pause");
                break;                        
        }            
    }
}

// Fun��o para realizar o registro de informa��es
int Registro(){
    setlocale(LC_ALL, "portuguese");

    // Vari�veis para armazenar informa��es
    char arquivo[40]; // Nome do arquivo    
    char cpf[40]; // CPF    
    char nome[40]; // Nome    
    char sobrenome[40]; // Sobrenome    
    char cargo[40]; // Cargo
    
    // Solicita e armazena o CPF
    printf ("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);

    // Copia o CPF para o nome do arquivo
    strcpy(arquivo, cpf);

    FILE *file;
    // Abre o arquivo para escrita e adiciona "CPF: "
    file = fopen(arquivo,"w");
    fprintf(file,"CPF: ");
    fclose(file);

    // Abre o arquivo para adicionar o CPF
    file = fopen(arquivo,"a");
    fprintf(file,cpf);
    fclose(file);

    // Abre o arquivo para adicionar ", "
    file = fopen(arquivo,"a");
    fprintf(file,", ");
    fclose(file);

    // Solicita e armazena o nome
    printf ("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    // Abre o arquivo para adicionar "Nome: "
    file = fopen(arquivo,"a");
    fprintf(file,"Nome: ");
    fclose(file);

    // Abre o arquivo para adicionar o nome
    file = fopen(arquivo,"a");
    fprintf(file,nome);
    fclose(file);

    // Abre o arquivo para adicionar ", "
    file = fopen(arquivo,"a");
    fprintf(file,", ");
    fclose(file);

    // Solicita e armazena o sobrenome
    printf ("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    // Abre o arquivo para adicionar "Sobrenome: "
    file = fopen(arquivo,"a");
    fprintf(file,"Sobrenome: ");
    fclose(file);

    // Abre o arquivo para adicionar o sobrenome
    file = fopen(arquivo,"a");
    fprintf(file,sobrenome);
    fclose(file);

    // Abre o arquivo para adicionar ", "
    file = fopen(arquivo,"a");
    fprintf(file,", ");
    fclose(file);

    // Solicita e armazena o cargo
    printf ("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    // Abre o arquivo para adicionar "Cargo: "
    file = fopen(arquivo,"a");
    fprintf(file,"Cargo: ");
    fclose(file);

    // Abre o arquivo para adicionar o cargo
    file = fopen(arquivo,"a");
    fprintf(file,cargo);
    fclose(file);

    system("pause");                
}

// Fun��o para consultar informa��es
int Consultar(){
    setlocale(LC_ALL, "portuguese");

    // Vari�veis para armazenar informa��es
    char cpf[40];
    char conteudo[200];

    // Solicita e armazena o CPF a ser consultado
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);

    FILE *file;
    // Abre o arquivo para leitura
    file = fopen(cpf,"r");

    if(file == NULL){
        printf("\n Arquivo inexistente. \n");
        system("pause");
    }

    // L� e exibe o conte�do do arquivo
    while(fgets(conteudo, 200, file) != NULL){
        printf("\n Essas s�o as informa��es do usu�rio: ");
        printf("%s",conteudo);
        printf("\n\n");

        fclose(file);
        system("pause");
    }
}

// Fun��o para deletar informa��es
int Deletar(){
    // Vari�veis para armazenar informa��es
    char cpf[40];
    char conteudo[200];
    int opcao = 0;
    int x=0;

    setlocale(LC_ALL, "portuguese");

    for(x=1;x=1;){
        system("cls");

        // Solicita e armazena o CPF a ser deletado
        printf("Digite o CPF a ser deletado: ");
        scanf("%s",cpf);

        FILE *file;
        // Abre o arquivo para leitura
        file = fopen(cpf,"r");

        if(file == NULL){
            printf("\n Arquivo inexistente. \n");
            system("pause");
            main();
        }

        // L� e exibe o conte�do do arquivo
        while(fgets(conteudo, 200, file) != NULL){
            printf("\n Essas s�o as informa��es do usu�rio: ");
            printf("%s",conteudo);
            printf("\n\n");

            fclose(file);
        }

        // Confirma��o do usu�rio para deletar
        printf("Confirme se este � o usu�rio a ser deletado \n");
        printf("\t1 - Sim \n");
        printf("\t2 - N�o \n");
        scanf("%d", &opcao);

        switch (opcao) {  // Conduz o usu�rio � op��o
			case 1:	
				
				remove(cpf);
				printf("Arquivo removido\n");
				system("pause");
				main();
				
				break;	
						
			case 2:
				break;	
							
			default:
				
				printf("\n Essa op��o � inv�lida \n");
				system("pause");
				break;						
		}
		fclose(file);
	}		
		
}


