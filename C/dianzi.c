#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#define Max_Size 100/*定义数组长度*/

typedef struct _USER_Info/*记录用户账户*/
{
	int no;/*店铺号*/
	char user_count[20];/*账户*/
	char user_code[20];/*密码*/
}USER,*PUSER;

typedef struct _GOOD/*记录用户账户*/
{
	char name[20];/*商品名*/
	int num;//商品数量
	float price;//价格
}GOOD,*PGOOD;

typedef struct _SHOP/*记录用户账户*/
{
	int no;/*店铺号*/
	char name[20];/*店铺名*/
	int num;//商品数
	GOOD goods[10];//商品信息
}SHOP,*PSHOP;

/*
*函数功能:注册用户
*参数1:PUSER user 传递用户数组首地址
*参数2:int* n     传递数组长度变量地址
*/
void User_Regest(PUSER user,int* n)
{
	system("cls");//清屏
	user[*n].no = -1;//无店铺
	printf("请输入用户账号:");
	scanf("%s",user[*n].user_count);//直接加入到数组尾部  *n为数组最后一个元素
	printf("请输入用户密码:");
	scanf("%s",user[*n].user_code);
	printf("注册成功!\n");
	system("pause");//暂停
	(*n)++;//数组长度+1
}

/*
*函数功能:输入账号密码登录
*参数1:PUSER user 传递用户数组首地址
*参数2:int n      传递数组长度
*返回值:-3代表登录失败
*返回值:[0,n-1]中的任意一个 代表登录成功的用户或管理员数组下标
*/
int Log_In(PUSER user,int n)
{
	int i;
	char name[20],code[20];//记录账号密码
	system("cls");
	printf("请输入账号:");
	scanf("%s",name);
	fflush(stdin);//情况输入流 避免读取回车
	printf("请输入密码:");
	i=0;
	while(code[i]=getch())//循环获取输入流数据赋值给code[i]
	{
		if(code[i] == '\r')//如果获取的字符为回车
		{
			code[i]='\0';//给字符串添加结尾
			printf("\n");//输出回车
			break;//跳出获取字符
		}
		printf("*");//如果输入的不是回车  在屏幕输出*代替按键
		i++;//下标+1
	}

	for(i=0;i<n;i++)//遍历用户结构体数组
	{
		if(!strcmp(name,user[i].user_count)&&!strcmp(code,user[i].user_code))//如果账号密码都正确
		{
			break;//跳出循环
		}
	}

	if(i==n)//如果一直没跳出循环 说明账号密码不对
	{
		printf("密码不正确!\n");
		system("pause");
		return -3;//返回-3代表账号密码不正确
	}

	printf("登录成功!\n");
	system("pause");
	return i;//返回i是查找到的用户或管理员在数组内的位置下标
}


/*
*函数功能:提供用户主选择菜单
*参数1:PUSER user 传递用户数组首地址
*参数2:int* n     传递数组长度地址
*返回值:-2代表退出系统
*返回值:[0,n-1]中的任意一个 代表登录成功的用户或管理员数组下标
*/
int Main_Menu(PUSER user,int*n)/*主菜单*/
{
 int chioce,flag;/*记录选择与函数返回值*/
 do{
	 system("cls");
	 printf("1:登录\n");
     printf("2:注册\n");
	 printf("0:退出系统\n");
	 printf("请输入选择:");//提供选择菜单
	 scanf("%d",&chioce);//获取选择
	 while (chioce<0||chioce>2)//判断选择是否正确 是否是0-3范围
	 {
		 printf("请重新输入:");//不正确重新获取
		 scanf("%d",chioce);
	 }

	 flag=-1;//初始化为-1

	 switch(chioce)
	 {
	 case 1:
		 flag=Log_In(user,*n);/*返回编号为用户下标 或者登陆失败-2*/
		 break;
	case 2:
		 User_Regest(user,n);/*注册用户*/
		 break;
	case 0:
		flag = -2;//退出程序
		break;
	 }

	 if(flag==-2)
	 {
		return flag;/*退出程序*/
	 }
	  else if(flag==-3)
	  {
		  ;//登录失败 不操作
	  }
	  else if(flag==-1)
	  {
		;//选择了2功能 不操作
	  }
	  else//返回说明登录成功
	  {
		  break;//跳出循环
	  }
	}while(chioce!=0);
	 return flag;//返回用户下标
 }


/*
*函数功能:保存用户信息
*参数1:PUSER user 传递套餐数组首地址
*参数2:int n      传递数组长度
*/
void Save_USER_File(PUSER user,int n)
{
	int i;
	FILE* fp=fopen("user.txt","w+");//用写的方式打开文件
	if(fp==NULL)//打开失败则返回
	{
		return ;
	}
	for(i=0;i<n;i++)	//循环写入文件
	{
		fwrite(&user[i],sizeof(USER),1,fp);//每次写入一个结构体大小
	}
	fclose(fp);//关闭文件
}

/*
*函数功能:加载用户信息
*参数1:PUSER user 传递套餐数组首地址
*/
int Load_USER_File(PUSER user)
{
	int i=0;
	FILE* fp=fopen("user.txt","r+");//用读的方式打开文件
	if(fp==NULL)//打开失败则返回
	{
		return 0;
	}
	while(fread(&user[i],sizeof(USER),1,fp))	//每次读取一个结构体大小
	{
		i++;//直到读取到文件结尾
	}
	fclose(fp);//关闭文件
	return i;//返回读取到的数据长度
}


/*
*函数功能:保存用户信息
*参数1:PUSER user 传递套餐数组首地址
*参数2:int n      传递数组长度
*/
void Save_Shop_File(PSHOP shop,int n)
{
	int i;
	FILE* fp=fopen("shop.txt","w+");//用写的方式打开文件
	if(fp==NULL)//打开失败则返回
	{
		return ;
	}
	for(i=0;i<n;i++)	//循环写入文件
	{
		fwrite(&shop[i],sizeof(SHOP),1,fp);//每次写入一个结构体大小
	}
	fclose(fp);//关闭文件
}

/*
*函数功能:加载用户信息
*参数1:PUSER user 传递套餐数组首地址
*/
int Load_Shop_File(PSHOP shop)
{
	int i=0;
	FILE* fp=fopen("shop.txt","r+");//用读的方式打开文件
	if(fp==NULL)//打开失败则返回
	{
		return 0;
	}
	while(fread(&shop[i],sizeof(SHOP),1,fp))	//每次读取一个结构体大小
	{
		i++;//直到读取到文件结尾
	}
	fclose(fp);//关闭文件
	return i;//返回读取到的数据长度
}

/*
*函数功能:开通商店
*参数1:PUSER user 传递套餐数组首地址
*参数2:int who    传递用户数组首地址
*参数3:PSHOP shop 传递数组长度地址
*参数4:int n      传递数组长度地址
*返回值:新的商店数
*/
int Open_Shop(PUSER user,int who,PSHOP shop,int n)
{
	system("cls");
	if(user[who].no != -1)//-1说明没开通
	{
		printf("已开通店铺，无需重新开通!\n");
		system("pause");
		return n;
	}
	printf("请输入店铺号:");
	scanf("%d",&user[who].no);
	shop[n].no=user[who].no;
	printf("请输入店铺名:");
	scanf("%s",shop[n].name);
	shop[n].num=0;//商品数量为0
	printf("店铺开通成功!\n");
	n++;//商铺数+1
	system("pause");
	return n;
}

/*
*函数功能:更新商品信息
*参数1:PUSER user 传递套餐数组首地址
*参数2:int who    传递用户数组首地址
*参数3:PSHOP shop 传递数组长度地址
*参数4:int n      传递数组长度地址
*/
void Updata_Goods_Info(PUSER user,int who,PSHOP shop,int n)
{
	int i,j;
	system("cls");
	if(user[who].no == -1)//如果商铺未开通
	{
		printf("未开通店铺，无法上货!\n");
		system("pause");
		return ;
	}
	for(i=0;i<n;i++)//遍历数组 查找商店信息
	{
		if(user[who].no==shop[i].no)
		{
			break;//找到
		}
	}
	j=shop[i].num;//获取商品数量
	printf("请输入商品名称:");
	scanf("%s",shop[i].goods[j].name);
	printf("请输入商品数量:");
	scanf("%d",&shop[i].goods[j].num);
	printf("请输入商品价格:");
	scanf("%f",&shop[i].goods[j].price);
	shop[i].num++;//商品数量+1
	printf("上货成功!\n");
	system("pause");
}


/*
*函数功能:搜索商铺信息
*参数1:PSHOP shop 传递数组长度地址
*参数2:int n      传递数组长度地址
*/
void Serach_Shop_Info(PSHOP shop,int n)
{
	int i,j;
	char name[20];
	system("cls");
	printf("请输入要查找的店铺名称:");
	scanf("%s",name);
	for(i=0;i<n;i++)
	{
		if(!strcmp(name,shop[i].name))
		{
			break;//找到
		}
	}
	if(i==n)//数组遍历完成未跳出  说明没有找到
	{
		printf("无该店铺!\n");
		system("pause");
		return ;
	}
	printf("%-10s%-10s%-10s\n","商品名","数量","单价");//输出提示信息
	for(j=0;j<shop[i].num;j++)//遍历商品 依次输出
	{
		printf("%-10s",shop[i].goods[j].name);
		printf("%-10d",shop[i].goods[j].num);
		printf("%-10.2f\n",shop[i].goods[j].price);
	}
	system("pause");
}

/*
*函数功能:搜索商品信息
*参数1:PSHOP shop 传递数组长度地址
*参数2:int n      传递数组长度地址
*/
void Serach_Goods_Info(PSHOP shop,int n)
{
	int i,j;
	char name[20];
	system("cls");
	printf("请输入要查找的商品名称:");
	scanf("%s",name);

	printf("%-10s%-10s%-10s%-10s\n","店铺名","商品名","数量","单价");

	for(i=0;i<n;i++)//遍历店铺
	{
		for(j=0;j<shop[i].num;j++)//遍历商品
		{
			if(!strcmp(name,shop[i].goods[j].name))//如果有该名字的商品 则输出商店及商品信息
			{
				printf("%-10s",shop[i].name);
				printf("%-10s",shop[i].goods[j].name);
				printf("%-10d",shop[i].goods[j].num);
				printf("%-10.2f\n",shop[i].goods[j].price);
			}
		}
	}


	system("pause");
}

/*
*函数功能:输出所有商品信息
*参数1:PSHOP shop 传递数组长度地址
*参数2:int n      传递数组长度地址
*/
void Print_All_Goods_Info(PSHOP shop,int n)
{
	int i,j;
	system("cls");
	for(i=0;i<n;i++)//遍历店铺 依次输出所有商品信息
	{
		printf("%-10s%-10s\n","店铺名","店铺号");
		printf("%-10s",shop[i].name);
		printf("%-10d\n",shop[i].no);

		printf("%-10s%-10s%-10s\n","商品名","数量","单价");
		for(j=0;j<shop[i].num;j++)//遍历商品
		{
			printf("%-10s",shop[i].goods[j].name);
			printf("%-10d",shop[i].goods[j].num);
			printf("%-10.2f\n",shop[i].goods[j].price);
		}
		printf("\n");
	}
	system("pause");
}

/*
*函数功能:购买商品
*参数1:PSHOP shop 传递数组长度地址
*参数2:int n      传递数组长度地址
*/
void Buy_Goods(PSHOP shop,int n)
{
	int i,j,flag=0,which,count;
	char name[20];
	system("cls");
	printf("请输入要购买的商品名称:");
	scanf("%s",name);

	for(i=0;i<n;i++)//遍历所有商铺
	{
		for(j=0;j<shop[i].num;j++)//遍历所有商品
		{
			if(!strcmp(name,shop[i].goods[j].name))//如果找到则显示商品信息店铺信息
			{
				if(flag==0)//如果是第一个商品 打印提示信息
				{
					printf("%-10s%-10s%-10s%-10s%-10s\n","店铺号","店铺名","商品名","数量","单价");
					flag=1;//说明已经输出过了提示信息
				}
				printf("%-10d",shop[i].no);
				printf("%-10s",shop[i].name);
				printf("%-10s",shop[i].goods[j].name);
				printf("%-10d",shop[i].goods[j].num);
				printf("%-10.2f\n",shop[i].goods[j].price);
			}
		}
	}
	if(!flag)//说明一件商品都没有找到
	{
		printf("该商品无商家出售!\n");
		system("pause");
		return ;
	}
	printf("请输入要购买的店铺号:");
	scanf("%d",&which);//获取商铺号 根据商铺号和商品名 确定商品
	for(i=0;i<n;i++)//遍历商店
	{
		if(which==shop[i].no)//如果是需要的店铺号
		{
			for(j=0;j<shop[i].num;j++)//遍历商品
			{
				if(!strcmp(name,shop[i].goods[j].name))//如果名称也一样
				{
					goto S0;//跳转到S0
				}
			}
		}
	}
S0:
	printf("%-10s%-10s%-10s%-10s%-10s\n","店铺号","店铺名","商品名","数量","单价");
	printf("%-10d",shop[i].no);
	printf("%-10s",shop[i].name);
	printf("%-10s",shop[i].goods[j].name);
	printf("%-10d",shop[i].goods[j].num);
	printf("%-10.2f\n",shop[i].goods[j].price);//打印商品信息
	printf("请输入要购买的数量:");//获取购买数量
	scanf("%d",&count);
	if(count>shop[i].goods[j].num)//如果要购买的数量大于剩余数量
	{
		printf("商品数量不足，购买失败!\n");//则购买失败
		system("pause");
		return ;
	}
	printf("共需付款%10.2f\n",shop[i].goods[j].price*count);//显示需要付款
	shop[i].goods[j].num-=count;//剩余商品数更新
	printf("商品购买成功!\n");
	system("pause");
}


/*
*函数功能:用户主菜单
*参数1:PUSER user 传递套餐数组首地址
*参数2:int who    传递用户数组首地址
*参数3:PSHOP shop 传递数组长度地址
*参数4:int n      传递数组长度地址
*/
int User_Menu(PUSER user,int who,PSHOP shop,int n)
{
	int chioce;/*记录选择与函数返回值*/
    do
	{
		 system("cls");
		 printf("1:搜索店铺\n");
		 printf("2:浏览商品\n");
		 printf("3:查询商品\n");
		 printf("4:购买商品\n");
		 printf("5:开启店铺\n");
		 printf("6:店铺上货\n");
		 printf("0:返回主菜单\n");
		 printf("请输入选择:");//提供选择菜单
		 scanf("%d",&chioce);//获取选择

		 while (chioce<0||chioce>6)//判断选择是否正确 是否是0-6范围
		 {
			 printf("请重新输入:");//不正确重新获取
			 scanf("%d",chioce);
		 }
		 switch(chioce)//根据选择进入相应功能
		 {
		 case 1:
			 Serach_Shop_Info(shop,n);//查找商铺
			 break;
		 case 2:
			 Print_All_Goods_Info(shop,n);//打印所有商品
			 break;
		 case 3:
			 Serach_Goods_Info(shop,n);//查找商品
			 break;
		 case 4:
			 Buy_Goods(shop,n);//购买商品
			 break;
		 case 5:
			 n=Open_Shop(user,who,shop,n);//开通店铺
			 break;
		 case 6:
			 Updata_Goods_Info(user,who,shop,n);//上货
			 break;
		 }
	}while(chioce!=0);
	return n;
}



/*
*主函数  程序入口点
*/
 int main()
 {
	 int flag;

	 USER user[Max_Size];/*记录用户数据*/
	 SHOP shop[Max_Size];/*记录商铺数据*/
	 int user_num=0;/*记录用户数量*/
	 int shop_num=0;/*记录店铺数量*/
	 user_num = Load_USER_File(user);//加载用户数据
	 shop_num = Load_Shop_File(shop);//加载商店数据
	 do
	 {
		 flag = Main_Menu(user,&user_num);//运行主菜单
		 if(flag == -2)//如果主菜单选择了0 返回-2 就是退出程序
		 {
			 Save_USER_File(user,user_num);//保存数据后 退出
			 Save_Shop_File(shop,shop_num);
			 exit(0);
		 }
		 shop_num=User_Menu(user,flag,shop,shop_num);
	 }while(1);
	return 0;
 }
