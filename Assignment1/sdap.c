/* Processed by ecpg (4.11.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "sdap.pgc"
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

//----------------------------------------------------------------------
// HOST VARIABLES definitions
//----------------------------------------------------------------------
/* exec sql begin declare section */
 
		
		
	    
	    
		 
		
		 
	

//----------------------------------------------------------------------
//  VARIABLES definitions for query 1
//----------------------------------------------------------------------

  
         
         
         
          
          
          
          
          
          
          
          
          




#line 32 "sdap.pgc"
 struct { 
#line 25 "sdap.pgc"
 char * cust ;
 
#line 26 "sdap.pgc"
 char * prod ;
 
#line 27 "sdap.pgc"
 short dd ;
 
#line 28 "sdap.pgc"
 short mm ;
 
#line 29 "sdap.pgc"
 short yy ;
 
#line 30 "sdap.pgc"
 char * state ;
 
#line 31 "sdap.pgc"
 long quant ;
 } sale_rec ;
 
#line 51 "sdap.pgc"
 struct node { 
#line 39 "sdap.pgc"
 char cust [ 20 ] ;
 
#line 40 "sdap.pgc"
 char prod [ 20 ] ;
 
#line 41 "sdap.pgc"
 char state [ 3 ] ;
 
#line 42 "sdap.pgc"
 int sum_q ;
 
#line 43 "sdap.pgc"
 int sum_q_os ;
 
#line 44 "sdap.pgc"
 int sum_q_op ;
 
#line 45 "sdap.pgc"
 int count_q ;
 
#line 46 "sdap.pgc"
 int count_q_os ;
 
#line 47 "sdap.pgc"
 int count_q_op ;
 
#line 48 "sdap.pgc"
 int avg_q ;
 
#line 49 "sdap.pgc"
 int avg_q_os ;
 
#line 50 "sdap.pgc"
 int avg_q_op ;
 } output [ 500 ] ;
/* exec sql end declare section */
#line 54 "sdap.pgc"


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

#line 55 "sdap.pgc"


//----------------------------------------------------------------------
// FUNCTION PROTOTYPE declaration
//----------------------------------------------------------------------
//FUNTION FOR QUARY 1

void    showresult(int index);                                  //output records to the console
int     IsExist(char* Name,char* prod,char* state,int index);   //Judge the name is exist or not
int     IsExist_os(char* Name,char* prod,char* state,int index);
int     IsExist_op(char* Name,char* prod,char* state,int index);
int     Theposition(char* Name,char* prod,char* state,int index);//where is the position in the ouput array
int     Theposition_os(char* Name,char* prod,char* state,int index);
int     Theposition_op(char* Name,char* prod,char* state,int index);
void    Count_Avg(int index);             //Count the average quant


//----------------------------------------------------------------------
int main(int argc, char* argv[])
//----------------------------------------------------------------------
{
   int index=0;
   //----------------------------------------------------------------------
   // DATABASE CONNECTION
   //----------------------------------------------------------------------
   // EXEC SQL CONNECT TO PostgreSQL@localhost:5432 USER PostgreSQL IDENTIFIED BY XYZ;
   { ECPGconnect(__LINE__, 0, "postgres@localhost:5432" , "postgres" , NULL , NULL, 0); }
#line 81 "sdap.pgc"


   if (sqlca.sqlcode != 0) {	// login error
   	printf ("Login error!!!\n");
   	return -1;
   }
   /* exec sql whenever sqlerror  sqlprint ; */
#line 87 "sdap.pgc"


   //----------------------------------------------------------------------
   // READ RECORDS
   //----------------------------------------------------------------------
   /* declare mycursor cursor for select * from sales */
#line 92 "sdap.pgc"

   { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "set transaction read only", ECPGt_EOIT, ECPGt_EORT);
#line 93 "sdap.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 93 "sdap.pgc"

   // Open cursor
   { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare mycursor cursor for select * from sales", ECPGt_EOIT, ECPGt_EORT);
#line 95 "sdap.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 95 "sdap.pgc"

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
#line 97 "sdap.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 97 "sdap.pgc"
 //fetch the first row

   while (sqlca.sqlcode == 0) {

     //Programming for query1
     //if the name is not exist in the output array then store it
      if(IsExist(sale_rec.cust,sale_rec.prod,sale_rec.state,index)==-1)
      {
        strcpy(output[index].cust,sale_rec.cust);
        strcpy(output[index].prod,sale_rec.prod);
        strcpy(output[index].state,sale_rec.state);
        output[index].count_q=1;
        output[index].sum_q=sale_rec.quant;
        output[index].count_q_os=0;
        output[index].sum_q_os=0;
        output[index].count_q_op=0;
        output[index].sum_q_op=0;
        ++index;
      }else{
         int pos=Theposition(sale_rec.cust,sale_rec.prod,sale_rec.state,index);
         output[pos].count_q++;
         output[pos].sum_q+=sale_rec.quant;
      }
      //the same name and product but not in the same state
      if(IsExist_os(sale_rec.cust,sale_rec.prod,sale_rec.state,index)==1)
      {
          int pos_1=Theposition_os(sale_rec.cust,sale_rec.prod,sale_rec.state,index);
          output[pos_1].sum_q_os+=sale_rec.quant;
          output[pos_1].count_q_os++;
      }
      //the same cust and same state but other kind of product
      if(IsExist_op(sale_rec.cust,sale_rec.prod,sale_rec.state,index)==1)
      {
          int pos_2=Theposition_op(sale_rec.cust,sale_rec.prod,sale_rec.state,index);
          output[pos_2].sum_q_op+=sale_rec.quant;
          output[pos_2].count_q_op++;
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
#line 135 "sdap.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 135 "sdap.pgc"
 //fetch the rest rows
   }
   // Close cursor

   { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close mycursor", ECPGt_EOIT, ECPGt_EORT);
#line 139 "sdap.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 139 "sdap.pgc"


   Count_Avg(index);

   showresult(index);


   return 0;
}

//----------------------------------------------------------------------
void	showresult(int index)
//----------------------------------------------------------------------
{
//----------------------------------------------------------------------
// PRINT TITLE
//----------------------------------------------------------------------
 printf(" CUSTOMER  | PRODUCT | STATE |   CUST_AVG   |  OTHER_STATE_AVG  |  OTHER_PROD_AVG |\n");
 printf("-----------+---------+-------+--------------+-------------------+-----------------+\n");

     for(int i=0;i<index;i++)
       {
      	printf(" %-8s  |",output[i].cust);        // Customer
        printf(" %-7s |",output[i].prod);     // Product
        printf(" %-2s   |",output[i].state);       // State
        printf("    %4d|",output[i].avg_q);      // Avg_Quantitiy
        printf("    %4d|",output[i].avg_q_os);      // Avg_Quantitiy for other state
        printf("    %4d|\n",output[i].avg_q_op);      // Avg_Quantitiy for other product
       }

}


int IsExist(char* Name,char* prod,char* state,int index)
{
   if(index==0)
   {
     return -1;
   }
   for(int i=0;i<index;i++)
   {
    int flag=strcmp(output[i].cust,Name);
    int flag_1=strcmp(output[i].prod,prod);
    int flag_2=strcmp(output[i].state,state);
    if(flag==0&&flag_1==0&&flag_2==0)
    {
      return 1;
    }
   }
   return -1;
}

int IsExist_os(char* Name,char* prod,char* state,int index)
{
    if(index==0)
    {
       return -1;
    }
     for(int i=0;i<index;i++)
    {
     int flag=strcmp(output[i].cust,Name);
     int flag_1=strcmp(output[i].prod,prod);
     int flag_2=strcmp(output[i].state,state);
     if(flag==0&&flag_1==0&&flag_2!=0)
     {
         return 1;
     }
     }
    return -1;
}

int IsExist_op(char* Name,char* prod,char* state,int index)
{
    if(index==0)
    {
      return -1;
    }
     for(int i=0;i<index;i++)
    {
     int flag=strcmp(output[i].cust,Name);
     int flag_1=strcmp(output[i].prod,prod);
     int flag_2=strcmp(output[i].state,state);
     if(flag==0&&flag_1!=0&&flag_2==0)
     {
         return 1;
     }
     }
    return -1;
}

int Theposition(char* Name,char* prod,char* state,int index)
{
    for(int i=0;i<index;i++)
   {
   int flag=strcmp(output[i].cust,Name);
   int flag_1=strcmp(output[i].prod,prod);
   int flag_2=strcmp(output[i].state,state);
   if(flag==0&&flag_1==0&&flag_2==0)
   {
     return i;
   }
   }
}
int Theposition_os(char* Name,char* prod,char* state,int index)
{
    for(int i=0;i<index;i++)
   {
   int flag=strcmp(output[i].cust,Name);
   int flag_1=strcmp(output[i].prod,prod);
   int flag_2=strcmp(output[i].state,state);
   if(flag==0&&flag_1==0&&flag_2!=0)
   {
     return i;
   }
   }
}
int Theposition_op(char* Name,char* prod,char* state,int index)
{
    for(int i=0;i<index;i++)
   {
   int flag=strcmp(output[i].cust,Name);
   int flag_1=strcmp(output[i].prod,prod);
   int flag_2=strcmp(output[i].state,state);
   if(flag==0&&flag_1!=0&&flag_2==0)
   {
     return i;
   }
   }
}

void Count_Avg(int index)
{
//count the avg for the product in this state
   for(int i=0;i<index;i++)
   {
   output[i].avg_q= output[i].sum_q/output[i].count_q;
   }
//count the avg for the product that belongs to otherwise
   for(int i=0;i<index;i++)
   {
   if(output[i].count_q_os==0)
   {
      output[i].avg_q_os=0;
      continue;
   }
   output[i].avg_q_os= output[i].sum_q_os/output[i].count_q_os;
   }
//count the avg for other product in this state
   for(int i=0;i<index;i++)
   {
   if(output[i].count_q_op==0)
   {
      output[i].avg_q_op=0;
      continue;
   }
   output[i].avg_q_op= output[i].sum_q_op/output[i].count_q_op;
   }
}
