#include<stdio.h>
#define MAX 10000
int multi(int a,int res[],int size,int c){
    int carry=0;
    int p;
    for(int i=0;i<size;i++){
        p=(res[i]*a+carry)%c;
        res[i]=p%10;
        carry=p/10;
    }
    while(carry){
        res[size]=carry%10;
        carry/=10;
        size++;
    }
    return size;
}
void pow_cal(int a,int b,int c){
    if(b==0){
        printf("1");
        return;
    }
    int res[MAX];
    int size=0;
    int base=a;
    while(base!=0){
        res[size++]=base%10;
        base=base/10;
    }
    for(int i=2;i<=b;i++){
        size=multi(a,res,size,c);
    }
    printf("%d ^ %d %% %d = ",a,b,c);
    for(int i=size-1;i>=0;i--){
        printf("%d",res[i]);
    }

}
int main(){
    int a,b,c;
    printf("Enter Base, Exp and MOD");
    scanf("%d%d%d",&a,&b,&c);
    pow_cal(a,b,c);

}