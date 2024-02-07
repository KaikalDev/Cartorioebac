#include <stdio.h> // Biblioteca para entrada/saída padrão
#include <stdlib.h> // Biblioteca para funções de alocação de memória
#include <locale.h> // Biblioteca para configuração de localidade
#include <string.h> // Biblioteca para manipulação de strings

int main() {
    // Variáveis de controle
    int opcao = 0; // Opção do menu
    int x = 1; // Variável de controle do loop

    for (x = 1; x = 1;) { // Loop principal

        system("cls"); // Limpa a tela

        setlocale(LC_ALL, "portuguese"); // Configura a localidade para português

        // Exibe o menu
        printf("\t---  Cartório da EBAC  ---\n\n");
        printf(" Escolha a opção desejada abaixo: \n\n");
        printf("\t1 - Novo registro \n");
        printf("\t2 - Consultar registro \n");
        printf("\t3 - Deletar registro \n\n");
        printf("\t4 - Sair do sistema \n\n");
        printf("Opção: ");
        
        scanf("%d", &opcao); // Recebe a opção do usuário

        system("cls"); // Limpa a tela

        switch (opcao) {  // Conduz o usuário à opção escolhida 
            
            case 1:
                Registro(); // Opção 1 direciona para a função Registro
                break;
                
            case 2:
                Consultar(); // Opção 2 direciona para a função Consultar
                break;
                
            case 3:
                Deletar(); // Opção 3 direciona para a função Deletar
                break;
                
            case 4: // Opção 4 fecha o programa
            	printf("Obrigado por utilizar o sistema");
				return 0;
                break;                   
				    
            default:
                printf("Essa opção é inválida \n"); // Qualquer outra opção indica erro
                system("pause");
                break;                        
        }            
    }
}

// Função para realizar o registro de informações
int Registro(){
    setlocale(LC_ALL, "portuguese");

    // Variáveis para armazenar informações
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

// Função para consultar informações
int Consultar(){
    setlocale(LC_ALL, "portuguese");

    // Variáveis para armazenar informações
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

    // Lê e exibe o conteúdo do arquivo
    while(fgets(conteudo, 200, file) != NULL){
        printf("\n Essas são as informações do usuário: ");
        printf("%s",conteudo);
        printf("\n\n");

        fclose(file);
        system("pause");
    }
}

// Função para deletar informações
int Deletar(){
    // Variáveis para armazenar informações
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

        // Lê e exibe o conteúdo do arquivo
        while(fgets(conteudo, 200, file) != NULL){
            printf("\n Essas são as informações do usuário: ");
            printf("%s",conteudo);
            printf("\n\n");

            fclose(file);
        }

        // Confirmação do usuário para deletar
        printf("Confirme se este é o usuário a ser deletado \n");
        printf("\t1 - Sim \n");
        printf("\t2 - Não \n");
        scanf("%d", &opcao);

        switch (opcao) {  // Conduz o usuário à opção
			case 1:	
				
				remove(cpf);
				printf("Arquivo removido\n");
				system("pause");
				main();
				
				break;	
						
			case 2:
				break;	
							
			default:
				
				printf("\n Essa opção é inválida \n");
				system("pause");
				break;						
		}
		fclose(file);
	}		
		
}


