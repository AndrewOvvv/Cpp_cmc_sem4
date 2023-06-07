#include <cmath>
#include <iostream>
#include <ostream>
#include <string>
#include <sstream>
#include <iomanip>


namespace numbers 
{
    class complex {
    private:
        double real{}, imag{};

    public:
        complex (double re = 0, double im = 0) {
            complex::real = re;
            complex::imag = im;
        }

        complex (const std::string &s) {
            char c;
            std::stringstream loc_stream(s);
            loc_stream >> c >> complex::real >> c >> complex::imag >> c;
        }

        double re() const {
            return complex::real;
        } 

        double im() const {
            return complex::imag;
        }

        double abs2() const {
            return complex::real * complex::real + complex::imag * complex::imag;
        }

        double abs() const {
            return std::sqrt(abs2());
        }

        std::string to_string() const {
            std::stringstream loc_stream;
            loc_stream << std::setprecision(10) << "(" << real << "," << imag << ")";
            return loc_stream.str();
        }

        complex& operator += (const complex &other) {
            complex::real += other.real;
            complex::imag += other.imag;
            return *this;
        } 

        complex& operator -= (const complex &other) {
            complex::real -= other.real;
            complex::imag -= other.imag;
            return *this;
        }

        complex& operator *= (const complex &other) {
            double curr_real = complex::real;
            double curr_imag = complex::imag;
            complex::real = curr_real * other.real - curr_imag * other.imag;
            complex::imag = curr_real * other.imag + curr_imag * other.real;
            return *this;
        }

        complex& operator /= (const complex &other) {
            double curr_real = complex::real;
            double curr_imag = complex::imag;
            complex::real = curr_real * other.real + curr_imag * other.imag;
            complex::imag = -curr_real * other.imag + curr_imag * other.real;
            complex::real /= other.abs2();
            complex::imag /= other.abs2();
            return *this;
        }

               complex operator ~() const {
            return complex(complex::real, -complex::imag);
        }

        complex operator -() const {
            return complex(-complex::real, -complex::imag);
        }

    };
        
    complex operator + (const complex &cur, const complex &other) {
        complex current = cur;
        current += other;
        return current;
    }
    
    complex operator - (const complex &cur, const complex &other) {
        complex current = cur;
        current -= other;
        return current;
    }
    
    complex operator * (const complex &cur, const complex &other) {
        complex current = cur;
        current *= other;
        return current;
    }
    
    complex operator / (const complex &cur, const complex &other) {
        complex current = cur;
        current /= other;
        return current;
    }


    class comlex_stack {

    };
}
