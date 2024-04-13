/*
	Description the project
		this is a basic DBMS for Bank . Using basic Filehandling . 
		i have done this project with a friend
*/


/* declaring the header files */
    #include <stdio.h>  /* standard input output library*/
 	#include <stdlib.h> /* standard general utility to use memory allocation*/
 	// this is for windows based system 
 	#include<windows.h> //this is to include sleep a built-in function of c, which helps to delays the exit of the code
 	
	//#include <unistd.h> /* this is to include sleep in unix based system*/
	#include<string.h>  /* to use strings */
    #include<time.h>    /* to use in random generator function*/

/* header files are declared */

/* declaring Global variables ( to create constant values ) */

/* global variables are declared */

/* declaring variables to store strings for ease */
	char temp_string[200]; // this is to store string temporily and assign that value to local variables , for ease of value declaration
/* declared the string variables */
/* declaring FILE pointers, to use file systems */

 	/*declaration of filepointers  DBMS of the bank */
  		FILE *data_pointer; /* creatng a pointer to open a file to read and write*/
  		FILE *id_pointer;   /* creatng a pointer to open a file and write data*/
  		FILE *file_pointer;  /* creatng a pointer to open a file*/
  		FILE *temp_file;     /* creatng a pointer to open a file to write data, and exploit data*/
	/*declared file filePointers for DBMS of the bank */

/* declared FILE pointers*/

/* declaration of functions (by project creators) */

	/* functions that are common to all the applications */
  		void screen_clear(); /* this will clear the screen ,and make it look like a new page*/
  		void screen_delay(int time_delay ); /*basic function to delay screen, by using sleep() function , this fuction takes input , for how long the screen should sleep */
  		void loading_graphic(int time_show); /*this function basically loads a (. , .. , ...) in this manner to show that dots, and takes input for how long the dots should show (if input is 1 then it shows dots for 3 seconds)*/
	/* declared the common function */

	/* Basic creation of Data Base Mangement System for a bank (using fileHandlling in C languae)*/
 		void signup_bank();  /* this function creates userid and password, and cross verifies if the username already exists , if exists then it suggest user id is taken , and creating password , this use filesystem*/
  		void login_bank();   /* function to login to the users bankaccount, it takes userid, password, cross verifies using filesystem data,(DBMS) */
		int bank_balance(char userid[]); // this fuction takes the user id , and open the file in the name of user and store the users bank balance 
		int updater_bank(int update_line ,  int debit_or_credit , char userid[] , int value); /* basic function to update the passbook of user */
        void account_creation();//this function is to create account in bank and collect user information
        void transaction(); // this functions helps to transfer money from one account number to another with the help of account numbers


 	/* function declared for DBMS of Bank */
 		
	/* Basic encrypter and functions */
		void encrypter(char input_to_encode_or_decode[], int encode_or_decode ); /* this function basically takes input of string and an inteager , based on the encode_or_decode value it will pass either encoder() ( encoder for  0 )or decoder() ( 0 for decoder )function respectively*/
    	void decoder(char encoded[],int n, char decoded[]); //this function takes an encoded string , and length of the string and a variable to store decoded string
 		void encoder(char encode_str[], int n, char encoded[]);		//this function takes an string , and its length , and string to store the encoded string
	/* declared encrypter and funciton*/

/* function are declared */
   
/* start of main() fuction */
	int main()
 		{
			
			screen_clear();
			screen_delay(1);
			int choice =1;
			printf("	WELCOME TO BIHTA BANK IITIAN'S NO.1 CHOICE  \n\n");
			while(choice!=0){
			screen_delay(3);
			printf("	Please select the required option\n\n");
			screen_delay(1);
			printf("1. Account creation\n");
			screen_delay(1);
			printf("2. Login Account (to check bank balence and to do transaction)\n");
			screen_delay(1);
			printf("0. Exit\n");
			screen_delay(1);
			printf("\nEnter your choice : ");
			scanf("%d",&choice);
			if(choice ==1){
				screen_clear();
				account_creation();
			}else if(choice ==2){
				screen_clear();
				login_bank();
			}else if(choice ==0){
				screen_clear();
				screen_delay(1);
				printf("	THANK YOU   \n");
				screen_delay(2);
				screen_clear();
			}
			}
			

		return 0;
  		}
    
/* end of main() function */

/* declaration of objectives of functions */

// objecrive of sugnup_bank 
/*	
	A functions which creates an account in the bank which takes the input of name,age,account number,input balence. 
    It gives an account number to the user via random generator
*/
void account_creation(){
	    FILE *ac_file_ptr;   // we create  a file named ac_no_id.txt and store all the information of the account

	char folder[100] = "users/";
    if(id_pointer == NULL)
    	{

     		system("mkdir users");
     		id_pointer = malloc(sizeof(id_pointer));
        	id_pointer = fopen(folder, "r");
     	}
     	fclose(id_pointer);	
	screen_clear();
    char name[30];//name of the user
    int age;      //age of the user
    int account_number; //account number 
    int balance;
	int money =0;
    time_t t;    //it is initialiser of the time in rand() function,so that it will not print again the same random number
    /* Intializes random number generator */
    srand((unsigned) time(&t));
	loading_graphic(3);
	printf("		|| BIHTA BANK  - AFFILIATED WITH IIT PATNA || \n ");
	screen_delay(3);
	screen_clear();
	printf("	IITIANS NO.1 CHOICE    \n");
	screen_delay(3);
	screen_clear();
	printf("=>  Since 2008 we have helped more than 10,000 college Graduates to fulfill their dream to be an Engineer\n\n");
	screen_delay(4);
	printf("=>   Funding PHD Scholars\n\n");
	screen_delay(2);
	printf("\n=>   Sanctioning scholarships to students in need\n\n");
	screen_delay(2);
	printf("\n=>   Transforming Students to Entreprenures by funding their projects \n");
	screen_delay(3);
	screen_clear();
	printf("	WELCOME TO BIHTA BANK FAMILY	\n");
	screen_delay(2);
    printf("\n	Enter your first name ");  
    scanf("%s",name);
	screen_delay(1);
    printf("\n	Enter your age ");
    scanf("%d",&age);
    account_number = rand()%90000 + 10000;  //generating random 5 digit account number
	screen_delay(1);
    printf("\n	Enter the money to be added in the account (minimum balence is 500 Rs) ");
    scanf("%d",&balance);
	money = balance;
    if(balance>=500){
		screen_clear();   // checking whether the input balence is greater than 500 
		
    printf("	Congratulations!! Your account has been created.\n\n");
	screen_delay(2);
    printf("	Your Account number is: %d\n",account_number);
	screen_delay(3);
	printf("	please note the account number for future references \n");
	screen_delay(3);
		printf("1 %d\n",balance);

    FILE *ac_no_ptr;                        //we store all the account numbers in a file named ac_n0_data.txt
    ac_no_ptr = fopen("ac_no_data.txt","a");
    fprintf(ac_no_ptr,"%d\n",account_number);
    fclose(ac_no_ptr);
    char ac_no[14];
    char folder[100] ="users/";    
		printf("2 %d\n",balance);
		

    sprintf(ac_no,"%d", account_number);   // we are changing integer variable into string with the help of sprintf function
	printf("3 %d\n",balance);
    strcat(ac_no,"_id.txt"); 
    strcat(folder,ac_no);             // strcat adds two strings and stores in first string
    printf("4 %d",balance);
	strcpy(ac_no,folder);
   	printf("5 %d\n",balance);

    ac_file_ptr = fopen(ac_no,"w");
    fprintf(ac_file_ptr,"%s\n",name);
		printf("6 %d\n",balance);

    fprintf(ac_file_ptr,"%d\n",money);
    fprintf(ac_file_ptr,"%d\n",age); 
    fprintf(ac_file_ptr,"%d\n",account_number);    
    fclose(ac_file_ptr);
    }else{
        printf("minimum balance should be 500 Rs ");
    }
    printf("	Please create online account, required details are only acccount number\n");
	screen_delay(3);
	printf("	NOW YOU WILL BE RE-DIRECTED TO ONLINE SIGNUP PAGE \n");
	screen_delay(3);
    signup_bank(); 
}
    
    

// objecrive of signup_bank 
/*	Objective is to take a user id and cross check with data in the previously stored file, 
	if its unique then the code executes further , and password is also set by the user, 
	based on user id , an file is created for the user and the first line in the file is encoded password set up by the user
	this file is created , for login verification purposes
	and userid is also stroed an Data file, where all useriid are stored , this is done to improve search and finding of user
*/
	void signup_bank() 
  		{

  		    loading_graphic(3); /* intiating the loading graphic */
			printf("	|| SIGNUP PAGE OF BIHTA BANK ||\n\n\n");
   			char user_id[25]; /* this is a character container , to user store user id*/
   			char cpy_id[52];  /* this is to temporarily stores the userid to create user file */
   			char verify_user[100]; /* this is the characeter container, which stores the userid's from "file data.txt" */
   			int verify=1;  /* this is to check whether userid is already taken or not, based in change of "verify" values , the further code is execcuted */
   			printf("	| create user id | \n");
			screen_delay(1);
   			printf("	create username(this will be id) : \n	");
  			scanf("%s",user_id); /* this will take only one word as user id, no white spaces*/
			screen_delay(1);
   			strcpy(cpy_id,user_id); /* copying user_id to cpy_id */
   			data_pointer = fopen("data.txt","r"); /* open the "data.txt" file, and pointing the data_pointer to "data.txt" , and open the file in read mode */
   			if( data_pointer == NULL) /* this is to check the pointer is NULL*/
    			{
     				/* if data_pointer is NULL , then error occurs while reading the file*/
    				/*hence we are creating the file , and writing to it and reading*/
    				data_pointer = malloc(sizeof(data_pointer));
     				data_pointer = fopen("data.txt","w");

    			}
    		while(fscanf(data_pointer, "%s", verify_user) != EOF ) /* using the fscanf() function to take data from data.txt and assign it temporarily to verify_user , and check whether userid already exists or not*/
    			{
     				if(strcmp(verify_user,user_id) == 0) /*if  userid and verify_user are same, then strcmp gives "0" , hence suggest enter different id */
      					{
       						printf("\n	user id is already taken,\n");
							screen_clear();
       						verify=0; /* asigning 0 to verify , to stop the code from moving forward */
       						break;
      					}
    			}
  			fclose(data_pointer); /* freeing the data_pointer to save computer resources */
   			if(verify==1) /* proceding the code, since userid is unique */
    			{
    				data_pointer = fopen("data.txt","a"); /* open the "data.txt" file, and pointing the data_pointer to "data.txt" , and open the file in append mode to add the userid to "data.txt" for future login */
     				fprintf(data_pointer, "%s\n",user_id); /* adding the user to "data.txt" file "\n this is to create a new line and append the userid to the newly created line" */
     				fclose(data_pointer);  /* freeing the data_pointer to save system resources */
     				char folder[50]="users/"; /* since , the user related folder is being created in a folder, within the main directory , i am assigning the "users/" to the folder variable */
     				id_pointer = fopen(folder, "r");

     				strcat(folder,user_id);  /* Now, I am concatinating the value stored in folder(i.e users/) to the userid (to make folder as "users/userid")*/
     				strcpy(user_id,folder);  /* copying the value in folder to user_id variable*/
     				strcat(user_id,"_id.txt"); /* now concatinating the "_id.txt" to user_id , */
       				/*the above process is to make sure , that text file is created for the newly created user , to access the bank details with this password and userid , for that purpose user_id became "users/userid_id.txt, where as "userid" user's input */
     				/* pointing the id_pointer to user_id which holds "users/userid_id.txt" , this will open the text file in the name of userid_id.txt in the folder "users" */
     				char user_password[50]; /* this will be the password container , No whitespaces will be included and maximum size is 12 characeters */
     			    printf("\n\n	create password : \n	");
     				scanf(" %s",user_password); /*user input id taken and assigned to user_password*/
					screen_delay(1); 				
    				encrypter(user_password, 0); // as encrypter eases our process to encode the code, we are passing user_password, and operation to perform , that is "0" to encode
    		        strcpy(user_password, temp_string); // as the value of encoded password is stored in global variable , we are assigning the value to local variable
    		        id_pointer = fopen(user_id,"w"); // open a file in the name of user , to store encoded password for future sessions
    				fprintf(id_pointer,"%s\n", user_password); /* now printing the password , onto the unique text file create to user (i.e, users/userid_id.txt) */     				
                    int ac_no;
                    int verify_no;
                    int check =0;
                    while(check !=1){                    
                    printf("\n\n	Enter your account number \n	");
                    scanf("%d",&ac_no);
					screen_delay(1);
                    FILE *ac_no_ptr;
                    ac_no_ptr = fopen("ac_no_data.txt","r");
                    while(fscanf(ac_no_ptr,"%d",&verify_no) != EOF){
                        if(verify_no==ac_no){
                           fprintf(id_pointer,"%d\n",ac_no);
                           
                            printf("\n	 Registration complete \n");
							screen_delay(2);
							screen_clear();
                            check = 1;
                        }
                    }
                    if(check!=1)
                    printf("	Invalid account number\n");
					screen_delay(1);
                    }
     				fclose(id_pointer); // to save system resources , we are closing the pointer
     				
     			}
  		}

// objective declaration of login_bank
/*
	the objective is to take user id from the user , and check whether it exists in our data file,
	if found the process continues, we will the file  which is previously stored in the name of the user 
	and take the encrypted password in the file , and assign it to a local variable , and decrypt it , and cross verify with the user input 
*/
 	void login_bank()
  		{
			char user_name[20];
    		int verify=0; // based on veify's value, code will be executed or stopped
  			char user_id[50]; // store user_id
  			char password[50]; // store password
  			char id_verify[50]; // temporary variable to store the userid's of the users for verification
			while(verify == 0){
				printf("	|| LOGIN PAGE OF BIHTA BANK ||\n\n");
			screen_delay(1);
  			printf("Enter the user id : ");
  			scanf("%s",user_id);
			strcpy(user_name,user_id);
			screen_delay(1);			
  			data_pointer = fopen("data.txt", "r"); // opening the file which contains the userid's
  			screen_delay(0.5); // functoin to provide a graphical feel
  			while(fscanf(data_pointer, "%s", &id_verify) != EOF) // taking the userid's to store temoporarily in a local variable and compare with user input 
 				{
  					if(strcmp(id_verify,user_id)==0) // comparing users input , and userid's present in the data base
   						{ 
     						verify=1; // assigning 1 to verify , to further execute the code as the user's input is present in data file
     						 /* 
     						 since users file , are stored in a folder with in the directory ,we are converting userid in the form of users/userid_id.txt
     						 */ 
							int check =0;//this variable helps to re enter the password
     						char folder[50]="users/";
     						strcat(user_id,"_id.txt"); // concatinating the userid with _id.txt
     						strcat(folder,user_id); // concatinating the folder with user_id
     						strcpy(user_id,folder); // copying the concatinated string folder to user_id
     						id_pointer = fopen(user_id,"r"); // opening the file for userid
     						char user_password[15]; // creating a variable to take actual password of the user from the users file and store it in the variable
     						fscanf(id_pointer,"%s",&user_password); 					
     					
     						strcpy(temp_string,user_password); // now copying the encoded password to global variable for ease of the process
     						decoder(temp_string,strlen(temp_string), user_password); // passing the required arguments for the decoder to decode
							while(check==0){
							printf("Enter Password : ");
     						scanf(" %[^\n]",password);
							screen_delay(1);
     						if(strcmp(password,user_password)==0) // verifying the actual password with users input 
      							{
           							screen_delay(2);
									check =1;
      							}
     						else 
      							{        						
           							printf("incorrect password\n");
									screen_clear();
      							 	screen_delay(2);
      							}     						
							}
   						}
  				}
  			if(verify==0) // since user id is not found in data base , we are not going to further execute code
  				{	
  					screen_delay(1);
  					printf("wrong user id\n");
  					screen_delay(2);
  				}else{
					int account_no;//account number of the user
					char ac_no[50];//a string to store the account number
					int choice = 0;//helps to show the options
  					fclose(data_pointer);
            		screen_clear();
					loading_graphic(3);
					while(choice!=3){
						screen_clear();
						printf("	|| BIHTA BANK ||\n\t\t	|| USER ID %s ||\n",user_name);
            			printf("Please select the required option \n");
						screen_delay(1);
            			printf("1. Display balence\n");
						screen_delay(1);
            			printf("2.Transaction\n");
						screen_delay(1);
						printf("3.Exit\n");
						screen_delay(2);
						printf("Enter the choice : ");
            			scanf("%d",&choice);
            			if(choice == 1 ){
                			screen_clear();	
													
							fscanf(id_pointer,"%d",&account_no);

    						sprintf(ac_no,"%d",account_no);   // we are changing integer variable into string with the help of sprintf function
							int paisa = bank_balance(ac_no);    					
							printf("Bank Balance : %d\n",paisa);
							screen_delay(2);
							
            			}else if(choice == 2){
							screen_clear();
							transaction();							
						}	
						fclose(id_pointer);					
					}

					screen_clear();

				}
           
			
  		    } 
		}
//objective declaration of transaction()
/*
    A function which undergoes transaction process.
	It takes the input of two account numbers and transaction amount then undergoes transaction process  

*/
void transaction(){
        int ac_bal;
        int txn_amt;
		int verify_no;
		int check=0;
        int  ac_no;
        char ac_no_1[50];
        char ac_no_2[50];
		FILE *ac_no_ptr;       
		while(check!=1){
			screen_delay(1);
	   		printf("\n	Enter your account number: ");
        	scanf("%d",&ac_no);
			screen_delay(1);
        	
        	ac_no_ptr = fopen("ac_no_data.txt","r");
       			while(fscanf(ac_no_ptr,"%d",&verify_no) != EOF){
                        if(verify_no == ac_no){
							check = 1;
                        }
                  
        		}
			if(check!=1)
        	printf("\n	Invalid account number\n");
			screen_delay(1);
     		fclose(id_pointer);
		}
		fclose(ac_no_ptr);
		sprintf(ac_no_1,"%d",ac_no);
		check = 0;
		FILE *ac_no_ptrr;
		while(check!=1){
	   		printf("\n	Enter the account number of the person to be transferred ");
        	scanf("%d",&ac_no);
			screen_delay(1);
        	ac_no_ptrr = fopen("ac_no_data.txt","r");
       			while(fscanf(ac_no_ptrr,"%d",&verify_no) != EOF){
                        if(verify_no==ac_no){
							check = 1;
                        }
                  
        		}
			if(check!=1)
        	printf("\n	Invalid account number\n");
			screen_delay(1);
     		fclose(id_pointer);
		}
		fclose(ac_no_ptrr);
		sprintf(ac_no_2,"%d",ac_no);  // to store integer in string
        printf("\n	Enter the amount to be transferred: ");
        scanf("%d",&txn_amt);
		screen_delay(1);
		if(bank_balance(ac_no_1)>=txn_amt){       // bank balance should be greater than transaction amount
       	 	if(updater_bank(2,0,ac_no_1,txn_amt) && updater_bank(2,1,ac_no_2,txn_amt)){
        	printf("\n	Transaction done\n");
			screen_delay(2);
       		}else{
            printf("\n	NO sufficient funds\n");
			screen_delay(2);
       		}
		}
        
	}

//objective declaration of screen_clear
/*
	objective of screen clear , is to pass an argument to the  command line to execute the "clear" command 
*/
 	void screen_clear()
		{
    		//system("clear"); /*this command is linux command to clear the screen, using system() function */
			system("cls"); // this command is for windows
    	}

//objective declaration of bank_balance
/*
	The objective is to take userid and find the bank balance of user
*/
    int bank_balance(char userid1[])
    	{
    		FILE *fptr; // declaring a local variable , for file system handling
    		char userid[100]; // re-declaring the size of userid
    		strcpy(userid, userid1);
    		int bankbalance; // to store bankbalance
			int money;
    		int count = 1; // to find which line we are in the file 
    		char value_from_file[100]; // temporarily save data of each line from the file
    		int line_of_bankbalance = 2; // line position of bankbalance in the file
 			/*
				this may actually not be the file where the bankbalance is stored, but for explanantion i have taken this user's file, which will have certain error .
				because in users file . first line is of string(password) , and we are using an integer to store value, so error, 
				the solution is re write the code , to take string value, and later convert string into an integer variable to do mathematical operations
 			*/
 			char folder[100] = "users/"; 
  			strcat(userid, "_id.txt");
  			strcat(folder,userid);
  			strcpy(userid,folder);
  			
  			fptr = fopen(userid, "r"); // opening the file
		    fscanf(fptr,"%s",value_from_file);
			fscanf(fptr,"%d",&money);			
  			 fclose(fptr);	
			  screen_delay(2);
   			  return money; // returning bankbalance
    	}

//objective declartion of updater_bank
/*
	this fuction takes the input which line to update in the text file, as the passbook , contains multiple details , 
	second argument is whether money is debited or credited in transaction 
	third argument is value of the transaction of the amount
*/
	int updater_bank( int update_line , int debit_or_credit , char userid1[], int value)
 		{
 			FILE *fptr; // creating a local file pointer
 			FILE *tptr;
 			int count = 0; // to find which line we are in the file system
 			char userid[100]; // re-defining the  array to use size 
 			strcpy(userid,userid1);
  			int status_transcation = 0; // this will be returned whether the transaction is success or failure
  			char value_from_file[100]; // to temporarily store value from the file 
 			/*
				this may actually not be the file where the bankbalance is stored, but for explanantion i have taken this user's file, which will have certain error .
				because in users file . first line is of string(password) , and we are using an integer to store value, so error, 
				the solution is re write the code , to take string value, and later convert string into an integer variable to do mathematical operations
 			*/
  			char folder[100] = "users/";
  			strcat(userid, "_id.txt");
  			strcat(folder,userid);
  			strcpy(userid,folder);
  			
  			fptr = fopen(userid, "r"); // opening the user id file
  			tptr = fopen("temp.txt", "w"); // creating a temporary file , to store the data from the user id file ,update data from user id and append to temporay file
  			int bankbalance; // to store the bankbalnce of user
  			int date_of_birth = 3;   										
  			while (fscanf(fptr,"%s", &value_from_file) != EOF) // taking the data from each line of the file and storing it temporarily  
   				{
   					count++; // to make sure we are on correct itteration
       				if( count == update_line ) // if we are on the desired line
         				{
         				
         					bankbalance = atoi(value_from_file) ; // we will store the bankbalance taken from file
         				 	if(debit_or_credit == 1 ) // this means transaction is credit
         				 		{ 
         							bankbalance = bankbalance+value; // adding the value to bankbalance
         							fprintf(tptr, "%d\n", bankbalance); // copying the new bankbalance to temporary file
         							status_transcation = 1 ; // transaction status is 1
         				 		}
         				 	else if(debit_or_credit == 0) // this means debit
         				 		{
         				 			if(bankbalance>value) // if bankbalance is greater than value
         									{
         										bankbalance = bankbalance-value; // subtract value from bankbalance        										
         										fprintf(tptr, "%d\n" , bankbalance); // updating the new bankbalance to temporary file
         								    	status_transcation = 1; // transaction status is 1
         									}
         								 else // implies value is more than bankbalance
         								 	{
         								 		fprintf(tptr,"%s\n", value_from_file); // no new balance is found , hence old balance is updated to temporary file
         								 		status_transcation = 0 ; // since no trasaction is done , satus is 0
         								 	}       								
         				 		}
                            
         				 	else
         				 		{
         				 			status_transcation = 0; // if debit_or_credit is neither 1 nor 0 then status is 0
         				 		}
         				} 
        			else
        				{
        	  				fprintf(tptr, "%s\n", value_from_file); 
        				}

        		}
  			fclose(fptr);
  			fclose(tptr);
  			remove(userid); // since new data of user (passbook ) is stored in temporary file , we are removinf the userid textfile
  			rename("temp.txt" , userid); // we are renaming our temporary file to userid file, for future transaction, this will automaticaly remove temporary file
  			return status_transcation; // returning status
  
		}

// objective declaration of screen_delay
/*
	this function will use sleep() , command to delay the end of code, or further execution of code, 
	this function has argument to take how long to delay
*/
	void screen_delay( int time_delay )
		{
    		//sleep(time_delay); 	/* using sleep for linux (the input of sleep() is seconds)*/
    		
	 		time_delay = time_delay*1000;
    		Sleep(time_delay);  /* using sleep for for windows, the input for sleep() is milli seconds */
    		
		}

// objecive declaration of laoding_graphic		
/*
	this function creates a simple graphic like visual in command line using dots,
	this uses , sleep(), and clear function to achive its uses
	*/
	void loading_graphic(int time_show)

		{	
			screen_clear();
			int verify = 1; /* this is to stop the while loop based on " time_show " variable */
   			int control_dots = 0; /* this is the variable which controls how many dots should show */
   			time_show = time_show*3; /*this is to delay for 3 seconds if input is 1 second */
   			while(verify == 1)
   				{	
   					if( time_show != 0 )
   						{
   							
   							for( int i = 0 ; i < control_dots ; i++ )
   								{
   									printf(". ");
   									  						
   								}   
   						 	printf("\n");
   						 	printf("Please wait while the loading process is happenong \n");
   							screen_delay(1); 		
   							screen_clear();					   
   							time_show--;
   						 	control_dots++;							
   						}
   					else
   						{
   							verify = 0;
   						}
   				} 
		}	 

// objecitve declaration of encrypter
/*
	This function takes string, to encode or decode 
	and second argument is an inteager , 0 for encode and 1 for decode
*/
	void encrypter(char input_to_encode_or_decode[], int encode_or_decode )
		{   
			char encode_str[200]; //this will store string
    		char encoded[200]; // this will contain encoded string
    		char decoded[200]; // this will contain decoded string
  			strcpy(encode_str,input_to_encode_or_decode); // copying the string value into our local variable
  			strcpy(temp_string, input_to_encode_or_decode); // copying the string value into global varibale
    		FILE *check_pointer; 
 			check_pointer = fopen("encoder.txt","w"); // opening the file in write mode, which is creation of the file
 			char encoder_text1[] = "6TmPQ[AJojNres;kX-aRS7?/Ch}tF43~p*>q5LE#Yvn 1OdgUDBZ&,I^u@'8(+:!fz{wM%|=V$.)_cxyb`]9WKGh<2l0iH"; // the trash text which will be stored in encoder.txt
 			fprintf(check_pointer, "%s", encoder_text1); //copying the file concatenated file into encoder.txt
 			fclose(check_pointer);
    		switch(encode_or_decode)// based on the users input, we will pass respectibe arguments to encoder or decoder
    			{
    				case 0 :
    					encoder(encode_str, strlen(encode_str), encoded);
    					break;
    				case 1 :
						decoder(temp_string, strlen(temp_string), decoded);	
    					break;
    				default :
    					break;
    			}
    		
		}

// objective declaration of encoder	
/*
	the main arguments are string to encode, size of string and variable to store data
	basically, i have a string , and i will minus 32 from ascii value of the character, but i will be using encoder.txt, which has a trash of characters, 
	based on the  ascii value obtained from subtraction of original charater by 32, i will get new ascii value.
	now with help of ascii value i will find positon of the character from trash that is encoder.txt
	for example
	if string is hello
	the first character is h and its ascii valur is 104
	and ' ' which is space has an ascii value of 32
	now the subtraction gives 72
	and the trash is stored in a variable, 
	now with this 72 we will find the position of that variable what ever that is, that is trash[72], this will give the new character from trash
*/
	void encoder(char encode_str[], int n, char encoded[])
		{
			FILE *encoder_fptr;
    		char encoder[200]; 
    		//    Reading a file
    		encoder_fptr = fopen("encoder.txt","r");
  		 	fscanf(encoder_fptr,"%[^\n]",encoder);
    		fclose(encoder_fptr);
    		for (int i=0;i<n;i++)
    			{
        			char temp = encode_str[i];
        			// Subtract the ASCII of our character with 32 (ASCII of space) which will give us some index, bring char of that index from our encoder file, and then paste it in encoded string
        			encoded[i] = encoder[temp-' '];
    			}
			encoded[n] = '\0';   // Ending the string by putting null 
    		strcpy(temp_string,encoded); // this function copies the encoded into temp_string whixh is a global variable and can be access throught the code ,
		}

// objective declaration of decoder
/*
	same procedure as encoder, we will do opposite , 
	strchr() this fucrion will give the first apperance of the character in a string,
	and encoded text first character is j , hence strchr(encoder, j), which means , in encoder string find pos of first apperance of j and subtract encoder , 
	which means , imagine encoder begining has value 30 , which is assigned by computer , and strchr() gives use 50, 50 is not the position of the character rather 30 + 20
	hence 20 is the actual position , so we are removing encoder , which is like removing 30 from 50 , to get correct value 
	then add 32 to that resulted value ,
	which will give ascii value of actual value
*/	
	void decoder(char encoded[],int n, char decoded[])
		{
    		// This function will decode the things
    		FILE *decoder_fptr;
    		char encoder[200];
			//    Reading a file
    		decoder_fptr = fopen("encoder.txt","r");
    		fscanf(decoder_fptr,"%[^\n]",encoder);
    		fclose(decoder_fptr);

    		for (int i=0;i<strlen(encoded);i++)
    			{
        			// Get the pos of element our encoded character in our encoder file
       				int decoder_index = strchr(encoder, encoded[i]) - encoder;
        			decoded[i] = ' '+ decoder_index;
    			}	

			decoded[n] = '\0';   // Ending the string by putting null
    		strcpy(temp_string,decoded); // this function copies the encoded into temp_string whixh is a global variable and can be access throught the code 
		}

/* objectives of functions are decalred*/

