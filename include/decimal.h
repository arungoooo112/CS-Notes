#ifndef MY_DECIMAL_H
#define MY_DECIMAL_H
#include <string>
#include <algorithm>
// std::string ten2n(int dec, int n = 10);
// int n2ten(std::string nec, int n = 10); 
// stoi(nec, nullptr, n);

std::string ten2n(unsigned int dec, int n = 10)
{
	std::string ans="";
	do{
		int t=dec%n;
		if(t>=0&&t<=9)	ans+=t+'0';
		else ans+=t-10+'a';
		dec/=n;
	}while(dec!=0);

	std::reverse(ans.begin(),ans.end());
	return ans;
}

unsigned int n2ten(std::string nec, int n = 10)
{
	unsigned int ans=0;
	for(int i=0;i<nec.size();i++)
	{
		char t=nec[i];
		if(t>='0'&&t<='9') ans=ans*n+t-'0';
		else ans=ans*n+t-'a'+10;
	}
	return ans;
}

std::string n2n(std::string nec, int n, int d) 
{
	return ten2n(n2ten(nec, n), d);
}

#endif // MY_DECIMAL_H
