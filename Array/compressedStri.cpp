#include <iostream>
#include <cstring>
#include<string>
using namespace std;

string getCompressedString(string &input) {
   int len = input.size();
    if (input[0]=='\0')
    {
        return "";
    }
    string output = "";
    output += input[0];
    int count = 1;
    for (int i = 1; i <= len; i++)
    {
         if(input[i]=='\0'){
            output+=to_string(count);
             continue;
         }
        if (input[i] == input[i - 1])
        {
            count++;
            
            if (i == len)//correction
            {
                output += count;
               
            }

           
        }
        else
        {
            if (count > 1)
            {
                output += count+'0';//as string is of charcater type so change integer to character first then add that number in string
                output += input[i];
            }
            else
            {
                output += input[i];
            }
            count = 1;
        }
    }
    
    return output;
}



int main() {
    int size = 1e6;
    string str;
    cin >> str;
    str = getCompressedString(str);
    cout << str << endl;
}