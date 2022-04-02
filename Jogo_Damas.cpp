#include <iostream>
#include <conio.h>
#include <cctype>
#include <math.h>
#include "Functions.h" // faz o tabuleiro
using namespace std; 

int linhaOrigem;
int colunaOrigem;
int linhaDestino;
int colunaDestino;
char damaBranca = 2;
char damaPreta = 1;
char pecaBranca; 
char pecaPreta;

void populaMatriz_Rep(int n, int col, char matriz[][8], int  coordenada[2], int conta){
    
    char peca[]={'P', 'B'};
    
    //for(int i=0; i < 12; i ++){ // Verifica peça por peça.

    for(int i=0; i<2; i++){
        for (int j=0; j<2; ++j){
            if (conta == 0) matriz[coordenada[1]][coordenada[0]] = peca[0];
            else matriz[coordenada[1]][coordenada[0]] = peca[1];
        }         
    }
}  

void defineOrigem (){
	string msg = "Informe o valor da linha de origem: ", msg1 = "Informe o valor da coluna de origem: ";
	
	colunaOrigem = valida_letra(msg1);
	linhaOrigem = valida_linha(msg);
}

void defineDestino (){
	string msg = "Informe o valor da linha de destino: ", msg1 = "Informe o valor da coluna de destino: ";
	
	colunaDestino = valida_letra(msg1);
	linhaDestino = valida_linha(msg);
}

bool chekar_Movime( char matriz[][8]){
	char pecaOri = matriz[linhaOrigem][colunaOrigem];
	
	if (matriz [linhaDestino][colunaDestino] == ' '){
		// transformar em função ehdiagonal 
		if ( abs(linhaDestino - linhaOrigem) == abs(colunaDestino - colunaOrigem)){ }
	}
}
/*int som(){
	
	Beep(264, 500); // C
	Beep(297, 500); // D
	Beep(330, 800); // E
	Beep(264, 500); // C
	Beep(297, 500); // D
	Beep(330, 800); // E
	Beep(264, 500); // C
	Beep(297, 500); // D
	Beep(330, 700); // E
	Beep(264, 400); // C
	Beep(297, 500); // D
	Beep(330, 500); // E
	Beep(264, 800); // C
}*/

int main(){
    int pecasPlayer1=12, pecasPlayer2=12, n, rows=8, col=8, rep, coo[2],  cont=0, direct;
    bool empate = false; 
    char resp[2], tab[8][8];
    string  vez[]={"\n\t\tVEZ DE ", "\n\t\tVEZ DE "}, jogador[2];
    
    //som ();
    //começo
    telaInicial();
    
    //pedir os nomes dos jogadores; 
    system ("color 3F");
	cout << "\n\tSEJA BEM VINDO(A) AO JOGO DE DAMAS!\n";
	for (int j=1; j<3; j++){
		cout << "Informe o nome do Jogador" << j << ": ";
		cin >> jogador[j-1];
	}
	system("cls");
	
    definesimbolos(resp);
    pecaBranca = resp[0];
	pecaPreta = resp[1]; 
	
	populaMatriz_Inicial(rows, col, tab, pecaBranca, pecaPreta); // functions
	
	while (!empate && (pecasPlayer1>0 && pecasPlayer2>0)){

    	exibirTabuleiro(rows, col, tab); // está na library functions
    
    	do{    
       	 	//aparece a vez e ajuda a regular depois na função populaMatriz_Rep
        	if (cont==0) cout << vez[0] << jogador[0] << " ( " << resp[1] << " )\n"; 
        	else cout << vez[1] << jogador[1] << " ( " << resp[0] << " )\n";
			
			bool origem_valida = false, destino_valido = false;
			
			/*preta
			while (!origem_valida){
				defineOrigem(); 
				if (pecaPreta == tab[linhaOrigem][colunaOrigem]){ origem_valida = true;} // falta definir a dama Preta;		
			}
			
			while (!destino_valido){
				defineDestino(); 
				if (chekar_Movime(linhaOrigemtab)){ destino_valido = true;} // falta definir a dama Preta;		
			}
			
			//branca
			while (!origem_valida){
				defineOrigem(); 
				if (pecaBranca == tab[linhaOrigem][colunaOrigem]){ origem_valida = true;} // falta definir a dama Branca;		
			}
			
			while (!destino_valido){
				defineDestino(); 
				if ( ' ' == tab[linhaDestino][colunaDestino]){ destino_valido = true;} // falta definir a dama Branca;		
			}*/
			
    		mover(tab, linhaOrigem, colunaOrigem, linhaDestino, colunaDestino); 
        	system("cls");
        
        	populaMatriz_Rep(rows, col, tab, coo, cont);
        	exibirTabuleiro(rows, col, tab);
        
        	cout << "\n\tPress 0 to finish or space to continue...";
        	direct = getch(); //lê a tecla que foi pressionada
        
        	//altenagem de P e B, pode usar módulo
        	if (cont == 0) cont ++;
        	else cont--;
        
        
    	} while(direct==32); // enquanto pressionar espaço.
	}
}


	

