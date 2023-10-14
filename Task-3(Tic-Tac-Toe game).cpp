#include <iostream>
using namespace std;

char grid[3][3];
string p1,p2;
char turn='X';
int draw=0;

void display(){
	cout<<"       |     |		\n";
	cout<<"    "<<grid[0][0]<<"  |  "<<grid[0][1]<<"  |  "<<grid[0][2]<<"\n";
	cout<<"  _____|_____|_____\n";
	cout<<"       |     |		\n";
	cout<<"    "<<grid[1][0]<<"  |  "<<grid[1][1]<<"  |  "<<grid[1][2]<<"\n";
	cout<<"  _____|_____|_____\n";
	cout<<"       |     |		\n";
	cout<<"    "<<grid[2][0]<<"  |  "<<grid[2][1]<<"  |	"<<grid[2][2]<<"\n";
	cout<<"       |     |		\n";
}
void restore(){
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			grid[i][j]='1'+i*3+j;
}
int stat(){
	if((grid[0][0]==grid[1][1] && grid[1][1]==grid[2][2])||(grid[0][2]==grid[1][1] && grid[1][1]==grid[2][0]))
	return 0;
	
	for(int i=0;i<3;i++){
		if((grid[i][0]==grid[i][1] && grid[i][1]==grid[i][2])||(grid[0][i]==grid[1][i] && grid[1][i]==grid[2][i]))
		return 0;
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(grid[i][j]!='X' && grid[i][j]!='O')
			return 1;
		}
	}
	draw=1;
	return 0;
}
void game(){
	if(turn=='X')
	cout<<"\n"<<p1<<"'s turn (X) : ";
	else if(turn=='O')
	cout<<"\n"<<p2<<"'s turn (O) : ";
	int choice;
	cin>>choice;
	
	int r=choice/3;
	int c=choice%3-1;
	if(turn=='X' && grid[r][c]!='X' && grid[r][c]!='O'){
		grid[r][c]='X';
		turn='O';
	}
	else if(turn=='O' && grid[r][c]!='X' && grid[r][c]!='O'){
		grid[r][c]='O';
		turn='X';
	}
	else{
		cout<<"\n!! BOX ALREADY FILLED !!\n--Please select another box--\n";
		game();
	}
	display();
}
void play(){
	cout<<"Enter name of Player 1 : ";
	cin>>p1;
	cout<<"Enter name of Player 2 : ";
	cin>>p2;
	restore();
	cout<<"\n\n";
	cout<<p1<<" plays using X \t"<<p2<<" plays using O\n\n";
	display();
	while(stat()){
		game();
		stat();
	}
	if(turn=='X' && draw==0)
	cout<<"\nCONGRATS "<<p2<<" has WON the game !!!...\n";
	else if(turn=='O' && draw==0)
	cout<<"\nCONGRATS "<<p1<<" has WON the game !!!...\n";
	else
	cout<<"\nIts a DRAW!!!...\n";
	
	char choice='y';
	while(choice=='Y' || choice=='y')
	{
		cout<<"\nDo you want to play again?? ( enter Y/N )";
		cin>>choice;
		if(choice=='Y' || choice=='y'){
			turn='X';
			play();	
		}
		else
			cout<<"...Thanks for playing...";
	}
}
int main(){
	play();
	return 0;
}
