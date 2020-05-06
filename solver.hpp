#include <complex>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;
namespace solver
{
    class RealVariable{
        private:
            int p0;//then the power = 0
            int p1;//then the power = 1
            int p2;//then the power = 2

        public:
            double v1,v2,v3;
            RealVariable(): v1(0) ,v2(1) ,v3(0){};
            RealVariable(double v1, double v2 , double v3) : v1(v1), v2(v2),v3(v3){};
            //operator (+)
            friend RealVariable operator+(const RealVariable& x, const RealVariable& y);
            friend RealVariable operator+(const RealVariable& x, const double v3);
            friend RealVariable operator+(const double v3, const RealVariable& x);
            //operator (-)
            friend RealVariable operator-(const RealVariable& x, const RealVariable& y);
            friend RealVariable operator-(const RealVariable& x, const double v3);
            friend RealVariable operator-(const double v3, const RealVariable& x);
            //operator (/)
            friend RealVariable operator/(const RealVariable& x, const RealVariable& y);
            friend RealVariable operator/(const RealVariable& x, const double v3);
            friend RealVariable operator/(const double v3, const RealVariable& x);
            //operator (*)
            friend RealVariable operator*(const RealVariable& x, const double v3);
            friend RealVariable operator*(const double v3, const RealVariable& x);
            //operator (^)
            friend RealVariable operator^(const RealVariable& x,const int p);
            //operator (==)
            friend RealVariable operator==(const RealVariable& x, const RealVariable& y);
            friend RealVariable operator==(const RealVariable& x, const double v3);
            friend RealVariable operator==(const double v3, const RealVariable& x);     
    };//RealVariable

    class ComplexVariable{
        private :
            complex<int> p0;
            complex<int> p1;
            complex<int> p2;
        public :
            complex<double> v1,v2,v3;
            ComplexVariable(): v1(0) ,v2(1) ,v3(0){};
            ComplexVariable(complex<double> v1, complex<double> v2 , complex<double> v3) : v1(v1), v2(v2),v3(v3){};
            //operator (+)
            friend ComplexVariable operator+(const ComplexVariable& x, const ComplexVariable& y);
            friend ComplexVariable operator+(const ComplexVariable& x, const std::complex<double> v3);
            friend ComplexVariable operator+(const std::complex<double> v3, const ComplexVariable& x);
            friend ComplexVariable operator+(double v3, const ComplexVariable& x);
            friend ComplexVariable operator+(const ComplexVariable& x ,double v3);
            //operator (-)
            friend ComplexVariable operator-(const ComplexVariable& x, const ComplexVariable& y);
            friend ComplexVariable operator-(const ComplexVariable& x, const std::complex<double> v3);
            friend ComplexVariable operator-(const std::complex<double> v3, const ComplexVariable& x);
            friend ComplexVariable operator-(double v3, const ComplexVariable& x);
            friend ComplexVariable operator-(const ComplexVariable& x ,double v3);
            //operator (/)
            friend ComplexVariable operator/(const ComplexVariable& x, const ComplexVariable& y);
            friend ComplexVariable operator/(const ComplexVariable& x, const std::complex<double> v3);
            friend ComplexVariable operator/(const std::complex<double> v3, const ComplexVariable& x);
            friend ComplexVariable operator/(double v3, const ComplexVariable& x);
            friend ComplexVariable operator/(const ComplexVariable& x ,double v3);
            //operator (*)
            friend ComplexVariable operator*(const ComplexVariable& x, const std::complex<double> v3);
            friend ComplexVariable operator*(const std::complex<double> v3, const ComplexVariable& x);
            friend ComplexVariable operator*(double v3, const ComplexVariable& x);
            friend ComplexVariable operator*(const ComplexVariable& x ,double v3);
            //operator (^)
            friend ComplexVariable operator^(const ComplexVariable& x,const int p);
            //operator (==)
            friend ComplexVariable operator==(const ComplexVariable& x, const ComplexVariable& y);
            friend ComplexVariable operator==(const ComplexVariable& x, std::complex<double> v3);
            friend ComplexVariable operator==(const std::complex<double> v3, const ComplexVariable& x);
            friend ComplexVariable operator==(double v3, const ComplexVariable& x);
            friend ComplexVariable operator==(const ComplexVariable& x ,double v3);
    };//ComplexVariable
    double solve (RealVariable x);
    complex<double> solve (ComplexVariable x);
;} // namespace solver

