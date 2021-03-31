#include <iostream>
#include "matrix.h"
std::ostream& operator<<(std::ostream& stm, const TwoDimensionMatrix& matrix) {
	for (int i = 0; i < 2; i++) {
		stm << "[ ";
		for (int j = 0; j < 2; j++) stm << matrix.get(i, j) << " ";
		stm << "]" << std::endl;
	}
	return stm;
}
int main() {
	TwoDimensionMatrix m1,m2;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			m1.set(i, j, i + j);
			m2.set(i, j,(i + j)+2);
		}
	}
	std::cout <<"m1: "<<std::endl<<m1<<std::endl<<"m2: "<<std::endl<<m2<<std::endl;
	TwoDimensionMatrix m3;
	m3 = m1 + m2;
	std::cout << "m1 + m2: "<<std::endl<<m3;
	m2 *= 3;
	std::cout<<std::endl<<"m2 *= 3: "<<std::endl<< m2;
    std::cout<<std::endl<<"m1 == m2 ??"<<std::endl;
	if (m1 == m2) std::cout << "true" << std::endl;
	else std::cout << "false" << std::endl;
	TwoDimensionMatrix m4(m1);
    std::cout<<std::endl<<"m4: "<<std::endl<<m4<<std::endl;
    std::cout<<"m1 == m4 ??"<<std::endl;
	if (m1 == m4) std::cout << "true" << std::endl;
	else std::cout << "false" << std::endl;
	m4 *= 2;
	std::cout<<std::endl<<"m4 *= 2: "<<std::endl << m4 << std::endl;
	TwoDimensionMatrix m5;
	m5 = m1 && m4;
	std::cout << "m1 && m4"<<std::endl<<m5<<std::endl;
}