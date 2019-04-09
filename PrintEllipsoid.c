 #include <stdio.h>
 #include <malloc.h>

 int main()
 {
   /* Creates the 3D space matrix.*/
   char ***array;

   /* x, y, z are respectively the number of rows, columns and planes. */
   int x, y, z;

   /*
      i, j and k are the variables that will be increased in the "for"s during manipulations.
      a, b and c are the distances from the center of the ellipsoid to its shell.
    */
   int i, j, k, a, b, c;

   /* v is the variable that will receive the numerical value of the ellipsoid expression. */
   float v;

   /* "scanf"s that receive the 3D space dimensions that surrounds the ellipsoid. */
   printf("Choose the number of rows: ");
   scanf ("%d", &x);

   printf("Choose the number of columns: ");
   scanf ("%d", &y);

   printf("Choose the number of planes: ");
   scanf ("%d", &z);

   /* a, b, and c receive the distances from the center of the ellipsoid. */
   a=(x-1)/2;
   b=(y-1)/2;
   c=(z-1)/2;

   /* Dynamic memory allocation for the three-dimensional array. */
   array = (char***)malloc(x*sizeof(char**));
   array[0] = (char**)malloc(x*y*sizeof(char*));
   array[0][0] = (char*)malloc(x*y*z*sizeof(char));

   for(i = 1; i < x; i++){
     array[i] = array[i-1]+y;
     for(j = 1; j < y; j++){
       array[i-1][j] = array[i-1][j-1]+z;
       if(j==(y-1)){
         array[i][0] = array[i-1][j]+z;
       }
     }
   }

   for(j = 1; j < y; j++){
     array[x-1][j] = array[x-1][j-1]+z;
   }

   /* Fills the 3D space with the ellipsoid. */
   for (k = 0; k < z; k++) {
     for (i = 0; i < x; i++) {
       for (j = 0; j < y; j++) {
         /* Value of the ellipsoid equation. */
         v=(((i-a)*(i-a)/(float)(a*a))
         + (((j-b)*(j-b))/(float)(b*b))
         + (((k-c)*(k-c))/(float)(c*c)));
         if(v<=1.0){
           /* 64 represents the "@" of the ASCII Table. */
           array[i][j][k]=64;
         }else{
           /* 32 represents the " " of the ASCII Table. */
           array[i][j][k]=32;
         }
       }
     }
   }

   /* Plane choice variable. */
   int plano=0;

   /* "While" that shows the planes, stops when you choose a nonexistent plane. */
   printf("Choose a plane from 0 to %d: ", z-1);
   scanf("%d", &plano);
   while ((plano>=0)&&(plano<=(z-1))){
     printf("\n");
     for (i = 0; i < x; i++) {
       for (j = 0; j < y; j++) {
         printf("%c",array[i][j][plano]);
       }
       printf("\n");
     }
     printf("\n");
     printf("Choose a plane from 0 to %d: ", z-1);
     scanf("%d", &plano);
   }

   /* Frees the "malloc" memory. */
   free(array[0][0]);
   free(array[0]);
   free(array);

   /* End of code. */
   printf("\nThe End.\n");

   return 0;
 }
