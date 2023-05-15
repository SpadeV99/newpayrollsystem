#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>


struct employee
	{
		char emp_id[100];
		char  emp_name[100];
		char  address[100];
		char  position[100];
		char  email[100];
		char  contact[100];
		char hiredate[12];
		char bdate[12];
		char  department[100];
		float basic_rate,allowance,philhealth,sss_gsis,withholding_tax,pag_ibig,total_deductions,gross_pay,net_pay;
		int emp_num, day, month, year, b_day, b_month, b_year, worked;
	};

struct employee info ;


// Function to generate a unique employee number
int generate_employee_number() {
    srand(time(NULL));  // Seed the random number generator
    int num = rand() % 1000000;  // Generate a random number between 0 and 999,999
    return num;
}


main()
{

	FILE  *fp, *ft ;
	char  another, choice ;
		
	char emp_id[100];
	int flag=0;

	long int  recsize ;
	
    //dito mag oopen yung file
	fp = fopen ( "databse.txt", "a" ) ;



		if ( fp == NULL )
		{
			puts ( "Cannot open file" ) ;
			exit(0) ;
		}
	

	recsize = sizeof ( info ) ;


   
	while (1)
	{

        system("CLS"); 
        printf("\n");


	printf("\n");
	printf("\nGROUP 9 PAYROLL");
	printf("\n");
	

		printf("\n\n");
		printf ( "[A] REGISTRATION" ) ;
		printf("\n");
		printf ( "[B] PAYROLL" ) ;
		printf("\n");
		printf ( "[C] REPORTS" ) ;
		printf("\n");
		printf ( "[D] PAYSLIP" ) ;
		printf("\n");
		printf ( "[E] DELETE EMPLOYEE RECORDS" ) ;
		printf("\n");
		printf ( "[F] QUIT" ) ;
		printf("\n\n");
		printf ( "SELECT YOUR CHOICE : " ) ;

		fflush (stdin) ;
		choice = getche( ) ;
		switch ( choice )   //dito ka po mamimili ng gusto mo piliin
		{
			case 'A' : 
			case 'a':     

				fseek ( fp, 0 , SEEK_END ) ;   //EMPLOYEE RECORDS
				another = 'Y' ;

				while ( another == 'Y' )
				{
					system("cls");
					printf("\n\n");
		            printf("--- REGISTRATION ---");
		            printf("\n\n");
					
					printf("Enter Employee Name            : ");
					fflush (stdin) ;
					gets(info.emp_name);
					
					printf("Enter Address         		  : ");
					fflush (stdin) ;
					gets(info.address);
					
					printf("Enter Employee Position       : ");
					fflush (stdin) ;
					gets(info.position);
					
					printf("Enter Email                   : ");
					fflush (stdin) ;
					gets(info.email);
					
					printf("Enter Contact                 : ");
					fflush (stdin) ;
					gets(info.contact);
					
					printf("Enter employee date of hire (mm/dd/yyyy): " );
					fflush (stdin) ;
					gets(info.hiredate);
					
					
					
					printf("Enter Employee Department     : ");
					fflush (stdin) ;
					gets(info.department);
                    
					printf("Enter Basic Pay               : ");
					scanf("%f",&info.basic_rate);
					
					printf("Enter No. of Days Worked      : ");
					scanf("%d",&info.worked);
					
					printf("Enter Allowance               : ");
					scanf("%f",&info.allowance);

					info.gross_pay = (info.basic_rate*info.worked+info.allowance);

					printf("\n");
					printf("Employee's  Gross Pay : PHP %6.2f",info.gross_pay);

					printf("\n\n");
					printf("\nPhilhealth              : PHP 3200");
					info.philhealth = 3200;
					
					printf("\nSSS/GSIS                : 14 PERCENT of GROSS PAY ");
					info.sss_gsis = (info.gross_pay * .14);
					
					printf("\nWithholding Tax         : 10 PERCENT of GROSS PAY");
					info.withholding_tax = (info.gross_pay * .10);
					
					printf("\nPAG-IBIG                : PHP 200 ");
					info.pag_ibig = 200;

				    info.total_deductions = (info.philhealth+info.sss_gsis
				                            + info.withholding_tax+info.pag_ibig);

			        info.net_pay = (info.gross_pay-info.total_deductions);

				   printf("\n");
				   printf("Employee's  Total Deductions : PHP %6.2f",info.total_deductions);
				   printf("\n\n");
                   printf("Employee's  Net Pay        : PHP %6.2f",info.net_pay);
                   fwrite ( &info, recsize, 1, fp ) ;
                   
                   info.emp_num= generate_employee_number();
				

                if (emp_fp == NULL) {
    printf("Error opening file.\n");
    exit(1);
}
                fprintf(emp_fp, );


				printf("\n\n\nYour Employee Number is: %d\n", info.emp_num);
				printf("\n\nEmployee data saved to database\n");


                   
				   printf("\n\n");
				   printf ( "\nAdd another Record (Y/N) " ) ;
				   fflush ( stdin ) ;
				   another = toupper(getche()) ;
				}

				break ;

			case 'B' : //employee records
			case 'b':

			    system("cls");
				rewind (fp);
				printf("\n");
                printf("--- Employee records/Reports ---");
                printf("\n");
		while ( fread ( &info, recsize, 1, fp ) == 1 ) {
		    printf("\n");
            printf("\n Employee ID          : %d",info.emp_num);   // DITO SIYA NAG 0 OR NULL PLS FIX THIS
	        printf("\n Employee Name        : %s",info.emp_name);
	        printf("\n Address        		: %s",info.address);
		    printf("\n Position             : %s",info.position);
		    printf("\n Employee Email       : %s",info.email);
		    printf("\n Employee Contact     : %s",info.contact);
		    printf("\n Hiredate             : %s",info.hiredate);
		    printf("\n Department           : %s",info.department);
		    printf("\n Basic Pay            : PHP %6.2f",info.basic_rate);
		    printf("\n No. of Days Worked   : %d",info.worked);
			printf("\n Allowance            : PHP %6.2f",info.allowance);

			info.gross_pay = (info.basic_rate*info.worked+info.allowance);
			printf("\n\n");
			printf("\n Employee's  Gross Pay   : PHP %8.2f",info.gross_pay);
			printf("\n");
			printf("\n Philhealth           : PHP %6.2f",info.philhealth);
		    printf("\n SSS/GSIS             : PHP %6.2f",info.sss_gsis);
		    printf("\n Witholding Tax       : PHP %6.2f",info.withholding_tax);
		    printf("\n PAG-IBIG             : PHP %6.2f",info.pag_ibig);
		    info.total_deductions = (info.philhealth+info.sss_gsis
				                            + info.withholding_tax+info.pag_ibig);

	        info.net_pay = (info.gross_pay-info.total_deductions);

			printf("\n\n");
			printf("Employee's  Total Deductions : PHP %6.2f",info.total_deductions);
			printf("\n\n");
            printf("Employee's  Net Pay        : PHP %6.2f",info.net_pay);
		    printf("\n\n");
		    }
                system("pause");
				break ;

			case 'C' :  //update re4cords ng mga nakalagay na dito 
			case 'c' :
               rewind (fp);

				another = 'Y' ;
				while ( another == 'Y' )
				{
            system("cls");
            printf("\n");
		    printf("--- Update Employee Records in the System ---");
		    printf("\n\n");

					printf("\n");

                    printf("Enter Employee ID Number      : ");
					scanf("%s",&emp_id);
					rewind ( fp ) ;
					while ( fread ( &info, recsize, 1, fp ) == 1 )
					{
                    if ( strcmp ( info.emp_id, emp_id ) == 0 )  //dito nag kakamali sa pag alam nung generated number fix this
						{

                    printf("Enter Employee Name           : ");
					fflush (stdin) ;
					gets(info.emp_name);
					
					printf("Enter Address                 : ");
					fflush (stdin) ;
					gets(info.address);
					
					printf("Enter Employee Position       : ");
					fflush (stdin) ;
					gets(info.position);
					
					printf("Enter Email                   : ");
					fflush (stdin) ;
					gets(info.email);
					
					printf("Enter Contact                 : ");
					fflush (stdin) ;
					gets(info.contact);
					
					printf("Enter employee date of hire (mm/dd/yyyy): " );
					fflush (stdin) ;
					gets(info.hiredate);
					
					
					
					printf("Enter Employee Department     : ");
					fflush (stdin) ;
					gets(info.department);
                    
					printf("Enter Basic Pay               : ");
					scanf("%f",&info.basic_rate);
					
					printf("Enter No. of Days Worked      : ");
					scanf("%d",&info.worked);
					
					printf("Enter Allowance               : ");
					scanf("%f",&info.allowance);

					info.gross_pay = (info.basic_rate*info.worked+info.allowance);

					printf("\n");
					printf("Employee's  Gross Pay : PHP %6.2f",info.gross_pay);

					printf("\n\n");
					printf("\nPhilhealth              : PHP 3200");
					info.philhealth = 3200;
					
					printf("\nSSS/GSIS                : 14 PERCENT of GROSS PAY ");
					info.sss_gsis = (info.gross_pay * .14);
					
					printf("\nWithholding Tax         : 10 PERCENT of GROSS PAY");
					info.withholding_tax = (info.gross_pay * .10);
					
					printf("\nPAG-IBIG                : PHP 200 ");
					info.pag_ibig = 200;

				    info.total_deductions = (info.philhealth+info.sss_gsis
				                            + info.withholding_tax+info.pag_ibig);

			        info.net_pay = (info.gross_pay-info.total_deductions);

				   printf("\n");
				   printf("Employee's  Total Deductions : PHP %6.2f",info.total_deductions);
				   printf("\n\n");
                   printf("Employee's  Net Pay        : PHP %6.2f",info.net_pay);
                   printf("\n\n");
               	   printf("Records has been updated in the database.");
               	   printf("\n\n");
                   system("pause");
               					
								   	// dito siya mag ssave ng updated file
							fseek ( fp, - recsize, SEEK_CUR ) ;
							fwrite ( &info, recsize, 1, fp ) ;
							break ;
						}

                }
             if (strcmp(info.emp_id,emp_id) != 0 )  //dito nag kakamali sa pag alam nung generated number fix this
                    {
                        printf("\n\n");
                        printf("No Record in the Database.");
                        printf("\n");
                        system("pause");
                        break;
                    }

		    printf("\n");
					printf ( "\nUpdate Another Record (Y/N) : " ) ;
					fflush ( stdin ) ;
					another = toupper(getche());
				}

				break ;

	case 'D' :  // dito naman mag pprint ng reports from database
	case 'd' :
                rewind (fp);

				another = 'Y' ;
				while ( another == 'Y' )
				{
            system("cls");
            printf("\n");
		    printf("--- PAYSLIP ---");
		    printf("\n\n");
					 printf("Enter Employee ID       : ");
					scanf("%s",&emp_id);


					rewind (fp) ;
					while ( fread( &info, recsize, 1, fp ) == 1 )
					{
						// pag nakita niya yung file eto yung line na mag ooutput para sa record
						
						if (strcmp(info.emp_id,emp_id) == 0 )  //dito nag kakamali sa pag alam nung generated number fix this
						{

	        printf("\n");
            printf("\n Employee ID          : %s",info.emp_num);
	        printf("\n Employee Name        : %s",info.emp_name);
	        printf("\n Address        		: %s",info.address);
		    printf("\n Position             : %s",info.position);
		    printf("\n Employee Email       : %s",info.email);
		    printf("\n Employee Contact     : %s",info.contact);
		    printf("\n Hiredate             : %s",info.hiredate);
		    printf("\n Department           : %s",info.department);
		    printf("\n Basic Pay            : PHP %6.2f",info.basic_rate);
		    printf("\n No. of Days Worked   : %d",info.worked);
			printf("\n Allowance            : PHP %6.2f",info.allowance);

			info.gross_pay = (info.basic_rate*info.worked+info.allowance);
			printf("\n\n");
			printf("\n Employee's  Gross Pay   : PHP %8.2f",info.gross_pay);
			printf("\n");
			printf("\n Philhealth           : PHP %6.2f",info.philhealth);
		    printf("\n SSS/GSIS             : PHP %6.2f",info.sss_gsis);
		    printf("\n Witholding Tax       : PHP %6.2f",info.withholding_tax);
		    printf("\n PAG-IBIG             : PHP %6.2f",info.pag_ibig);
		    info.total_deductions = (info.philhealth+info.sss_gsis
				                            + info.withholding_tax+info.pag_ibig);

	        info.net_pay = (info.gross_pay-info.total_deductions);

			printf("\n\n");
			printf("Employee's  Total Deductions : PHP %6.2f",info.total_deductions);
			printf("\n\n");
            printf("Employee's  Net Pay        : PHP %6.2f",info.net_pay);
		    printf("\n\n");
		    }

                    system("pause");

                    break;
               		}
				}

            if (strcmp(info.emp_id,emp_id) != 0 ) //dito nag kakamali sa pag alam nung generated number fix this
                    {
                        printf("\n\n");
                        printf("No Record in the Database.");
                        printf("\n");
                        system("pause");
                        break;
                    }


                printf("\n");   
					printf ( "\n Search Another Employee Record? (Y/N) : " ) ;
					fflush ( stdin ) ;
					another = toupper(getche());
				break ;

			case 'E' :
			case 'e' :

				another = 'Y' ; // eto naman yung responsible sa pag dedelete ng file ng employee
				while ( another == 'Y' )
				{
					system("cls");
					flag=0;
                    printf("--- Delete Employee Records in the Database ---");
                    printf("\n\n");
					printf("Enter Employee ID       : ");
					scanf("%d",& info.emp_num);
					printf("\n");

    				ft = fopen ( "TEMP.TXT", "wb" ) ;
					rewind ( fp ) ;
					while ( fread ( &info, recsize, 1, fp ) == 1 )
					{
						if ( strcmp ( info.emp_id, emp_id ) != 0 )  //dito nag kakamali sa pag alam nung generated number fix this
							fwrite ( &info, recsize, 1, ft ) ;
						else
                            flag=1;


					}


                  // gagawa siya ng temp file for those ppl na ma dedelete
					fclose ( fp ) ;
					fclose ( ft ) ;
					remove ( "database.TXT" ) ;
					rename ( "TEMP.DAT", "database.TXT" ) ;
					fp = fopen ( "database.TXT", "rb+" ) ;
					
					
					    //pag nakita nung code yung emp number eto yung code na mag papakita ng output 

                  if(flag==1) {
                        printf("\n\n");
                        printf("Record Successfully Deleted From the Database.");
                         printf("\n");
                       system("pause");
                    }

					else if (flag!=1) {
                        printf("\n");
                        printf("Record Not Found in the Database.");
                        printf("\n");
                        system("pause"); // stdlib.h mahalaga tong library na to kasi eto yung nagpapagana sa code na to and sa dos also 

                    }

                    printf("\n");
					printf( "Delete Another Record (Y/N) " ) ;
					fflush ( stdin ) ;
					another = toupper(getche());  
				}
				break ;

			case 'F' :    
				fclose ( fp ) ;
				printf("\n\n");

				printf("Thank You For Using This Program, Please come again!!!  ");
				printf("\n\n");
				system("PAUSE");
				exit(0);  

		}
	}
}  
