#include<iostream>
#include<sstream>
#include<string>
#include<map>
#include<iterator>

using namespace std;

int main(void)
{
	int n,q;
	cin>>n>>q;
	cin.ignore();
	map<string,string> AVPair;
	map<string,string>::iterator AVit;
	string tag_preamble;
	while(n--)
	{
		string temp;
		getline(cin,temp);
		if(temp[1]=='/')
		{
			temp.erase(0,2);
    	    temp.pop_back();
	        stringstream word;
	        word<<temp;
	        string tag;
	        word>>tag;
	        int tag_size=tag.size();
	        int tag_pos=tag_preamble.find(tag);
			if(tag_preamble.size()>tag_size)
	        	tag_preamble.erase(tag_pos-1,tag_size+1);
			else
				tag_preamble.clear();
		}
		else
		{
			temp.erase(0,1);
			temp.pop_back();
			while(string::npos!=temp.find("="))
			{
				int pos=temp.find("=");
				temp.erase(pos,2);
				pos=temp.find("\"");
				temp.erase(pos,1);
				pos=temp.find("\"");
				temp.erase(pos,1);
			}
			string tag,attribute,value;
			stringstream ss;
			ss<<temp;
			ss>>tag;
			if(tag_preamble.empty())
				tag_preamble=tag;
			else
				tag_preamble=tag_preamble+"."+tag;
			while(!ss.eof())
			{
				ss>>attribute;
				ss>>value;
				AVPair[tag_preamble+"~"+attribute]=value;
			}
		}
	}
	while(q--)
	{
		string query;
		getline(cin,query);
		AVit=AVPair.find(query);
		if(AVit==AVPair.end())
			cout<<"Not Found!"<<endl;
		else
			cout<<AVit->second<<endl;
	}
	return 0;
}
