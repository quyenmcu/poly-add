#include <stdio.h>
#include <stdlib.h>

struct node
{
       int coe;
       int exp;
       struct node *next;
};



typedef struct node report;
void build_polynomial(report *tp);
void print_polyno(report *tp);
int poly_evaluate(int y);


report f_link,g_link;

int main()
{
    	
    	int k = 0;
    	build_polynomial(&f_link);
    	print_polyno(&f_link);
   
   	printf("Enter the value of x:");
   	scanf(" %d", &k);
   
int ans = poly_evaluate( k );
printf("\n The output of f(%d) is %d.\n", k, ans);
}


void build_polynomial(report *tp)
{
     int i;
     	for(tp->next =NULL,i=0; i<5; i=i+1,tp=tp->next)
     {
        tp->next = (report *)malloc(sizeof(report));
        tp->next->next=NULL;
        tp->next->coe=rand()%10;
        tp->next->exp=i;
     }
}


void print_polyno(report *tp)
{
     while(tp->next!=NULL )
     {
          printf("%d x ^%d + ",tp->next->coe,tp->next->exp);
          tp=tp->next;
     }
     printf("\b\b \n");
}


int poly_evaluate( int y )
{
	int result = 0;
	report *tp = &f_link;
	int val;
	result = tp->next->coe*1;	
	tp =tp->next;
	val = 1;
	for(int i=1;i<5;i++,tp=tp->next){
		while(tp->next->exp!=0)
	{
		val = val*y;
		tp->next->exp = tp->next->exp-1;
	}
	result = result+val*tp->next->coe;
	val = 1;
	}
	return result;
}
