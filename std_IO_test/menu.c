#include "uhead.h"
void showMenu()
{
	char filename[100]="abc.txt";
	char buf[1024]="123456";
	int i, select;
	int flag = 1;
	while(flag)
	{
		//system("clear");
		for(i=0;i<30;i++)
		{
			putchar('*');
		}
		putchar('\n');
		printf("0.退出\n");
		printf("1.创建文件\n");
		printf("2.写文件\n");
		printf("3.读文件\n");
		printf("4.查看文件权限\n");
		printf("5.修改文件权限\n");
		for(i=0;i<30;i++)
		{
			putchar('*');
		}
		putchar('\n');
		printf("Please specify your purpose:\n>");
		scanf("%d", &select);
		switch(select)
		{
			case EXIT:
			{
				flag = 0;
				break;
			}
			case CREATE_FILE:
			{
				printf("请输入路径：");
				scanf("%s",filename);
				CreateFile(filename);			
				break;
			}
			case WRITE_FILE:
			{
				
				WriteFile(filename,buf);				
				break;
			}
			case READ_FILE:
			{
			
				ReadFile(filename);			
				break;
			}
			case STAT_FILE:
			{
			
				StatFile(filename);
				break;
			}
			case CHMOD_FILE:
			{
			
				ChmodFile(filename,S_IRWXG);			
				break;
			}
			
			default :
			{
				printf("输入有误！\n");
			}
			//sleep(2000);
		}
		//sleep(20);
		/*getchar();
		system("pause");
		system("clear");*/
	}
}
