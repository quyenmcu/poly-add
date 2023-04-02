#include <stdio.h>
#include <stdlib.h>

struct node
{
       int coe;
       int exp;
       struct node *next;
};



typedef struct node report;
int build_polynomial(report *kp);
void print_polyno(report *tp);
int poly_evaluate(int y);
int exponent(int x,int n);
void display(struct node *head);
	report f_link,g_link,*tp;

int main()
{

    	int k = 0;
    	build_polynomial(&f_link);
    	print_polyno(&f_link);
    	display(&f_link);
    	printf("\b\b \n");
   
   	printf("Enter the value of x:");
   	scanf(" %d", &k);
   
int ans = poly_evaluate( k );
printf("\n The output of f(%d) is %d.\n", k, ans);
}

int build_polynomial(report *kp)
{
	FILE* file;
	file = fopen("polynomial.txt","r");
	if (file == NULL) {
        printf("\n The file could "
               "not be opened");
        exit(1);
    }
	
	report *gp; 
	
	while(feof(file)==0) 
	{
		kp=&f_link;
		gp = (report *)malloc(sizeof(report));
    	gp->next=NULL;
    	fscanf(file,"%d",&gp->coe);
    	fscanf(file,"%d",&gp->exp); 
    		while(kp->next!=NULL){
			if(kp->next->exp > gp->exp)
				kp=kp->next;
	        else
				break;	
		}
		gp->next = kp->next;
		kp->next = gp;

		 } 	
		 
}

void display (struct node *head)	//method for reverse display nodes
{
  if (head == NULL)
    return;

  // print the list after head node 
  display (head->next);

  // After everything else is printed, print head 
   if(head!=&f_link)
     printf("%d x ^%d + ",head->coe,head->exp);
   
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

 	int total=0;

 	report *tp = &f_link;

 	while(tp!=NULL) { 

 		

		total= total + tp->coe * exponent(y,tp->exp);

		tp=tp->next; 

	} 

   return total;	



}



int exponent(int x, int n)
{

	int result=1;

	while (n != 0) {

		result *= x;

		--n;

	}

	return result;

}



