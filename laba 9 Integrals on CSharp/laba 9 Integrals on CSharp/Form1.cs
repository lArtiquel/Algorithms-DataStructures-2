using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace laba_9_Integrals_on_CSharp
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

        private void button1_Click(object sender, EventArgs e)
        {
            //clear fields//
            chart1.Series[0].Points.Clear();
            richTextBox1.Clear();

            double a = 0, b = 4;
            double y=0,dy=0,In=0;
            int n;

            try   //check for trash
            {
                n = Convert.ToInt32(textBox1.Text);
            }
            catch (FormatException)
            {
                MessageBox.Show("Введено не число!");
                textBox1.Clear();
                return;
            }

            //chart module//
            //масштабирование графика по осям
            chart1.ChartAreas[0].AxisX.ScaleView.Zoom(0, 4);
            chart1.ChartAreas[0].CursorX.IsUserEnabled = true;
            chart1.ChartAreas[0].CursorX.IsUserSelectionEnabled = true;
            chart1.ChartAreas[0].AxisX.ScaleView.Zoomable = true;

            chart1.ChartAreas[0].AxisY.ScaleView.Zoom(-1, 1);
            chart1.ChartAreas[0].CursorY.IsUserEnabled = true;
            chart1.ChartAreas[0].CursorY.IsUserSelectionEnabled = true;
            chart1.ChartAreas[0].AxisY.ScaleView.Zoomable = true;

            if (n > 1)
            {
                dy = (b - a) / n;           //длина каждого отрезка интегрирования по х(шаг)
                y = (f(a) + f(b)) / 2;          //сумма значений подынтегральных функций на концах отрезков(по формуле)
                for (int i = 1; i < n; i++) //сумма значений подынтегральной функции на отрезках(с первого и до предпоследнего)
                    y += f(a + dy * i); //инкрементим данные значения к уже имеющимся на концах
                In = I(a, b, n, y);         //и берем интеграл по уже извесному 
                richTextBox1.AppendText("finded integral is equal " + In.ToString() + "\n");
                richTextBox1.AppendText("and now i did verification by Newton-Leibniz formula:" + (IN_L_Verification(b) - IN_L_Verification(a)).ToString() + "\n");
            }
            else { MessageBox.Show("Wrong data!");return; }       //слишком мало отрезков разбиения

            //draw graphic//
            for (double i = a; i < b; i += dy)
            {
                chart1.Series[0].Points.AddXY(i, f(i));
            }
        }

        double f(double x) //сама функция
        {
            return Math.Sin(x) * Math.Sin(x) - x / 5;
        }

        double I(double a, double b, int n, double y) //вычисление интеграла методом трапеций
        {
            return (b - a) / n * y;
        }
        //так как интеграл берущийся, можно организовать провероку
        double IN_L_Verification(double x)   //высчитанное значение интеграла в точке a and b для проверки по формуле Ньютона-Лейбница
        {
            return 1.0 / 10.0 * ((-x * (x - 5)) - 5 * Math.Sin(x) * Math.Cos(x));
        }
    }
}
