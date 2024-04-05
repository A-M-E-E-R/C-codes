
int add(int x,int y);
int sub(int x,int y);
int mul(int x,int y);
int Div(int x,int y);
int add(int x,int y){
    if(x==0) return y;
    return add((x&y)<<1,x^y);
}
int sub(int x,int y){
    if(y==0) return x;
    return sub(x^y,(~x&y)<<1);
}
int mul(int x,int y){
    int r=0;
    while(y>0){
        if((y&1)!=0) r=add(r,x);
        x = x<<1;
        y = y>>1;
    }
    return r;
}
int Div(int x,int y){
    int r=0;
    while(x>=y){
        x = sub(x,y);
        r++;
    }
    return r;
}
