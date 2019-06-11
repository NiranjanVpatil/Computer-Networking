//Hamming Code
#include<iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;

int main() {

	int db[10],received_db[10];
	int m,r,d,d1;
	int dataatrec[10];
	cout<<"Enter number of Message bits you want to enter "<<endl;
	cin>>m;
	cout<<"Enter "<<m<<" bits of message one by one in 0 & 1 only"<<endl;
	for(int i = 1; i <= m; ++i) {
		cin>>db[i];
	}
	r = 0;
	while (m + r + 1 > pow (2, r)) {
		r++;
	}

	cout <<endl<<"No of data bits to be added " << r << " : Total Bits :" << m + r << endl;

	int data[m + r];
	d = 0;
	d1 = m;
	for (int i = 1; i <= m + r; ++i) {
		if (i == pow (2, d)) {
			data[i] = 0;
			++d;
		} else {
			data[i] = db[d1];
			--d1 ;
		}
	}
	
	int k;
	// parity r1
	int i = 1;
	int count = 0;
	while(i <= m+r) {
		if(data[i] == 1) {
			count++;
		}
		i = i + 2;
	}
	if(count % 2 == 0) {
		data[1] = 0;
	} else {
		data[1] = 1;
	}
	count = 0;


	// parity r2
	int p2[7] = {0,2,3,6,7,10,11};
	for(int j = 1; j <= 6; j++) {
		int l = p2[j];
		if(l <= m+r && data[l] == 1) {
			count++;


		}
	}
	//	even function
	if(count % 2 == 0) {
		data[2] = 0;
	} else {
		data[2] = 1;
	}

	count = 0;
	// parity r3
	for(int k = 4; k < 8; k++) {

		if(data[k] == 1) {
			count++;
		}
	}
	//	even function call
	if(count % 2 == 0) {
		data[4] = 0;
	} else {
		data[4] = 1;
	}
	count = 0;
	//parity r8
	for(int k = 8; k < 12; k++) {
		if(data[k] == 1) {
			count++;
		}
	}
	// even function calll
	if(count % 2 == 0) {
		data[8] = 0;
	} else {
		data[8] = 1;
	}
	///  count = 0;

	cout<<"Sender message is :"<<endl;
	for (int i = 1; i <= m + r; ++i) {
		cout << data[i] << " ";
	}
	cout<<"\n Enter Received Bits One By One on 0 & 1 only: "<<endl;
	for(int i = 1; i <= m+r; ++i) {
		cin>>received_db[i];
	}

	// parity r1
	i = 1;
	count = 0;
	while(i <= m+r) {
		if(received_db[i] == 1) {
			count++;
		}
		i = i + 2;
	}
	if(count % 2 == 0) {
		received_db[1] = 0;
	} else {
		received_db[1] = 1;
	}
	count = 0;


	// parity r2
	int a3[7] = {0,2,3,6,7,10,11};
	for(int j = 1; j <= 6; j++) {
		int e = a3[j];
		if(e <= m+r && received_db[e] == 1) {
			count++;

		}

	}

	//	even function
	if(count % 2 == 0) {
		received_db[2] = 0;
	} else {
		received_db[2] = 1;
	}

	count = 0;
	// parity r3
	for(int k = 4; k < 8; k++) {

		if(received_db[k] == 1) {
			count++;
		}
	}
	//	even function call
	if(count % 2 == 0) {
		received_db[4] = 0;
	} else {
		received_db[4] = 1;
	}
	count = 0;
	//parity r8
	for(int k = 8; k < 12; k++) {
		if(received_db[k] == 1) {
			count++;
		}
	}
	// even function calll
	if(count % 2 == 0) {
		received_db[8] = 0;
	} else {
		received_db[8] = 1;
	}
	///  count = 0;
	cout<<"Received Message is : ";
	for(int i = 1; i <= m+r; ++i) {
		cout<<received_db[i]<<" ";
	}
	cout<<endl;
	int sum = 0;
	int error_bits[r];
	d = 0;
	int s = 0;
	for (int i = 1; i <= m + r; ++i) {
		if (i == pow (2, d)) {
			if(received_db[i] == 1) {
				sum = sum + i;
				error_bits[s] = i;
				s++;
			}
			++d;
		}

	}
	if(sum == 0) {
		cout<<"Received Code is same. No Error"<<endl;
	} else {
		cout<<"Received Code Contains error at bit"<<endl;
		for(int p = 0; p < s; p++) {
			cout<<error_bits[p]<<",";
		}
		cout<<"\n Bad Bits in message is :"<<sum<<endl;
	}

	cout<<endl;
	return 0;

}

/*
Enter number of Message bits you want to enter
6
Enter 6 bits of message one by one in 0 & 1 only
1
0
0
1
0
0

No of data bits to be added 4 : Total Bits :10
Sender message is :
0 0 1 1 0 0 1 0 0 0
 Enter Received Bits One By One on 0 & 1 only:
0
0
1
1
0
0
1
0
1
0
Received Message is : 1010001110
Received Code Contains error at bit
1,8,
 Bad Bits in message is :9


--------------------------------
Process exited after 17.43 seconds with return value 0
Press any key to continue . . .

*/
