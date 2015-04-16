#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>
#include<cstring>
#include"Sudoku.h"
using namespace std;

bool Sudoku::check(int n){
        int row=n%12;
        int col=n/12;
        //checking each block
        int block_r,block_c;
        block_r=row/3*3;
        block_c=col/3*3;
        int chr=block_r+2;
        int chc=block_c+2;
        for(block_c/3*3;block_c<=chc;block_c++){
                for(block_r=row/3*3;block_r<=chr;block_r++){
                        if(map[col][row]==map[block_c][block_r]&&block_c!=col&&block_r!=row)
                                return false;
                }
        }
        //checking row and column
        for(int i=0;i<12;i++){
                if(map[col][row]==map[col][i]&&i!=row)
                        return false;
                else if(map[col][row]==map[i][row]&&i!=col)
                        return false;
        }
        //after checking done
        return true;
}

void Sudoku::ReadIn(){
        count=0;
        for(int i=0;i<12;i++){
                for(int j=0;j<12;j++){
                        cin>>map[i][j];
                }
        }
}

void Sudoku::answer(int n){
        int row=n%12;
        int col=n/12;
        //when n=144 solve done
        if(count>=2){
                return; //quit
        }
        if(n==144){
                count+=1;   //total answer plus one
                for(int i=0;i<12;i++){
                        for(int j=0;j<12;j++){
                                sudoku[i][j]=map[i][j]; //copy the answer to another array.
                        }
                }
                return; //continue check second solved
        }
        //check it's dark place or not
        if(map[col][row]==-1)
                answer(n+3);
        //check it's blank or not
        else if(map[col][row]==0){
                for(int ans=1;ans<10;ans++){
                        map[col][row]=ans;
                        if(check(n)==true)
                                answer(n+1);
                }
                map[col][row]=0; //let grid now become 0 and return back to last grid
        }
        else{
                if(check(n)==true)
                        answer(n+1);
                else{
                        cout<<"0"<<endl;
                        exit(0);
                }
        }
}

void Sudoku::Solve(){
        //start solve
        answer(0);
        //after solved.
        if(count==1){
                cout<<"1"<<endl;
                for(int i=0;i<12;i++){
                        for(int j=0;j<12;j++){
                                cout<<sudoku[i][j]<<" ";
                        }
                        cout<<endl;
                }
                return;
        }
        else if(count>=2)
                cout<<"2"<<endl;
        else
                cout<<"0"<<endl;
}

void Sudoku::place_dark(){
        int checkr,checkc,col=0,row=0,rec,yo=0;

        while(col<12){
                checkc=col+3;   //set col end point
                checkr=row*3+3; //set row end point
                rec=row;
                for(;col<checkc;col++){
                        for(row*=3;row<checkr;row++){
                                map[col][row]=-1;
                        }
                        row=rec;
                }
                row=rec+1;
        }
}

void Sudoku::place_num(){
        srandom((unsigned)time(NULL));
        int index,row=0,col,rec,save[3],k;
        for(col=6;col<9;col++){
                k=0;
                //adding 3 random numbers for each row
                for(row=0;row<3;row++){
                        rec=0;
                        while(rec<1){
                                index=rand()%9+1;
                                if(rand_check[index]==false){
                                        map[col][row]=index;
                                        rand_check[index]=true;
                                        save[row]=index;
                                        rec++;
                                }
                        }
                }
                rec=col+1;
                //copy the 3 numbers to other column and row
                for(;row<12;row++){
                        if(rec>8)
                                rec-=3;
                        if(map[rec][row]==-1)
                                row+=3;
                        if(map[rec][row]==0){
                                map[rec][row]=save[k];
                                k++;
                                if(k==3){
                                        k-=3;
                                        rec++;
                                }
                        }
                }
        }
}

void Sudoku::take_num(){
        srandom((unsigned)time(NULL));
        int row,col,i=0;
        while(i<15){
                row=rand()%12;
                col=rand()%12;
                if(sudoku[col][row]!=-1&&sudoku[col][row]!=0){
                        sudoku[col][row]=0;
                        i++;
                }
        }
}

void Sudoku::GiveQuestion(){
        memset(map,0,sizeof(map));
        memset(rand_check,false,sizeof(rand_check));
        count=0;
        place_dark();   //add dark place
        place_num();    //add  numbers
        answer(0);      //solve sudoku and save in an array
        take_num();     //take out some numbers in the array
        for(int i=0;i<12;i++){
                for(int j=0;j<12;j++){
                        cout<<sudoku[i][j]<<" ";
                }
                cout<<endl;
        }
        return;
}
