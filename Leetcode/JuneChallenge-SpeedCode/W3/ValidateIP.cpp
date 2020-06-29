class Solution {
public:
    string validIPAddress(string IP) {
        if(count(IP.begin(),IP.end(),'.')==3){
            if(IP[IP.size()-1]=='.')
                return "Neither";
            stringstream ss(IP);
            string token;
            while(getline(ss,token,'.')){
                int len=token.length();
                for(auto c: token) if(!isdigit(c))  return "Neither";
                if(len>3 || len==0 || (token[0]=='0' && len!=1) || stoi(token)>255)    return "Neither";
            }
            return "IPv4";
        }
        else if(count(IP.begin(),IP.end(),':')==7){
            if(IP[IP.size()-1]==':')
                return "Neither";
            stringstream ss(IP);
            string token;
            while(getline(ss,token,':')){
                int len=token.length();
                if(len>4 || len==0 )    return "Neither";
                for(auto c: token) if(!isxdigit(c))  return "Neither";
            }
            return "IPv6";
        }
        return "Neither";
    }
};