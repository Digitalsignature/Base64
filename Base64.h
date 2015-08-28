/**********************************************************************
* Base64 library.
* version: 1.5
*
* July, 5th, 2015
*
* This lib was written by DucThang
* Contact:thangdn.tlu@outlook.com
*
* Every comment would be appreciated.
*
* If you want to use parts of any code of mine:
* let me know and
* use it!
**********************************************************************
base64_encode(file binary)
base64_decode(file base64)
**********************************************************************/
#ifndef BASE64_H
#define BASE64_H

#include <string>
#include <iostream>
#include <gmpxx.h>
using namespace std;
typedef ZZZ mpz_class;

/*input is binary code*/
string base64_encode(string code)
{
    string encode;
    ZZZ convert_number;
    int counter=0;
    for(int i=code.length()%6;i<6;i++)
    {
        code+='0';
        counter++;
    }
    for(int i=0;i<code.length();i+=6)
    {
        convert_number.set_str(code.substr(i,6),2);
        long ka=convert_number.get_ui();
        if(ka<26) ka+=65;
        else if(ka<52)ka+=71;
        else if(ka<62)ka-=4;
        else if(ka==62)ka=43;
        else if(ka==63)ka=47;
        encode+=(char)ka;
    }
    if(counter==2)encode+='=';
    else{
        if(counter==4)encode+="==";
    }
    return encode;
}
/*input is base64 code*/
string base64_decode( string code)
{
    string decode;
    ZZZ convert_number;
    long ka;
    int i=0;
    for(;i<code.length();i++)
    {
        ka=code[i];
        if(ka<='Z'&& ka>='A') ka-=65;
        else if(ka>='a'&&ka<='z')ka-=71;
        else if(ka<='9'&&ka>='0')ka+=4;
        else if(ka=='+')ka=62;
        else if(ka=='/')ka=63;
        else if(ka=='=') break;
        convert_number=ka;
        string ma=convert_number.get_str(2);
        for(int j=0;j<6-ma.length();j++)
        {
            decode+='0';
        }
        decode+=ma;
    }

    if(code.length()-i==2)decode.erase(decode.length()-4,5);
    else if(code.length()-i==1)decode.erase(decode.length()-2,3);

    return decode;
}


#endif // BASE64_H
