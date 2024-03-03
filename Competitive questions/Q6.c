 #include<stdio.h>
 int main(){
    int N;
    scanf("%d",&N);
    int a[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&a[i][j]);
        }
    }
    if(N==1){
        printf("%d",a[0][0]);
    }
    else if(N==2){
        for(int j=0;j<N;j++){
            printf(" %d",a[0][j]);
        }
        for(int j=N-1;j>=0;j--){
            printf(" %d",a[1][j]);
        }
    }
    else{
        int i=0,j=0,Nj=N,Ni=N,jj=1,ii=1,c=0;
        while(i!=N/2 && ((N%2)?j!=(N/2):j!=((N/2)-1))){
            for(;(jj>0)?j<Nj:j>=N-Nj-1;j+=jj){
                if(c){
                    c--;
                    continue;
                }
                printf("\t %d",a[i][j]);
            }
            c=1;
            if(j==Nj){
                jj*=-1;
                Nj--;
                j--;
            }
            if(j==N-Nj-2) {
                jj*=-1;
                j++;
            }
            for(;(ii>0)?i<Ni:i>=N-Ni;i+=ii){
                if(c){
                    c--;
                    continue;
                }
                printf("\t %d",a[i][j]);
            }
            c=1;
            if(i==Ni){
                ii*=-1;
                Ni--;
                i--;
            }
            if(i==N-Ni-1){
                ii*=-1;
                i++;
            }
        }
        if(N%2)
            printf("\t %d",a[i][++j]);
        else
            printf("\t %d",a[i][--j]);
    }
 }