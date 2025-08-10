using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp2
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
            this.Text = "Your bill";
        }

        private void CloseBtn_Click(object sender, EventArgs e)
        {
            Close();
        }

        public void Bill(string type, string size, string[] top)
        {
            TypeLbl.Text = type + "\n";
            TypeLbl.Text += size + "\n";
            if (top.Length > 0)
            {
                for (int i = 0; i < top.Length; i++)
                {
                    TypeLbl.Text += top[i] + "\n";
                }
            }

            double sum = 0;
            if (type == "Vegeterian\n")
            {
                PriceLbl.Text += "2$\n";
                sum += 2;
            }
            else if (type == "Capricciosa\n")
            {
                PriceLbl.Text += "2.5$\n";
                sum += 2.5;
            }
            else
            {
                PriceLbl.Text += "3$\n";
                sum += 3;
            }

            double sizeprice = 0;
            if (size == "Small\n")
            {
                PriceLbl.Text += "0$\n";
                sum += 1;
            }
            else if (size == "Medium\n")
            {
                sizeprice = 0.5 * sum;
                PriceLbl.Text += $"{sizeprice}$\n";
                sum += sizeprice;
            }
            else
            {
                sizeprice = 0.7 * sum;
                PriceLbl.Text += $"{sizeprice}$\n";
                sum += sizeprice;
            }

            if (top.Length > 0)
            {
                for (int i = 0; i < top.Length; i++)
                {
                    if (top[i] == "Mushrooms")
                    {
                        PriceLbl.Text += "0.5$\n";
                        sum += 0.5;
                    }
                    else if (top[i] == "Onions")
                    {
                        PriceLbl.Text += "0.4$\n";
                        sum += 0.7;
                    }
                    else if (top[i] == "Tomatoes")
                    {
                        PriceLbl.Text += "0.3$\n";
                        sum += 0.3;
                    }
                    else if (top[i] == "Green Peppers")
                    {
                        PriceLbl.Text += "0.2$\n";
                        sum += 0.2;
                    }
                }
            }
            PriceLbl.Text += $"Total: {sum}$\n";

            if (!TypeLbl.Visible)
            {
                TypeLbl.Visible = true;
            }
            if (!PriceLbl.Visible)
            {
                PriceLbl.Visible = true;
            }
        }
    }
}
