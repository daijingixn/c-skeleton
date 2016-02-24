#include "stdio.h"
#include<stdlib.h>
typedef struct man{
	int number;
	char name[10];
	long telephonenumber;
	int label;
	}MAN;

void dayinxinxi(MAN xinxi){
	int j;
	printf("%d\n",xinxi.number);
	for(j=0;xinxi.name[j];j++)
		printf("%c",xinxi.name[j]);
	printf("\n");
	printf("电话号码：%ld\n",xinxi.telephonenumber);
}



void find(char *filename)/*查找通讯录中的信息*/{
	FILE *fp;
	int i,j,x,y;
	long dianhua;
	char xingming[10];
	MAN s[100],t;
	fp=fopen(filename,"rb");
	fread(s,sizeof(MAN),100,fp);
	fclose(fp);
	printf("请选择你的查询方式。1为输入编号查询，2为输入姓名查询，3为输入电话号码查询。\n");
	scanf("%d",&x);
	if(x==1){
		printf("请输入编号\n");
		scanf("%d",&y);
		for(i=0;i<100;i++){
			if(s[i].label==0)break;
			if(s[i].number==y){
				dayinxinxi(s[i]);
					}
				}
		}
	else if(x==2){
		printf("请输入联系人姓名\n");
		scanf("%s",xingming);
		getchar();
		for(i=0;i<100;i++){
			if(s[i].label==0)break;
			if (strcmp(s[i].name,xingming)==0)dayinxinxi(s[i]);
				}
		}
	else if(x==3){
		printf("请输入联系人的电话\n");
		scanf("%ld",&dianhua);
		for(i=0;i<100;i++){
			if(s[i].label==0)break;
			if (dianhua==s[i].telephonenumber)dayinxinxi(s[i]);
					}
			}
	else printf("请输入正确的数字");
}
void delete(char *filename)/*删除通讯录中的信息*/{
	FILE *fp;
	int i,j,x,y,a;
	long dianhua;
	char xingming[10];
	MAN s[100],t;
	fp=fopen(filename,"rb");
	fread(s,sizeof(MAN),100,fp);
	fclose(fp);
	printf("请选择你的删除方式。1为输入编号删除，2为输入姓名删除，3为输入电话号码删除。\n");
	scanf("%d",&x);
	if(x==1){
		printf("请输入编号\n");
		scanf("%d",&y);
		for(i=0;i<100;i++){
			if(s[i].label==0)break;
			if(s[i].number==y){
				printf("以下是你想要删除的信息\n");
				dayinxinxi(s[i]);
				printf("确定要删除信息吗?如果确定，请输入1，不确定请输入2\n");
				scanf("%d",&a);
				if(a==1)
				for(j=i;j<100;j++){
					s[j]=s[j+1];
					s[j].number=j+1;
						}
					printf("已经成功删除！\n");
					}
				}
		}
	else if(x==2){
		printf("请输入联系人姓名\n");
		scanf("%s",xingming);
		getchar();
		for(i=0;i<100;i++){
			if(s[i].label==0)break;
			if (strcmp(s[i].name,xingming)==0){
				printf("以下是你想要删除的信息\n");
				dayinxinxi(s[i]);
				printf("确定要删除信息吗?如果确定，请输入1，不确定请输入2\n");
				scanf("%d",&a);
				if(a==1)
				for(j=i;j<100;j++){
					s[j]=s[j+1];
					s[j].number=j+1;
						}
				printf("已经成功删除！\n");
					}									
				}
		}
	else if(x==3){
		printf("请输入联系人的电话\n");
		scanf("%ld",&dianhua);
		for(i=0;i<100;i++){
			if(s[i].label==0)break;
			if (dianhua==s[i].telephonenumber){
				printf("以下是你想要删除的信息\n");
				dayinxinxi(s[i]);
				printf("确定要删除信息吗?如果确定，请输入1，不确定请输入2\n");
				scanf("%d",&a);
				if(a==1)
				for(j=i;j<100;j++){
					s[j]=s[j+1];
					s[j].number=j+1;
						}
					printf("已经成功删除！\n");
					}
					}
			}
	else printf("请输入正确的数字");
	fp=fopen(filename,"wb");
	fwrite(s,sizeof(MAN),100,fp);
	fclose(fp);
	printf("请在输入一次回车后再使用其它功能。\n");
	}
void add(char *filename)/*向通讯录中添加信息*/{
	FILE *fp;
	int i,j;
	MAN s[100],t;
	fp=fopen(filename,"rb");
	fread(s,sizeof(MAN),100,fp);
	fclose(fp);
	for(i=0;i<100;i++)
	if(s[i].label==0){s[i-1].label=1;
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
void print(char *filename)/*打印出通讯录中的所有信息*/
	{FILE *fp;
	int i,j;
	MAN s[100],t;
	fp=fopen(filename,"rb");
	fread(s,sizeof(MAN),100,fp);
	fclose(fp);
	for(i=0;i<100;i++)
	{if(s[i].label!=1)break;
		dayinxinxi(s[i]);
	}
	}
void change(char *filename)/*编辑通讯录中的信息*/
	{FILE *fp;
	int i,j,x,y;
	char xingming[10];
	long dianhua;
	MAN s[100],t;
	fp=fopen(filename,"rb");
	fread(s,sizeof(MAN),100,fp);
	fclose(fp);
	printf("请选择你的编辑方式。1为通过输入编号找到信息编辑，2为通过姓名编辑，3为通过电话号码编辑。\n");
	scanf("%d",&x);
	if(x==1){
		printf("请输入编号\n");
		scanf("%d",&y);
		for(i=0;i<100;i++){
			if(s[i].label==0)break;
			if(s[i].number==y){
			printf("以下为原来的信息\n");
			dayinxinxi(s[i]);
			printf("请输入新的联系人姓名\n");
			scanf("%s",&s[i].name);
			printf("请输入新的联系人电话\n");
			scanf("%ld",&s[i].telephonenumber);
					}
				}
		}
	else if(x==2){
		printf("请输入联系人姓名\n");
		scanf("%s",xingming);
		getchar();
		for(i=0;i<100;i++){
			if(s[i].label==0)break;
			if (strcmp(s[i].name,xingming)==0){
			printf("以下为原来的信息\n");
			dayinxinxi(s[i]);
			printf("请输入新的联系人姓名\n");
			scanf("%s",&s[i].name);
			printf("请输入新的联系人电话\n");
			scanf("%ld",&s[i].telephonenumber);
					}
				}
		}
	else if(x==3){
		printf("请输入联系人的电话\n");
		scanf("%ld",&dianhua);
		for(i=0;i<100;i++){
			if(s[i].label==0)break;
			if (dianhua==s[i].telephonenumber){
			printf("以下为原来的信息\n");
			dayinxinxi(s[i]);
			printf("请输入新的联系人姓名\n");
			scanf("%s",&s[i].name);
			printf("请输入新的联系人电话\n");
			scanf("%ld",&s[i].telephonenumber);
					}
					}
			}
	else printf("请输入正确的数字\n");
	printf("成功修改信息！请在进行下一次操作前先按下回车键\n");
	fp=fopen(filename,"wb");
	fwrite(s,sizeof(MAN),100,fp);
	fclose(fp);
	}
int main(void){
	FILE *fp;	
	char a;/*使用do while循环体可以进行多次操作*/
		do{/*通过输入数字来表达想要实现的功能*/
		printf("提示：输入1为查找信息，输入2为删除信息，输入3为添加信息，输入4为打印所有信息,输入5为修改信息，输入#为退出通讯录。\n");
		scanf("%c",&a);/*在输入完字符后按下回车键，此时会产生多余的回车符，用getchar函数把回车符提走*/
		getchar();
			if(a=='1')
				{find("information.txt");}
			else if(a=='2')
				{delete("information.txt");}
			else if(a=='3')
				{add("information.txt");}
			else if(a=='4')
				{print("information.txt");}
			else if(a=='5')
				{change("information.txt");}
			else if(a=='#')
				{exit(0);}
			else
				{printf("请输入正确的数字\n");}
		}while(a!='#');
}
