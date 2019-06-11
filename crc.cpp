//CRC Code
#include<iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;
int n1,n2,n3;
int result[50];


void XOR(int temp[],int DIV[])
{
	
 //Division
    for(int i=0;i<n1;i++)
    {
       int j=0;
       int  k=i;
        //check whether it is divisible or not
        if (temp[k]>=DIV[j])
        {
            for(j=0,k=i;j<n2;j++,k++)
            {
                if((temp[k]==1 && DIV[j]==1) || (temp[k]==0 && DIV[j]==0))
                {
                    temp[k]=0;
                }
                else
                {
                    temp[k]=1;
                }
            }
        }
    }
}


int main()

{
    int i,j;

	cout<<"Enter the size of Message Bit:";
	cin>>n1;								//Size of msg				
	
	int MSG[n1];
	
	cout<<"Enter bits of message one by one in 0 & 1 only :"<<endl;
	for(i=0;i<n1;i++)
	{
		cout<<"\n"<<i<<" bit : ";
		cin>>MSG[i];						//take msg input
	}
	
	cout<<"Your Entered Bit :";

	for(i=0;i<n1;i++)
	{
		cout<<MSG[i]<<" ";						//take msg input
	}
	
	cout<<endl;
	cout<<"\n\nEnter the  size of div bit :";
	cin>>n2;								//Size of divisor
	
	int DIV[n2];
	
	cout<<"\nEnter div bits:"<<endl;
	for(i=0;i<n2;i++)
	{
		cout<<"Bit "<<i<<": ";
		cin>>DIV[i];						//take div input
	}
	
	cout<<"\nYour Entered Bit :";

	for(i=0;i<n2;i++)
	{
		cout<<DIV[i]<<" ";						//take msg input
	}
    cout<<endl;	



	n3 = n1+(n2-1);
	int MN[n3],temp[n3];
	
	
	for (i=0;i<n1;i++)
	{
		MN[i]=MSG[i];					//copy msg into m+r array
	}
	
	for ( i= n1;i<n3;i++)
	{
		MN[i]=0;						//Add 0 bits in Msg
	}
	
	for(i=0;i<n3;i++)
	{
		temp[i]=MN[i];					//Copy m+r array into temp array
		cout<<MN[i];
	}
	
	XOR(temp,DIV);						//Calling XOR division
		
	
	int crc[50];
    for( i=0, j=n1;i<(n2-1);i++,j++)
    {
        crc[i]=temp[j];					//Copy CRC bits
    }
    
     cout<<endl;
	cout<<"\nCRC bits: ";
    for( i=0;i<(n2-1);i++)
    {
        cout<<crc[i];				//print CRC bits
    }
	 cout<<endl;
	cout<<"\nEncoded Data Send is : ";
    int REC[50];
    int SEN[50];
    for(i=0;i<n1;i++)
    {
        SEN[i]=MSG[i];				//Appending reciever frame 
    }
    for(i=n1,j=0;i<n3;i++,j++)
    {
        SEN[i]=crc[j];				//Appending reciever frame 
    }
    for(i=0;i<n3;i++)
    {
        cout<<SEN[i];				//Display reciever frame
    }
    
    cout<<endl;
    cout<<"Enter Code word received at the receiver side : "<<endl;
    for(i=0;i<n3;i++)
    {
        cin>>REC[i];				//Display reciever frame
    }
    XOR(REC,DIV);
    
   for( i=0, j=n1;i<(n2-1);i++,j++)
    {
        crc[i]=REC[j];					//Copy CRC bits
    }
    
     cout<<endl;
    int count;
	count = 0;
    for( i=0;i<(n2-1);i++)
    {
        if(crc[i] == 1)
		{
			count++;
		}
    }
    if(count == 0)
    {
    	cout<<"Remainder is all zeros. Hence, the Message received has no error. "<<endl;
	}
	else
	{
		cout<<"Remainder is not all zeroes, the error is detected at the receiver side.";
	}
	 cout<<endl;
	
		  

	
	return 0;
}


/*
OUTPUT:
Enter the size of Message Bit:6
Enter bits of message one by one in 0 & 1 only :

0 bit : 1

1 bit : 0

2 bit : 0

3 bit : 1

4 bit : 0

5 bit : 0
Your Entered Bit :1 0 0 1 0 0


Enter the  size of div bit :4

Enter div bits:
Bit 0: 1
Bit 1: 1
Bit 2: 0
Bit 3: 1

Your Entered Bit :1 1 0 1 100100000

CRC bits: 001

Encoded Data Send is : 100100001
Enter Code word received at the receiver side :
1
0
0
1
0
0
1
1
0

Remainder is not all zeroes, the error is detected at the receiver side.

--------------------------------
Process exited after 21.92 seconds with return value 0
Press any key to continue . . .



*/
