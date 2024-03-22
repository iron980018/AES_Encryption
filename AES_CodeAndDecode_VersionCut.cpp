#include<iostream>
#include<iomanip>
#include<map>
#include<algorithm>
#include<bitset>
#include<cctype>
#include<sstream>
#include<typeinfo>
#include<string>
#include<string.h>
using namespace std;

string convertToUpperCase(string str) 
{
    for (char &c : str) 
    {
        if (isalpha(c))
            c = toupper(c);     
    }
    return str;
}

const static string S_BOX [256] =
{
    "63", "7C", "77", "7B", "F2", "6B", "6F", "C5", "30", "01", "67", "2B", "FE", "D7", "AB", "76",
    "CA", "82", "C9", "7D", "FA", "59", "47", "F0", "AD", "D4", "A2", "AF", "9C", "A4", "72", "C0",
    "B7", "FD", "93", "26", "36", "3F", "F7", "CC", "34", "A5", "E5", "F1", "71", "D8", "31", "15",
    "04", "C7", "23", "C3", "18", "96", "05", "9A", "07", "12", "80", "E2", "EB", "27", "B2", "75",
    "09", "83", "2C", "1A", "1B", "6E", "5A", "A0", "52", "3B", "D6", "B3", "29", "E3", "2F", "84",
    "53", "D1", "00", "ED", "20", "FC", "B1", "5B", "6A", "CB", "BE", "39", "4A", "4C", "58", "CF",
    "D0", "EF", "AA", "FB", "43", "4D", "33", "85", "45", "F9", "02", "7F", "50", "3C", "9F", "A8",
    "51", "A3", "40", "8F", "92", "9D", "38", "F5", "BC", "B6", "DA", "21", "10", "FF", "F3", "D2",
    "CD", "0C", "13", "EC", "5F", "97", "44", "17", "C4", "A7", "7E", "3D", "64", "5D", "19", "73",
    "60", "81", "4F", "DC", "22", "2A", "90", "88", "46", "EE", "B8", "14", "DE", "5E", "0B", "DB",
    "E0", "32", "3A", "0A", "49", "06", "24", "5C", "C2", "D3", "AC", "62", "91", "95", "E4", "79",
    "E7", "C8", "37", "6D", "8D", "D5", "4E", "A9", "6C", "56", "F4", "EA", "65", "7A", "AE", "08",
    "BA", "78", "25", "2E", "1C", "A6", "B4", "C6", "E8", "DD", "74", "1F", "4B", "BD", "8B", "8A",
    "70", "3E", "B5", "66", "48", "03", "F6", "0E", "61", "35", "57", "B9", "86", "C1", "1D", "9E",
    "E1", "F8", "98", "11", "69", "D9", "8E", "94", "9B", "1E", "87", "E9", "CE", "55", "28", "DF",
    "8C", "A1", "89", "0D", "BF", "E6", "42", "68", "41", "99", "2D", "0F", "B0", "54", "BB", "16"
};

const static string ReS_BOX[256] =
{
    "52", "09", "6A", "D5", "30", "36", "A5", "38", "BF", "40", "A3", "9E", "81", "F3", "D7", "FB",
    "7C", "E3", "39", "82", "9B", "2F", "FF", "87", "34", "8E", "43", "44", "C4", "DE", "E9", "CB",
    "54", "7B", "94", "32", "A6", "C2", "23", "3D", "EE", "4C", "95", "0B", "42", "FA", "C3", "4E",
    "08", "2E", "A1", "66", "28", "D9", "24", "B2", "76", "5B", "A2", "49", "6D", "8B", "D1", "25",
    "72", "F8", "F6", "64", "86", "68", "98", "16", "D4", "A4", "5C", "CC", "5D", "65", "B6", "92",
    "6C", "70", "48", "50", "FD", "ED", "B9", "DA", "5E", "15", "46", "57", "A7", "8D", "9D", "84",
    "90", "D8", "AB", "00", "8C", "BC", "D3", "0A", "F7", "E4", "58", "05", "B8", "B3", "45", "06",
    "D0", "2C", "1E", "8F", "CA", "3F", "0F", "02", "C1", "AF", "BD", "03", "01", "13", "8A", "6B",
    "3A", "91", "11", "41", "4F", "67", "DC", "EA", "97", "F2", "CF", "CE", "F0", "B4", "E6", "73",
    "96", "AC", "74", "22", "E7", "AD", "35", "85", "E2", "F9", "37", "E8", "1C", "75", "DF", "6E",
    "47", "F1", "1A", "71", "1D", "29", "C5", "89", "6F", "B7", "62", "0E", "AA", "18", "BE", "1B",
    "FC", "56", "3E", "4B", "C6", "D2", "79", "20", "9A", "DB", "C0", "FE", "78", "CD", "5A", "F4",
    "1F", "DD", "A8", "33", "88", "07", "C7", "31", "B1", "12", "10", "59", "27", "80", "EC", "5F",
    "60", "51", "7F", "A9", "19", "B5", "4A", "0D", "2D", "E5", "7A", "9F", "93", "C9", "9C", "EF",
    "A0", "E0", "3B", "4D", "AE", "2A", "F5", "B0", "C8", "EB", "BB", "3C", "83", "53", "99", "61",
    "17", "2B", "04", "7E", "BA", "77", "D6", "26", "E1", "69", "14", "63", "55", "21", "0C", "7D"
};

const int overflow = 0x100, modulus2 = 0x11B;

int GaloisMultiplication(string x , string y)
{
    //cout<<"X : "<<x<<", Y : "<<y<<endl;
    int sum = 0 , a , b;
    stringstream ss,ss2;

    ss << hex << x;
    ss >> a;
    ss2 << hex << y;
    ss2 >> b;
    
    //cout<<"A : "<<a<<", B : "<<b<<endl;

    while (b > 0) 
    {
        if (b & 1) 
            sum = sum ^ a;             // if last bit of b is 1, add a to the sum

        b = b >> 1;                           // divide b by 2, discarding the last bit
        a = a << 1;                           // multiply a by 2

        if (a & overflow) 
            a = a ^ modulus2;    // reduce a modulo the AES polynomial
    }
    //cout<<"sum : "<<sum <<endl;
    return sum;
}

string intToHexString(int value) 
{
    stringstream stream;
    stream << hex << value;

    if(value < 16)
    {
        string t = "0";
        t+= stream.str();
        return t;
    }
    else
        return stream.str();
}

// hex add func from https://www.geeksforgeeks.org/how-to-add-two-hexadecimal-numbers/
map<char, int> hex_value_of_dec(void)
{
    // Map the values to decimal values
    map<char, int> m{ { '0', 0 }, { '1', 1 }, 
                      { '2', 2 }, { '3', 3 }, 
                      { '4', 4 }, { '5', 5 }, 
                      { '6', 6 }, { '7', 7 }, 
                      { '8', 8 }, { '9', 9 }, 
                      { 'A', 10 }, { 'B', 11 }, 
                      { 'C', 12 }, { 'D', 13 }, 
                      { 'E', 14 }, { 'F', 15 } };
 
    return m;
}

class aes
{
    public:
        string code(string imsg , string ikey)
        {
            msg = imsg;
            key = ikey;
            hex_msg = StringToHexString(msg);
            hex_key = KeyString2KeyHexString(key);
            hex_msg = convertToUpperCase(hex_msg);
            hex_key = convertToUpperCase(hex_key);

            //cout<<"hex_msg : "<<hex_msg<<endl;
            //cout<<"hex_key : "<<hex_key<<endl;

            hex_msg = AddRoundKey(hex_msg);
            hex_msg = convertToUpperCase(hex_msg);
            //cout<<"after AddRoundKey hex_msg : "<<hex_msg<<endl;
            
            for(int i = 0 ; i < 1 ; i ++)
            {
                hex_msg = SubBytes(hex_msg);
                hex_msg = convertToUpperCase(hex_msg);
                //cout<<"after "<<i<<" SubBytes hex_msg : "<<hex_msg<<endl;
                hex_msg = ShiftRows(hex_msg);
                hex_msg = convertToUpperCase(hex_msg);
                //cout<<"after "<<i<<" ShiftRows hex_msg : "<<hex_msg<<endl;
                hex_msg = MixColumns(hex_msg);
                hex_msg = convertToUpperCase(hex_msg);
                //cout<<"after "<<i<<" MixColumns hex_msg : "<<hex_msg<<endl;
                hex_msg = AddRoundKey(hex_msg);
                hex_msg = convertToUpperCase(hex_msg);
                //cout<<"after "<<i<<" AddRoundKey hex_msg : "<<hex_msg<<endl;
            }
            hex_msg = SubBytes(hex_msg);
            hex_msg = convertToUpperCase(hex_msg);
            //cout<<"after "<<" SubBytes hex_msg : "<<hex_msg<<endl;
            hex_msg = ShiftRows(hex_msg);
            hex_msg = convertToUpperCase(hex_msg);
            //cout<<"after "<<" ShiftRows hex_msg : "<<hex_msg<<endl;
            hex_msg = AddRoundKey(hex_msg);
            hex_msg = convertToUpperCase(hex_msg);
            //cout<<"after "<<" AddRoundKey hex_msg : "<<hex_msg<<endl;

            code_msg =  GetCodedMsg();
            //cout<<"code_msg : "<<code_msg<<endl;
            return code_msg;
        }
        string decode(string icode_msg,string ikey)
        {
            key = ikey;
            code_msg = icode_msg;
            hex_key = KeyString2KeyHexString(key);
            hex_key = convertToUpperCase(hex_key);
            //cout<<"original code msg : "<<code_msg<<endl;

            code_msg =  AddRoundKey(code_msg);
            code_msg = convertToUpperCase(code_msg);
            //cout<<"after 1 addRK : "<<code_msg<<endl;

            for(int i = 0 ; i < 1 ; i ++)
            {
                code_msg = InvShiftRows(code_msg);
                code_msg = convertToUpperCase(code_msg);
                //cout<<"after "<<i<<" InvShiftRows : "<<code_msg<<endl;
                code_msg = InvSubBytes(code_msg);
                code_msg = convertToUpperCase(code_msg);
                //cout<<"after "<<i<<" InvSubBytes : "<<code_msg<<endl;
                code_msg = AddRoundKey(code_msg);
                code_msg = convertToUpperCase(code_msg);
                //cout<<"after "<<i<<" AddRoundKey : "<<code_msg<<endl;
                code_msg = InvMixColumns(code_msg);
                code_msg = convertToUpperCase(code_msg);
                //cout<<"after "<<i<<" InvMixColumns : "<<code_msg<<endl;
            }
            code_msg = InvShiftRows(code_msg);
            code_msg = convertToUpperCase(code_msg);
            //cout<<"last InvShiftRows : "<<code_msg<<endl;
            code_msg = InvSubBytes(code_msg);
            code_msg = convertToUpperCase(code_msg);
            //cout<<"last InvSubBytes : "<<code_msg<<endl;
            code_msg =  AddRoundKey(code_msg);
            code_msg = convertToUpperCase(code_msg);
            //cout<<"last AddRoundKey : "<<code_msg<<endl;
            
            //cout<<"code_msg : "<<code_msg<<endl;
            
            msg = HexStringToString(code_msg);

            return msg;
        }
    private:
        string key="",msg="",code_msg="",hex_msg="",hex_key="";
        string GetCodedMsg()
        {
            return hex_msg;
        }
        string hexXOR(const string& hex_msg, const string& hex_key) 
        {
            // Convert hexadecimal strings to binary strings
            string bin_msg, bin_key;
            for (char c : hex_msg) 
            {
                bitset<4> bits( stoi( string(1, c), 0, 16));
                bin_msg += bits.to_string();
            }
            for (char c : hex_key) 
            {
                bitset<4> bits( stoi( string(1, c), 0, 16));
                bin_key += bits.to_string();
            }

            // Perform XOR operation on each pair of bits
            string result;
            for (size_t i = 0; i < bin_msg.size(); ++i) 
            {
                result += (bin_msg[i] == bin_key[i]) ? '0' : '1';
            }

            // Convert binary result back to hexadecimal
            stringstream ss;
            for (size_t i = 0; i < result.size(); i += 4) 
            {
                bitset<4> bits(result.substr(i, 4));
                ss <<  hex << bits.to_ulong();
            }

            return ss.str();
        }
        string AddRoundKey(string ihex_msg)//XOR
        {
            
            string extend_key="";
            for(int i = 0 ; i < ihex_msg.length()/hex_key.length() ; i++)
                extend_key += hex_key;
            
            return hexXOR(ihex_msg, extend_key);
        }
        string SubBytes(string ihex_msg)
        {
            string temp_hex_msg = "";
            map<char, int> m = hex_value_of_dec();

            for(int i = 0 ; i < ihex_msg.length() ; i+=2)
            {
                temp_hex_msg += S_BOX[m[ihex_msg[i]]*16+m[ihex_msg[i+1]]];
            }
            return temp_hex_msg;
        }
        string ShiftRows(string ihex_msg)
        {
            string temp_hex_msg="";
            string temp_arr[16];
            for(int i = 0 ; i < ihex_msg.length() ; i+=32)
            {
                for(int j = 0 ; j < 32 ; j +=2)
                {
                    //cout<<"hex_msg[J] : "<<hex_msg[j]<<endl;
                    temp_arr[j/2] = to_string(ihex_msg[i*32+j]) + to_string(ihex_msg[i*32+j+1]);
                    //
                }
                /*
                for(int j = 4 ; j < 16 ; j++)
                {
                    cout<<"temp_arr["<<j<<"] : "<<temp_arr[j]<<endl;
                }
                */
                //rotate(first,middle,last)
                //first	 -	the beginning of the original range
                //middle -	the element that should appear at the beginning of the rotated range
                //last	 -	the end of the original range
                rotate(temp_arr + 4,temp_arr + 5, temp_arr +8);
                rotate(temp_arr + 8, temp_arr + 10, temp_arr + 12);
                rotate(temp_arr + 12, temp_arr + 15, temp_arr + 16);
                
                /*
                for(int i = 0 ; i < 16 ; i++)
                {
                    cout<<temp_arr[i]<<endl;
                }
                */
                
                for(int i = 0 ; i < 16 ; i++)
                {
                    for (size_t j = 0; j < temp_arr[i].length(); j += 2) 
                    {
                        string substring = temp_arr[i].substr(j, 2);
                        //cout<<substring<<endl;
                        int ascii_value = stoi(substring);
                        char character = static_cast<char>(ascii_value);
                        temp_hex_msg += character;
                    }
                }
            }
            return temp_hex_msg;
        }
        string MixColumns(string ihex_msg)
        {
            string temp_hex_msg = "";
            string MixArray[4][4] = 
            {
                {"02", "03", "01", "01"},
                {"01", "02", "03", "01"},
                {"01", "01", "02", "03"},
                {"03", "01", "01", "02"}
            };

            string temp_state[16];
            string PlainArray[4][4];

            for(int i = 0 ; i < ihex_msg.length()/32 ; i++)
            {
                
                for(int j = 0 ; j < 32 ; j +=2)
                {
                    string temp_str = "";
                    temp_str += ihex_msg[i*32+j];
                    temp_str += ihex_msg[i*32+j+1];
                    //cout<<"temp_str : "<<temp_str<<", i*32+j = "<<i*32+j<<", ihex_msg = "<<ihex_msg[i*32+j]<<endl;
                    temp_state[j/2] = temp_str;
                    //cout<<"temp_state["<<j/2<<"] : "<<temp_state[j/2]<<endl; 
                }
            }

            /*
            for(int i = 0 ; i < 16 ; i++)
                cout<<"temp_state["<<i<<"] : "<<temp_state[i]<<endl;
            */

            for(int i = 0 ; i < 4 ; i++)
            {
                for(int j = 0 ; j < 4 ; j++)
                {
                    //cout<<"temp_state["<<i*4+j<<"] : "<<temp_state[i*4+j]<<endl;
                    PlainArray[i][j] = temp_state[i*4+j];
                    //cout<<"PlainArray["<<i<<"]["<<j<<"] : "<<PlainArray[i][j]<<endl;
                }
            }
            //https://bbs.kanxue.com/thread-253884.htm
            //定义变量
            string ArrayTemp[4][4];

            for(int i = 0 ; i < 4 ; i++)
            {
                for(int j = 0 ; j < 4 ; j++)
                {
                    ArrayTemp[i][j] = PlainArray[i][j];
                    //cout<<"ArrayTemp["<<i<<"]["<<j<<"] : "<<ArrayTemp[i][j]<<endl;
                }
            }

            //矩阵乘法 4*4
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    PlainArray[i][j] = intToHexString(GaloisMultiplication(MixArray[i][0], ArrayTemp[0][j]) ^
                                                      GaloisMultiplication(MixArray[i][1], ArrayTemp[1][j]) ^
                                                      GaloisMultiplication(MixArray[i][2], ArrayTemp[2][j]) ^
                                                      GaloisMultiplication(MixArray[i][3], ArrayTemp[3][j]));
                    //cout<<"2PlainArray["<<i<<"]["<<j<<"] : "<<PlainArray[i][j]<<endl;
                }
            }

            for(int i = 0 ; i < 4 ; i++)
            {
                for(int j = 0 ; j < 4 ; j++)
                {
                    temp_hex_msg += PlainArray[i][j];
                }
            }
            return temp_hex_msg;
        }
        string InvShiftRows(string ihex_msg)
        {
            string temp_hex_msg="";
            string temp_arr[16];
            for(int i = 0 ; i < ihex_msg.length() ; i+=32)
            {
                for(int j = 0 ; j < 32 ; j +=2)
                {
                    //cout<<"hex_msg[J] : "<<hex_msg[j]<<endl;
                    temp_arr[j/2] = to_string(ihex_msg[i*32+j]) + to_string(ihex_msg[i*32+j+1]);
                }

                /*
                for(int j = 4 ; j < 16 ; j++)
                {
                    cout<<"temp_arr["<<j<<"] : "<<temp_arr[j]<<endl;
                }
                */

                //rotate(first,middle,last)
                //first	 -	the beginning of the original range
                //middle -	the element that should appear at the beginning of the rotated range
                //last	 -	the end of the original range
                rotate(temp_arr + 4,temp_arr + 7, temp_arr +8);
                rotate(temp_arr + 8, temp_arr + 10, temp_arr + 12);
                rotate(temp_arr + 12, temp_arr + 13, temp_arr + 16);
                
                /*
                for(int i = 0 ; i < 16 ; i++)
                {
                    cout<<temp_arr[i]<<endl;
                }
                */
                
                for(int i = 0 ; i < 16 ; i++)
                {
                    for (size_t j = 0; j < temp_arr[i].length(); j += 2) 
                    {
                        string substring = temp_arr[i].substr(j, 2);
                        //cout<<substring<<endl;
                        int ascii_value = stoi(substring);
                        char character = static_cast<char>(ascii_value);
                        temp_hex_msg += character;
                    }
                }
            }
            return temp_hex_msg;
        }
        string InvSubBytes(string ihex_msg)
        {
            //cout<<"Befor InvSub : "<<ihex_msg<<endl;
            string temp_hex_msg = "";
            map<char, int> m = hex_value_of_dec();

            for(int i = 0 ; i < ihex_msg.length() ; i+=2)
            {
                temp_hex_msg += ReS_BOX[m[ihex_msg[i]]*16+m[ihex_msg[i+1]]];
            }

            return temp_hex_msg;
        }
        string InvMixColumns(string ihex_msg)
        {
            string temp_hex_msg = "";
            string MixArray[4][4] = 
            {
                {"0E", "0B", "0D", "09"},
                {"09", "0E", "0B", "0D"},
                {"0D", "09", "0E", "0B"},
                {"0B", "0D", "09", "0E"}
            };

            string temp_state[16];
            string PlainArray[4][4];

            for(int i = 0 ; i < ihex_msg.length()/32 ; i++)
            {
                
                for(int j = 0 ; j < 32 ; j +=2)
                {
                    string temp_str = "";
                    temp_str += ihex_msg[i*32+j];
                    temp_str += ihex_msg[i*32+j+1];
                    //cout<<"temp_str : "<<temp_str<<", i*32+j = "<<i*32+j<<", ihex_msg = "<<ihex_msg[i*32+j]<<endl;
                    temp_state[j/2] = temp_str;
                    //cout<<"temp_state["<<j/2<<"] : "<<temp_state[j/2]<<endl; 
                }
            }

            /*
            for(int i = 0 ; i < 16 ; i++)
                cout<<"temp_state["<<i<<"] : "<<temp_state[i]<<endl;
            */

            for(int i = 0 ; i < 4 ; i++)
            {
                for(int j = 0 ; j < 4 ; j++)
                {
                    //cout<<"temp_state["<<i*4+j<<"] : "<<temp_state[i*4+j]<<endl;
                    PlainArray[i][j] = temp_state[i*4+j];
                    //cout<<"PlainArray["<<i<<"]["<<j<<"] : "<<PlainArray[i][j]<<endl;
                }
            }
            //https://bbs.kanxue.com/thread-253884.htm
            //定义变量
            string ArrayTemp[4][4];

            for(int i = 0 ; i < 4 ; i++)
            {
                for(int j = 0 ; j < 4 ; j++)
                {
                    ArrayTemp[i][j] = PlainArray[i][j];
                    //cout<<"ArrayTemp["<<i<<"]["<<j<<"] : "<<ArrayTemp[i][j]<<endl;
                }
            }

            //矩阵乘法 4*4
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    PlainArray[i][j] = intToHexString(GaloisMultiplication(MixArray[i][0], ArrayTemp[0][j]) ^
                                                      GaloisMultiplication(MixArray[i][1], ArrayTemp[1][j]) ^
                                                      GaloisMultiplication(MixArray[i][2], ArrayTemp[2][j]) ^
                                                      GaloisMultiplication(MixArray[i][3], ArrayTemp[3][j]));
                    //cout<<"2PlainArray["<<i<<"]["<<j<<"] : "<<PlainArray[i][j]<<endl;
                }
            }

            for(int i = 0 ; i < 4 ; i++)
            {
                for(int j = 0 ; j < 4 ; j++)
                {
                    temp_hex_msg += PlainArray[i][j];
                }
            }
            return temp_hex_msg;
        }
        string KeyString2KeyHexString(string ikey)
        {
            stringstream ss;
            string temp_hex_key = "";
            for (int i = 0; i < ikey.length(); i++)
            {
                ss << hex << setw(2) << setfill('0') << static_cast<int>(ikey[i]);
            }
            temp_hex_key = ss.str();
            if(temp_hex_key.length()%32 != 0)
            {
                if(temp_hex_key.length() % 2 == 0)
                {
                    while (temp_hex_key.length()%32 != 0)
                    {
                        temp_hex_key += "0";
                    }
                }
                else
                    cout<<"Some Wrong In KeyToHex() !"<<endl;
            }
            return temp_hex_key;
        }
        string StringToHexString(string imsg)
        {
            stringstream ss;
            string temp_hex_msg;
            // msg
            for (int i = 0; i < imsg.length(); i++)
            {
                ss << hex << setw(2) << setfill('0') << static_cast<int>(imsg[i]);
            }
            temp_hex_msg = ss.str();
            if(temp_hex_msg.length()%32 != 0)
            {
                if(temp_hex_msg.length() % 2 == 0)
                {
                    while (temp_hex_msg.length()%32 != 0)
                    {
                        temp_hex_msg += "00";
                    }
                }
                else
                    cout<<"Some Wrong In MsgToHex() !"<<endl;
            }
            return temp_hex_msg;
        }
        string HexStringToString(string ihex_msg)
        {
            string temp_msg = "";

            if (ihex_msg.length() % 2 != 0)             
                cout << "Invalid hexadecimal string length!" << endl;
            
            for (size_t i = 0; i < ihex_msg.length(); i += 2) 
            {
                string byteString = ihex_msg.substr(i, 2);
                char byte = static_cast<char>(std::stoi(byteString, nullptr, 16));
                temp_msg.push_back(byte);
            }

            return temp_msg;
        }
};

int main()
{
    aes alice;
    aes bob;
    
    string key = "ABCDEFGH12345678",msg="Hello World ! this is AES encryption implementation",code="",ans="",temp="";
    int time = 1 , left = msg.length()%16;
    if(msg.length() > 16)
        time = msg.length()/16 + 1;

    for(int i = 0 ; i < time ; i++)
    {
        temp = "";
        if(i != time -1)
        {
            for(int j = 0 ; j < 16 ; j++)
            {
                temp += msg[i*16+j];                
            }
        }
        else
        {
            for(int j = 0 ; j < left ; j++)
            {
                temp += msg[i*16+j];                
            }
        }
        code = alice.code(temp,key);
        ans += bob.decode(code,key);
    }
    
    
    cout<<ans<<endl;

    return 0;
}