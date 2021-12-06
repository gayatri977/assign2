#include <stdio.h>
#include<string.h>
struct cricketer
{
 char name[50];
 char country[50];
 char category[30];
 int age;
 int runs;
 int wickets;
 int ODI_played;
 int T20_played;
 float avg;
}c[20];

int main()
{
 int n,p,max=0,i,temp;
 char country[50],name[30];
 int choice;
 printf("enter no of players: ");
 scanf("%d",&n);

printf("\n information of players:");

 for(int i=0;i<n;i++)
 {
   printf("\nenter the information of player %d:",i+1);

  printf("\nname of cricketer:");
    scanf("%s",c[i].name);

    printf("country of cricketer:");
    scanf("%s",c[i].country);

    printf("age of cricketer:");
    scanf("%d",&c[i].age);

    printf("category of cricketer:");
    scanf("%s",c[i].category);

    printf("runs of cricketer:");
    scanf("%d",&c[i].runs);

    printf("wickets taken by cricketer:");
    scanf("%d",&c[i].wickets);

    printf("no of ODI played:");
    scanf("%d",&c[i].ODI_played);

    printf("no of 20-20 played:");
    scanf("%d",&c[i].T20_played);

    printf("avg score of cricketer:");
    scanf("%f",&c[i].avg);

 }
while(1)
{
printf("\nenter the choice\n1.Number of batsman of a particular country ,\n2.Sort the Batsman as per the average batting score,\n3.Batsman with highest average score\n4.Number of bowlers of a particular country \n5.The bowler that has taken a maximum no of wickets \n6.Show particular players the entire “Display board information”\n7.Exit:");
scanf("%d",&choice);



switch (choice)
{
  case 1:
  p=0;
  printf("enter the country:");
  scanf("%s",country);
  for(i=0; i<n; i++)
    {
        if((strcmp(country,c[i].country)==0)&&(strcmp("batsman",c[i].category)==0))
           p++;
    }
       printf("\nNumber of batsman of  %s = %d \n", country, p);
  break;

  case 2:
 for(i=0;i<n;i++)
 {
   for(int j=0;j<n-1;j++)
   {
    if(c[j].avg>c[j+1].avg)
    {
      temp=c[i].avg;
      c[i].avg=c[j].avg;
      c[j].avg=temp;

    }

   }
 }
printf("\nThe sorted detils of players as per avg batting score:");
printf("\nNo\tName\tCategory\tAvg score");
for(i=0;i<n;i++)
{
  printf("\n%d\t%s\t\t%s\t\t%.2f",i+1,c[i].name,c[i].category,c[i].avg);
}
printf("\n");
  break;

  case 3:
  p=0;
  max=c[0].avg;
  for(i=0;i<n;i++)
  {
    if(strcmp("batsman",c[i].category)==0)
    {
      if(c[i].avg>max)
      {
        max=c[i].avg;
        p=i;
      }
    }
  }
  printf("\nBatsman with highest avg score:%s\n",c[p].name);
   break;


  case 4:
  p=0;
  printf("enter the country:");
  scanf("%s",country);
  for(i=0; i<n; i++)
    {
        if((strcmp(country,c[i].country)==0)&&(strcmp("bowler",c[i].category)==0))
           p++;
    }
       printf("\nNumber of bowler of  %s = %d \n", country, p);
break;

case 5:
for(int i=0;i<n;i++)
  {
      if(strcmp("bowler",c[i].category)==0)
      {
      if (c[i].wickets>max)
       {
         max=c[i].wickets;
         p=i;
       }
      }
 }
  printf("\nBowler who has taken maximum no of wickets:%s\n", c[p].name);
break;

case 6:
printf("enter name:");
scanf("%s",name);

for(i=0;i<n;i++)
{
  if(strcmp(name,c[i].name)==0)
  {
    printf("\nName\tcountry\tcategory\tage\t\tODI_played\tT20_played\t\t\tAvg\t\t\t\truns\t\t\t\twickets\n");
    printf("\n---------------------------------------------------------------------------------------------------");
    printf("\n%s\t%s\t%s\t\t%d\t\t\t%d\t\t\t%d\t\t\t\t%.2f\t\t\t%d\t\t\t%d\n",c[i].name,c[i].country,c[i].category,c[i].age,c[i].ODI_played,c[i].T20_played,c[i].avg,c[i].runs,c[i].wickets);

  }
}

break;

case 7:
printf("Thank you!....program executed successfully!");
goto out;
break;
  }
}
out:;
return 0;

}
