
#include <stdio.h>
#include <string.h>
int M,N,i,j,k,x,y,z;
int a,b;
typedef struct prefix
{
    char character;
    int no;
}prefix_str;


prefix_str* prefixfunc(prefix_str x[]);
int KMP(char l[],char m[],prefix_str n[]);

int main(){

    //printf("Enter N and M : ");
    scanf("%d %d",&N,&M);
    //printf("the values are %d %d\n",N,M);
    char Text[N];
    char Pattern[M];
    prefix_str prefix[M];
    //printf("enter string text: \n");
    scanf("%s",Text);
    //printf("enter string pattern: \n");
    scanf("%s",Pattern);
    if(strlen(Text)== 0){
        printf("enter non zero string");
        return 0;
    }
    if(strlen(Pattern)== 0){
        printf("enter non zero string");
        return 0;
    }
    //printf("text is: %s\n",Text);
    //printf("pattern is: %s\n",Pattern);
    for(i=0;i<M;i++){
        prefix[i].character = Pattern[i];
        prefix[i].no = -1;
    };
    prefixfunc(prefix);
    
    /*for(i=0;i<N;i++){
    printf("%c",prefix[i].character);
    printf("%d\n",prefix[i].no);
    };*/
    KMP(Text,Pattern,prefix);
return 0;}

prefix_str* prefixfunc(prefix_str prefix[]){
    int k = 0;
    int j = 1;
    for(j=1;j<N;j=j+1){
        if(prefix[k].character==prefix[j].character){
            //printf("%d %d\n",k,j);
            //printf("%d belongs to %c\n",i,prefix[i].character);
            //printf("k is %c, j is %c\n",prefix[k].character,prefix[j].character);
            prefix[j].no = k;
            k++;
        }
        else{
            i = 0;
            //prefixfunc(prefix);
        }
    }
    return prefix;
}

int KMP(char Text[],char Pattern[],prefix_str prefix[]){
    int y,z = 0;
    for (x =0;x<N;x++){
        if(y==M){
            printf("%d",x-y+1);
            return x-y+1;
        }
        if(Text[x]==prefix[y].character){
            y++;
        }
        else{
            if(prefix[y].no != -1){
            y = prefix[y].no;
            }
            else{
                y = 0;
            }
        }
    }
    printf(0);
    return 0;

}