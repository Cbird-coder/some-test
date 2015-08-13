#include<stdio.h>
#include<string.h>

#define LEN 4096

int text_c(FILE *fp)
{
	char buffer[LEN];
	int i=0,count=0;

	while(fgets(buffer,LEN,fp)!=NULL)
	{
		while(buffer[i]!='\0')
		{
			if(buffer[i]!='\n' && buffer[i]!=' ')
				++count;
		    i++;
		}
		i=0;
	}
	return count;
}

int text_l(FILE *fp)
{
	char buffer[LEN];
	int  count=0;
	while(fgets(buffer,LEN,fp)!=NULL)
				++count;
	return count;
}

int text_w(FILE *fp)
{
    char buffer[LEN];
	int i=0,count=0;
	while(fgets(buffer,LEN,fp)!=NULL)
	{
		while(buffer[i]!='\0')
		{
			if(buffer[i]==' ' || buffer[i]==',' || buffer[i]=='.' || buffer[i]=='!' ||buffer[i]=='?')
				 ++count;
		    i++;
		}
		i=0;
	}
	return count;
}

int main()
{
	FILE *fp;
	char choice;
	int data;
	fp=fopen("F:\\paperandtechnology\\C_proj_code\\wc\\passkey.txt","r+");
	if(fp==NULL)
		printf("no file found!please check your path!");
	choice=getchar();
	switch(choice)
	{
	    case 'l':
           data=text_l(fp);
		   fclose(fp);
		   printf("line:%d\n",data);
		   break;
		case 'c':
		   data=text_c(fp);
		   fclose(fp);
		   printf("character:%d\n",data);
		   break;
		case 'w':
		   data=text_w(fp);
		   fclose(fp);
		   printf("word:%d\n",data);
		   break;
		default:
			break;
	}
}
