#include<stdio.h>
#include<math.h>

double calc(double x){
	double sine;
	sine=x*sin(x);
	return sine;
}

void mn(double x, double y){ //analyses the function x*sin(x) to find the local minima between x1 and x2
	double i, j, cur, aft, minx;
	double min = x;
	
	for(i=x; i<=y; i+=0.01){
		cur=calc(min);
		aft=calc(i+0.01);
		if(cur>aft){ //checks if the next value of sin(i) is smaller than the current minimum
			min=i+0.01;
			minx=aft;
			printf("Local minimum of %lf at %lf\n", minx, min);
		}
	}
	printf("Global minimum of %lf found at %lf\n", minx, min);
}

void mx(double x, double y){ //analyses the function x*sin(x) to find the local maxima between x1 and x2
	double i, j, cur, aft, maxx;
	double max = x;
	
	for(i=x; i<=y; i+=0.01){
		cur=calc(max);
		aft=calc(i+0.01);
		if(cur<aft){ //checks if the next value of sin(i) is greater than the current minimum
			max=i+0.01;
			maxx=aft;
			printf("Local maximum of %lf at %lf\n", maxx, max);
		}
	}
	printf("Global maximum of %lf found at %lf\n", maxx, max);
}

int main(){
	double x1, x2; //edges of the domain
	double x1r, x2r; //edges in rads
	double temp, min, max;
	
	printf("Enter the edges of the domain in degrees");
	scanf("%lf%lf", &x1, &x2);
	
	if(x2-x1<0){
		temp=x2;
		x2=x1;
		x1=temp;
	}
	
	x1r = x1*M_PI/180;
	x2r = x2*M_PI/180;
	
	mn(x1r, x2r);
	mx(x1r, x2r);
	
	return 0;
}
