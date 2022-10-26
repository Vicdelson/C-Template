#include <stdio.h>
#include <math.h>

int main(){
    long n,k=0;
    int d1,d2,d3,d4,ans[16];
    scanf("%ld",&n);
    scanf("%d %d %d %d",&d1,&d2,&d3,&d4);
    int sum=d1+d2+d3+d4;
    char nc[32],temp[32],check[32];
    for(int i=0;i<32;i++)nc[i]='0';
    for(int i=0;i<32;i++)temp[i]='0';
    for(int i=31;i>=0;i--){
    	if(n%2)nc[i]='1';
        n/=2;
    }
    for(int i=1;i<9;i++){
    	if(nc[i+d1*8-9]==nc[i+d2*8-9]){
        	temp[i-1]='0';
        }else{
        	temp[i-1]='1';
        }
    }//step2
    for(int i=1;i<9;i++){
    	if(nc[i+d2*8-9]=='1'&&nc[i+d3*8-9]=='1'){
        	temp[i+7]='1';
        }else{
        	temp[i+7]='0';
        }
    }//step3
    for(int i=1;i<9;i++){
    	if(nc[i+d3*8-9]=='1'||nc[i+d1*8-9]=='1'){
        	temp[i+15]='1';
        }else{
        	temp[i+15]='0';
        }
    }//step4
    for(int i=1;i<9;i++){
    	if(nc[i+8*d4-9]=='1'){
        	temp[i+23]='0';
        }else{
        	temp[i+23]='1';
        }
    }//step5
    for(int i=0;i<32;i++){
        int k=(i+32-sum)%32;
        check[i]=temp[k];
    }//step6
    for(int i=0;i<16;i++){
    	if(check[i]==check[i+16]){
        	ans[i]=0;
        }else{
        	ans[i]=1;
        }
    }//step7
    for(int i=0;i<16;i++){
    	if(ans[i]){
            if(i==15){
            	k+=1;
            }else{
            	k+=pow(2,15-i);
            }
        }
    }
    printf("%ld",k);
}