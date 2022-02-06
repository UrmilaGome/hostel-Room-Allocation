#include<stdio.h>
#include<stdlib.h>

typedef struct hostel{
	int rollno;
	char name[30];
	char location[30];
	char gender[6];
	int room_no;
}hostel;

int lower=501, upper=510,rnd;

void create()
{
	int rnd;
	//printf("%d",rnd);

	hostel h;
	FILE *fp = fopen("hostel.txt","a");

	printf("Enter Roll No. :");
	scanf("%d",&h.rollno);

	printf("Enter Name :");
	scanf("%s",&h.name);

	printf("Enter  Locaton :");
	scanf("%s",&h.location);

	printf("Enter Gender :");
	scanf("%s",&h.gender);

	h.room_no = ((rand()%(upper - lower+1))+lower);

	if(h.room_no!=0)

	fwrite(&h,sizeof(hostel),1,fp);

	fclose(fp);
}
int getRoomNo(int room_no)
{
  int allocated=0;
 FILE *fp= fopen("hostel.txt","r");
    hostel h1;
    while(fread(&h1,sizeof(hostel),1,fp))
    {
	if(h1.room_no==room_no)
        {
		allocated=1;
        }
    }
    if(allocated==0)
    {
	return room_no;
    }
    else
    {
	return getRoomNo(((rand()%(upper - lower+1))+lower));
    }
    fclose(fp);
}
void display()
{
	hostel h1;
	printf("\n--------------------------------------------------------------------\n");
	FILE *fp= fopen("hostel.txt","r");
	printf("%-10s%-20s%-15s%-10s%-5s%\n","RollNo","Name","Location","Gender","RoomNo");
	printf("\n----------------------------------------------------------------------\n");
    while(fread (&h1,sizeof(hostel),1,fp))
	printf("%-10d%-20s%-15s%-10s%-5d%\n",h1.rollno,h1.name,h1.location,h1.gender,h1.room_no);
}

int main()
{
	int ch;
	char c;
	do{
		printf("\n1.ALLOCATE NEW ROOM");
		printf("\n2.DISPLAY");
		printf("\n3.EXIT");
		printf("\nEnter your choice:");
		scanf("%d",&ch);


		switch(ch)
		{
			case 1:
				create();
				break;

			case 2:
				display();
				break;

			case 3:printf("\nThanks.....\n");
                    break;

			default:printf("\nEnter valid option!!!!");

		}
		getchar();
		printf("\n\nWant to continue [y/n]");
		scanf("%c",&c);
		}while(c=='y'||c=='Y');

}

