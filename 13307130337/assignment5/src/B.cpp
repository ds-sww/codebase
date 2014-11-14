#include <iostream>
#include <cstring>
#include <string>
using namespace std;

string s;
int len;

int num[550];
int numHead;
//num is a stack
char oper[550];
int operHead;
//oper is a stack

int GetPri(char ch, string f)
{
  if(f == "in")
  //in the stack
  {
    switch (ch)
    {
      case ')': return 1;
      case '^': return 3;
      case '*':            //fall through
      case '/': return 5;
      case '+':            //fall through
      case '-': return 7;
      case '(': return 9;

      default:
        return -1;
    } //end switch
  } //end if
  
  if(f == "out")
  //out of the stack
  {
    switch (ch)
    {
      case '(': return 1;
      case '^': return 3;
      case '*':           // fall through
      case '/': return 6;
      case '+':           // fall through
      case '-': return 8;
      case ')': return 9;

      default:
        return -1;
    } //end switch
  } //end if
}

void CalOper()
{
  int temp;

  switch (oper[operHead])
  {
    case '+':
    {
      temp = num[numHead - 1] + num[numHead];
      break;
    }
    case '-':
    {
      temp = num[numHead - 1] - num[numHead];
      break;
    }
    case '*':
    {
      temp = num[numHead - 1] * num[numHead];
      break;
    }
    case '/':
    {
      if(num[numHead] != 0)
        temp = num[numHead - 1] / num[numHead];
      break;
    }
    case '^':
    {
      int pow = num[numHead];
      int base = num[numHead - 1];
      temp = 1;
      
      while (pow > 0)
      {
        if (pow & 1) temp *= base;
        base *= base;
        pow >>= 1;
      }
      break;
    } //end case '^'

    default:
      break;
  } //end swtich
  
  operHead--;
  numHead--;
  num[numHead] = temp;
  return;
}

void CalValue()
{
  int pre = -1;
  
  len = s.length();
  numHead = 0;
  operHead = 0;
  
  for (int i = 0; i < len; i++)
  {
    if ('0' <= s[i] && s[i] <= '9')
    {
      if(pre == -1) pre = 0;
      pre = pre * 10 + (s[i] - '0');
      continue;
    }

    if (pre != -1)
    {
      numHead++;
      num[numHead] = pre;
      pre = -1;
    }

    if (operHead == 0 || GetPri(oper[operHead], "in") >=
                         GetPri(s[i], "out"))
    {
      operHead++;
      oper[operHead] = s[i];
    }

    else if (s[i] == ')')
    {
      while (oper[operHead] != '(')
        CalOper();
      operHead--;
    }

    else
    {
      while (GetPri(oper[operHead], "in") <
             GetPri(s[i], "out"))
      {
        CalOper();
      }
      operHead++;
      oper[operHead] = s[i];
    } //end else
  } //end for
  return;
}

int main()
{
  while (cin >> s)
  {
    s = "(" + s + ")";
    CalValue();
    cout << num[1] << endl;
  }
  return 0;
}
