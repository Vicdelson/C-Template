#include <stdio.h>
#define NUM 9
void check_sudoku(int (*grid_p)[NUM]);
int main(void){
    int grid[NUM][NUM]; // sudoku puzzle
    for(int i = 0; i < NUM; ++i){
        for(int j = 0; j < NUM; ++j){
            scanf("%d", &grid[i][j]);
        }
    }
    check_sudoku(grid);
    return 0;
}

void check_sudoku(int (*grid_p)[NUM]){
    int i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc,dd,ee,ff,gg,hh,ii,jj,kk,ll,mm,nn,oo,pp,qq,rr,ss,tt,uu,vv,ww,xx,yy,zz,aaa,bbb,ccc,ddd,eee,fff,ggg,hhh,iii,jjj,kkk,lll,mmm,nnn,ooo,ppp,qqq,rrr,sss,ttt,uuu,vvv,www,xxx,yyy,zzz,aaaa,bbbb,cccc,dddd,eeee,ffff,gggg,hhhh,iiii,jjjj,kkkk,llll,mmmm,nnnn,oooo,pppp,qqqq,rrrr,ssss,tttt,uuuu,vvvv,wwww,xxxx,yyyy,zzzz;
    for(i=0;i<NUM;i++){
        for(j=0;j<NUM;j++){
            for(k=0;k<NUM;k++){
                if(j!=k){
                    if(grid_p[i][j]==grid_p[i][k]){
                        printf("(%d,%d) ",i,j);
                    }
                }
            }
        }
    }
    for(l=0;l<NUM;l++){
        for(m=0;m<NUM;m++){
            for(n=0;n<NUM;n++){
                if(m!=n){
                    if(grid_p[m][l]==grid_p[n][l]){
                        printf("(%d,%d) ",m,l);
                    }
                }
            }
        }
    }
    for(o=0;o<NUM;o++){
        for(p=0;p<NUM;p++){
            for(q=0;q<NUM;q++){
                for(r=0;r<NUM;r++){
                    if(p!=q){
                        if(p!=r){
                            if(q!=r){
                                if(grid_p[o][p]==grid_p[o][q]){
                                    if(grid_p[o][p]==grid_p[o][r]){
                                        printf("(%d,%d) ",o,p);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for(s=0;s<NUM;s++){
        for(t=0;t<NUM;t++){
            for(u=0;u<NUM;u++){
                for(v=0;v<NUM;v++){
                    if(t!=u){
                        if(t!=v){
                            if(u!=v){
                                if(grid_p[t][s]==grid_p[u][s]){
                                    if(grid_p[t][s]==grid_p[v][s]){
                                        printf("(%d,%d) ",t,s);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for(w=0;w<NUM;w++){
        for(x=0;x<NUM;x++){
            for(y=0;y<NUM;y++){
                for(z=0;z<NUM;z++){
                    if(x!=y){
                        if(x!=z){
                            if(y!=z){
                                if(grid_p[w][x]==grid_p[w][y]){
                                    if(grid_p[w][x]==grid_p[w][z]){
                                        printf("(%d,%d) ",w,x);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for(aa=0;aa<NUM;aa++){
        for(bb=0;bb<NUM;bb++){
            for(cc=0;cc<NUM;cc++){
                for(dd=0;dd<NUM;dd++){
                    if(bb!=cc){
                        if(bb!=dd){
                            if(cc!=dd){
                                if(grid_p[bb][aa]==grid_p[cc][aa]){
                                    if(grid_p[bb][aa]==grid_p[dd][aa]){
                                        printf("(%d,%d) ",bb,aa);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for(ee=0;ee<NUM;ee++){
        for(ff=0;ff<NUM;ff++){
            for(gg=0;gg<NUM;gg++){
                for(hh=0;hh<NUM;hh++){
                    if(ff!=gg){
                        if(ff!=hh){
                            if(gg!=hh){
                                if(grid_p[ee][ff]==grid_p[ee][gg]){
                                    if(grid_p[ee][ff]==grid_p[ee][hh]){
                                        printf("(%d,%d) ",ee,ff);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for(ii=0;ii<NUM;ii++){
        for(jj=0;jj<NUM;jj++){
            for(kk=0;kk<NUM;kk++){
                for(ll=0;ll<NUM;ll++){
                    if(jj!=kk){
                        if(jj!=ll){
                            if(kk!=ll){
                                if(grid_p[jj][ii]==grid_p[kk][ii]){
                                    if(grid_p[jj][ii]==grid_p[ll][ii]){
                                        printf("(%d,%d) ",jj,ii);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}