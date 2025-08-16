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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            this.Text = "Pizza Builder";
        }

        private void groupBox3_Enter(object sender, EventArgs e)
        {} 
        private string PizzaType()
        {
            string type = "";
            if (VeganRB.Checked)
            {
                type += "Vegeterian\n";
            }
            else if (CapriRB.Checked)
            {
                type += "Capricciosa\n";
            }
            else if (SupRB.Checked)
            {
                type += "Supreme\n";
            }
            return type;
        }

        private void radioButton4_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void radioButton5_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void PizzaSizeGrp_Enter(object sender, EventArgs e)
        { }

        private string PizzaSize()
        {
            string size = "";
            if (SmallRB.Checked)
            {
                size = "Small\n";
            }
            else if (MediumRB.Checked)
            {
                size = "Medium\n";
            }
            else if (LargeRB.Checked)
            {
                size = "Large\n";
            }
            return size;
        }

        private void PizzaToppingGrp_Enter(object sender, EventArgs e)
        {}
        private string[] PizzaToppings()
        {
            List<string> toppings = new List<string>();
            if (MushCB.Checked)
            {
                toppings.Add("Mushrooms");
            }
            if (OniCB.Checked)
            {
                toppings.Add("Onions");
            }
            if (TomaCB.Checked)
            {
                toppings.Add("Tomatoes");
            }
            if (GPepCB.Checked)
            {
                toppings.Add("Green Peppers");
            }
            return toppings.ToArray();
        }

        private void BuildBtn_Click(object sender, EventArgs e)
        {
            PizzaPartsLbl.Text = "Your Pizza:\n";
            PizzaPartsLbl.Text += "-----------------\n";
            if (VeganRB.Checked || CapriRB.Checked || SupRB.Checked)
            {
                PizzaPartsLbl.Text += PizzaType();
            }
            else return;
            if (SmallRB.Checked || MediumRB.Checked || LargeRB.Checked)
            {
                PizzaPartsLbl.Text += PizzaSize();
            }
            else return;
            string[] toppings = PizzaToppings();
            if (toppings.Length > 0)
            {
                PizzaPartsLbl.Text += "Toppings:\n";
                PizzaPartsLbl.Text += string.Join("\n", toppings) + "\n";
            }
            if (!PizzaPartsLbl.Visible)
            {
                PizzaPartsLbl.Visible = true;
            }
        }

        private void ExitBtn_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void ChangeBtn_Click(object sender, EventArgs e)
        {
            PizzaPartsLbl.Visible = false;
        }

        private void BillBtn_Click(object sender, EventArgs e)
        {
            Form2 form2 = new Form2();
            form2.Bill(PizzaType(), PizzaSize(), PizzaToppings());
            form2.ShowDialog();
        }
    }
}
