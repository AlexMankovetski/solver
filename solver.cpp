#include "solver.hpp"
#include <exception>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <complex>

using namespace std;

namespace solver{
    //----------------------------------RealVariable_Solve_Function---------------------------------------------------------//
    double solver:: solve (RealVariable x){
        double ans=0;
        double temp = 0;
        if(x.v1==0 && x.v2==0 && x.v3!=0){
            throw runtime_error("This cannot be rigth, false equation");
        }
        temp=(x.v2)*(x.v2)-4*(x.v1)*(x.v3);
        if(temp<0){
            throw runtime_error("There is no real solution to this equation");
        }
        else{
            if(x.v1 == 0){
                ans = (x.v3*(-1))/(x.v2);
            }
            else{
                double temproot = sqrt(temp);
                ans = ((-1)*(x.v2)+temproot)/(2*(x.v1));
            }
        }
        return ans;
    }
            //operator (+)
            RealVariable solver::operator+ (const RealVariable& x, const RealVariable& y){
                return RealVariable(x.v1 + y.v1, x.v2 + y.v2, x.v3 + y.v3);
            }
            RealVariable solver::operator+ (const RealVariable& x, const double v3){
                return RealVariable(x.v1,x.v2,x.v3+v3);
            }
            RealVariable solver::operator+ (const double v3, const RealVariable& x){
                return RealVariable(x.v1,x.v2,x.v3+v3);
            }
            //operator (-)
            RealVariable solver::operator- (const RealVariable& x, const RealVariable& y){
                return RealVariable(x.v1 - y.v1, x.v2 - y.v2, x.v3 - y.v3);
            }
            RealVariable solver::operator- (const RealVariable& x, const double v3){
                return RealVariable(x.v1,x.v2,x.v3-v3);
            }
            RealVariable solver::operator- (const double v3, const RealVariable& x){
                return RealVariable(-x.v1 , -x.v2 , v3-x.v3);
            }
            //operator (/)
            RealVariable solver::operator/ (const RealVariable& x, const RealVariable& y){
                RealVariable temp(x.v1 , x.v2 , x.v3);
                if(temp.v1!= 0 && y.v1 != 0){
                    temp.v1 =0 ;
                    temp.v3= temp.v3 + temp.v1/temp.v1;
                }
                 if(temp.v1!= 0 && y.v2 != 0){
                    temp.v1 =0 ;
                    temp.v2= temp.v2 + temp.v1/temp.v2;
                }
                 if(temp.v2 != 0 && y.v2 != 0){
                    temp.v2 =0 ;
                    temp.v1= temp.v1 + temp.v2/temp.v2;
                }
                return temp;
            }
            RealVariable solver::operator/ (const RealVariable& x, const double v3){
                if(v3==0){
                    throw runtime_error("You cannot do this , It's illegal to divide with zero");
                }
                RealVariable temp(x.v1 , x.v2 , x.v3);
                if(x.v1!=0){
                    temp.v1 = temp.v1/v3;
                }
                    if(x.v2!=0){
                    temp.v2 = temp.v2/v3;
                }
                    if(x.v3!=0){
                    temp.v3 = temp.v3/v3;
                }
                return temp;
            }
            RealVariable solver::operator/ (const double v3, const RealVariable& x){
                RealVariable temp(x.v1 , x.v2 , x.v3);
                if(x.v1!=0){
                    temp.v1 = v3/temp.v1;
                }
                    if(x.v2!=0){
                    temp.v2 = v3/temp.v2;
                }
                    if(x.v3!=0){
                    temp.v3 = v3/temp.v3;
                }
                return temp;
            }
            //operator (*)
            RealVariable solver::operator* (const RealVariable& x, const double v3){
                return RealVariable(x.v1*v3, x.v2*v3,x.v3*v3);
            }
            RealVariable solver::operator* (const double v3, const RealVariable& x){
                return RealVariable(x.v1*v3, x.v2*v3,x.v3*v3);
            }
            //operator (^)
            RealVariable solver::operator^ (const RealVariable& x,const int p){
                if(p==0){return RealVariable(0,0,1);}
                if(p==1){return x;}
                if(p==2){return RealVariable(x.v1 + (x.v2*x.v2) ,0, x.v3);}
                if(p>2){
                    throw runtime_error("Don't know how to solve this equation yet...coming soon");
                }
            }
            //operator (==)
            RealVariable solver::operator== (const RealVariable& x, const RealVariable& y){
                RealVariable temp(x.v1 , x.v2 , x.v3);
                if(y.v1 != 0){
                    temp.v1 = x.v1 + (-1)*(y.v1);
                }
                if(y.v2 != 0){
                    temp.v2 = x.v2 + (-1)*(y.v2);
                }
                if(y.v3 != 0){
                    temp.v3 = x.v3 + (-1)*(y.v3);
                }
                return temp;
            }
            RealVariable solver::operator== (const RealVariable& x, const double v3){
                RealVariable temp(x.v1 , x.v2 , x.v3);
                temp.v3 =temp.v3 + (-1)*(v3);
                return temp;
            }
            RealVariable solver::operator== (const double v3, const RealVariable& x){
                RealVariable temp(x.v1 , x.v2 , x.v3);
                temp.v3 =temp.v3 + (-1)*(v3);
                return temp;
            }
//----------------------------------End_of_RealVariable_Solve_Function--------------------------------------------------// 
    complex<double> solver:: solve (ComplexVariable x){
        complex<double> ans=0;
        complex<double> temp = 0;
            if((x.v1==complex<double>(0,0)) && (x.v2==complex<double>(0,0)) && (x.v3!=complex<double>(0,0))){
                throw runtime_error("This cannot be rigth, false equation");
            }
            temp=(x.v2)*(x.v2)-(complex<double>(4,0)*(x.v1)*(x.v3));
          
            if(x.v1 == (complex<double>(0,0))){
                ans = ((complex<double>(-1))*(x.v3)/(x.v2));
            }
            else{
                complex<double>temproot = sqrt(temp);
                ans = (complex<double>(-1)*(x.v2)+temproot)/(complex<double>(2)*(x.v1));
            }

            return ans;
        }
            //operator (+)
            ComplexVariable operator+ (const ComplexVariable& x, const ComplexVariable& y){
                return ComplexVariable(x.v1 + y.v1, x.v2 + y.v2, x.v3 + y.v3);
            }
            ComplexVariable operator+ (const ComplexVariable& x, const std::complex<double> v3){
                return ComplexVariable(x.v1,x.v2,x.v3+v3);
            }
            ComplexVariable operator+ (const std::complex<double> v3, const ComplexVariable& x){
                return ComplexVariable(x.v1,x.v2,x.v3+v3);
            }
            ComplexVariable operator+ (double v3, const ComplexVariable& x){
                return ComplexVariable(x.v1,x.v2,x.v3+v3);
            }
            ComplexVariable operator+ (const ComplexVariable& x ,double v3){
                return ComplexVariable(x.v1,x.v2,x.v3+v3);
            }
            //operator (-)
            ComplexVariable operator- (const ComplexVariable& x, const ComplexVariable& y){
                return ComplexVariable(x.v1 - y.v1, x.v2 - y.v2, x.v3 - y.v3);
            }
            ComplexVariable operator- (const ComplexVariable& x, const std::complex<double> v3){
                return ComplexVariable(x.v1,x.v2,x.v3-v3);
            }
            ComplexVariable operator- (const std::complex<double> v3, const ComplexVariable& x){
                return ComplexVariable(-x.v1 , -x.v2 , v3-x.v3);
            }
            ComplexVariable operator- (double v3, const ComplexVariable& x){
                return ComplexVariable(x.v1,x.v2,x.v3-v3);
            }
            ComplexVariable operator- (const ComplexVariable& x ,double v3){
                return ComplexVariable(-x.v1 , -x.v2 , v3-x.v3);
            }
            //operator (/)
            ComplexVariable solver::operator/ (const ComplexVariable &x , const ComplexVariable &y){
	            ComplexVariable temp(x.v1, x.v2, x.v3);
	            if (temp.v1 != std::complex<double> (0) && y.v1 != std::complex<double> (0) ){
                    temp.v1 =0;
                    temp.v3 = temp.v3 + temp.v1/y.v1;
                }
                if (temp.v1 != std::complex<double> (0) && y.v2 != std::complex<double> (0) ){
                    temp.v1 =0;
                    temp.v2 = temp.v2 + temp.v1/y.v2;   
                }
                if (temp.v2 != std::complex<double> (0) && y.v2 != std::complex<double> (0)){
                    temp.v3= temp.v3 + temp.v2/y.v2;
                    temp.v2 =0;
                }
                return temp;
            }
            ComplexVariable solver::operator/ (const ComplexVariable &x , std::complex<double> v3){
	            return ComplexVariable(x.v1/v3, x.v2/v3, x.v3/v3);
            }
            ComplexVariable solver::operator/ ( std::complex<double> v3 ,const ComplexVariable &x){
	            return ComplexVariable(v3/x.v1, v3/x.v2, v3/x.v3);
            }
            ComplexVariable solver::operator/ (const ComplexVariable &x , double v3){
	            return ComplexVariable(x.v1/v3, x.v2/v3, x.v3/v3);
            }
            ComplexVariable solver::operator/ ( double v3 ,const ComplexVariable &x){
	            return ComplexVariable(v3/x.v1, v3/x.v2, v3/x.v3);
            }

            //operator (*)
            ComplexVariable solver::operator* (const ComplexVariable& x, const std::complex<double> v3){
                return ComplexVariable(x.v1*v3, x.v2*v3,x.v3*v3);
            }
            ComplexVariable solver::operator* (const std::complex<double> v3, const ComplexVariable& x){
                return ComplexVariable(x.v1*v3, x.v2*v3,x.v3*v3);
            }
            ComplexVariable solver::operator* (double v3, const ComplexVariable& x){
                return ComplexVariable(x.v1*v3, x.v2*v3,x.v3*v3);
            }
            ComplexVariable solver::operator* (const ComplexVariable& x ,double v3){
                return ComplexVariable(x.v1*v3, x.v2*v3,x.v3*v3);
            }
            //operator (^)
            ComplexVariable solver::operator^ (const ComplexVariable& x,const int p){
                if(p==0){return ComplexVariable(0,0,1);}
                if(p==1){return x;}
                if(p==2){return ComplexVariable(x.v1 + (x.v2*x.v2) ,0, x.v3);}
                if(p>2){
                    throw runtime_error("Don't know how to solve this equation yet...coming soon");
                }
            }
            //operator (==)
            ComplexVariable solver::operator== (const ComplexVariable& x, const ComplexVariable& y){
             ComplexVariable temp(x.v1, x.v2, x.v3);
	            if (y.v1 !=std::complex<double> (0)){
                    temp.v1 = x.v1 + (std::complex<double> (-1)*y.v1); 
                }
	            if (y.v2 !=std::complex<double> (0)){ 
                    temp.v2 = x.v2 + (std::complex<double> (-1)*y.v2); 
                }
	            if (y.v3 !=std::complex<double> (0)){ 
                    temp.v3 = x.v3 + (std::complex<double> (-1)*y.v3); 
                }
	            return temp;

            }
            ComplexVariable solver::operator== (const ComplexVariable& x, std::complex<double> v3){
                ComplexVariable temp(x.v1 , x.v2 , x.v3);
                temp.v3 =temp.v3 + (std::complex<double>(-1)*(v3));
                return temp;
            }
            ComplexVariable solver::operator== (const std::complex<double> v3, const ComplexVariable& x){
                ComplexVariable temp(x.v1 , x.v2 , x.v3);
                temp.v3 =temp.v3 + (std::complex<double>(-1)*(v3));
                return temp;
            }
            ComplexVariable solver::operator== (double v3, const ComplexVariable& x){
                ComplexVariable temp(x.v1 , x.v2 , x.v3);
                temp.v3 =temp.v3 + (std::complex<double>(-1)*(v3));
                return temp;
            }
            ComplexVariable solver::operator== (const ComplexVariable& x ,double v3){
                ComplexVariable temp(x.v1 , x.v2 , x.v3);
                temp.v3 =temp.v3 + (std::complex<double>(-1)*(v3));
                return temp;
            }   
}//namespace solver
