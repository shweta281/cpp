class Solution {
public:
// lcm a,b= a*b / gcd(a,b)
    int gcd(int a, int b){
        if(b==0) return a;
        return gcd(b, a%b);
        }
    int lcm(int a, int b){
        return (a *b)/(gcd(a, b));
        }
    int getDigitden(int i, string ex){
        int temp=0;
        while(i+1<ex.length() ){
            if (ex[i+1]=='+' || ex[i+1]=='-') break;
            // cout<<temp<<" "<<ex[i+1]<<endl;
            temp=(temp*10)+(ex[i+1] - '0');
            // cout<<temp<<endl;
            i++;
            
        }
        return temp;
    }
    //182
    //2
    //10
    //80+2
    int getDigitnum(int i, string ex){
        int temp=0;
        int ans=1;
        while(i-1>=0){
            if (ex[i-1]=='+' || ex[i-1]=='-') break;
            temp=temp+ (ex[i-1]-'0')*ans;
            ans*=10;
            i--;
        }
        if(i-1>=0 && ex[i-1]=='-') temp=-temp;
        return temp;
    }
    string fractionAddition(string ex) {
        int den=1;
        int num=0;
        for (int i=0; i<ex.length(); i++){
            if(ex[i]=='/'){
                den=lcm(den, getDigitden(i, ex));
                // cout<<getDigitden(i, ex)<<endl;
                i+=2;
            }
        }
        for (int i=0; i<ex.length(); i++){
            if(ex[i]=='/'){
                int temp=getDigitnum(i, ex);
                // cout<<temp<<endl;
                num += (den/getDigitden(i, ex)) * temp;
                // cout<<num<<endl;
            }
        }
        string ans="";
        if(num<0){
           ans+='-';
           num=-num; 
        } 
        int temp=gcd(num, den);
        num=num/temp;
        den=den/temp;
        ans+=to_string(num);
        ans+='/';
        ans+=to_string(den);
        return ans;
    }
};
