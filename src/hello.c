#include <stdio.h>
#include <stdlib.h>


typedef struct man
{
	int number;/*编号*/
	char name[10];/*姓名*/
	long telephonenumber;/*电话号码*/
	int label;/*标签，在添加联系人信息时起到作用。最多存放100个联系人，已经有信息储存的此项为1，没有则为0*/

}MAN;/*定义通讯录中的每个联系人为结构体形式*/


void Print(MAN temp)
{/*通过这个函数，配合for循环打印出所有联系人信息，也可打印单个联系人信息*/

	int j;

	printf("%d\n",temp.number);

	for(j=0;temp.name[j];j++)

		printf("%c",temp.name[j]);

	printf("\n");

	printf("电话号码：%ld\n",temp.telephonenumber);

}



void find(char *filename)/*查找通讯录中的信息*/
{
	
	FILE *fp;
	int i,j,x,y;
	long telephone;
	char name[10];
	MAN s[100],t;
	fp=fopen(filename,"rb");/*从储存数据的文件中提取数据*/
	fread(s,sizeof(MAN),100,fp);
	fclose(fp);
	printf("请选择你的查询方式。1为输入编号查询，2为输入姓名查询，3为输入电话号码查询。\n");/*因为联系人信息有三项，所以可以采用三种不同方式*/
	scanf("%d",&x);
	if(x==1)
	{
		printf("请输入编号\n");
		scanf("%d",&y);
		for(i=0;i<100;i++)
		{/*通过for循环依次寻找正确信息*/
			
			if(s[i].label==0)
				break;

			if(s[i].number==y)
			{
				Print(s[i]);
		    }
		}

	}

	else if(x==2)
	{
		printf("请输入联系人姓名\n");
		scanf("%s",name);
		getchar();
		for(i=0;i<100;i++)
		{
			if(s[i].label==0)break;
			if (strcmp(s[i].name,name)==0)
				Print(s[i]);
				
		}
	}

	else if(x==3)
	{
		printf("请输入联系人的电话\n");
		scanf("%ld",&telephone);
		for(i=0;i<100;i++)
		{
			if(s[i].label==0)
				break;
			if(telephone==s[i].telephonenumber)
				Print(s[i]);
		}

	}

	else 
		printf("请输入正确的数字");

}


void delete(char *filename)/*删除通讯录中的信息*/
{
	
	FILE *fp;
	int i,j,x,y,a;
	long dianhua;
	char xingming[10];
	MAN s[100],t;
	fp=fopen(filename,"rb");
	fread(s,sizeof(MAN),100,fp);
	fclose(fp);
	printf("        请输入数字选择你的删除方式。\n1:输入编号删除      \n2:输入姓名删除      \n3:输入电话号码删除。\n");
	scanf("%d",&x);
	if(x==1)
	{
		printf("请输入编号\n");
		scanf("%d",&y);
		for(i=0;i<100;i++)
		{
			if(s[i].label==0)break;
			if(s[i].number==y)
			{
				printf("以下是你想要删除的信息\n");
				Print(s[i]);
				printf("确定要删除信息吗?\n如果确定，请输入1，不确定请输入2\n");
				scanf("%d",&a);
				if(a==1)
				for(j=i;j<100;j++)
				{/*通过for循环依次改变原本的联系人顺序，以此删除信息*/
					s[j]=s[j+1];
					s[j].number=j+1;
				}
					printf("已经成功删除！\n");
			}
		}
	}

	else if(x==2)
	{
		printf("请输入联系人姓名\n");
		scanf("%s",xingming);
		getchar();
		for(i=0;i<100;i++)
		{
			if(s[i].label==0)break;
			if(strcmp(s[i].name,xingming)==0)
			{
				printf("以下是你想要删除的信息\n");
				Print(s[i]);
				printf("确定要删除信息吗?\n如果确定，请输入1，不确定请输入2\n");
				scanf("%d",&a);
				if(a==1)
				for(j=i;j<100;j++)
				{
					s[j]=s[j+1];
					s[j].number=j+1;
				}
				printf("已经成功删除！\n");
			}									
		}
	}

	else if(x==3)
	{
		printf("请输入联系人的电话\n");
		scanf("%ld",&dianhua);
		for(i=0;i<100;i++)
		{
			if(s[i].label==0)break;
			if (dianhua==s[i].telephonenumber)
			{
				printf("以下是你想要删除的信息\n");
				Print(s[i]);
				printf("确定要删除信息吗?如果确定，请输入1，不确定请输入2\n");
				scanf("%d",&a);
				if(a==1)
				for(j=i;j<100;j++)
				{
					s[j]=s[j+1];
					s[j].number=j+1;
				}
					printf("已经成功删除！\n");
			}
		}
	}

	else 
		printf("请输入正确的数字");

	fp=fopen(filename,"wb");
	fwrite(s,sizeof(MAN),100,fp);
	fclose(fp);
	printf("请在输入一次回车后再使用其它功能。\n");

}

void add(char *filename)/*向通讯录中添加信息*/
{

	FILE *fp;
	int i,j;
	MAN s[100],t;
	fp=fopen(filename,"rb");
	fread(s,sizeof(MAN),100,fp);
	fclose(fp);
	for(i=0;i<100;i++)
	if(s[i].label==0)
	{
		s[i-1].label=1;
		printf("请输入新联系人的名字\n");
		scanf("%s",&s[i-1].name);
		printf("请输入新联系人的联系电话\n");
		scanf("%ld",&s[i-1].telephonenumber);
		s[i-1].number=i+1;
		break;
	}

	printf("请在输入一次回车后再使用其它功能。\n");
	fp=fopen(filename,"ab");
	fwrite(s+i-1,sizeof(MAN),1,fp);
	fclose(fp);

}

void PrintAll(char *filename)/*打印出通讯录中的所有信息*/
{
	
	FILE *fp;
	int i,j;
	MAN s[100],t;
	fp=fopen(filename,"rb");
	fread(s,sizeof(MAN),100,fp);
	fclose(fp);
	for(i=0;i<100;i++)
	{
		if(s[i].label!=1)break;
			Print(s[i]);
	}

}

void change(char *filename)/*编辑通讯录中的信息*/
{
	
	FILE *fp;
	int i,j,x,y;
	char xingming[10];
	long dianhua;
	MAN s[100],t;
	fp=fopen(filename,"rb");
	fread(s,sizeof(MAN),100,fp);
	fclose(fp);
	printf("         请输入数字选择你的编辑方式。\n1:通过输入编号找到信息编辑      \n2:通过姓名编辑      \n3:通过电话号码编辑      \n");
	scanf("%d",&x);
	if(x==1)
	{
		printf("请输入编号\n");
		scanf("%d",&y);
		for(i=0;i<100;i++)
		{
			if(s[i].label==0)break;
			if(s[i].number==y)
			{
				printf("以下为原来的信息\n");
				Print(s[i]);
				printf("请输入新的联系人姓名\n");
				scanf("%s",&s[i].name);
				printf("请输入新的联系人电话\n");
				scanf("%ld",&s[i].telephonenumber);
			}
		}
	}

	else if(x==2)
	{
		printf("请输入联系人姓名\n");
		scanf("%s",xingming);
		getchar();
		for(i=0;i<100;i++)
		{
			if(s[i].label==0)
				break;
			if(strcmp(s[i].name,xingming)==0)
			{
				printf("以下为原来的信息\n");
				Print(s[i]);
				printf("请输入新的联系人姓名\n");
				scanf("%s",&s[i].name);
				printf("请输入新的联系人电话\n");
				scanf("%ld",&s[i].telephonenumber);
			}
		}
	}
	
	else if(x==3)
	{
		printf("请输入联系人的电话\n");
		scanf("%ld",&dianhua);
		for(i=0;i<100;i++)
		{
			if(s[i].label==0)
				break;
			if(dianhua==s[i].telephonenumber)
			{
				printf("以下为原来的信息\n");
				Print(s[i]);
				printf("请输入新的联系人姓名\n");
				scanf("%s",&s[i].name);
				printf("请输入新的联系人电话\n");
				scanf("%ld",&s[i].telephonenumber);
			}
		}
	}
	
	else 
		printf("请输入正确的数字\n");

	printf("成功修改信息！请在进行下一次操作前先按下回车键\n");
	fp=fopen(filename,"wb");
	fwrite(s,sizeof(MAN),100,fp);
	fclose(fp);

}

int main(void)
{

	FILE *fp;	
	char a;/*使用do while循环体可以进行多次操作*/
	
	do{/*通过输入数字来表达想要实现的功能*/
	
	
		printf("        请输入数字选择您想要进行的操作\n提示：\n1:查找信息      2:删除信息      \n3:添加信息      4:打印所有信息      \n5:修改信息      #:退出通讯录\n");
	
		scanf("%c",&a);/*在输入完字符后按下回车键，此时会产生多余的回车符，用getchar函数把回车符提走*/
	
		getchar();
		
	
		if(a=='1')
		{
			find("information.txt");
		}

		else if(a=='2')
		{
			delete("information.txt");
		}

		else if(a=='3')
		{
			add("information.txt");
		}

		else if(a=='4')	
		{
			PrintAll("information.txt");
		}
		
		else if(a=='5')
		{
			change("information.txt");
		}
			
		else if(a=='#')
		{
			exit(0);
		}
	
		else
		{
			printf("请输入正确的数字\n");
		}

	}while(a!='#');

}
