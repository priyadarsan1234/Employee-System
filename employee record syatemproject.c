#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <conio.h>
int main() 
{ 
	struct emp
     { 
     	
         char name[50]; 
         float salary; 
         int age; 
         long long int mobno;
         char adress[100];
         int id;
         
     }e; 

    char empname[40]; 
    long int resize=sizeof(e);
    
	char another;
	FILE *fp,*ft;
    int choice; 
    fp = fopen("Emp.txt", "rb+"); 
    if (fp == NULL)
     { 
     	
        fp = fopen("Emp.txt", "wb+"); 
        if (fp == NULL)
        
         { 
         	
            printf("\nCannot open file..."); 
            exit(1); 
            
        } 
        
    }    
    printf("\n\t\t\t\t\t   <><><><><><><><><><><><><><><><>");
    printf("\n\n\n\n\n");
    printf("\n\t\t\t\t\t   *  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= *");
    printf("\n\t\t\t\t\t   *  =                  WELCOME                  = *");
    printf("\n\t\t\t\t\t   *  =                    TO                     = *");
    printf("\n\t\t\t\t\t   *  =              EMPLOYEE RECORD              = *");
    printf("\n\t\t\t\t\t   *  =                   SYSTEM                  = *");
    printf("\n\t\t\t\t\t   *  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= *");
    printf("\n\t\t\t\t\t   <><><><><><><><><><><><><><><><>\n");
    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t""DEVELOPER:\t\t\t\t");
    printf("\t\tGUIDED BY:");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t""@PRIYDARSAN PRADHAN\t\t\t\t");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    system("pause"); 

 while (1) 
    { 
    	
        system("cls");
        printf("\n\t\t\t\t\t1. ADD RECORD\n"); 
        printf("\n\t\t\t\t\t2. DELETE RECORD\n");
        printf("\n\t\t\t\t\t3. DISPLAY RECORDS\n"); 
        printf("\n\t\t\t\t\t4. MODIFY RECORD\n"); 
        printf("\n\t\t\t\t\t5. SEARCH RECORD\n"); 
        printf("\n\t\t\t\t\t6. EXIT\n"); 
        printf("\n\t\t\t\t\tENTER YOUR CHOICE :"); 
        fflush(stdin); 
//        choice=getche(\t\t\t\t\t);
        
	    scanf("%d",&choice);
        switch(choice) 

        
        {
        	
//add employee record
        	
        	case 1:
        	system ("cls");
        	another='Y';
        	while(another=='Y')
        	{
        		
                 printf("\n\t\t\t\t\tEnter Name : "); 
                 fflush(stdin);
                 gets(e.name);
                 printf("\n\t\t\t\t\tEnter Age : "); 
                 scanf("%d", &e.age);
                 printf("\n\t\t\t\t\tEnter Salary : "); 
                 scanf("%f", &e.salary); 
                 printf("\n\t\t\t\t\tEnter EMP-ID : "); 
                 scanf("%d", &e.id); 
                 printf("\n\t\t\t\t\tEnter Mobile no :");
                 scanf("%lld", &e.mobno);
                 printf("\n\t\t\t\t\tEnter the Adress :");
                 fflush(stdin);
                 gets(e.adress);
                 fwrite(&e, sizeof(e), 1, fp); 
                 printf("\n\t\t\t\t\tRECORD SUCESSIFULLY ADDED\n");
                 printf("\n\t\t\t\t\tWant to add another""record (Y/N) : "); 
                 fflush(stdin); 
                 another=getche();  
                      	
            }
        break;
            
//delete employee record
                  
        case 2:
        system("cls");    
        another = 'Y';
        while (another == 'Y')
         {
         	
           printf("\n\t\t\t\t\tEnter employee name to delete : "); 
           fflush(stdin);
           gets(empname);
           ft = fopen("temp.txt", "wb"); 
           rewind(fp); 
           while (fread(&e,resize,1, fp) == 1) 
            { 
            	
                if (strcmp(e.name,empname)!= 0) 
                fwrite(&e,resize, 1, ft); 
                
            } 
           fclose(fp); 
           fclose(ft); 
           remove("Emp.txt"); 
           rename("temp.txt", "Emp.txt"); 
           fp = fopen("Emp.txt", "rb+"); 
           printf("\n\t\t\t\t\tRECORD SUCESSFULLY DELETED\n");
           printf("\n\t\t\t\t\tdelete another" "record (Y/N) :"); 
           fflush(stdin); 
           another = getche(); 
            
        } 
           break;
           
//display employee record
                      
           case 3:
           system ("cls");
           rewind(fp);
           while(fread(&e,resize,1,fp)==1)
           {
           	
           	    printf("\n\t\t\t\t\t NAME :%s",e.name);
           	    printf("\n\t\t\t\t\t AGE  :%d",e.age);
           	    printf("\n\t\t\t\t\t SALARY :%2f",e.salary);
           	    printf("\n\t\t\t\t\t ID :%d",e.id);
           	    printf("\n\t\t\t\t\t MOBILE NO :%lld",e.mobno);
           	    printf("\n\t\t\t\t\t ADDRESS :%s",e.adress);
            }
           getche();
           break;
           
//modify employee record
                     
         
case 4:       
            another='Y';
            while(another=='Y')
            {       	
           printf("\n\t\t\t\t\tEnter employee name to modify: "); 
           fflush(stdin);
           gets(empname);
           rewind(fp); 
           while (fread(&e,resize,1, fp) == 1) 
            { 
            	
                if (strcmp(e.name,empname)== 0) 
                
                {  
             
                printf("\n\t\t\t\t\tEnter new name:"); 
                fflush(stdin);
                gets(e.name);
                printf("\n\t\t\t\t\tEnter new age :"); 
                scanf("%d", &e.age); 
                printf("\n\t\t\t\t\tEnter new salary :"); 
                scanf("%f", &e.salary); 
                printf("\n\t\t\t\t\tEnter new EMP-ID :"); 
                scanf("%d", &e.id); 
				printf("\n\t\t\t\t\tEnter new mobile no :");
                scanf("%lld",&e.mobno);
                printf("\n\t\t\t\t\tEnter new the adress :");
                fflush(stdin);
                gets(e.adress);  
                fseek(fp,-resize,SEEK_CUR);   
                fwrite(&e,resize, 1, fp);
                break;
                }
             }   
                printf("\n\t\t\t\t\tRECORD SUCESSIFULLY MODIFIED\n");
                printf("\n\t\t\t\t\tModify another record(Y/N)");
                fflush(stdin);
                another=getche();
                
          }
            break;
     
     
 case 5:       
            another='Y';
            while(another=='Y')
            {       	
           printf("\n\t\t\t\t\tEnter employee name to search: "); 
           fflush(stdin);
           gets(empname);
           rewind(fp); 
           while (fread(&e,resize,1, fp) == 1) 
            { 
            	
                if (strcmp(e.name,empname)== 0) 
               {
           	    printf("\n\t\t\t\t\t NAME :%s",e.name);
           	    printf("\n\t\t\t\t\t AGE  :%d",e.age);
           	    printf("\n\t\t\t\t\t SALARY :%2f",e.salary);
           	    printf("\n\t\t\t\t\t ID :%d",e.id);
           	    printf("\n\t\t\t\t\t MOBILE NO :%lld",e.mobno);
           	    printf("\n\t\t\t\t\t ADDRESS :%s",e.adress);
                break;
               }
            else
            {
            	exit(0);
			}
           }
                printf("\n\t\t\t\t\tModify another record(Y/N)");
                fflush(stdin);
                another=getche();    
          }
            break;
//exit
     
    case 6:
    fclose(fp);
    printf("\n\t\t\t\t\tEXIT\n");
    exit(0);
    }
    
  } 
   
  return 0;  
}
