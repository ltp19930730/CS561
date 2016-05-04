/* Processed by ecpg (4.11.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "sdap_1.pgc"
/* Name:Tianpei Luo CWID:10408917
 * File - sdap.pgc (Need the .pgc extension!)
 *
 * Desc - This is a simple skeleton program using Embedded SQL to read all
 *        of the rows from the table "sales" and output to the console.
 *        Simple but it contains all of the essential features of ESQL
 *        discussed in class!
 *
 * Steps to run this program :
 *  1. In the program (L49), modify [dbname], [username], [password] to
 *     yours ([dbname] is the same as your [username] by default).
 *  2. Preprocessor - $ ecpg -I "C:\Program Files\PostgreSQL\9.4\include" sdap.pgc
 *  3. Compile      - $ gcc -c -I "C:\Program Files\PostgreSQL\9.4\include" sdap.c
 *  4. Link         - $ gcc -L "C:\Program Files\PostgreSQL\9.4\lib" -lecpg -o sdap sdap.o
 *  5. Execute      - $ .\sdap
 */

#include	<stdio.h>
#include <math.h>
//----------------------------------------------------------------------
// HOST VARIABLES definitions
//----------------------------------------------------------------------
/* exec sql begin declare section */
 
		
		
	    
	    
		   
		
		 
	

//----------------------------------------------------------------------
//  VARIABLES definitions for query 1
//----------------------------------------------------------------------

  
         
         
         
         
         
         
         
        
        
        




 
       



 
       


 
       


//----------------------------------------------------------------------
//  VARIABLES definitions for query 2 and query 3
//----------------------------------------------------------------------

  
         
         
         
         
         
         
        
        
        
        





#line 32 "sdap_1.pgc"
 struct { 
#line 25 "sdap_1.pgc"
 char * cust ;
 
#line 26 "sdap_1.pgc"
 char * prod ;
 
#line 27 "sdap_1.pgc"
 short dd ;
 
#line 28 "sdap_1.pgc"
 short mm ;
 
#line 29 "sdap_1.pgc"
 short yy ;
 
#line 30 "sdap_1.pgc"
 char * state ;
 
#line 31 "sdap_1.pgc"
 long quant ;
 } sale_rec ;
 
#line 50 "sdap_1.pgc"
 struct node { 
#line 39 "sdap_1.pgc"
 char cust [ 20 ] ;
 
#line 40 "sdap_1.pgc"
 char prod [ 20 ] ;
 
#line 41 "sdap_1.pgc"
 char state [ 3 ] ;
 
#line 42 "sdap_1.pgc"
 long sum_quant ;
 
#line 43 "sdap_1.pgc"
 long cust_avg ;
 
#line 44 "sdap_1.pgc"
 long other_state_sum ;
 
#line 45 "sdap_1.pgc"
 long other_prod_sum ;
 
#line 46 "sdap_1.pgc"
 short sum_times ;
 
#line 47 "sdap_1.pgc"
 short times_other_state ;
 
#line 48 "sdap_1.pgc"
 short times_other_prod ;
 } output [ 500 ] ;
 
#line 55 "sdap_1.pgc"
 struct node_name { 
#line 54 "sdap_1.pgc"
 char cust [ 20 ] ;
 } cust_name [ 10 ] ;
 
#line 60 "sdap_1.pgc"
 struct node_prod { 
#line 59 "sdap_1.pgc"
 char prod [ 20 ] ;
 } prod_name [ 20 ] ;
 
#line 64 "sdap_1.pgc"
 struct node_state { 
#line 63 "sdap_1.pgc"
 char state [ 5 ] ;
 } state_name [ 10 ] ;
 
#line 82 "sdap_1.pgc"
 struct node_1 { 
#line 71 "sdap_1.pgc"
 char cust [ 20 ] ;
 
#line 72 "sdap_1.pgc"
 char prod [ 20 ] ;
 
#line 73 "sdap_1.pgc"
 long sum_Q1 ;
 
#line 74 "sdap_1.pgc"
 long sum_Q2 ;
 
#line 75 "sdap_1.pgc"
 long sum_Q3 ;
 
#line 76 "sdap_1.pgc"
 long sum_Q4 ;
 
#line 77 "sdap_1.pgc"
 short times_Q1 ;
 
#line 78 "sdap_1.pgc"
 short times_Q2 ;
 
#line 79 "sdap_1.pgc"
 short times_Q3 ;
 
#line 80 "sdap_1.pgc"
 short times_Q4 ;
 } output_2 [ 50 ] ;
/* exec sql end declare section */
#line 85 "sdap_1.pgc"


#line 1 "D:\\PostgreSql\\include/sqlca.h"
#ifndef POSTGRES_SQLCA_H
#define POSTGRES_SQLCA_H

#ifndef PGDLLIMPORT
#if  defined(WIN32) || defined(__CYGWIN__)
#define PGDLLIMPORT __declspec (dllimport)
#else
#define PGDLLIMPORT
#endif   /* __CYGWIN__ */
#endif   /* PGDLLIMPORT */

#define SQLERRMC_LEN	150

#ifdef __cplusplus
extern		"C"
{
#endif

struct sqlca_t
{
	char		sqlcaid[8];
	long		sqlabc;
	long		sqlcode;
	struct
	{
		int			sqlerrml;
		char		sqlerrmc[SQLERRMC_LEN];
	}			sqlerrm;
	char		sqlerrp[8];
	long		sqlerrd[6];
	/* Element 0: empty						*/
	/* 1: OID of processed tuple if applicable			*/
	/* 2: number of rows processed				*/
	/* after an INSERT, UPDATE or				*/
	/* DELETE statement					*/
	/* 3: empty						*/
	/* 4: empty						*/
	/* 5: empty						*/
	char		sqlwarn[8];
	/* Element 0: set to 'W' if at least one other is 'W'	*/
	/* 1: if 'W' at least one character string		*/
	/* value was truncated when it was			*/
	/* stored into a host variable.             */

	/*
	 * 2: if 'W' a (hopefully) non-fatal notice occurred
	 */	/* 3: empty */
	/* 4: empty						*/
	/* 5: empty						*/
	/* 6: empty						*/
	/* 7: empty						*/

	char		sqlstate[5];
};

struct sqlca_t *ECPGget_sqlca(void);

#ifndef POSTGRES_ECPG_INTERNAL
#define sqlca (*ECPGget_sqlca())
#endif

#ifdef __cplusplus
}
#endif

#endif

#line 86 "sdap_1.pgc"


//----------------------------------------------------------------------
// FUNCTION PROTOTYPE declaration
//----------------------------------------------------------------------
//FUNTION FOR QUARY 1

void    showresult(int index);                                  //output records to the console
int ifexist_cust(int index,char* cust);
int ifexist_prod(int index,char* prod);
int ifexist_state(int index,char* state);
int thePosition(char* cust, char* prod, char* state,int index_output);
void countAvg(int index_output);


//----------------------------------------------------------------------
//FUNTION FOR QUARY 2
void showresult2(int index_output_2);
int thePosition_2(char* cust, char* prod,int index_output_2);

//----------------------------------------------------------------------
//FUNTION FOR QUARY 2
void showresult3(int index_output_2);



//----------------------------------------------------------------------
int main(int argc, char* argv[])
//----------------------------------------------------------------------
{

   int index_cust = 0;
   int index_prod = 0;
   int index_state = 0;
   int index_output = 0;
   int index_output_2 = 0;
   int pos =0;
   //----------------------------------------------------------------------
   // DATABASE CONNECTION
   //----------------------------------------------------------------------
   // EXEC SQL CONNECT TO PostgreSQL@localhost:5432 USER PostgreSQL IDENTIFIED BY XYZ;
   { ECPGconnect(__LINE__, 0, "postgres@localhost:5432" , "postgres" , NULL , NULL, 0); }
#line 127 "sdap_1.pgc"


   if (sqlca.sqlcode != 0) {	// login error
   	printf ("Login error!!!\n");
   	return -1;
   }
   /* exec sql whenever sqlerror  sqlprint ; */
#line 133 "sdap_1.pgc"


   //----------------------------------------------------------------------
   // READ RECORDS
   //----------------------------------------------------------------------
   /* declare mycursor cursor for select * from sales */
#line 138 "sdap_1.pgc"

   { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "set transaction read only", ECPGt_EOIT, ECPGt_EORT);
#line 139 "sdap_1.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 139 "sdap_1.pgc"

   // Open cursor
   { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare mycursor cursor for select * from sales", ECPGt_EOIT, ECPGt_EORT);
#line 141 "sdap_1.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 141 "sdap_1.pgc"

   // Fetch Data
   { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch from mycursor", ECPGt_EOIT, 
	ECPGt_char,&(sale_rec.cust),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(sale_rec.prod),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_short,&(sale_rec.dd),(long)1,(long)1,sizeof(short), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_short,&(sale_rec.mm),(long)1,(long)1,sizeof(short), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_short,&(sale_rec.yy),(long)1,(long)1,sizeof(short), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(sale_rec.state),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_long,&(sale_rec.quant),(long)1,(long)1,sizeof(long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 143 "sdap_1.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 143 "sdap_1.pgc"
 //fetch the first row

   while (sqlca.sqlcode == 0) {

     //Programming for query1

     //store the cust name in the cust_name struct
     if(ifexist_cust(index_cust,sale_rec.cust)==0){
        strcpy(cust_name[index_cust].cust,sale_rec.cust);
        index_cust++;
      }

     //store the prod name in the prod_name struct
     if(ifexist_prod(index_prod,sale_rec.prod)==0){
       strcpy(prod_name[index_prod].prod,sale_rec.prod);
       index_prod++;
     }

     //store the state name in the state_name struct
     if(ifexist_state(index_state,sale_rec.state)==0){
       strcpy(state_name[index_state].state,sale_rec.state);
       index_state++;
     }

      { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch from mycursor", ECPGt_EOIT, 
	ECPGt_char,&(sale_rec.cust),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(sale_rec.prod),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_short,&(sale_rec.dd),(long)1,(long)1,sizeof(short), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_short,&(sale_rec.mm),(long)1,(long)1,sizeof(short), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_short,&(sale_rec.yy),(long)1,(long)1,sizeof(short), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(sale_rec.state),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_long,&(sale_rec.quant),(long)1,(long)1,sizeof(long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 167 "sdap_1.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 167 "sdap_1.pgc"
 //fetch the rest rows
   }
   // Close cursor

   { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close mycursor", ECPGt_EOIT, ECPGt_EORT);
#line 171 "sdap_1.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 171 "sdap_1.pgc"


  //arrange the output array for three elements combination

   for(int i = 0;i < index_cust; ++i){
     for(int j = 0;j < index_prod; ++j){
       for(int k = 0;k < index_state; ++k){
          strcpy(output[index_output].cust,cust_name[i].cust);
          strcpy(output[index_output].prod,prod_name[j].prod);
          strcpy(output[index_output].state,state_name[k].state);
          index_output++;
       }
     }
   }

   //arrange the data structure for the query 2

   for(int i = 0; i < index_cust; ++i){
      for(int j = 0; j <index_prod; ++j){
        strcpy(output_2[index_output_2].cust,cust_name[i].cust);
        strcpy(output_2[index_output_2].prod,prod_name[j].prod);
        index_output_2++;
      }
   }

   { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare mycursor cursor for select * from sales", ECPGt_EOIT, ECPGt_EORT);
#line 196 "sdap_1.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 196 "sdap_1.pgc"

   // Fetch Data
   { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch from mycursor", ECPGt_EOIT, 
	ECPGt_char,&(sale_rec.cust),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(sale_rec.prod),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_short,&(sale_rec.dd),(long)1,(long)1,sizeof(short), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_short,&(sale_rec.mm),(long)1,(long)1,sizeof(short), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_short,&(sale_rec.yy),(long)1,(long)1,sizeof(short), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(sale_rec.state),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_long,&(sale_rec.quant),(long)1,(long)1,sizeof(long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 198 "sdap_1.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 198 "sdap_1.pgc"
 //fetch the first row

   while (sqlca.sqlcode == 0) {

     //Programming for query1

     pos=thePosition(sale_rec.cust, sale_rec.prod, sale_rec.state,index_output);
     output[pos].sum_quant+=sale_rec.quant;
     output[pos].sum_times++;


     //Programming for query2
     int pos_2=thePosition_2(sale_rec.cust, sale_rec.prod,index_output_2);
     if(sale_rec.mm<=3){
        output_2[pos_2].sum_Q1+=sale_rec.quant;
        output_2[pos_2].times_Q1++;
     }else if(sale_rec.mm > 3 && sale_rec.mm <=6){
        output_2[pos_2].sum_Q2+=sale_rec.quant;
        output_2[pos_2].times_Q2++;
    }else if(sale_rec.mm > 6 && sale_rec.mm <=9){
        output_2[pos_2].sum_Q3+=sale_rec.quant;
        output_2[pos_2].times_Q3++;
    }else{
        output_2[pos_2].sum_Q4+=sale_rec.quant;
        output_2[pos_2].times_Q4++;
    }


      { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch from mycursor", ECPGt_EOIT, 
	ECPGt_char,&(sale_rec.cust),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(sale_rec.prod),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_short,&(sale_rec.dd),(long)1,(long)1,sizeof(short), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_short,&(sale_rec.mm),(long)1,(long)1,sizeof(short), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_short,&(sale_rec.yy),(long)1,(long)1,sizeof(short), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(sale_rec.state),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_long,&(sale_rec.quant),(long)1,(long)1,sizeof(long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 226 "sdap_1.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 226 "sdap_1.pgc"
 //fetch the rest rows
   }
   // Close cursor

   { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close mycursor", ECPGt_EOIT, ECPGt_EORT);
#line 230 "sdap_1.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 230 "sdap_1.pgc"

   countAvg(index_output);
   showresult(index_output);
   showresult2(index_output_2);
   showresult3(index_output_2);


   return 0;
}

//----------------------------------------------------------------------
//function for query 1
//----------------------------------------------------------------------

void showresult(int index_output){

   printf("Report #1:\n");
   printf(" CUSTOMER    PRODUCT   STATE   CUST_AVG   OTHER_STATE_AVG   OTHER_PROD_AVG  \n");
   printf(" ========    =======   =====   ========   ===============   ==============  \n");
   for(int i=0;i<index_output;i++){


   if(output[i].sum_quant!=0){
   printf(" %-8s   ",output[i].cust);        // Customer
   printf(" %-7s  ",output[i].prod);     // Product
   printf(" %-2s     ",output[i].state);       // State
   int cust_avg = round(output[i].sum_quant*1.0/output[i].sum_times);
        printf("    %5d",cust_avg);
     }else{
	continue;
        printf("   NULL    ");
    }

   if(output[i].other_state_sum!=0){
    int other_state_avg = round(output[i].other_state_sum*1.0/output[i].times_other_state);
        printf("            %6d",other_state_avg);
     }else{
        printf("          NULL    ");
    }

    if(output[i].other_prod_sum!=0){
     int other_prod_avg = round(output[i].other_prod_sum*1.0/output[i].times_other_prod);
         printf("           %6d \n",other_prod_avg);
      }else{
         printf("        NULL   \n");
     }
   }
}


int ifexist_cust(int index,char* cust){
    for(int i = 0;i < index;i++){
        if(strcmp(cust_name[i].cust,cust)==0){
          return 1;
        }
      }
    return 0;
}

int ifexist_prod(int index,char* prod){
    for(int i = 0;i < index;i++){
        if(strcmp(prod_name[i].prod,prod)==0){
          return 1;
        }
      }
    return 0;
}

int ifexist_state(int index,char* state){
    for(int i = 0;i < index;i++){
        if(strcmp(state_name[i].state,state)==0){
          return 1;
        }
      }
    return 0;
}

int thePosition(char* cust, char* prod, char* state,int index_output){
     for(int i=0;i<index_output;i++){
        int flag=strcmp(output[i].cust,cust);
        int flag_1=strcmp(output[i].prod,prod);
        int flag_2=strcmp(output[i].state,state);
        if(flag==0&&flag_1==0&&flag_2==0){
           return i;
        }
     }
}

void countAvg(int index_output){
    for(int i=0;i<index_output;++i){
          for(int j=0;j<index_output;++j){
           int flag=strcmp(output[j].cust,output[i].cust);
           int flag_1=strcmp(output[j].prod,output[i].prod);
           int flag_2=strcmp(output[j].state,output[i].state);
            if(flag==0&&flag_1==0&&flag_2!=0){
               output[i].other_state_sum+=output[j].sum_quant;
               output[i].times_other_state+=output[j].sum_times;
            }
            if(flag==0&&flag_1!=0&&flag_2==0){
               output[i].other_prod_sum+=output[j].sum_quant;
               output[i].times_other_prod+=output[j].sum_times;
            }
        }
    }
}
//----------------------------------------------------------------------
// function for query 2
//----------------------------------------------------------------------

void showresult2(int index_output_2){

  printf("Report #2:\n");
  printf(" CUSTOMER    PRODUCT   QUARTER   BEFORE_AVG   AFTER_AVG\n");
  printf(" ========    =======   =======   ==========   =========\n");
   for(int i=0;i<index_output_2;i++){
    for(int j=0;j<4;j++){

      if(j==0){
        printf(" %-8s   ",output_2[i].cust);        // Customer
        printf(" %-7s  ",output_2[i].prod);         // Product
        printf("      Q");
        printf("%d    ",j+1);
        printf("   <NULL>");
        if(output_2[i].sum_Q2!=0){
             int avg_Q2=round(output_2[i].sum_Q2*1.0/output_2[i].times_Q2);
             printf("        %4d\n",avg_Q2);
           }else{
             printf("      <NULL>\n");
         }
      }
      if(j==1){
        if(output_2[i].sum_Q1!=0&&output_2[i].sum_Q3!=0){
          int avg_Q1=round(output_2[i].sum_Q1*1.0/output_2[i].times_Q1);
          int avg_Q3=round(output_2[i].sum_Q3*1.0/output_2[i].times_Q3);
          if(avg_Q1<=avg_Q3){
            printf(" %-8s   ",output_2[i].cust);        // Customer
            printf(" %-7s  ",output_2[i].prod);         // Product
            printf("      Q");
            printf("%d    ",j+1);
            printf("     %4d",avg_Q1);
            printf("        %4d\n",avg_Q3);
          }
        }else if(output_2[i].sum_Q1==0&&output_2[i].sum_Q3!=0){
          int avg_Q3=round(output_2[i].sum_Q3*1.0/output_2[i].times_Q3);
          printf(" %-8s   ",output_2[i].cust);        // Customer
          printf(" %-7s  ",output_2[i].prod);         // Product
          printf("      Q");
          printf("%d    ",j+1);
          printf("   <NULL>");
          printf("        %4d\n",avg_Q3);
        }else if(output_2[i].sum_Q1!=0&&output_2[i].sum_Q3==0){
          int avg_Q1=round(output_2[i].sum_Q1*1.0/output_2[i].times_Q1);
          printf(" %-8s   ",output_2[i].cust);        // Customer
          printf(" %-7s  ",output_2[i].prod);         // Product
          printf("      Q");
          printf("%d    ",j+1);
          printf("     %4d",avg_Q1);
          printf("      <NULL>\n");
        }else if(output_2[i].sum_Q1==0&&output_2[i].sum_Q3==0){
          printf(" %-8s   ",output_2[i].cust);        // Customer
          printf(" %-7s  ",output_2[i].prod);         // Product
          printf("      Q");
          printf("%d    ",j+1);
          printf("   <NULL>");
          printf("      <NULL>\n");
        }
      }
      if(j==2){
      if(output_2[i].sum_Q2!=0&&output_2[i].sum_Q4!=0){
        int avg_Q2=round(output_2[i].sum_Q2*1.0/output_2[i].times_Q2);
        int avg_Q4=round(output_2[i].sum_Q4*1.0/output_2[i].times_Q4);
        if(avg_Q2<=avg_Q4){
          printf(" %-8s   ",output_2[i].cust);        // Customer
          printf(" %-7s  ",output_2[i].prod);         // Product
          printf("      Q");
          printf("%d    ",j+1);
          printf("     %4d",avg_Q2);
          printf("        %4d\n",avg_Q4);
        }
      }else if(output_2[i].sum_Q2==0&&output_2[i].sum_Q4!=0){
        int avg_Q4=round(output_2[i].sum_Q4*1.0/output_2[i].times_Q4);
        printf(" %-8s   ",output_2[i].cust);        // Customer
        printf(" %-7s  ",output_2[i].prod);         // Product
        printf("      Q");
        printf("%d    ",j+1);
        printf("   <NULL>");
        printf("        %4d\n",avg_Q4);
      }else if(output_2[i].sum_Q2!=0&&output_2[i].sum_Q4==0){
        int avg_Q2=round(output_2[i].sum_Q2*1.0/output_2[i].times_Q2);
        printf(" %-8s   ",output_2[i].cust);        // Customer
        printf(" %-7s  ",output_2[i].prod);         // Product
        printf("      Q");
        printf("%d    ",j+1);
        printf("     %4d",avg_Q2);
        printf("      <NULL>\n");
      }else if(output_2[i].sum_Q2==0&&output_2[i].sum_Q4==0){
        printf(" %-8s   ",output_2[i].cust);        // Customer
        printf(" %-7s  ",output_2[i].prod);         // Product
        printf("      Q");
        printf("%d    ",j+1);
        printf("   <NULL>");
        printf("      <NULL>\n");
      }
      }
      if(j==3){
        printf(" %-8s   ",output_2[i].cust);        // Customer
        printf(" %-7s  ",output_2[i].prod);         // Product
        printf("      Q");
        printf("%d    ",j+1);
        if(output_2[i].sum_Q3!=0){
            int avg_Q3=round(output_2[i].sum_Q3*1.0/output_2[i].times_Q3);
            printf("     %4d",avg_Q3);
            }else{
            printf("   <NULL>");
       }
            printf("      <NULL>\n");
      }
     }
   }
}

int thePosition_2(char* cust, char* prod,int index_output_2){
    for(int i=0;i<index_output_2;i++){
      int flag=strcmp(output_2[i].cust,cust);
      int flag_1=strcmp(output_2[i].prod,prod);
      if(flag==0 && flag_1==0){
            return i;
        }
      }
}

//----------------------------------------------------------------------
// function for query 3
//----------------------------------------------------------------------
void showresult3(int index_output_2){

  printf("Report #3:\n");
  printf(" CUSTOMER    PRODUCT   1/3 QUART PURCHASED BY\n");
  printf(" ========    =======   ======================\n");
  for(int i = 0;i < index_output_2; ++i){
      int sum=0;
      int temp=output_2[i].sum_Q1;
      sum = output_2[i].sum_Q1+output_2[i].sum_Q2+output_2[i].sum_Q3+output_2[i].sum_Q4;
      if(temp>sum/3){
        printf(" %-8s   ",output_2[i].cust);        // Customer
        printf(" %-7s  ",output_2[i].prod);         // Product
        printf(" Q1 \n");
        continue;
      }
      temp+=output_2[i].sum_Q2;
      if(temp>sum/3){
        printf(" %-8s   ",output_2[i].cust);        // Customer
        printf(" %-7s  ",output_2[i].prod);         // Product
        printf(" Q2 \n");
        continue;
      }
      temp+=output_2[i].sum_Q3;
      if(temp>sum/3){
        printf(" %-8s   ",output_2[i].cust);        // Customer
        printf(" %-7s  ",output_2[i].prod);         // Product
        printf(" Q3 \n");
        continue;
      }
      printf(" %-8s   ",output_2[i].cust);        // Customer
      printf(" %-7s  ",output_2[i].prod);         // Product
      printf(" Q4  \n");

  }




}
