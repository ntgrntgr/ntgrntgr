/*Create ways to delete from each and every recording method*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Workout{
        int number;
        char name[15];
        int code;
}WO;

/*********************************
***********PROTOTYPES*************
*********************************/

void addWO();
void display1();
void prompt();
void delWO();
void del(char *,int);
void display2();
void reps_sets(char *);
void reps_sets_del(char * );
void length_duration(char *);
void distance(char *);
void height(char *);
void test();

/****************************************
*************MAIN FUNCTION***************
****************************************/

int  main(){
     
     //char name[10] = "plank";
     //height(name);
     //addWO();
     //prompt();
     //display1();
     //delWO();
     //test();
}

/***************************************
***************************************/
void addWO(){
     int i,j,k,l;
     i = k = j = 0;
     char wo[25];
     FILE *ptr1;
     FILE *ptr1_counter;
     FILE *ptr2;
     FILE *ptr2_counter;
     ptr1 = fopen("dash.txt","r");
     ptr1_counter = fopen("dash_count.dat","r");
     i = getw(ptr1_counter);
     fclose(ptr1_counter);
     WO workout[i];
     for(j=0;j<i-1;j++){
        fscanf(ptr1,"%d\t%s\t%d\n",&workout[j].number,workout[j].name,&workout[j].code);
        }
     fclose(ptr1);

     system("clear");
     printf("Enter Workout Name: ");
     scanf("%s",wo);
     printf("-----Choose a measuring method-----\n");
     printf("1.\tsets&reps\n2.\tduration\n3.\tdistance");
     printf("\n4.\theight\n\nEnter your selection(1-4):");
     scanf("%d",&l);
     if(l>0 && l<5){

     for(j=0;j<i-1;j++){
        if(strcmp(workout[j].name,wo) == 0 ){
        k++;
        }
     }
     if(k==0){

     ptr2 = fopen(wo,"w");
     fclose(ptr2);

     ptr1 = fopen("dash.txt","a");
     fprintf(ptr1,"%d\t%s\t%d\n",i,wo,l);
     fclose(ptr1);

     ptr1_counter = fopen("dash_count.dat","w");
     i++;
     putw(i,ptr1_counter);
     fclose(ptr1_counter);


     strcat(wo,"_c");
     ptr2_counter = fopen(wo,"w");
     putw(1,ptr2_counter);
     fclose(ptr2_counter);
     }
     }
}
void display1(){
     int i,j;
     FILE *ptr1_counter;
     ptr1_counter = fopen("dash_count.dat","r");
     j = getw(ptr1_counter);
     fclose(ptr1_counter);
     if(j>1){
     do{
          prompt();
          printf("Enter your selection: ");
          scanf("%d",&i);
     }while(i != 0);
     }
     else
     {
     printf("You have no workouts\n");
     }
}
void prompt(){
     char myChar;
     FILE *ptr1;
     ptr1 = fopen("dash.txt","r");
     while((myChar = fgetc(ptr1)) != EOF){
          putchar(myChar);
     };
     fclose(ptr1);
}
void delWO(){
     int i,j;
     FILE *ptr1_counter;
     ptr1_counter = fopen("dash_count.dat","r");
     j = getw(ptr1_counter);
     fclose(ptr1_counter);
     if(j > 1){
     prompt();
     printf("Enter your selection: ");
     scanf("%d",&i);
     char name[15] = "dash.txt";
     del(name,i);
     }
     else
     {
     printf("You have no Workouts\n");
     }

}
void del(char *pointer,int x){
     int i;
     FILE *ptr1_counter;
     ptr1_counter = fopen("dash_count.dat","r");
     i = getw(ptr1_counter);
     fclose(ptr1_counter);
     WO wo[i];
     FILE *temp_dash;
     FILE *ptr1;

     ptr1 = fopen(pointer,"r");
     for(int j=0;j<i-1;j++){
        fscanf(ptr1,"%d\t%s\t%d\n",&wo[j].number,wo[j].name,&wo[j].code);
        }

        fclose(ptr1);
        ptr1 = fopen(pointer,"w");
        int n = 1;
     for(int j=0;j<i-1;j++){

        if(wo[j].number != x){

        fprintf(ptr1,"%d\t%s\t%d\n",n,wo[j].name,wo[j].code);
        n++;
        }
        else{
             remove(wo[j].name);
             strcat(wo[j].name,"_c");
             remove(wo[j].name);
        }
        }
        fclose(ptr1);
        if(i>1){
        i--;
        }
        else
        {
        test();
        }
        ptr1_counter = fopen("dash_count.dat","w");
        putw(i,ptr1_counter);
        fclose(ptr1_counter);
}
void display2(){
}
void reps_sets(char *pointer){
     int i,j,sets,reps;
     char counter[15];
     sets = 1;
     reps = 0;
     do
     {
     printf("----Set %d----",sets);
     printf("Enter 0 to exit\nEnter Number of reps: ");
     scanf("%d",&i);
     sets++;
     reps += i;
     }while(i != 0);
     sets = sets-2;
     if(reps>0){
     FILE *ptr2;
     FILE *ptr2_counter;
     strcpy(counter,pointer);
     strcat(counter,"_c");
     ptr2_counter = fopen(counter,"r");
     j = getw(ptr2_counter);
     fclose(ptr2_counter);
     if(j>0){
     ptr2 = fopen(pointer,"a");
     fprintf(ptr2,"%d\t%d sets\t%d reps\n",j,sets,reps);
     fclose(ptr2);
     j++;
     ptr2_counter = fopen(counter,"w");
     putw(j,ptr2_counter);
     fclose(ptr2_counter);
     }
     else
     {
     printf("\nError\n");
     }
     }
}
void rep_sets_del(char *pointer){
     char counter[15];
     strcpy(counter,"_c");
}
void length_duration(char *pointer){
     FILE *ptr2;
     FILE *ptr2_counter;
     char counter[15];
     char data_n[3][8] = {"hours","minutes","seconds"};
     int  data_v[3];
     int i,j,k;
     strcpy(counter,pointer);
     strcat(counter,"_c");
     ptr2_counter = fopen(counter,"r");
     i = getw(ptr2_counter);
     fclose(ptr2_counter);
     /*********************************
     *********************************/
     if(i>0){
        for(k=0;k<3;k++){
           printf("%s ",data_n[k]);
           scanf("%d",&data_v[k]);  
        }
        if((data_v[0]+data_v[1]+data_v[2])>0){
        ptr2 = fopen(pointer,"a");
        fprintf(ptr2,"%d\tH:%d\tM:%d\tS:%d\n",i,data_v[0],data_v[1],data_v[2]);
     fclose(ptr2);
     i++;
     ptr2_counter = fopen(counter,"w");
     putw(i,ptr2_counter);
     fclose(ptr2_counter);
     }
     }
}
void distance(char *pointer){
     FILE *ptr2;
     FILE *ptr2_counter;
     char counter[15];
     int i;
     strcpy(counter,pointer);
     strcat(counter,"_c");
     ptr2_counter = fopen(counter,"r");
     i = getw(ptr2_counter);
     fclose(ptr2_counter);
     if(i>0){
     float km;
     printf("Enter number of kilometers:\n");
     scanf("%f",&km);
     if(km>(float)0){
     ptr2 = fopen(pointer,"a");
     fprintf(ptr2,"%d\t%f km\n",i,km);
     fclose(ptr2);
     i++;
     ptr2_counter = fopen(counter,"w");
     putw(i,ptr2_counter);
     fclose(ptr2_counter);
     }
     } 
}
void height(char *pointer){
     FILE *ptr2;
     FILE *ptr2_counter;
     char counter[10];
     int i;
     strcpy(counter,pointer);
     strcat(counter,"_c");
     ptr2_counter = fopen(counter,"r");
     i = getw(ptr2_counter);
     fclose(ptr2_counter);
     if(i>0){
     float j;
     printf("Enter a reached height in meters: ");
     scanf("%f",&j);
     if(j>(float)0){
     ptr2 = fopen(pointer,"a");
     fprintf(ptr2,"%d\t%f-meters\n",i,j);
     fclose(ptr2);
     i++;
     ptr2_counter = fopen(counter,"w");
     putw(i,ptr2_counter);
     }
     }
}
void test(){
     int i = 1;
     FILE *ptr;
     ptr = fopen("dash_count.dat","w");
     putw(i,ptr);
     fclose(ptr);
}
