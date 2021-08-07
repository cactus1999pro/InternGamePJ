#include<cstdio>
void swap(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}
int main(){
int val1;
int val2;
scanf("%d %d", &val1 , &val2);
swap(val1, val2);
printf("val1 = %d", "val2 = %d", val1 , val2);
}