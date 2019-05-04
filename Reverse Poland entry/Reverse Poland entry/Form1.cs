using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Windows;

namespace Reverse_Poland_entry
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label9_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        char[] sign = new char[] { '*', '/', '+', '-', '^' };

        int Priority(char a)
        {
            switch (a)
            {
                case '^': return 4;
                case '*': return 3;
                case '/': return 3;
                case '-': return 2;
                case '+': return 2;
                case '(': return 1;
            }
            return 0;
        }


        private void button1_Click(object sender, EventArgs e)          //translate button
        {
            Stack<char> stack = new Stack<char>();      //here we will store our signs
            textBox8.Clear();

            char ss;
            String InStr, OutStr = "";           // input and output strings

            try   //check for trash
            {
                InStr = Convert.ToString(textBox7.Text);
            }
            catch (FormatException)
            {
                MessageBox.Show("Smth wrong in input string!");
                textBox7.Clear();
                return;
            }

            int len = InStr.Length, k;
            for (k = 0; k < len; k++)   //here!!!
            {
                ss = InStr[k];
                // 'open bracket' put in stack
                if (ss == '(') stack.Push(ss); else
                if (ss == ')')
                {
                    // out all operetions since '('
                    while (true)
                    {
                        if (stack.Count > 0)
                        {
                            if (stack.Peek() != '(')
                            {
                                OutStr += Convert.ToString(stack.Pop());
                            } else
                            {
                                stack.Pop();    //delete '('  
                                break;
                            }
                        } else
                            {
                                 MessageBox.Show("Missed '(' bracket !!!");
                                 return;
                            }
                    }
                } else
                // operend put in Out string
                if (ss >= 'a' && ss <= 'z') OutStr += ss; else
                /* if chra is sign and priority is equal or bigger - put all operetors in Input string */
                if (sign.Contains(ss))
                {
                    while (stack.Count() > 0 && Priority(stack.Peek()) >= Priority(ss))
                    {
                        OutStr += stack.Pop();                
                    }
                    stack.Push(ss);
                }
            }
            // if Stack is not empty - put all operations to the out string
            while (stack.Count() > 0)
            {
                if(stack.Peek()=='(')
                {
                    MessageBox.Show("You missed ')' bracket!");
                    return;
                } else
                OutStr += stack.Pop();                // write this
            }
            textBox8.AppendText(OutStr);       // and show this out string in the window
        }


        private void button2_Click(object sender, EventArgs e)
        {
            Stack<double> stack = new Stack<double>();      //where we will store our results
            textBox9.Clear();

            String str = textBox8.Text;
            if(str.Length==0)
            {
                MessageBox.Show("Just make RPE before!");
                return;
            }

            Dictionary<char, double> temp = new Dictionary<char, double>();  //yep, it's map

            try
            {
                temp.Add('a', Convert.ToDouble(textBox1.Text));
                temp.Add('b', Convert.ToDouble(textBox2.Text));
                temp.Add('c', Convert.ToDouble(textBox3.Text));
                temp.Add('d', Convert.ToDouble(textBox4.Text));
                temp.Add('e', Convert.ToDouble(textBox5.Text));
            }
            catch(FormatException)
            {
                MessageBox.Show("irregular data entered!");
                return;
            }

            char ch;
            double op1, op2,result=0;
  
            for (int i = 0; i < str.Length; i++)
            {
                ch = str[i];
                if (!sign.Contains(ch)) stack.Push(temp[ch]); //if cher isn't a sign put him to the stack (all variables in stack)
                else
                {
                    op1 = stack.Pop();        //get value from map
                    op2 = stack.Pop();
                    switch (ch)
                    {
                        case '+': result = op2 + op1; break;
                        case '-': result = op2 - op1; break;
                        case '*': result = op2 * op1; break;
                        case '/': result = op2 / op1; break;
                        case '^': result = Math.Pow(op2, op1); break;
                    }
                    stack.Push(result);        //put result into stack
                }
            }
            textBox9.AppendText(Convert.ToString(result));
        }
    }
}