#include <windows.h>
#include <stdio.h>
#define WIDTH 700
#define HEIGHT 150
#define dW 10
#define dH 5

using namespace std;

struct coord{
	int x;
	int y;
};

struct dato{
	coord pos[13];
	char d[13];
};
//dibujo del pajaro
char bird[2][8]={
	"/--o\\  ",
	"|___ > "
};
//largo y ancho del lugar en el cual va a estar la pantalla
void draw(char plano[HEIGHT/dH][WIDTH/dW+1], int A, int B, char C){
	B=HEIGHT/dH-1-B;
	if (A < 0 || B < 0 || A>=WIDTH/dW || B>=HEIGHT/dH)return;
	plano[B][A]=C;
}
//funcion para que se puede ver donde esta el mouse, es un seguimiento a las coord
void gotoxy(int x, int y){
	HANDLE hcon= GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X =x;
	dwPos.Y =y;
	SetConsoleCursorPosition(hcon,dwPos);	
}

class flappybird{
	//movimiento del aver
	private:
		dato ave[1];
		
		public: 
			void info(){
				int q=0;
				int y;
				for(int i=0;i<2;i++){
					y=2-i;
					for(int j=0; j<7;j++){
						if(bird[i][j] != ' '){
							ave[0].pos[q] = {j,y};
							ave[0].d[q]=bird[i][j];
							q++;							
							
						}
						
					}
				}
			}
			//posicionamiento de ave
			void player(char plano[HEIGHT/dH][WIDTH/dW+1]){
				for(int i=0; i<10 ;i++){
					draw(plano,5+ave[0].pos[i].x,10+ave[0].pos[i].y,ave[0].d[i]);
				}
			}
			
};

main(){
	char plano[HEIGHT/dH][WIDTH/dW+1];
	//impresion del plano caracteres y obstaculos
	for (int i=0; i<HEIGHT/dH;i++)
		plano[i][WIDTH/dW]='\n';
		plano[HEIGHT/dH+1][WIDTH/dW]='\o';
		
		flappybird j1;
		j1.info();
		
		while(true){
		
		for(int i=0;i<HEIGHT/dH;i++){
			for(int j=0;j<WIDTH/dW;j++){
				plano [i][j]='*';
			}
		}
		//llama a la posicion de las cordenadas el.player
		j1.player(plano);
		gotoxy(0,0);
		puts(plano[0]);
		}
	
	
	
	
	return 0;
}
