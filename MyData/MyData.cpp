// MyData.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <regex>
using namespace std;

bool CalFeb(int a){
	if(!(a%100)){
		if(!(a%400)){
			return true;
		}
		else
			return false;
	}
	else if(!(a%4)){
		return true;
	}
	else
		return false;
}

int _tmain(int argc, _TCHAR* argv[]){
	//ѭ��ʵ��
	//������
 	int year=0, month=0, day=0;
	regex reg("^(\\d+)([\\.\\-\\/])([1-9]|1[0-2])([\\.\\-\\/])([1-9]|[1-2][0-9]|3[0-1])$");
	string str;
	bool match=false;
	cout<<"�����������ղ���.-��/����"<<endl;
	while(!match){
		cin>>str;
		smatch result;		
		match=regex_search(str,result,reg);
		if(!match){
			cout<<"��ʽ���������������ڲ��Ϸ�!\n����.-��/���������ղ�������ȷ������"<<endl;
		}
		year=atoi(result[1].str().c_str());
		month=atoi(result[3].str().c_str());
		day=atoi(result[5].str().c_str());					
	}

	/*	while(month<=0||month>12||day<=0||day>31){
		scanf("%d%d%d", &year, &month, &day);
		if(month<=0||month>12||day<=0||day>31){
			char err[]="��������ȷ������";
			printf("%s\n",err);
	}
	}*/
 	bool calfeb=CalFeb(year);
 	int arr_month[12]={31,0,31,30,31,30,31,31,30,31,30,31};	
 	if(calfeb){
 		arr_month[1]=29;
 	}
 	else{
 		arr_month[1]=28;
 	}
 	int total=0;
 	for(int i=0;i<month-1;i++){
 		total+=arr_month[i];
 	}
 	total+=day;
 	char str1[]="���������Ϊ����ĵ�";
 	char str2[]="��";
 	printf("%s%d%s\n",str1,total,str2);
 	//������
	printf("%s\n","������һ����ݺ�һ���������Կո����");
 	int total_day=0;
 	int iYear,iMonth,iDay;
 	while(total_day<=0||total_day>366){
 		scanf("%d%d",&iYear,&total_day);
 		if(total_day<=0||total_day>366){
 			char err[]="��������ȷ������";
 			printf("%s\n",err);
 		}
 	}
 	bool checkFeb=CalFeb(iYear);
 	if(checkFeb)
 		arr_month[1]=29;
 	else
 		arr_month[1]=28;
 	int total_temp=0;
 	for(int i=0;i<12;i++){
 		total_temp+=arr_month[i];
 		if(total_temp>total_day){
 			iMonth=i+1;
 			iDay=arr_month[i]-(total_temp-total_day);
			break;
 		}
 	}

 	char str3[]="�������������Ϊ";
 	printf("%s%d-%d-%d\n",str3,iYear,iMonth,iDay);
 	return 0;
	//�㷨ʵ��
	//int iYear,iMonth,iDay;
	//scanf("%d%d%d",&iYear,&iMonth,&iDay);
	//int iTotal=iDay;
	//int Feb=2;
	//if((iYear%4==0&&iYear%100!=0)||iYear%400==0)
	//	Feb=1;
	////for(int i=1;i<iMonth;i++){
	////	iTotal+=30+(i/8+i)%2-(i==2)*Feb;
	////}
	//iTotal=(iMonth-1)*30+iDay-(iMonth>=2)*Feb+(iMonth<=8)*(iMonth-iMonth%2)/2+(iMonth>8)*(iMonth+iMonth%2)/2;
	//printf("%d\n",iTotal);
}

