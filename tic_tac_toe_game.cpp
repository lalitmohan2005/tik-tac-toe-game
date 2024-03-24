#include <iostream>
using namespace std;

char spaces[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char currentPlayer = 'x';
bool tie = false;
string player1="";
string player2="";

void displayBoard(){
    cout<<"  |   |   \n";
    for(int i=0;i<3;i++){
        cout<<""<<spaces[i][0]<<" | "<<spaces[i][1]<<" | "<<spaces[i][2]<<" \n";
        cout << "  |   |   \n";
        if(i<2)
        {
            cout<<"--|---|--\n";
        }
    }
    cout <<"-------------------------------------------------------------\n";
}

void processInput(){
    int digit;
    cout<<(currentPlayer == 'x' ? player1 : player2)<<" please enter";
    cin>> digit;

    int row = (digit-1)/3;
    int col = (digit -1) % 3;

    if(digit <1 || digit >9 || spaces[row][col] == 'x' || spaces[row][col]=='0')
    {
        cout<<"Invalid input!" <<endl;
        processInput();
    }
    else
    {
        spaces[row][col] = currentPlayer;
        currentPlayer = (currentPlayer == 'x' ? '0' :'x');
    }
}

bool checkGameResults(){
    for(int i=0;i<3;i++){
        if((spaces[i][0] == spaces[i][1] && spaces[i][0]==spaces[i][2]) ||
          (spaces[0][i] == spaces[1][i] && spaces[0][i]==spaces[2][i]))
        {
            return true; //Win
        }
    }
        if((spaces[0][0] == spaces[1][1] && spaces[1][1]==spaces[2][2]) ||
          (spaces[0][2] == spaces[1][1] && spaces[1][1]==spaces[2][0]))
        {
            return true; //Win
        }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
        {
                if(spaces[i][j] != 'x' && spaces[i][j] !='0')
                {
                    return false; //Game still running                    
                }
    }
    }
    tie = true;
    return false;
}
int main(){
    cout<<"Enter the name of 1st player:";
    getline(cin,player1);
    cout<<"Enter the name of 2nd player:";
    getline(cin,player2);

    cout << player1<<"is player1,so they will play x\n";
    cout<<player2<<"is player 2,so will play 0\n";

    while(!checkGameResults())
    {
         displayBoard();
         processInput();
    }
    displayBoard();
    if(currentPlayer =='x'&& !tie){
        cout<< player2 << "wins!!"<<endl;
    }else if(currentPlayer =='0'&& !tie){
        cout<< player1 << "wins!!"<<endl;
    }else{
        cout<<"it's a tie!!"<<endl;
    }
    return 0;
}