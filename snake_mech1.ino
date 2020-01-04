/*

    SNAKE
    
    The LED matrix used might be 16x16. So directions on this matrix board are similar to north-south-east-west directions with numbers
    given to each direction:
        
        Direction               Number-assigned
        North                   1
        South                   -1
        East                    2
        West                    -2
        
        
    points[10][2] is the matrix that will contain the coordinates of each point of the snake body. Just head and tail havent been kept track
    as it will be difficult to display a snake that has many corners in it.
    
*/

#include<MaxMatrix.h>

#define LENGTH_SNAKE 5
#define WIDTH 16
#define HEIGHT 16

void move(int ,int ,int );
int input();
void start();
int getTailX(int ,int );
int getTailY(int ,int );

int DIN = 7;   // DIN pin of MAX7219 module
int CLK = 6;   // CLK pin of MAX7219 module
int CS = 5;    // CS pin of MAX7219 module
int maxInUse = 1;
MaxMatrix m(DIN, CS, CLK, maxInUse); 

void setup()
{
    randomSeed(analogRead(0));
    
    headx=random(0,WIDTH);
    heady=random(0,HEIGHT);
    dir=random(1,5);
    
    tailx=getTailX(headx,dir);
    taily=getTaily(heady,dir);

}

void loop()
{
    
}

void display(int points[5][2],int N)
{
    int N=LENGTH_SNAKE;

    m.clear();              // Clearing the display
    int i;
    for(i=0;i<N;i++)
        m.SetDot(points[i][1],points[i][0],true);

    // Display N points in their respective locations. points[0][0],points[0][1] => head(x,y). points[N][0],points[N][1] => tail(x,y) 
    
}

void move_forward(int points[5],int init_dir,int new_dir,int N)
{
    // Function to move the snake forward by one step
    
    headx=points[0][0];
    heady=points[0][1];
    
    if(init_dir==1)
    {
        if(new_dir=='L') 
            headx--;
        else if(new_dir=='R')
            headx++;
        else
            heady--;
    }
    else if(inti_dir==-1)
    {
        if(new_dir=='L') 
            headx++;
        else if(new_dir=='R')
            headx--;
        else
            heady++;
    }
    else if(inti_dir==2)
    {
        if(new_dir=='L') 
            heady--;
        else if(new_dir=='R')
            heady++;
        else
            headx++;
    }
    else if(inti_dir==-2)
    {
        if(new_dir=='L') 
            heady++;
        else if(new_dir=='R')
            heady--;
        else
            headx--;
    }
    
    
    for(i=N-1;i>=1;i--)
    {
        points[i][0]=points[i-1][0];
        points[i][1]=points[i-1][1];
    }
    
    points[0][0]=headx;
    points[0][1]=heady; 
    
}

int input()
{
    /*
    
        Function to accept input and return the direction of movement
        
        Give default direction as forward
    
    */
	
    // Just reading 2 digital inputs. can be changed later
    
    unsigned char left=0,right=0;
    char new_dir=0;
    
    left=digitalRead(LEFT);
    right=digitalRead(RIGHT);
    
    if(left==1)
        new_dir='L';
    else if(right==1)
        new_dir='R';
        
    return new_dir;
    
}


