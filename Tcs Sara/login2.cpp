#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <conio.h>
#include <string.h>

using namespace std;
int check(char name[],char pass[],int opt)
{
    FILE *fin;
    fin=fopen("signUp.txt","r");
    char c=0;
    char str1[100],str2[100];
    //cout<< "fin\n";
    //cout<<fin;
    if(fin==NULL)
    {
        cout << ("\nError opening file");
        return 0;
    }
    fscanf(fin,"%s",str1);
    //cout<< "This line worked:  %c"<< (c==fgetc(fin));
    while(fin !=NULL && strcmp(str1,"-1")!=0)
    {
        //char str[]=fread();
        if(strcmp(str1,name)==0)
            {

                fscanf(fin,"%s",str2);
                if(opt==2)
                {
                    cout << "\nLogin id already exists\nTry again\n";
                    fclose(fin);
                    return 0;
                }
                if(strcmp(str2,pass)==0 && opt==1)
                {
                    cout << "\nLogin Successful\n";
                    fclose(fin);
                    return 1;
                }
                else
                {
                    strcpy(str2,"");
                }
            }

        strcpy(str1,"");

        fscanf(fin,"%s",str1);

        //cout << " str = "<<str1;
        /*if(c=='\n')
        {
            cout << "\n";
        }*/
    }
    fclose(fin);
    if(opt==2)
        return 1;
    else
        return 0;
}

int AdminPowers()
{
    FILE *fin,*f2;
    fin=fopen("signUp.txt","r");
    f2=fopen("file2.txt","w");
    int temp=0;
    char str1[100],str2[100],name[100];

    if(!fin)
    {
        cout<<"Error Opening File\n";
        return -1;
    }
    int ch=0,ch2=0,found=0;
    char subscriptionNo[100];

    while(1==1)
    {
        cout<< "\nPress:\n1:To Search a record\n2:To Delete a record\nAny other no. to exit\n";
        cin>>ch;
        found=0;
        switch(ch)
        {
            case 1:cout<<"\nPress:\n1:To search by subscriber no:\n2:To search by name:\nAny other no. to exit\n";
            cin>>ch2;
            switch(ch2)
            {
            case 1:
                fclose(fin);
                fin=fopen("signUp.txt","r");
                cout<<"\nEnter any subcriber no. to search: ";
                cin>>subscriptionNo;
                fscanf(fin,"%s",str1);
                while(fin !=NULL && strcmp(str1,"-1")!=0)
                {
                    //char str[]=fread();
                    if(strcmp(str1 ,subscriptionNo)==0)
                    {
                        cout<<"\nRecord Found\n";
                        found=1;
                        break;
                    }
                    strcpy(str1,"");
                    fscanf(fin,"%s",str1);
                    //cout<<"\nstr 1 = "<<str1;
                }
                if(!found)
                {
                    cout<<"\nRecord not found";
                }
                break;
            case 2:
                cout<<"\nEnter any username to search:";
                getchar();
                gets(name);
                fscanf(fin,"%s",str1);//,subscriptionNo);
                //cout<< "This line worked: "<< str1;
                while(fin !=NULL && strcmp(str1,"-1")!=0)
                {
                    //char str[]=fread();
                    if(strcmp(str1,name)==0)
                        {
                            cout<<"Record found\n";
                            found=1;
                            break;
                        }
                        strcpy(str1,"");
                        fscanf(fin,"%s",str1);//,subscriptionNo);
                }
                if(!found)
                {
                    cout<<"\nRecord not found";
                }
                break;

                default:exit(0);
            }//inner switch

            break;

            case 2:
                cout<<"\nEnter any username to delete:";
                getchar();
                gets(name);
                fclose(fin);
                fin=fopen("signUp.txt","r");
                fscanf(fin,"%s",str1);//,subscriptionNo);
                //cout<< "This line worked: "<< str1;
                while(fin !=NULL && strcmp(str1,"-1")!=0)
                {
                    //cout<<"\nStr 1 = "<<str1;
                    //char str[]=fread();
                    if(strcmp(str1,name)==0)
                    {
                        cout<<"Record found\n";
                        found=1;
                        strcpy(str1,"");
                        fscanf(fin,"%s",str1);
                        strcpy(str1,"");
                        fscanf(fin,"%s",str1);
                        strcpy(str1,"");
                        fscanf(fin,"%s",str1);
                    }
                    else
                    {
                        fprintf(f2,"%s\n",str1);
                        strcpy(str1,"");
                        fscanf(fin,"%s",str1);
                        //cout<<"\nStr 1=  "<<str1;
                    }

                        //,subscriptionNo);
                }//ewhile
                if(!found)
                {
                    cout<<"\nRecord not found";
                }
                fprintf(f2,"-1\n");
                fclose(f2);
                fclose(fin);

                fin=fopen("signUp.txt","w");
                f2=fopen("file2.txt","r");
                strcpy(str1,"");
                fscanf(f2,"%s",str1);
                while(f2 !=NULL && strcmp(str1,"-1")!=0)
                {
                    fprintf(fin,"%s\n",str1);
                    strcpy(str1,"");
                    fscanf(f2,"%s",str1);
                }
                fprintf(fin,"-1\n");
                fclose(f2);
                fclose(fin);

                break;

            default:exit(0);

        }//outter switch
    }//Outter while

}

int login()
{
    int ch=0;
    char name[100],password[100];
    int c=0,counter=0;
    FILE *fout;
    int success=0;
    fout=fopen("signUp.txt","a");

    while(1==1)
    {
        cout<< "\nPress:\n1:To Login\n2:To Signup:\nAny other no. to exit\n";
        cin>>ch;
        strcpy(password,"");
        counter=0;
        switch(ch)
        {
            case 1:cout << "Enter your username: ";
            cin>> name;
            cout<< "\nEnter your password: ";


            while((c=getch())!=13)
            {
                putchar('*');
                password[counter++]=c;
            }
            password[counter]='\0';
            success=check(name,password,1);
            if(success && strcmp(name,"admin")==0)
            {
                AdminPowers();
                return 1;
            }

            if(!success)
            {
                cout<< "\nWrong Login Credentials\n";
            }
            success=0;
            break;

            case 2:
                cout<< "Enter any username: ";
                cin>> name;
                getchar();
                cout<< "Enter any pwd: ";
                while((c=getch())!=13)
                {
                    putchar('*');
                    password[counter++]=c;
                }
                password[counter]='\0';
                //cout <<"Line 1";
                success=check(name,password,2);
                //cout <<"Line 2";
                if(success==1)
                {
                    cout << "\nSign Up successful\n";
                    fprintf(fout,"%d\n",1024);// use a random fn to create a random no. here instead of 1024
                    fprintf(fout,"%s\n",name);
                    fprintf(fout,"%s\n",password);
                    return 1;
                }
                success=0;
                break;

            default:exit(0);
        }


    }
    return 0;
}
