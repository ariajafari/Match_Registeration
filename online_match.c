#include <stdio.h>
#include <string.h>
int main()
{
    int op,l=1,p=1,m=1,p1,r=0,ctr=0;
    char uname[30];
    char phnumber[20];
    char testname[30];
    char ch1[30],ch2[30],ch3[30];
    char tid[30];
    char pn[30];
    char str[2048];
    FILE* player_list;
    FILE* temp;
    while(l)
    {
        printf("\n1)Register    2)Edit    3)Remove    4)Quit\n\nEnter your choice: ");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            player_list=fopen("players.txt","a+");
            if (player_list==NULL){
            printf("Players\' List Is Not Available\n");
            break;
            }
            printf("\nRegisteration:\n");
            printf("Enter Your User Name:\n");
            scanf("%s",uname);
            fprintf(player_list,"%s ",uname);
            printf("Enter Your Phone Number:\n");
            scanf("%s",phnumber);
            fprintf(player_list,"%s ",phnumber);
            printf("Enter Your Telegram ID:\n");
            scanf("%s",tid);
            fprintf(player_list,"%s\n",tid);
            fclose(player_list);
            break;
        case 2:
            p1=0;
            r=0;
            printf("Editing:\n");
            printf("Enter your User Name or Phone Number:\n");
            scanf("%s",testname);
            player_list=fopen("players.txt","r");
            if (player_list==NULL){
                printf("Players\' List Is Not Available\n");
                break;
            }
            while(fscanf(player_list,"%s %s %s",uname,phnumber,tid)!=EOF){
                p=strcmp(uname,testname);
                m=strcmp(phnumber,testname);
                p1++;
                if(p==0||m==0){
                    r=1;
                    break;
                }
            }
            fclose(player_list);
            //p1++;
            if(r==1){
                player_list=fopen("players.txt","r");
                if (player_list==NULL){
                    printf("Players\' List Is Not Available\n");
                }
                temp=fopen("temp.txt","w+");
                if (temp==NULL){
                    printf("temp file is not available\n");
                }
                ctr=0;
                while (!feof(player_list))
                {
                    char str[2048];
                    strcpy(str,"\0");
                    fgets(str,2048,player_list);
                    if(!feof(player_list)){
                        ctr++;
                        if(ctr!=p1){
                            fprintf(temp,"%s",str);
                        }
                    }
                }
                fclose(player_list);
                fclose(temp);
                remove("players.txt");
                rename("temp.txt","players.txt");
            }
            if(r==0){
                printf("Not Found\n");
            }
            if(r==1){
                player_list=fopen("players.txt","a+");
                if (player_list==NULL){
                printf("Players\' List Is Not Available\n");
                break;
                }
                printf("Enter Your New User Name:\n");
                scanf("%s",uname);
                fprintf(player_list,"%s ",uname);
                printf("Enter Your New Phone Number:\n");
                scanf("%s",phnumber);
                fprintf(player_list,"%s ",phnumber);
                printf("Enter Your New Telegram ID:\n");
                scanf("%s",tid);
                fprintf(player_list,"%s\n",tid);
                fclose(player_list);
            }
            break;
        case 3:
            p1=0;
            r=0;
            printf("Removing:\n");
            printf("Enter your User Name or Phone Number:\n");
            scanf("%s",testname);
            player_list=fopen("players.txt","r");
            if (player_list==NULL){
                printf("Players\' List Is Not Available\n");
                break;
            }
            while(fscanf(player_list,"%s %s %s",uname,phnumber,tid)!=EOF){
                p=strcmp(uname,testname);
                m=strcmp(phnumber,testname);
                p1++;
                if(p==0||m==0){
                    r=1;
                    break;
                }
            }
            fclose(player_list);
            //p1++;
            if(r==1){
                player_list=fopen("players.txt","r");
                if (player_list==NULL){
                    printf("Players\' List Is Not Available\n");
                }
                temp=fopen("temp.txt","w+");
                if (temp==NULL){
                    printf("temp file is not available\n");
                }
                ctr=0;
                while (!feof(player_list))
                {
                    char str[2048];
                    strcpy(str,"\0");
                    fgets(str,2048,player_list);
                    if(!feof(player_list)){
                        ctr++;
                        if(ctr!=p1){
                            fprintf(temp,"%s",str);
                        }
                    }
                }
                fclose(player_list);
                fclose(temp);
                remove("players.txt");
                rename("temp.txt","players.txt");
            }
            if(r==0){
                printf("Not Found\n");
            }
            break;
        case 4:
            printf("Quitting\n");
                l=0;
            break;
        default:
            printf("\n Invalid Input, Please Enter 1, 2, 3 or 4\n");
            break;
        }
    }
   return 0; 
}