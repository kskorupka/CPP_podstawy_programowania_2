#include <iostream>
void Addition1(int const A,int const B,int* __restrict C){
    *C=A+B;
}
void Addition2(const int* A, const int* B, int* __restrict C){
    *C=*A+*B;
}
void Addition3(int const &A, int const &B, int* __restrict C){
    *C=A+B;
}
void Addition4(const int *&A,const int *&B, int* __restrict C){
    *C=*A+*B;
}
void AddArrays1(const int A[10], const int B[10],int* C){ 
    int i=0;
    while(i<10){
        *C=A[i]+B[i];
        i++;
        C++;
    }
}
void AddArrays2(const int* A,const int *B, int* __restrict C){
    int i=0;
    while(i<10){
        *C=*A+*B;
        A++;
        B++;
        C++;
        i++;
    }
}
void AddArrays3(const int (&A)[10],const int (&B)[10],int* __restrict C){
    int i=0;
    while(i<10){
        *C=A[i]+B[i];
        i++;
        C++;
    }
}
void AddArrays4(const int *(&A)[10],const int *(&B)[10],int* __restrict C){
    int i=0;
    while(i<10){
       
    }
}
int main(int argc, char *argv[])
{
    //a.i
    std::cout << "Hello world." << std::endl;
    int const a_1=5,b_1=7;
    int c_1;
    int* __restrict p_1=&c_1;
    Addition1(a_1,b_1,p_1);
    std::cout<<c_1<<std::endl;
    //a.ii
    int const a_2=13,b_2=9;
    const int* p_a=&a_2;
    const int* p_b=&b_2;
    int c_2;
    int* __restrict p_2=&c_2;
    Addition2(p_a,p_b,p_2);
    std::cout<<c_2<<std::endl;
    //a.iii
    int const a_3=10,b_3=14;
    int const &r_a_3=a_3,&r_b_3=b_3;
    int c_3;
    int* __restrict p_3=&c_3;
    Addition3(r_a_3,r_b_3,p_3);
    std::cout<<c_3<<std::endl;
    //a.iv
    int const a_4=2,b_4=4;
    int const &r_a_4=a_4,&r_b_4=b_4;
    const int *pointer_r_a=&r_a_4;
    const int *pointer_r_b=&r_b_4;
    int c_4;
    int* __restrict p_4=&c_4;
    Addition4(pointer_r_a,pointer_r_b,p_4);
    std::cout<<c_4<<std::endl;
    //b.i
    const int a1[10]={1,2,3,4,5,6,7,8,9,10},b1[10]={2,4,6,8,10,12,14,16,18,20};
    int c1[10]={0};
    int* __restrict p1=c1;
    AddArrays1(a1,b1,p1);
    for(int i=0;i<10;i++) std::cout<<c1[i]<<" ";
    std::cout<<std::endl;
    //b.ii
    const int a2[10]={10,9,8,7,6,5,4,3,2,1},b2[10]={20,18,16,14,12,10,8,6,4,2};
    int c2[10]={0};
    const int*pa2=a2,*pb2=b2;
    int* __restrict p2=c2;
    AddArrays2(pa2,pb2,p2);
    for(int i=0;i<10;i++) std::cout<<c2[i]<<" ";
    std::cout<<std::endl;
    //b.iii
    const int a3[10]={1,3,5,7,9,11,13,15,17,19},b3[10]={1,2,3,4,5,6,7,8,9,10};
    int c3[10]={0};
    const int (&ra3)[10]=a3,(&rb3)[10]=b3;
    int* __restrict p3=c3;
    AddArrays3(ra3,rb3,p3);
    for(int i=0;i<10;i++) std::cout<<c3[i]<<" ";
    std::cout<<std::endl;
    //b.iv
    const int a4[10]={19,17,15,13,11,9,7,5,3,1},b4[10]={10,9,8,7,6,5,4,3,2,1};
    int c4[10]={0};
    const int (&ra4)[10]=a4,(&rb4)[10]=b4;
    const int *pa4=ra4,*pb4=rb4;
    return 0;
}