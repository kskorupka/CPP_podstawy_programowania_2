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
    return 0;
}