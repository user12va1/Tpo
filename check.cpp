#pragma once
#include "stdafx.h"
int check(double x,double y,int error)
{
	if (error==1)
		return 4;
	if ((x<0.61)&&(x>0)&&(x*x+y*y<1))
		return 0;
	else
		if (((x==0)&&(x*x+y*y<=1))||((x==0.61)&&(x*x+y*y<=1))||((x>=0)&&(x<=0.61)&&(x*x+y*y==1)))
			return 1;
		else
			return 2;
}