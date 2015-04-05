#pragma once
#include "stdafx.h"
int check(double x,double y,int error)
{
	if (error==1)
		return 4;
	if ((y<0.2)&&(y>0)&&(x*x+y*y<1))
		return 0;
	else
		if (((y==0)&&(x*x+y*y<=1))||((y==0.2)&&(x*x+y*y<=1))||((y>=0)&&(y<=0.2)&&(x*x+y*y==1)))

			return 1;
		else
			return 2;
}