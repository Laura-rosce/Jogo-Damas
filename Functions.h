#include <iostream>
#include <conio.h>
using namespace std;

void populaMatriz_Inicial(int n, int col, char matriz[][8], char pecaBranca, char pecaPreta){
    int i, j;
    char vazio = ' ', brancas = pecaBranca, pretas = pecaPreta;
    
    for (i=0;i<n;i++){
        for(j=0;j<col;j++){
            matriz[i][j] = vazio;
        }
    }
    
      for(i=0;i<3;i++){
        for(j=0;j<col;j++){
              if ((i+j)%2 == 1) matriz[i][j] = brancas;
            //else matriz[i][j] = brancas;    
        }
      }  
      
      for (i=5;i<n;i++){
        for(j=0;j<col;j++){
            if ((i+j)%2 == 1) matriz[i][j] = pretas;
            //else matriz[i][j] = pretas;    
        }
    }
}

void exibirTabuleiro(int linhas, int colunas, char matriz[][8]){
	char alfa[]={'A', 'B','C', 'D', 'E', 'F', 'G', 'H'};
	
	for ( int i = 0; i<linhas; i++) { 
		int cont=linhas+1;// gambiarra numeracao do lado :)
	    if (i == 0){ 
	    	printf("\t %c", 218);
	    	for (int topo=0; topo<7; topo++){ printf("%c%c%c%c", 196,196,196,194);}
	    	printf ("%c%c%c%c", 196,196,196,191,"\n");
	    }
	    
	    cont--; 
		
		//colocar numeros ao lado e barra;
		printf("\n\t%d%c",cont-i,179); 
		for (int lim=0; lim<linhas; lim++){ printf(" %c %c", matriz[i][lim], 179);}
		
	
		if (i == linhas-1){
	    	printf("\n\t %c", 192);
	    	for (int abaixo=0; abaixo<7; abaixo++){ printf("%c%c%c%c",196,196,196, 193);}
	    	printf ("%c%c%c%c", 196,196,196,217,"\n");
	    	
		} else{
		//as interceções entre as barras;
	    	printf("\n\t %c", 195);
	    	for (int lim=7; lim>0; lim--){ printf("%c%c%c%c",196,196,196,197);}
	    	printf("%c%c%c%c", 196,196,196,180,"\n");
				
	    } 
		}
		cout << "\n\t   "; 
		for (int j=0; j<8; j++){ cout << alfa[j] << "   ";}
		cout << endl;
}

int valida_letra(string mensagem){
	char letra[]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'}, resp; 

	do{
		cout << mensagem;
		cin >> resp; 
		resp = toupper(resp); 
		
		for (int i=0; i<16; i++){
			if ( resp == letra[i]){
				return i; 
			} 	
		}
		
		cout << "Informe uma letra valida!\n";
		
	} while(true); 
}

int valida_linha(string mensagem){
	int  num; 

	do{
		cout << mensagem;
		cin >> num; 
		
		if (num>0 && num<9)  return 8 - num;
		
		cout << "Informe um numero valido!\n";
		
	} while(true); 
}

void mover(char matriz[][8], int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino){
	char peca = matriz[linhaOrigem][colunaOrigem]; 
	
	matriz[linhaOrigem][colunaOrigem] = ' '; 
	matriz[linhaDestino][colunaDestino] = peca;
	
	
}

void tabela_simb(){
	//tabela
	printf("%c", 201);
	for (int topo=0; topo<8; topo++){ printf("%c%c%c%c", 205,205,205,205);}
	printf ("%c%c%c%c", 205,205,205,187,"\n");
	
	printf ("\n%c\t\t\t\t    %c\n", 186,186);
	for (int lat=0; lat<13; lat++){ printf ("%c\t\t\t\t    %c\n", 186,186);}
	
	printf("%c%c%c", 200,61,61);
	for (int abaixo=0; abaixo<7; abaixo++){ printf("%c%c%c%c",61,61,61,61);}
	printf ("%c%c%c%c%c%c", 61,61,61,61,61,188,"\n");	
}

void definesimbolos ( char resp[2]){
	int i2 = 1, p[]={1, 2, 111, 220}, direc;
	
	while (direc != 13){
		cout << "Escolha o formato das pecas:\n     BRANCAS  PRETAS";
		switch(i2){
        	case 1:
            	printf("\n\n\t%c (%c) (%c)\n\n\t (B) (P)\n\n\t (W) (B)\n\n\t (%c) (%c)",16,p[1],p[0],p[2],p[3]);
            	break;  
        	case 2:
            	printf("\n\n\t (%c) (%c)\n\n\t%c (B) (P)\n\n\t (W) (B)\n\n\t (%c) (%c)",p[1],p[0],16,p[2],p[3]);
            	break;
        	case 3:
            	printf("\n\n\t (%c) (%c)\n\n\t (B) (P)\n\n\t%c (W) (B)\n\n\t (%c) (%c)",p[1],p[0],16,p[2],p[3]);
            	break;
			case 4:
				printf("\n\n\t (%c) (%c)\n\n\t (B) (P)\n\n\t (W) (B)\n\n\t%c (%c) (%c)",p[1],p[0],16,p[2],p[3]);
            	break;  
        	default:;
    	}
    
    	direc = getch(); //lê a tecla que foi pressionada.
    	if(direc == 115 && i2<=3 ) { i2++;} // move com S pra baixo
		else if (direc == 119 && i2>=2) { i2--;} // move com W pra cima
		else if (direc == 13)  resp[0] = i2; // enter ele devolve os valores da peça
    
    	system ("cls"); 
	}
	if (resp[0] == 2){ 
		resp[0] = 'B'; 
		resp[1] = 'P';}
	else if (resp[0] == 3){ 
		resp[0] = 'W'; 
		resp[1] = 'B';}
	else {
		for (int i=0; i<2; i++){
			if (resp[0] == 1)resp[i] = p[i];
			else resp[i] = p[i+2];
		}
	}
	
	printf("\n\n\t\tFoi escolhido  as pecas %c %c ", resp[0], resp[1]);
	system("pause");
	system("cls");
	
}

void como_jogar(){
	system ("color A0");
	cout << "\t\t ~ COMO JOGAR ~\n\n"
		 <<	"- Para alternar as opcoes pressione W (cima) e S (baixo), sendo o enter (confirmar);\n"
		 << "- No jogo da Damas você precisara utilizar as coordenadar (coluna | linha) para mover"
		 << "as pecas;\n"
		 << "- Quando a peca for capturada, seus pontos serao contabilizado no score;\n"
		 << "- Quando desejar terminar o jogo, pressione 0, assim o vencendendor sera o de maior " 
		 << "posse de pecas; \n\n";
	
	cout << "\t\t ~ HOW TO PLAY ~\n\n"
 		 << "- To toggle the options press W (up) and S (down), being the enter (confirm);\n"
		 << "- In Checkers you will need to use the coordinates (column | row) to move"
 		 << "the pieces;\n"
		 << "- When the piece is captured, its points will be counted in the score;\n"
 		 << "- When you want to end the game, press 0, so the winner will be the highest"
		 << "possession of pieces; \n\n";
	
	cout << "\t\t ~ COMO JUGAR ~\n\n"
		 << "- Para alternar las opciones presione W (arriba) y S (abajo), siendo el enter (confirmar);\n"
		 << "- En Damas necesitaras usar las coordenadas (columna | fila) para moverte "
		 << "las piezas;\n"
		 << "- Cuando la pieza sea capturada, sus puntos serán contados en el puntaje;\n"
		 << "- Cuando quieras terminar el juego, presiona 0, asi el ganador sera el mas alto"
		 << "posesión de piezas; \n";
}

void creditos(){
	system("color 5F");
	cout << "\t\t ~ CRIADORES ~\n\n";
	printf ("%c Andre Ribeiro - Idealizador e Colaborador - Engenheiro Mecatronico\n", 26);
	printf ("%c Djair Alves - Desenvolvedor e Programador em Java - Licenciatura\n", 26);
	printf ("%c Laura Roscelle - Desenvolvedora e Programadora - Cursando tecnico em Info\n", 26);
	printf ("%c Livia Rachell - Programadora e Desenvolvedora - TADS", 26);	 
}

void telaInicial(){ // falta trilha sonora
	int i2 = 1, fail = 0;
	while(fail==0) {
		system ("color 70");
		cout << "\n\t\t\t ~ DAMAS CLASSIC ~ ";
    	switch(i2) {
        	case 1:
            	printf("\n\n\t%c Jogar \n\n\t  Como jogar \n\n\t  Criadores\n", 16);
            	break;  
        	case 2:
            	printf("\n\n\t  Jogar \n\n\t%c Como jogar  \n\n\t  Criadores\n",16);
            	break;
        	case 3:
            	printf("\n\n\t  Jogar \n\n\t  Como jogar \n\n\t%c Criadores\n",16);
            	break;  
        	default:;
    	}
    	int direc=getch(); //lê a tecla que foi pressionada.
    	if(direc== 115 && i2<=2) i2 ++;
    	else if (direc == 119 && i2>=2) i2--; 
    	else if (direc==13 && i2==1) fail=1;
		else if (direc==13 && i2==2) {system ("cls");  como_jogar(); cout << endl; system ("pause");}
		else if (direc==13 && i2==3) { system ("cls"); creditos();  cout << endl; system ("pause");}	
	
		system("cls");
	}
}


