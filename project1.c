#include<stdio.h>
#include<string.h>
//hello choising choice 1 will for some reason not make the functions work so please try to start from 2 to see that it is working thank u.

typedef struct
{
  char city[200];
  char country[200];
  double tourist;
  char famous[300];
} city_info;

int content (FILE *);
void loading (FILE *, city_info[]);
int ranking (city_info[], char[], int);	/* the char is the name of the city */
int info (city_info[],char[/*array to fill*/],int);
       /* the int is the ranking call ranking function inside.int in return fo if it exisit or doest */
int sorting(city_info[],double,char[],int);/* the double is the new tourist no. the last char is the city name we want to know the thing about*/
      /*int in return fo if it exisit or doest */
int finding(city_info [],char [],int);
int delete(city_info[], char[/*the country to look for*/],int);


int menu ()
{
  int choice;
  printf (" Please enter the number of your choice\n");
  printf ("-------------------------------------\n");
  printf
    ("1. View File Content\n 2. Load File Data to an Array\n 3. Get ranking of a city X\n 4. Get Information about a city X\n 5. Update the number of yearly tourists of a city X\n 6. Find the most visited cities in a country X\n 7. Remove a city from the ranking\n 8. Quit\n");
  printf ("-------------------------------------\n");
  scanf ("%d", &choice);
  getchar ();
  return choice;
}

int content (FILE * fl)
{

  char line[200];
  int count = 0;
  int i = 0;

  while (fgets (line, 200, fl) != NULL)
    {
      if (count % 25 == 0)
	{
	  i++;
	  printf (" click enter to see the next 5 cities\n");
	  getchar ();
	}
      printf ("%s", line);
      count++;

    }
  return count / 5;
}

void loading (FILE * fl, city_info arr[]) {
    int i = 0;
	char c;
	char line[80];

    while (!feof (fl)) {
    fgets (arr[i].city, 200, fl);
    arr[i].city[strcspn(arr[i].city, "\r\n")] = 0; 
    fgets (arr[i].country, 200, fl);
    arr[i].country[strcspn(arr[i].country, "\r\n")] = 0;
    fscanf (fl, "%lf\n", &arr[i].tourist); 
	
    fgets (arr[i].famous, 300, fl);
    arr[i].famous[strcspn(arr[i].famous, "\r\n")] = 0; 
    fgets (line, 80, fl); 

  i++;
}}

int ranking (city_info arr[], char look_city[200], int city_num)
{
  int i;
 

  for (i = 0; i < city_num; i++)
    {
      if (strcmp (arr[i].city, look_city) == 0)
	{
	  return i +1 ;
	}    }
  return -1;

}

 int info(city_info arr[],char look_city[200],int city_num){
	int i, rank;
  for (i = 0; i < city_num; i++)
    {
      if (strcmp (arr[i].city, look_city) == 0)
	{
	  return i ;
	}}
  return -1;}

  int sorting(city_info arr[],double tour_up,char look_city[],int city_num){
int a;
int i, j, flag; 
city_info temp[200];

  for (a = 0; a < city_num; a++)
    {
      if (strcmp (arr[a].city, look_city) == 0)
	{
		arr[a].tourist = tour_up;

   		 for (i = 0; i < city_num; i++) {
        flag = 0;
        for (j = 0; j < city_num- 1 - i; j++) {
            if (arr[j].tourist > arr[j + 1].tourist) {
                strcpy(temp[j].city ,arr[j].city);
                strcpy(temp[j].country,arr[j].country);
				strcpy(temp[j].famous,arr[j].famous);
				temp[j].tourist= arr[j].tourist;
				
			    strcpy(arr[j].city,arr[j+1].city);
			    strcpy(arr[j].country,arr[j+1].country);
			    strcpy(arr[j].famous,arr[j+1].famous);
			    arr[j].tourist = arr[j+1].tourist;
			    
			    strcpy(arr[j+1].city,temp[j].city);
			    strcpy(arr[j+1].country,temp[j].country);
			    strcpy(arr[j+1].famous,temp[j].famous);
			    arr[j+1].tourist = temp[j].tourist;
			    
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
	  return 0 ;
	}    }
  return -1;

}

int finding(city_info arr[],char look_country[200],int city_num){ 
    int countryFound = 0; 
	int i; 
	FILE* new_fl;
	int flag=0;
    
		for (i = 0; i < city_num ; i++){
            if (strcmp(arr[i].country, look_country ) == 0) {
				if(flag==0){
					 new_fl = fopen("countries_looked.txt", "w");
					 flag = 1 ;
				}
				fprintf(new_fl, "%s\n%s\n",arr[i].city,arr[i].famous);
            }}
			if(flag==1){
				return 0;
				fclose(new_fl);
			}
			else
				return -1;
}

int delete(city_info arr[], char look_city[200], int city_num) {
    int a, i;
    
    for (a = 0; a < city_num; a++) {
        if (strcmp(arr[a].city, look_city) == 0) {
            
            for (i = a; i < city_num - 1; i++) {

                strcpy(arr[i].city, arr[i+1].city);
                strcpy(arr[i].country, arr[i+1].country);
                strcpy(arr[i].famous, arr[i+1].famous);
                arr[i].tourist = arr[i+1].tourist;
            } 
            return 0;
        }
    }
    
    return -1;
}

int main ()
{
  int choice, city_num = 50, rank, c,close=0,num;
  FILE *fl;
  city_info arr[200];
  char look_city[200], look_country[200];
  double tour_up;



  fl = fopen ("data.txt", "r");


  if (fl != NULL)
    {

      while (choice != 8)
	{
	  choice = menu ();
	  switch (choice)
	    {
	    case 1:
	      num = content (fl);
	      printf (" \n there are %d of cities\n",num);
	      printf ("please enter another choice if you want or quit\n");
	      scanf ("%d", &choice);
	      break;
	    case 2:
	      loading (fl, arr);
	      printf("please enter another choice from 3-7 if you want to continue or 8 to quit\n");
	      scanf ("%d", &choice);
	      getchar ();
		  fclose (fl);
		 close = 1;
		 break;

		 if(close = 1){
	      
	    		case 3:

		 		 printf("Enter the city you want the ranking for:\n");
        		  fgets(look_city, sizeof(look_city), stdin);

      		   	  look_city[strcspn(look_city, "\r\n")] = 0;
	            
				  rank = ranking (arr, look_city, city_num);

				  if (rank == -1)
				    {
		 	     printf ("the city doesnt exist\n");
		   		 }
				  else
				    {
			      printf ("the ranking for the city %s is %d\n",
			      look_city, rank);
			    }
		 		 break;

	   			 case 4:

				  c = info(arr,look_city,city_num);
			     printf (" enter the city you want the information for:\n");
				  fgets (look_city, sizeof (look_city), stdin);

				  look_city[strcspn(look_city, "\r\n")] = 0;
				  getchar();
		   		  if(c == 0){
		 		    printf("the city doesnt exist\n");
		 		    break;} 
		   		  else{
		   		  rank = ranking(arr,look_city,city_num); 
		   		  printf("%s is ranked %d ", look_city, rank);
		   		  printf("located in %s receiving %lf tourists yearly ",arr[c].country,arr[c].tourist);
		   		  printf("and the most visited place is %s.\n",arr[c].famous);}
		   		  break; 

	   			 case 5:

				  printf (" enter the city you want to update its tourists number\n");
				  fgets (look_city, sizeof (look_city), stdin);
				  look_city[strcspn(look_city, "\r\n")] = 0;
				  getchar();

				  printf("please enter the number of tourists you want to apdate to\n");
				  scanf ("%lf", &tour_up);
				  getchar();
				   c = sorting( arr,tour_up , look_city,city_num);
				  if (c == -1)
		 		   printf ("the city doesnt exist\n");
		 		   else{
		 	       printf("the update has been done successfully");
		  		  }
		  		break;
		  
	  			  case 6:
				  printf (" enter the country you want \n");
				  fgets (look_country, sizeof (look_country), stdin);
				  look_country[strcspn(look_city, "\r\n")] = 0;
				  getchar();
		
				  c = finding( arr, look_country, city_num);
		  
				  if (c == -1)
				    {
		 	     printf ("the country doesnt exist\n");
		  		    break;}
					  else{
		    	  printf (" A new file has been created\n"); }
		 		 break;
		 		 
	   			 case 7:
				 printf("Enter the city you want to delete :\n");
        		  fgets(look_city, sizeof(look_city), stdin);

      		   	  look_city[strcspn(look_city, "\r\n")] = 0;

				  c = delete(arr,look_city, city_num);
				
		 		 if (c == -1)
				    {
			      printf ("the city doesnt exist\n");
		 	     break;
				    }
				  else
				    {
				        city_num -= 1;
			      printf (" the array has been updated \n");
				    }
				  

	    default:
		  printf
		    (" You entered a wrong number or if you chose from 3-7 without picking 2. enter a new one\n");

		  break;
		}
	    }
	}}
    
  else
    printf (" The file doesnt exist\n");

  return 0;
}




