#include <stdio.h>
#include <stdlib.h>

struct node
{
       int coe;
       int exp;
       struct node *next;
};



typedef struct node report;
int build_polynomial(report *tp,report *kp,report *gp);
void print_polyno(report *tp);
void add_polyno(report *tp,report *kp,report *gp);
void outcome(report *gp);


report f_link,g_link,h_link;

int main()
{
    	
    	build_polynomial(&f_link,&g_link,&h_link);
		add_polyno(&f_link,&g_link,&h_link);
		outcome(&h_link);
			
}

int build_polynomial(report *tp,report *kp,report *gp)
{
	FILE* file;
	file = fopen("polynomial addition.txt","r");
	if(file == NULL){
		return 1;
	}
	int i = 0;
     for(kp->next =NULL; i<4;i=i+1,kp=kp->next)
     {
     	kp->next = (report *)malloc(sizeof(report));
       	kp->next->next=NULL;
       	fscanf(file,"%d",&kp->next->coe);
       	fscanf(file,"%d",&kp->next->exp);
	}
	 i = 0;
	for(tp->next =NULL; i<4;i=i+1,tp=tp->next)
     {
     	tp->next = (report *)malloc(sizeof(report));
       	tp->next->next=NULL;
       	fscanf(file,"%d",&tp->next->coe);
       	fscanf(file,"%d",&tp->next->exp);
	}
	 i = 0;
	 for(gp->next =NULL; i<6;i=i+1,gp=gp->next)
     {
     	gp->next = (report *)malloc(sizeof(report));
       	gp->next->next=NULL;
       	fscanf(file,"%d",&gp->next->coe);
       	fscanf(file,"%d",&gp->next->exp);
	}
}

void add_polyno(report *tp,report *kp,report *gp)
{
	
	int HighExp = 0;
	if(tp->next->exp > kp->next->exp)
		HighExp = tp->next->exp;
	else if(tp->next->exp < kp->next->exp)
		HighExp = kp->next->exp;
	else
		HighExp = tp->next->exp;
		
	int TmpExp = 0;
	TmpExp = HighExp;
	for(;TmpExp>=-1;TmpExp=TmpExp-1,gp = gp->next)
	{
		if(tp->next->exp==TmpExp)
		{
		gp->next->coe = gp->next->coe + tp->next->coe;
		tp = tp->next;
		}
	      if(TmpExp==0)
		  {
		    break;
		  }
			if(kp->next->exp==TmpExp)
	    	{
			gp->next->coe = gp->next->coe + kp->next->coe;
			kp = kp->next;
			}
		  
	}
}

void outcome(report *gp)
{
	printf("h(x) = f(x)+g(x) = ");
	while(gp->next!=NULL)
     {
          printf("%d x ^%d + ",gp->next->coe,gp->next->exp);
          gp=gp->next;
     }
     printf("\b\b \n");
}
