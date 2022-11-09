/*
Atividade Supervisoda da APS2 - Unicarioca [955 - PROGRAMAÇÃO ESTRUTURADA 2022/1]
Exercicio - Sistema de Cadastro de Aluno
Professor: Andre Cotelli Do Espirito Santo


*/

// Declaração de Biblioteca utilizadas para a compilação do programa.

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <locale.h>
#define MAX 50

using namespace std;

//Estrutura de Registros de dados e Tabela Geral.

typedef struct{ 

	char nome[50], sexo[10];
	float notas[3], media;
	int idade, matricula, ativo;

}registro; // Nome do registro e abaixo tem o limite do registro contido na tabela esta informação do limite está no campo da biblioteca.

registro alunos[MAX];

//  Declaração de váriaveis Globais.

int total = 0; char arq_name[15];

/* 

Declaração de Funções e abaixo segue as explicações de cada opção principal. 

void main_menu();//menu principal
void cadastros();//função cadastrar
void buscar();//Pesquisa de alunos pela matrícula
void listagem_menu();//sub menu de listagem
void todos_alunos();//listagem de todos os alunos
void media();//função para calcular a média
void lista_apr();//listagem de todos os alunos aprovados
void lista_rep();//listagem de todos os alunos reprovados
void apr_7();//listagem de todos os alunos aprovados com média 7 e 8
void apr_9();//listagem de todos os alunos aprovados com média 9 e 10
void rep_7();//listagem de todos os alunos reprovados com média inferior a 7
void rep_5();//listagem de todos os alunos reprovados com média inferior a 5
void menu_arq();//Sub menu para manipulação de arquivos externos
void save_arq();//salvar arquivos externos
void upload_arq();//carregar arquivo externo;


*/

void main_menu();
void cadastros();
void buscar();
void listagem_menu();
void todos_alunos();
void media();
void lista_apr();
void lista_rep();
void apr_7();
void apr_9();
void rep_7();
void rep_5();
void menu_arq();
void save_arq();
void upload_arq();


main(){ //Parte Principal e execução do programa e adicionamos uma modificação para caracteres usados na língua portuguesa
	
	setlocale(LC_ALL, "Portuguese");
		
	main_menu();
		
	return 0;
}

void main_menu(){  // Estrutura de Menu Principal (Aonde possui todos os Menu do Sistema. A variavel "op" é usada para chamada dos Menus.

int op;
	
	do{
		system("cls");
		
		cout<<"Sistema de cadastro de alunos"<<endl;
	
	cout<<"-----------------------------"<<endl;
		
		cout<<endl<<"1 - Cadastrar Aluno"<<endl;
		cout<<"2 - Buscar Aluno"<<endl;
		cout<<"3 - Listagem de Alunos"<<endl;
		cout<<"4 - Salvar/Carregar registros"<<endl;
		
		cout<<"0 - Encerrar o Programa"<<endl<<endl;
		cout<<"Comando: "; cin>>op;
		getchar();
		
		switch(op){
			case 1:
				cadastros();
			break;
				
			case 2:
				buscar();
			break;
			
			case 3:
				listagem_menu();
			break;
		
			case 4:
				menu_arq();
			break;
			
			case 0:
				exit(0);
			break;
			
			default:
			cout<<endl<<"Error! Comando inválido!"<<endl;
			system("pause");
			main_menu();
			break;
		}
		
			getchar();
		
	}while(op!=0);

}

void cadastros(){  // Estrutura de Menu Cadastro - Aonde possui as opções para efetuação de cadastro. As variavies da função e na estrutura de repetição permite salvar os dados.
	
	system("cls");

// Declaração Variaives Locais da função cadastro.

	char nome[50], sexo[10];
	float notas[3], media;
    int matricula, idade, ativo, op;

// Estrutura do cadastro - Solicita os dados e armazena nas váriavies Locais. Na opção do "for" executa a repetição de dados até concluir o MAX da função.

	do{
		cout<<endl<<"CADASTRO DO ALUNO"<<endl;
		cout<<"------------------"<<endl;
		cout<<endl<<"Digite o nome: ";gets(nome); 
		cout<<endl<<"Digite a matrícula: ";cin>>matricula;
		cout<<endl<<"Digite a idade: ";cin>>idade;
		cout<<endl<<"Digite o sexo: ";cin>>sexo;
		cout<<endl<<"Digite a nota de AV1: ";cin>>notas[0];
		cout<<endl<<"Digite a nota de AV2: ";cin>>notas[1];
		cout<<endl<<"Digite a nota de AV3: ";cin>>notas[2];
		
		for(int i=0;i<MAX; i++){
			if(alunos[i].ativo==0){
				alunos[i].notas[0] = notas[0];
				alunos[i].notas[1] = notas[1];
				alunos[i].notas[2] = notas[2];
				alunos[i].matricula = matricula;
				alunos[i].idade = idade;
				strcpy(alunos[i].nome, nome);
				strcpy(alunos[i].sexo, sexo);
				alunos[i].ativo=1;
				total ++;
				break;
			}
		}
		cout<<endl<<"Parabéns! Aluno cadastrado com sucesso!"<<endl;
		cout<<endl<<"1 - Novo cadastro"<<endl;
		cout<<"0 - Menu Principal"<<endl; 
		cout<<endl<<"Comando: ";cin>>op;
		getchar();

//	Estrutura de Menu dentro da Opção Cadastro.

		switch(op){
			case 0:
				main_menu();
			break;
			
			case 1:
				cadastros();
			break;
			
			default:
			cout<<endl<<"Error! Comando inválido!"<<endl;
			system("pause");
			main_menu();
			break;
		}
	}while(op!=0 && total<MAX);
getchar();

}

void menu_arq(){   //Estrutura de Menu de Arquivos - Aonde possui as opções para carregar e salvar arquivos externos.
	int op;
	
	system("cls");
	
	cout<<endl<<"SALVAR/CARREGAR UM ARQUIVO EXTERNO"<<endl;
	cout<<"---------------------------------------"<<endl;
	cout<<"Lembre-se de salvar ao fim da execução"<<endl; 
	cout<<"---------------------------------------"<<endl;
	
	cout<<endl<<"1 - Salvar arquivo"<<endl;
	cout<<"2 - Carregar arquivo"<<endl;
	cout<<"0 - Menu principal"<<endl;
	cout<<endl<<"Comando: ";	cin>>op;
	getchar();
	
	//Estrutura de Menu dentro da Opção Arquivo.
	
	switch(op){
		
		case 1:
			save_arq();
		break;
		
		case 2:
			upload_arq();
		break;
		
		case 0:
			main_menu();
		break;
		
		default:
			cout<<endl<<"Error! Comando inválido!"<<endl;
			system("pause");
			main_menu();
        break;
	}	
	

}

void save_arq(){  //Estrutura de Menu de Arquivos da Opção Salvar Arquivo Externo - Permite Salvar o arquivo para ser aberto em outras aplicações.

// Declaração de Variaives Locais da função Salvar Arquivos

	media();
	
	FILE* arq;

// Operação da  função Salvar Arquivos - Aonde precisa ser digitado a extensão para o arquivo ser salvo.
	
	cout<<endl<<"Digite um nome para o arquivo: "; cin>>arq_name; strcat(arq_name,".txt");
	if((arq=fopen(arq_name,"w"))==NULL){
		cout<<endl<<"não foi possível abrir o arquivo"<<endl;
	}else{
	
	fprintf (arq,"Total= %d\n",total);
	
	// Estrutura de Salvar Arquivo - Permite salvar os dados do sistema de forma externa. Na opção do "for" executa o armazenamento dos dados salvo no sistema para ser usado de forma externa.
	
	for(int i=0;i<total;i++){
		
		fprintf (arq, "\nNome= %s",alunos[i].nome);
		fprintf (arq, "\nMatricula= %d",alunos[i].matricula);		
		fprintf (arq, "\nSexo= %s",alunos[i].sexo);
		fprintf (arq, "\nIdade= %d",alunos[i].idade);
		fprintf (arq, "\nAV1= %.1f",alunos[i].notas[0]);
		fprintf (arq, "\nAV2= %.1f",alunos[i].notas[1]);
		fprintf (arq, "\nAV3= %.1f",alunos[i].notas[2]);
		fprintf (arq, "\nMédia= %.1f",alunos[i].media);
	}
	cout<<endl<<"Arquivo criado com sucesso!"<<endl; fclose(arq);
	cout<<"Você será redirecionado ao menu principal"<<endl;
    cout<<" "<<endl;
    system("pause");
	
}
}

void upload_arq(){  // Estrutura de Menu de Arquivos da Opção Carregar Arquivo Externo - Permite carregar o arquivo externo.

// Declaração de Variaives Locais da função Carregar Arquivos
	
FILE *arq;

// Operação da  função carregar  Arquivos - Aonde precisa ser digitado a extensão para o arquivo ser carregado.
   
	cout<<endl<<"-----------------------------------------------------------------------"<<endl;
	cout<<"O arquivo que será carregado deve estar no mesmo diretório do sistema"<<endl; 
	cout<<"-----------------------------------------------------------------------"<<endl;
	cout<<"Lembre-se de adicionar a extensão '.txt' junto do nome do programa"<<endl; 
	cout<<"-----------------------------------------------------------------------"<<endl;
   
   cout<<endl<<"Digite o nome do arquivo: "; cin>>arq_name;
   arq = fopen(arq_name,"r");
   if (arq == NULL){
   	cout<<endl<<"não foi possível carregar o arquivo"<<endl;
   }else{
   	    fseek (arq,7,0);
		fscanf (arq, "%d\n", &total);
	
	// Estrutura de Carregar Arquivo - Permite carregar os dados do sistema de forma externa. Na opção do "for" executa o carregamento dos dados externos no sistema.
		
	for(int i=0;i<total;i++){
		fseek(arq,6,1); fscanf(arq,"%s\n",alunos[i].nome);
		fseek(arq,11,1); fscanf(arq,"%d\n",&alunos[i].matricula);
		fseek(arq,6,1); fscanf(arq,"%s\n",alunos[i].sexo);
		fseek(arq,7,1); fscanf(arq,"%d\n",&alunos[i].idade);
		fseek(arq,5,1); fscanf(arq,"%f\n",&alunos[i].notas[0]);
		fseek(arq,5,1); fscanf(arq,"%f\n",&alunos[i].notas[1]);
		fseek(arq,5,1); fscanf(arq,"%f\n",&alunos[i].notas[2]);
		fseek(arq,7,1); fscanf(arq,"%f\n",&alunos[i].media);
	}
   
}

fclose(arq);
    
	cout<<endl<<"Arquivo carregado com sucesso!"<<endl;
	cout<<endl<<"Você será redirecionado ao menu principal"<<endl;
    cout<<" "<<endl;
    	system("pause");
	
}

void buscar(){  //Estrutura de Menu Buscar - Aonde possui as opções para efetuação de cadastro. As variavies da função e na estrutura de repetição permite salvar os dados.

// Declaração de Variaives Locais da função Buscar.

	int matricula, op, local, op1, op2, op_;
	bool coteli=false;
	media();
	
	system ("cls");
	
	cout<<endl<<"********************PESQUISAR ALUNO**************************"<<endl;
	cout<<"------------------------------------------------------------"<<endl;
	cout<<"A busca deve ser feito pelo número de matrícula do aluno."<<endl; 
	cout<<"------------------------------------------------------------"<<endl;

cout<<endl<<"Digite a matricula: "; cin>>matricula;

if(total==0){
  cout<<endl<<"Sistema vazio"<<endl;
  
  cout<<endl<<"Gostaria de cadastrar um novo aluno?"<<endl;
  cout<<endl<<"1 - Cadastrar novo aluno"<<endl;
  cout<<"0 - Menu Principal"<<endl;
  
  cout<<endl<<"Comando: "; cin>>op_;
  
  // Estrutura de subMenu dentro da Opção Buscar.
  
  switch(op_){ 
  	case 1:
  		cadastros();
  	break;
  	
  	case 0:
  		main_menu();
  	break;
  	
}
    
  /*
  Estrutura do Buscar  -  Realiza a busca de dados a parti de informações digitada pelo usuário.
  No Laço "FOR1", ele realiza a busca através da matricula e determina se está ativo ou não a matricula.
  No Laço "FOR2", ele realiza a busca a parti de uma matricula ativa e exibe os dados na tela. No final da exibição apresenta uma opção de pesquisa.
  Para matriculas não localizada criamos a opção de cadastrar diretamente.
  E retornar para o Menu Principal da opção Buscar.
  */ 
  
  
}else{


for(int i=0;i<MAX;i++){
	if(matricula==alunos[i].matricula){
		local=i;
		coteli=true;
	}
}

for(int i=0;i<MAX;i++){
	if (coteli == true && matricula==alunos[i].matricula) {
		
cout<<endl<<"-------------------------------"<<endl;
			cout<<"Nome: "<<alunos[i].nome<<endl;
			cout<<"Sexo: "<<alunos[i].sexo<<endl;
			cout<<"Idade: "<<alunos[i].idade<<endl;
			cout<<"AV1: "<<alunos[i].notas[0]<<endl;
			cout<<"AV2: "<<alunos[i].notas[1]<<endl;
			cout<<"AV3: "<<alunos[i].notas[2]<<endl;
			cout<<"Média: "<<alunos[i].media<<endl;
cout<<endl<<"-------------------------------"<<endl;
   
   cout<<"1 - Nova pesquisa"<<endl;
	cout<<"0 - Menu Principal"<<endl;
	cout<<endl<<"Comando: ";	cin>>op;
	getchar();
	
	// Estrutura de SubMenu dentro da Opção Buscar.
	
	switch(op){
		
		case 1:
			buscar();
		break;
		
		case 0:
			main_menu();
		break;
		
		default:
			cout<<endl<<"Error! Comando inválido!"<<endl;
			system("pause");
			main_menu();
        break;
}	

} else if (coteli==false){
	cout<<endl<<"Aluno Não encontrado"<<endl;

	cout<<endl<<"Gostaria de cadastra-lo?"<<endl;
			cout<<endl<<"1 - Sim"<<endl;
			cout<<"0 - Não"<<endl;
			
			cout<<endl<<"Comando: "; cin>>op1;
			getchar();
			switch(op1){
				case 1:
					cadastros();
				break;
				
				case 0:
					cout<<endl<<"Gostaria de continuar pesquisando?"<<endl;
					cout<<endl<<"1 - Nova pesquisa"<<endl;
			        cout<<"0 - Retornar ao menu principal"<<endl;
			        cout<<endl<<"Comando: "; cin>>op2;
			        getchar();
			switch(op2){
				case 1:
					buscar();
			    break;
			    
			    case 0:
			    	main_menu();
			    break;
}
					
}

}
}
}
}

void media(){  //Estrutura de Menu Media - A lógica utilizada é do sistema de média da Unicarioca. 

// Declaração de Variaives Locais da função Média.

int op, ZERO;

/* 
Estrututa de Media - O FOR realiza a operação de dados das notas do alunos com base no sistema de notas da Unicarioca.

Para o calculo de notas deve ser considerado as variaveis abaixos.

cout<<"AV1: "<<alunos[i].notas[0]<<endl;
cout<<"AV2: "<<alunos[i].notas[1]<<endl;
cout<<"AV3: "<<alunos[i].notas[2]<<endl;

*/

	for(int i=0;i<MAX;i++){
		
		if (alunos[i].notas[0]<alunos[i].notas[2] && alunos[i].notas[1]>alunos[i].notas[0]) 
		{
		alunos[i].media = (alunos[i].notas[1]+alunos[i].notas[2])/2;
		}
		
		else if (alunos[i].notas[1]<alunos[i].notas[2] && alunos[i].notas[0]>alunos[i].notas[1])
		{
		alunos[i].media = (alunos[i].notas[0]+alunos[i].notas[2])/2;	
		}
	
		else if (alunos[i].notas[0]>alunos[i].notas[2] && alunos[i].notas[1]>alunos[i].notas[2])
		{
			alunos[i].media = (alunos[i].notas[0]+alunos[i].notas[1])/2;
		}
		
		else if (alunos[i].notas[0]==0 && alunos[i].notas[1]==0 && alunos[i].notas[2]==0)
		{
			alunos[i].media = 0;
		}
		else if(alunos[i].notas[0] == alunos[i].notas[1] && alunos[i].notas[0] == alunos[i].notas[2])
		{
			alunos[i].media = (alunos[i].notas[0]+alunos[i].notas[1])/2;
		}
		else if(alunos[i].notas[0] == alunos[i].notas[1] && alunos[i].notas[1] == alunos[i].notas[2])
		{
			alunos[i].media = (alunos[i].notas[1]+alunos[i].notas[2])/2;
		}
		else if(alunos[i].notas[1] == alunos[i].notas[2] && alunos[i].notas[1] == alunos[i].notas[0])
		{
			alunos[i].media = (alunos[i].notas[0]+alunos[i].notas[2])/2;
		}
		else if(alunos[i].notas[0] == alunos[i].notas[1] && alunos[i].notas[2]>alunos[i].notas[1] && alunos[i].notas[2]>alunos[i].notas[0])
		{
		 alunos[i].media = (alunos[i].notas[2]+alunos[i].notas[0])/2;
		}
	
	}
}

void listagem_menu(){ //Estrutura de Menu Listagem - Nessa estrutura permite listar as opções e situações do alunos, mediante as notas de provas.

//Declaração de Variaives Locais da função listagem
	
	int op;
	
	do{
		system("cls");
		cout<<endl<<"LISTAGEM DE ALUNOS CADASTRADOS"<<endl;
		cout<<"--------------------------------"<<endl;
	   	cout<<"1 - Todos os Alunos"<<endl;	
		cout<<"2 - Alunos Aprovados"<<endl;
		cout<<"3 - Alunos Reprovados"<<endl;
		cout<<"4 - Alunos reprovados com média inferior a 5"<<endl;
		cout<<"5 - Alunos reprovados com média inferior a 7"<<endl;
		cout<<"6 - Alunos aprovados com média superior ou igual a 7"<<endl;
		cout<<"7 - Alunos aprovados com média superior ou igual a 9"<<endl;
	
		cout<<"0 - Menu Principal"<<endl<<endl;
		cout<<"Comando: "; cin>>op;
		getchar();
		
//Estrutura de exibição de dados dentro da Opção Listagem. Apresenta os dados a parti da opoção escolhida anteriormente.

		switch(op){
			
			case 1:
			   todos_alunos();
			break;
			
			case 2:
				lista_apr();
			break;
			
			case 3:
				lista_rep();
			break;
			
			case 4:
		         rep_5();
		    break;
		    
		    case 5:
		    	rep_7();
		    break;
		    
		    case 6:
		    	apr_7();
		    break;
		    
		    case 7:
		    	apr_9();
		    break;
		    
			case 0:
				main_menu();
			break;
			
			default:
			cout<<endl<<"Error! Comando inválido"<<endl;
			system("pause");
			main_menu();
			break;
		}
	}while(op!=0);

}

void todos_alunos(){ //Estrutura de exibição de todos os alunos. Nessa estrutura permite exibir todos os dados. Desde que esteja cadastrado no sistema.

//Declaração de Variaives Locais da função listagem

int op;
	
	system("cls");
	media();
	
	cout<<endl<<"***********TODOS OS ALUNOS CADASTRADOS***********"<<endl;
		cout<<"-------------------------------"<<endl;
    cout<<"Total de alunos: "<<total<<endl;
    	cout<<"-------------------------------"<<endl;

	for(int i=0;i<MAX;i++){
		if(alunos[i].matricula!=0){
			cout<<"-------------------------------"<<endl;
			cout<<"Nome: "<<alunos[i].nome<<endl;
			cout<<"Matrícula: "<<alunos[i].matricula<<endl;
			cout<<"Sexo: "<<alunos[i].sexo<<endl;
			cout<<"Idade: "<<alunos[i].idade<<endl;
			cout<<"AV1: "<<alunos[i].notas[0]<<endl;
			cout<<"AV2: "<<alunos[i].notas[1]<<endl;
			cout<<"AV3: "<<alunos[i].notas[2]<<endl;
			cout<<"Média: "<<alunos[i].media<<endl;
			cout<<endl<<"-------------------------------"<<endl<<endl;
		}
	}
	
	cout<<endl<<"1 - Menu de listagem"<<endl;
	cout<<"0 - Menu principal"<<endl;
	cout<<endl<<"Comando: "; cin>>op; 
	
//Estrutura de SubMenu dentro da Opção Listagem
	
	switch(op){
		case 1:
			listagem_menu();
		break;
		
		case 0:
			main_menu();
		break;
		
		default:
			cout<<endl<<"Error! Comando inválido"<<endl;
			system("pause");
			main_menu();
		break;
	}
}

void lista_apr(){ //Estrutura de exibição dos alunos aprovados. Nessa estrutura permite exibir somente os alunos aprovados. Desde que esteja cadastrado no sistema.

int op;
	
	system("cls");
	media();
	
	cout<<endl<<"***********ALUNOS APROVADOS***********"<<endl;

	for(int i=0;i<MAX;i++){
		if(alunos[i].media>=7){
			cout<<"-------------------------------"<<endl;
			cout<<"Nome: "<<alunos[i].nome<<endl;
			cout<<"Matrícula: "<<alunos[i].matricula<<endl;
			cout<<"Sexo: "<<alunos[i].sexo<<endl;
			cout<<"Idade: "<<alunos[i].idade<<endl;
			cout<<"AV1: "<<alunos[i].notas[0]<<endl;
			cout<<"AV2: "<<alunos[i].notas[1]<<endl;
			cout<<"AV3: "<<alunos[i].notas[2]<<endl;
			cout<<"Média: "<<alunos[i].media<<endl;
			cout<<endl<<"-------------------------------"<<endl<<endl;
		}
	}
	
	cout<<endl<<"1 - Menu de listagem"<<endl;
	cout<<"0 - Menu principal"<<endl;
	cout<<endl<<"Comando: "; cin>>op; 
	
	//Estrutura de SubMenu dentro da Opção Listagem
	
	switch(op){
		case 1:
			listagem_menu();
		break;
		
		case 0:
			main_menu();
		break;
		
		default:
			cout<<endl<<"Error! Comando inválido"<<endl;
			system("pause");
			main_menu();
		break;
	}
}

void lista_rep(){ //Estrutura de exibição dos alunos reprovados. Nessa estrutura permite exibir somente os alunos reprovados. Desde que esteja cadastrado no sistema.
	
	int op;
	
	system("cls");
	media();
	
	cout<<endl<<"***********ALUNOS REPROVADOS***********"<<endl;

	for(int i=0;i<MAX;i++){
		if(alunos[i].media<7 && alunos[i].matricula != 0){
			cout<<"-------------------------------"<<endl;
			cout<<"Nome: "<<alunos[i].nome<<endl;
			cout<<"Matrícula: "<<alunos[i].matricula<<endl;
			cout<<"Sexo: "<<alunos[i].sexo<<endl;
			cout<<"Idade: "<<alunos[i].idade<<endl;
			cout<<"AV1: "<<alunos[i].notas[0]<<endl;
			cout<<"AV2: "<<alunos[i].notas[1]<<endl;
			cout<<"AV3: "<<alunos[i].notas[2]<<endl;
			cout<<"Média: "<<alunos[i].media<<endl;
			cout<<endl<<"-------------------------------"<<endl<<endl;
		}
	}
	
	cout<<endl<<"1 - Menu de listagem"<<endl;
	cout<<"0 - Menu principal"<<endl;
	cout<<endl<<"Comando: "; cin>>op; 
	
	//Estrutura de SubMenu dentro da Opção Listagem
	
	switch(op){
		case 1:
			listagem_menu();
		break;
		
		case 0:
			main_menu();
		break;
		
		default:
			cout<<endl<<"Error! Comando inválido"<<endl;
			system("pause");
			main_menu();
		break;
	}
	
}

void apr_7(){ //Estrutura de exibição dos alunos aprovados com média igual ou superior a 7. Nessa estrutura permite exibir somente os alunos aprovados. Desde que esteja cadastrado no sistema.
		
	int op;
	
	system("cls");
	media();
	
	cout<<endl<<"ALUNOS APROVADOS COM MÉDIA SUPERIOR OU IGUAL A 7"<<endl;

	for(int i=0;i<MAX;i++){
		if(alunos[i].media >=7){
			cout<<"-------------------------------"<<endl;
			cout<<"Nome: "<<alunos[i].nome<<endl;
			cout<<"Matrícula: "<<alunos[i].matricula<<endl;
			cout<<"Sexo: "<<alunos[i].sexo<<endl;
			cout<<"Idade: "<<alunos[i].idade<<endl;
			cout<<"AV1: "<<alunos[i].notas[0]<<endl;
			cout<<"AV2: "<<alunos[i].notas[1]<<endl;
			cout<<"AV3: "<<alunos[i].notas[2]<<endl;
			cout<<"Média: "<<alunos[i].media<<endl;
			cout<<endl<<"-------------------------------"<<endl<<endl;
		}
	}
	
	cout<<endl<<"1 - Menu de listagem"<<endl;
	cout<<"0 - Menu principal"<<endl;
	cout<<endl<<"Comando: "; cin>>op; 
	
	//Estrutura de SubMenu dentro da Opção Listagem
	
	switch(op){
		case 1:
			listagem_menu();
		break;
		
		case 0:
			main_menu();
		break;
		
		default:
			cout<<endl<<"Error! Comando inválido"<<endl;
			system("pause");
			main_menu();
		break;
	}
	
}

void apr_9(){ //Estrutura de exibição dos alunos aprovados com média igual ou superior a 9. Nessa estrutura permite exibir somente os alunos aprovados. Desde que esteja cadastrado no sistema.
		
	int op;
	
	system("cls");
	media();
	
	cout<<endl<<"ALUNOS APROVADOS COM MÉDIA SUPERIOR OU IGUAL A 9"<<endl;

	for(int i=0;i<MAX;i++){
		if(alunos[i].media >=9){
			cout<<"-------------------------------"<<endl;
			cout<<"Nome: "<<alunos[i].nome<<endl;
			cout<<"Matrícula: "<<alunos[i].matricula<<endl;
			cout<<"Sexo: "<<alunos[i].sexo<<endl;
			cout<<"Idade: "<<alunos[i].idade<<endl;
			cout<<"AV1: "<<alunos[i].notas[0]<<endl;
			cout<<"AV2: "<<alunos[i].notas[1]<<endl;
			cout<<"AV3: "<<alunos[i].notas[2]<<endl;
			cout<<"Média: "<<alunos[i].media<<endl;
			cout<<endl<<"-------------------------------"<<endl<<endl;
		}
	}
	
	cout<<endl<<"1 - Menu de listagem"<<endl;
	cout<<"0 - Menu principal"<<endl;
	cout<<endl<<"Comando: "; cin>>op; 

//Estrutura de SubMenu dentro da Opção Listagem
	
	switch(op){
		case 1:
			listagem_menu();
		break;
		
		case 0:
			main_menu();
		break;
		
		default:
			cout<<endl<<"Error! Comando inválido"<<endl;
			system("pause");
			main_menu();
		break;
	}
	

}

void rep_7(){ //Estrutura de exibição dos alunos reprovados com média inferior a 7. Nessa estrutura permite exibir somente os alunos reprovados. Desde que esteja cadastrado no sistema.
	
		int op;
	
	system("cls");
	media();
	
	cout<<endl<<"ALUNOS COM MÉDIA INFERIOR A 7"<<endl;

	for(int i=0;i<MAX;i++){
		if(alunos[i].media<7 && alunos[i].matricula != 0){
			cout<<"-------------------------------"<<endl;
			cout<<"Nome: "<<alunos[i].nome<<endl;
			cout<<"Matrícula: "<<alunos[i].matricula<<endl;
			cout<<"Sexo: "<<alunos[i].sexo<<endl;
			cout<<"Idade: "<<alunos[i].idade<<endl;
			cout<<"AV1: "<<alunos[i].notas[0]<<endl;
			cout<<"AV2: "<<alunos[i].notas[1]<<endl;
			cout<<"AV3: "<<alunos[i].notas[2]<<endl;
			cout<<"Média: "<<alunos[i].media<<endl;
			cout<<endl<<"-------------------------------"<<endl<<endl;
		}
	}
	
	cout<<endl<<"1 - Menu de listagem"<<endl;
	cout<<"0 - Menu principal"<<endl;
	cout<<endl<<"Comando: "; cin>>op; 
	
	//Estrutura de SubMenu dentro da Opção Listagem
	
	switch(op){
		case 1:
			listagem_menu();
		break;
		
		case 0:
			main_menu();
		break;
		
		default:
			cout<<endl<<"Error! Comando inválido"<<endl;
			system("pause");
			main_menu();
		break;
	}
	
}

void rep_5(){ //Estrutura de exibição dos alunos reprovados com média inferior a 5. Nessa estrutura permite exibir somente os alunos reprovados. Desde que esteja cadastrado no sistema.
		
		int op;
	
	system("cls");
	media();
	
	cout<<endl<<"ALUNOS COM MÉDIA INFERIOR A 5"<<endl;

	for(int i=0;i<MAX;i++){
		if(alunos[i].media<5 && alunos[i].matricula != 0){
			cout<<"-------------------------------"<<endl;
			cout<<"Nome: "<<alunos[i].nome<<endl;
			cout<<"Matrícula: "<<alunos[i].matricula<<endl;
			cout<<"Sexo: "<<alunos[i].sexo<<endl;
			cout<<"Idade: "<<alunos[i].idade<<endl;
			cout<<"AV1: "<<alunos[i].notas[0]<<endl;
			cout<<"AV2: "<<alunos[i].notas[1]<<endl;
			cout<<"AV3: "<<alunos[i].notas[2]<<endl;
			cout<<"Média: "<<alunos[i].media<<endl;
			cout<<endl<<"-------------------------------"<<endl<<endl;
		}
	}
	
	cout<<endl<<"1 - Menu de listagem"<<endl;
	cout<<"0 - Menu principal"<<endl;
	cout<<endl<<"Comando: "; cin>>op; 
	
	//Estrutura de SubMenu dentro da Opção Listagem
	
	switch(op){
		case 1:
			listagem_menu();
		break;
		
		case 0:
			main_menu();
		break;
		
		default:
			cout<<endl<<"Error! Comando inválido"<<endl;
			system("pause");
			main_menu();
		break;
	}
	
}

