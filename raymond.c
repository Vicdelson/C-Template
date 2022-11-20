#include <stdio.h>
#include <ctype.h>
void fight(int [][2],int [],int,int);
int _2n(int);
int Winner;
int main() {
    int N;
    scanf("%d\n",&N);
    int n=_2n(N);
    int player[1024][2]={0},round[10]={0};
    for(int i=0;i<N;i++){
        player[i][0]=i+1;
        player[i][1]=getchar();
    }
    getchar();
    for(int i=0;i<n;i++){
        round[i]=getchar();
    }
    fight(player,round,N,0);
    printf("%d\n",Winner);
    return 0;
}

int _2n(int k){
    if(k==1) return 0;
    else return 1+_2n(k/2);
}

void fight(int player[][2],int round[],int people,int Rou){
    int map[1024][2];
    if(people==1){
        //有贏家
        Winner=player[0][0];
        return;
    }else{
        //猜拳
        for(int i=0;i<people;i+=2){
            if(player[i][1]=='p' && player[i+1][1]=='r'||player[i][1]=='s' && player[i+1][1]=='p'||player[i][1]=='r' && player[i+1][1]=='s') {
                map[i / 2][0] = player[i][0], map[i / 2][1] = player[i][1];
            }else if(player[i][1]=='p' && player[i+1][1]=='s'||player[i][1]=='s' && player[i+1][1]=='r'||player[i][1]=='r' && player[i+1][1]=='p'){
                map[i / 2][0] = player[i+1][0], map[i / 2][1] = player[i+1][1];
            }else if(player[i][1]=='p' && player[i+1][1]=='p'||player[i][1]=='s' && player[i+1][1]=='s'||player[i][1]=='r' && player[i+1][1]=='r'){
                if(round[Rou]=='s'){
                    map[i / 2][0] = player[i][0], map[i / 2][1] = player[i][1];
                }else if(round[Rou]=='b'){
                    map[i / 2][0] = player[i+1][0], map[i / 2][1] = player[i+1][1];
                }
            }

        }
        fight(map,round,people/2,Rou+1);
        return;
    }
}