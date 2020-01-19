#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define R 10
#define COL 5
//1 pacman
//2 food
//0 block
//3 empty
int choice;
typedef struct{
	int x;
	int y;
}Coord;
int scanChoice();
void gotoxy(int,int);
void drawMap(int Map [COL][R]);
void Move(int,Coord*, int Map[COL][R]);
int main(){
	char ans,c;
	int i,j;
	Coord pacman={0,0};
	int Map[COL][R];
	FILE *ptf=fopen("C:\\LastProject\\Matrix2.txt","r");
	if(ptf!=NULL){
		while(feof(ptf)==0){
			for(i=0;i<COL;i++){
				for(j=0;j<R;j++){
					fscanf(ptf,"%d",&Map[i][j]);
					fscanf(ptf,"%c",&c);
				}
			}
		}
	}
/*	int Map[COL][R]={1,3,3,2,3,0,0,3,3,0,
					 3,3,3,3,3,3,0,3,3,3,
					 3,3,3,2,3,3,3,3,3,3,
					 3,3,3,3,3,3,0,3,3,3,
					 3,3,3,3,3,2,3,3,3,0};*/
drawMap(Map);
while(1){
	//drawMap(Map);
	gotoxy(pacman.x,pacman.y);
	printf("%c",'S');
	choice=scanChoice();
	gotoxy(pacman.x,pacman.y);
	printf(" ");
	if(choice){
		Move(choice,&pacman,Map);
	  }
    }
}
int scanChoice(){
	char ans;
	ans=getch();
	switch(ans){
		case 72:
			return 1;
		case 80:
			return 2;
		case 75:
			return 3;
		case 77:
			return 4;
		default:
			return 0;
	}
}
void gotoxy(int x,int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle,coord);	
}
void drawMap(int Map[COL][R]){
	char block;
	int i,j;
	for(i=0;i<COL;i++){
		for(j=0;j<R;j++){
			switch(Map [i][j]){
				case 0:
					block='*';
					break;
				case 2:
					block='.';
					break;
				case 3:
					block=' ';
					break;
			}
			printf("%c",block);
		}
		printf("\n");
	}
}
void Move(int choice,Coord *pacman,int Map[COL][R]){
		Map[pacman->y][pacman->x]=3;
		switch(choice){
			case 1:
				if(pacman->y&&Map[pacman->y-1][pacman->x])
					pacman->y--;
					break;
			case 2:
				if(pacman->y+1<COL&&Map[pacman->y+1][pacman->x])
					pacman->y++;
					break;
			case 3:
				if(pacman->x&&Map[pacman->y][pacman->x-1])
					pacman->x--;
					break;
			case 4:
				if(pacman->x+1<R&&Map[pacman->y][pacman->x+1])
					pacman->x++;
					break;
		}
		Map[pacman->y][pacman->x]=1;
}
