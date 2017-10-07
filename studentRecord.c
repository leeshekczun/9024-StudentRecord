// Student record implementation ... Assignment 1 COMP9024 17s2
#include <stdio.h>

#define LINE_LENGTH 1024

// scan input for a positive integer, returns -1 if none
int readInt(void) {
   char line[LINE_LENGTH];
   int  n;

   fgets(line, LINE_LENGTH, stdin);
   if ( (sscanf(line, "%d", &n) != 1) || n <= 0 )
      return -1;
   else
      return n;
}

// scan input for a positive floating point number, returns -1 if none
float readFloat(void) {
   char  line[LINE_LENGTH];
   float f;

   fgets(line, LINE_LENGTH, stdin);
   if ( (sscanf(line, "%f", &f) != 1) || f <= 0.0 )
      return -1;
   else
      return f;
}

/*** Your code for stage 1 starts here ***/

int readValidID(void) {
   int ID;   
   ID = readInt();
   while (ID < 1000000 || ID > 9999999){
      printf("Not valid. Enter a valid value: ");
      ID = readInt();
   }   
   return ID;
}

int readValidCredits(void) {
   int Credits;   
   Credits = readInt();
   while (Credits < 2 || Credits > 480)
   {
      printf("Not valid. Enter a valid value: ");
      Credits = readInt();
   }   
   return Credits; 
}

float readValidWAM(void) {
   float WAM;
   WAM = readFloat();
   while (WAM < 50 || WAM > 100)
   {
      printf("Not valid. Enter a valid value: ");
      WAM = readFloat();
   }   
   return WAM; 
}

void printStudentData(int ID, int Credits, float WAM) {
   printf("------------------------\n");
   printf("Student ID: z%d\n", ID);
   printf("Credits: %d\n", Credits);
   printf("Level of performance: ");
   if (WAM > 85) {
      printf("HD\n");
   }
   else if (WAM > 75) {
      printf("DN\n");
   }
   else if (WAM > 65) {
      printf("CR\n");
   }
   else {
      printf("PS\n");
   }
   printf("------------------------\n");   
   return;
}
