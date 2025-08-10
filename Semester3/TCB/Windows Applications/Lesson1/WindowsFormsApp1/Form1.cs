using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
        
        private void Form1_Load_1(object sender, EventArgs e)
        {

        }

        private void CalcBtn_Click(object sender, EventArgs e)
        {
            double val1, val2;
            if (string.IsNullOrWhiteSpace(ValTxtBx1.Text) || string.IsNullOrWhiteSpace(ValTxtBx2.Text)) {
                ResLbl.Text = "Please enter both values";
                return;
            }

            val1 = double.Parse(ValTxtBx1.Text);
            val2 = double.Parse(ValTxtBx2.Text);

            if (SumBtn.Checked)
            {
                ResLbl.Text = "Result: " + (val1 + val2).ToString();
            }
            else if (SubBtn.Checked)
            {
                ResLbl.Text = "Result: " + (val1 - val2).ToString();
            }
            else if (MultBtn.Checked)
            {
                ResLbl.Text = "Result: " + (val1 * val2).ToString();
            }
            else if (DivBtn.Checked)
            {
                if (val2 == 0)
                {
                    ResLbl.Text = "Cannot divide by zero";
                    return;
                }
                ResLbl.Text = "Result: " + (val1 / val2).ToString();
            }
            else
            {
                ResLbl.Text = "Please select an operation";
                return;
            }




        }

        private void ExitBtn_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
