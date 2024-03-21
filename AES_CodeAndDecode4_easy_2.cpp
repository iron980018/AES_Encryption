/*

hex_msg : 48656C6C6F576F726C64000000000000
hex_msg : 09272F282E152C362D26434441424344
after 0 SubBytes hex_msg : 01CC153431597105D8F71A1B832C1A1B
after 0 ShiftRows hex_msg : 01CC1534597105311A1BD8F71B832C1A
temp_str : 01, i*32+j = 0, ihex_msg = 0
temp_state[0] : 
temp_str : CC, i*32+j = 2, ihex_msg = C
temp_state[1] : 
temp_str : 15, i*32+j = 4, ihex_msg = 1
temp_state[2] : 
temp_str : 34, i*32+j = 6, ihex_msg = 3
temp_state[3] : 
temp_str : 59, i*32+j = 8, ihex_msg = 5
temp_state[4] : 
temp_str : 71, i*32+j = 10, ihex_msg = 7
temp_state[5] : 
temp_str : 05, i*32+j = 12, ihex_msg = 0
temp_state[6] : 
temp_str : 31, i*32+j = 14, ihex_msg = 3
temp_state[7] : 
temp_str : 1A, i*32+j = 16, ihex_msg = 1
temp_state[8] : 
temp_str : 1B, i*32+j = 18, ihex_msg = 1
temp_state[9] : 
temp_str : D8, i*32+j = 20, ihex_msg = D
temp_state[10] : 
temp_str : F7, i*32+j = 22, ihex_msg = F
temp_state[11] : 
temp_str : 1B, i*32+j = 24, ihex_msg = 1
temp_state[12] : 
temp_str : 83, i*32+j = 26, ihex_msg = 8
temp_state[13] : 
temp_str : 2C, i*32+j = 28, ihex_msg = 2
temp_state[14] : 
temp_str : 1A, i*32+j = 30, ihex_msg = 1
temp_state[15] : 
PlainArray[0][0] : 
PlainArray[0][1] : 
PlainArray[0][2] : 
PlainArray[0][3] : 
PlainArray[1][0] : 
PlainArray[1][1] : 
PlainArray[1][2] : 
PlainArray[1][3] : 
PlainArray[2][0] : 
PlainArray[2][1] : 
PlainArray[2][2] : 
PlainArray[2][3] : 
PlainArray[3][0] : 
PlainArray[3][1] : 
PlainArray[3][2] : 
PlainArray[3][3] : 
after 0 MixColumns hex_msg : 01010101010101010101010101010101
after 0 AddRoundKey hex_msg : 40434245404342454043424540434245
after  SubBytes hex_msg : 091A2C6E091A2C6E091A2C6E091A2C6E
after  ShiftRows hex_msg : 091A2C6E1A2C6E092C6E091A6E091A2C
after  AddRoundKey hex_msg : 48586F2A5B6E2D4D6D2C4A5E2F4B5968
code_msg : 48586F2A5B6E2D4D6D2C4A5E2F4B5968
original code msg : 48586F2A5B6E2D4D6D2C4A5E2F4B5968
after 1 addRK : 091A2C6E1A2C6E092C6E091A6E091A2C
after 0 InvShiftRows : 091A2C6E091A2C6E091A2C6E091A2C6E
after 0 InvSubBytes : 40434245404342454043424540434245
after 0 InvMixColumns : 60554853495779534C5564537F574F53
after 0 AddRoundKey : 21170B1708153A170D1727173E150C17
last InvShiftRows : 21170B171708153A27170D17150C173E
last InvSubBytes : 7B879E8787BF2FA23D87F3872F8187D1
last AddRoundKey : 3AC5DDC3C6FD6CE67CC5B0C36EC3C495
code_msg : 3AC5DDC3C6FD6CE67CC5B0C36EC3C495
:�����l�|Űn�ĕ

*/

/*

hex_msg : 48656C6C6F576F726C64000000000000
hex_msg : 09272F282E152C362D26434441424344
after 0 SubBytes hex_msg : 01CC153431597105D8F71A1B832C1A1B
after 0 ShiftRows hex_msg : 01CC1534597105311A1BD8F71B832C1A
after 0 MixColumns hex_msg : 3A384D4F20513B5A7E7C2F1E4B207320
after 0 AddRoundKey hex_msg : 7B7A0E0B6113781E3F3E6C5A0A623064
after  SubBytes hex_msg : 21DAAB2BEF7DBC7275B250BE67AA0443
after  ShiftRows hex_msg : 21DAAB2B7DBC72EF50BE75B24367AA04
after  AddRoundKey hex_msg : 6098E86F3CFE31AB11FC36F60225E940
code_msg : 6098E86F3CFE31AB11FC36F60225E940
original code msg : 6098E86F3CFE31AB11FC36F60225E940
after 1 addRK : 21DAAB2B7DBC72EF50BE75B24367AA04
after 0 InvShiftRows : 21DAAB2BEF7DBC7275B250BE67AA0443
after 0 InvSubBytes : 7B7A0E0B6113781E3F3E6C5A0A623064
after 0 InvMixColumns : 6C58344071333E497B1A77336A4A5002
after 0 AddRoundKey : 2D1A770430717D0D3A5834772B081346
last InvShiftRows : 2D1A77040D30717D34773A580813462B
last InvSubBytes : FA430230F3082C132802A25EBF82980B
last AddRoundKey : BB014174B24A6F576940E11AFEC0DB4F
code_msg : BB014174B24A6F576940E11AFEC0DB4F
�At�JoWi@����O

*/

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

/*

const unsigned char S_BOX [256] =
{
    0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76,
    0xCA, 0x82, 0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0, 0xAD, 0xD4, 0xA2, 0xAF, 0x9C, 0xA4, 0x72, 0xC0,
    0xB7, 0xFD, 0x93, 0x26, 0x36, 0x3F, 0xF7, 0xCC, 0x34, 0xA5, 0xE5, 0xF1, 0x71, 0xD8, 0x31, 0x15,
    0x04, 0xC7, 0x23, 0xC3, 0x18, 0x96, 0x05, 0x9A, 0x07, 0x12, 0x80, 0xE2, 0xEB, 0x27, 0xB2, 0x75,
    0x09, 0x83, 0x2C, 0x1A, 0x1B, 0x6E, 0x5A, 0xA0, 0x52, 0x3B, 0xD6, 0xB3, 0x29, 0xE3, 0x2F, 0x84,
    0x53, 0xD1, 0x00, 0xED, 0x20, 0xFC, 0xB1, 0x5B, 0x6A, 0xCB, 0xBE, 0x39, 0x4A, 0x4C, 0x58, 0xCF,
    0xD0, 0xEF, 0xAA, 0xFB, 0x43, 0x4D, 0x33, 0x85, 0x45, 0xF9, 0x02, 0x7F, 0x50, 0x3C, 0x9F, 0xA8,
    0x51, 0xA3, 0x40, 0x8F, 0x92, 0x9D, 0x38, 0xF5, 0xBC, 0xB6, 0xDA, 0x21, 0x10, 0xFF, 0xF3, 0xD2,
    0xCD, 0x0C, 0x13, 0xEC, 0x5F, 0x97, 0x44, 0x17, 0xC4, 0xA7, 0x7E, 0x3D, 0x64, 0x5D, 0x19, 0x73,
    0x60, 0x81, 0x4F, 0xDC, 0x22, 0x2A, 0x90, 0x88, 0x46, 0xEE, 0xB8, 0x14, 0xDE, 0x5E, 0x0B, 0xDB,
    0xE0, 0x32, 0x3A, 0x0A, 0x49, 0x06, 0x24, 0x5C, 0xC2, 0xD3, 0xAC, 0x62, 0x91, 0x95, 0xE4, 0x79,
    0xE7, 0xC8, 0x37, 0x6D, 0x8D, 0xD5, 0x4E, 0xA9, 0x6C, 0x56, 0xF4, 0xEA, 0x65, 0x7A, 0xAE, 0x08,
    0xBA, 0x78, 0x25, 0x2E, 0x1C, 0xA6, 0xB4, 0xC6, 0xE8, 0xDD, 0x74, 0x1F, 0x4B, 0xBD, 0x8B, 0x8A,
    0x70, 0x3E, 0xB5, 0x66, 0x48, 0x03, 0xF6, 0x0E, 0x61, 0x35, 0x57, 0xB9, 0x86, 0xC1, 0x1D, 0x9E,
    0xE1, 0xF8, 0x98, 0x11, 0x69, 0xD9, 0x8E, 0x94, 0x9B, 0x1E, 0x87, 0xE9, 0xCE, 0x55, 0x28, 0xDF,
    0x8C, 0xA1, 0x89, 0x0D, 0xBF, 0xE6, 0x42, 0x68, 0x41, 0x99, 0x2D, 0x0F, 0xB0, 0x54, 0xBB, 0x16
};

const unsigned char ReS_BOX[256] =
{
    0x52, 0x09, 0x6A, 0xD5, 0x30, 0x36, 0xA5, 0x38, 0xBF, 0x40, 0xA3, 0x9E, 0x81, 0xF3, 0xD7, 0xFB,
    0x7C, 0xE3, 0x39, 0x82, 0x9B, 0x2F, 0xFF, 0x87, 0x34, 0x8E, 0x43, 0x44, 0xC4, 0xDE, 0xE9, 0xCB,
    0x54, 0x7B, 0x94, 0x32, 0xA6, 0xC2, 0x23, 0x3D, 0xEE, 0x4C, 0x95, 0x0B, 0x42, 0xFA, 0xC3, 0x4E,
    0x08, 0x2E, 0xA1, 0x66, 0x28, 0xD9, 0x24, 0xB2, 0x76, 0x5B, 0xA2, 0x49, 0x6D, 0x8B, 0xD1, 0x25,
    0x72, 0xF8, 0xF6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xD4, 0xA4, 0x5C, 0xCC, 0x5D, 0x65, 0xB6, 0x92,
    0x6C, 0x70, 0x48, 0x50, 0xFD, 0xED, 0xB9, 0xDA, 0x5E, 0x15, 0x46, 0x57, 0xA7, 0x8D, 0x9D, 0x84,
    0x90, 0xD8, 0xAB, 0x00, 0x8C, 0xBC, 0xD3, 0x0A, 0xF7, 0xE4, 0x58, 0x05, 0xB8, 0xB3, 0x45, 0x06,
    0xD0, 0x2C, 0x1E, 0x8F, 0xCA, 0x3F, 0x0F, 0x02, 0xC1, 0xAF, 0xBD, 0x03, 0x01, 0x13, 0x8A, 0x6B,
    0x3A, 0x91, 0x11, 0x41, 0x4F, 0x67, 0xDC, 0xEA, 0x97, 0xF2, 0xCF, 0xCE, 0xF0, 0xB4, 0xE6, 0x73,
    0x96, 0xAC, 0x74, 0x22, 0xE7, 0xAD, 0x35, 0x85, 0xE2, 0xF9, 0x37, 0xE8, 0x1C, 0x75, 0xDF, 0x6E,
    0x47, 0xF1, 0x1A, 0x71, 0x1D, 0x29, 0xC5, 0x89, 0x6F, 0xB7, 0x62, 0x0E, 0xAA, 0x18, 0xBE, 0x1B,
    0xFC, 0x56, 0x3E, 0x4B, 0xC6, 0xD2, 0x79, 0x20, 0x9A, 0xDB, 0xC0, 0xFE, 0x78, 0xCD, 0x5A, 0xF4,
    0x1F, 0xDD, 0xA8, 0x33, 0x88, 0x07, 0xC7, 0x31, 0xB1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xEC, 0x5F,
    0x60, 0x51, 0x7F, 0xA9, 0x19, 0xB5, 0x4A, 0x0D, 0x2D, 0xE5, 0x7A, 0x9F, 0x93, 0xC9, 0x9C, 0xEF,
    0xA0, 0xE0, 0x3B, 0x4D, 0xAE, 0x2A, 0xF5, 0xB0, 0xC8, 0xEB, 0xBB, 0x3C, 0x83, 0x53, 0x99, 0x61,
    0x17, 0x2B, 0x04, 0x7E, 0xBA, 0x77, 0xD6, 0x26, 0xE1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0C, 0x7D
};

*/



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

map<int, char> dec_value_of_hex(void)
{
    // Map the values to the
    // hexadecimal values
    map<int, char> m{ { 0, '0' }, { 1, '1' }, 
                      { 2, '2' }, { 3, '3' }, 
                      { 4, '4' }, { 5, '5' }, 
                      { 6, '6' }, { 7, '7' }, 
                      { 8, '8' }, { 9, '9' }, 
                      { 10, 'A' }, { 11, 'B' }, 
                      { 12, 'C' }, { 13, 'D' }, 
                      { 14, 'E' }, { 15, 'F' } };
 
    return m;
}

string Add_Hex(string a, string b)
{
    map<char, int> m = hex_value_of_dec();
    map<int, char> k = dec_value_of_hex();
 
    // Check if length of string first is
    // greater than or equal to string second
    if (a.length() < b.length())
        swap(a, b);
 
    // Store length of both strings
    int l1 = a.length(), l2 = b.length();
 
    string ans = "";
 
    // Initialize carry as zero
    int carry = 0, i, j;
 
    // Traverse till second string
    // get traversal completely
    for (i = l1 - 1, j = l2 - 1;
         j >= 0; i--, j--) {
 
        // Decimal value of element at a[i]
        // Decimal value of element at b[i]
        int sum = m[a[i]] + m[b[j]] + carry;
 
        // Hexadecimal value of sum%16
        // to get addition bit
        int addition_bit = k[sum % 16];
 
        // Add addition_bit to answer
        ans.push_back(addition_bit);
 
        // Update carry
        carry = sum / 16;
    }
 
    // Traverse remaining element
    // of string a
    while (i >= 0) {
 
        // Decimal value of element
        // at a[i]
        int sum = m[a[i]] + carry;
 
        // Hexadecimal value of sum%16
        // to get addition bit
        int addition_bit = k[sum % 16];
 
        // Add addition_bit to answer
        ans.push_back(addition_bit);
 
        // Update carry
        carry = sum / 16;
        i--;
    }
 
    // Check if still carry remains
    if (carry) {
        ans.push_back(k[carry]);
    }
 
    // Reverse the final string
    // for desired output
    reverse(ans.begin(), ans.end());
 
    // Return the answer
    return ans;
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
            //cout<<"hex_msg : "<<hex_msg<<endl;
            /*
            SubBytes();
            cout<<"hex_msg : "<<hex_msg<<endl;
            ShiftRows();
            cout<<"hex_msg : "<<hex_msg<<endl;
            MixColumns();
            cout<<"hex_msg : "<<hex_msg<<endl;
            */
            
            for(int i = 0 ; i < 9 ; i ++)
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
            //cout<<"original code msg : "<<code_msg<<endl;

            code_msg =  AddRoundKey(code_msg);
            code_msg = convertToUpperCase(code_msg);
            //cout<<"after 1 addRK : "<<code_msg<<endl;

            for(int i = 0 ; i < 9 ; i ++)
            {
                code_msg = InvShiftRows(code_msg);
                code_msg = convertToUpperCase(code_msg);
                //cout<<"after "<<i<<" InvShiftRows : "<<code_msg<<endl;
                code_msg = InvSubBytes(code_msg);
                code_msg = convertToUpperCase(code_msg);
                //cout<<"after "<<i<<" InvSubBytes : "<<code_msg<<endl;
                code_msg = InvMixColumns(code_msg);
                code_msg = convertToUpperCase(code_msg);
                //cout<<"after "<<i<<" InvMixColumns : "<<code_msg<<endl;
                code_msg = AddRoundKey(code_msg);
                code_msg = convertToUpperCase(code_msg);
                //cout<<"after "<<i<<" AddRoundKey : "<<code_msg<<endl;
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
            /**/
            string extend_key="";
            for(int i = 0 ; i < ihex_msg.length()/hex_key.length() ; i++)
                extend_key += hex_key;
            /*
            for (size_t i = 0; i < hex_msg.length(); ++i) 
            {
                
                char c1 = hex_msg[i];
                char c2 = extend_key[i];
                int val1 = (c1 >= '0' && c1 <= '9') ? (c1 - '0') : (c1 - 'A' + 10);
                int val2 = (c2 >= '0' && c2 <= '9') ? (c2 - '0') : (c2 - 'A' + 10);
                int xorResult = val1 ^ val2;
                char hexChar = (xorResult < 10) ? (xorResult + '0') : (xorResult - 10 + 'A');
                temp_hex_msg += hexChar;
                
            }
            */
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
            /*
            unsigned int temp;
            stringstream ss;
            char PlainArray[4][4],temp_state[16];
            string temp_hex_msg = "";
            const unsigned char MixArray[4][4] = 
            {
                {0x02, 0x03, 0x01, 0x01},
                {0x01, 0x02, 0x03, 0x01},
                {0x01, 0x01, 0x02, 0x03},
                {0x03, 0x01, 0x01, 0x02}
            };

            for(int i = 0 ; i < ihex_msg.length()/32 ; i++)
            {
                
                for(int j = 0 ; j < 32 ; j +=2)
                {
                    string temp_str = "";
                    temp_str += ihex_msg[i*32+j];
                    temp_str += ihex_msg[i*32+j+1];
                    cout<<"temp_str : "<<temp_str<<", i*32+j = "<<i*32+j<<", ihex_msg = "<<ihex_msg[i*32+j]<<endl;
                    ss << hex << temp_str;
                    ss >> temp ;
                    temp_state[j/2] = static_cast<char>(temp);
                    cout<<"temp_state["<<j/2<<"] : "<<temp_state[j/2]<<endl; 
                }
            }

            for(int i = 0 ; i < 4 ; i++)
            {
                for(int j = 0 ; j < 4 ; j++)
                {
                    PlainArray[i][j] = temp_state[(i+1)*(j+1)-1];
                    cout<<"PlainArray["<<i<<"]["<<j<<"] : "<<PlainArray[i][j]<<endl;
                }
            }
            */
            //https://bbs.kanxue.com/thread-253884.htm
            //定义变量
            string ArrayTemp[4][4];
        
            //初始化变量
            //memcpy(ArrayTemp, PlainArray, 16);

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
            /*
            unsigned int temp;
            stringstream ss;
            char PlainArray[4][4],temp_state[16];
            string temp_hex_msg = "";
            const unsigned char MixArray[4][4] = 
            {
                {0x02, 0x03, 0x01, 0x01},
                {0x01, 0x02, 0x03, 0x01},
                {0x01, 0x01, 0x02, 0x03},
                {0x03, 0x01, 0x01, 0x02}
            };

            for(int i = 0 ; i < ihex_msg.length()/32 ; i++)
            {
                
                for(int j = 0 ; j < 32 ; j +=2)
                {
                    string temp_str = "";
                    temp_str += ihex_msg[i*32+j];
                    temp_str += ihex_msg[i*32+j+1];
                    cout<<"temp_str : "<<temp_str<<", i*32+j = "<<i*32+j<<", ihex_msg = "<<ihex_msg[i*32+j]<<endl;
                    ss << hex << temp_str;
                    ss >> temp ;
                    temp_state[j/2] = static_cast<char>(temp);
                    cout<<"temp_state["<<j/2<<"] : "<<temp_state[j/2]<<endl; 
                }
            }

            for(int i = 0 ; i < 4 ; i++)
            {
                for(int j = 0 ; j < 4 ; j++)
                {
                    PlainArray[i][j] = temp_state[(i+1)*(j+1)-1];
                    cout<<"PlainArray["<<i<<"]["<<j<<"] : "<<PlainArray[i][j]<<endl;
                }
            }
            */
            //https://bbs.kanxue.com/thread-253884.htm
            //定义变量
            string ArrayTemp[4][4];
        
            //初始化变量
            //memcpy(ArrayTemp, PlainArray, 16);

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
    
    string key = "ABCDABCDABCDABCD",msg="HelloWorld",code="",ans="",temp="";
    int time = 1;
    if(msg.length() > 16)
        time = msg.length()/16 + 1;

    for(int i = 0 ; i < time ; i++)
    {
        temp = "";
        for(int j = 0 ; j < msg.length()-i*16 ; j++)
        {
            temp += msg[i*16+j];                
        }
        code = alice.code(temp,key);
        ans += bob.decode(code,key);
    }
    
    
    cout<<ans<<endl;

    return 0;
}