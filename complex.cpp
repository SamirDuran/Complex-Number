#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Pi 3.1415926

typedef struct TAG_Complex
{
	double Real;
	double Imag;

}Complex;

Complex Complex_Add(Complex a,Complex b);
Complex Complex_Sub(Complex a,Complex b);
Complex Complex_Mul(Complex a,Complex b);
Complex Complex_Dev(Complex a,Complex b);
Complex Complex_Coj(Complex a);
double NormOfComplex(Complex a);
void PrintOfComplex(Complex a);
//
Complex Translation(Complex z,double offsetx,double offsety);
Complex Rotation(Complex z,double angle);
Complex Scale(Complex z,double xscale,double yscale);
//


void main()
{
	Complex a,b;

	a.Real = 5;   //5+7i
	a.Imag = 7;

	b.Real = 3;	  //3+2i
	b.Imag = 2;
	PrintOfComplex(Complex_Add(a,b));
	PrintOfComplex(Complex_Sub(a,b));
	PrintOfComplex(Complex_Mul(a,b));
	PrintOfComplex(Complex_Coj(a));
	PrintOfComplex(Rotation(a,Pi/2));
	PrintOfComplex(Scale(a,2,-1));
}



Complex Complex_Add(Complex a,Complex b)
{
	Complex temp;
//	temp->Real = 0 ;
//	temp->Imag = 0 ;  // init

	temp.Real = a.Real + b.Real;
	temp.Imag = a.Imag + b.Imag;
	return temp;
}

Complex Complex_Sub(Complex a,Complex b)
{
	Complex temp;
//	temp->Real = 0 ;
//	temp->Imag = 0 ;  // init

	temp.Real = a.Real - b.Real;
	temp.Imag = a.Imag - b.Imag;
	return temp;
}

Complex Complex_Mul(Complex a,Complex b)
{
	Complex temp ;
//	temp->Real = 0 ;
//	temp->Imag = 0 ;  // init

	temp.Real = (a.Real) *(b.Real) - (a.Imag)*(b.Imag);
	temp.Imag = (a.Real) *(b.Imag) + (a.Imag)*(b.Real);
	return temp;
}

Complex Complex_Coj(Complex a)
{
	Complex temp ;
//	temp->Real = 0 ;
//	temp->Imag = 0 ;  // init

	temp.Real = a.Real;
	temp.Imag = a.Imag * (-1);
	return temp;
}

double NormOfComplex(Complex a)
{
	double temp;
	temp = sqrt((a.Real)*(a.Real)+(a.Imag)*(a.Imag));
	return temp;
}

Complex Complex_Dev(Complex a,Complex b)
{
	Complex tempz ;

	double den = b.Real * b.Real + b.Imag * b.Imag ;

	tempz.Real = (a.Real * b.Real +a.Imag * b.Imag)/(den);
	tempz.Imag = (a.Imag * b.Real -a.Real * b.Imag)/(den);

	return tempz;
}

void PrintOfComplex(Complex a)
{

	if( (a.Imag > 0) && (a.Real != 0))
	{
	printf("result = %2.2f+%2.2fi\n",a.Real,a.Imag);
	}
	else if((a.Imag < 0 )&&(a.Real != 0 ))
	{
	printf("result = %2.2f%2.2fi\n",a.Real,a.Imag);
	}
	else if((a.Real == 0 )&&(a.Imag != 0))
	{
	printf("result = %2.2fi\n",a.Imag);
	}
	else if((a.Imag == 0)&&(a.Real != 0))
	{
	printf("result = %2.2f\n",a.Real);
	}
	else
	{
	printf("result = 0\n");
	}
}

Complex Translation(Complex z,double offsetx,double offsety)
{
	Complex tempz = z;

	tempz.Real += offsetx;
	tempz.Imag += offsety;

	return tempz;
}


Complex Rotation(Complex z,double angle)
{
	Complex tempz = z;

	tempz.Real = z.Real * cos(angle) - z.Imag * sin(angle);
	tempz.Imag = z.Real * sin(angle) + z.Imag * cos(angle);

	return tempz;
}

Complex Scale(Complex z,double xscale,double yscale)
{
	Complex tempz = z;

	tempz.Real *= xscale;
	tempz.Imag *= yscale;

	return tempz;
}
