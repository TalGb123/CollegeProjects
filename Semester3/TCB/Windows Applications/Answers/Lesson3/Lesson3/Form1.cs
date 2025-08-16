using Lesson3;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lesson3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private List<Student> students = new List<Student>(10);

        private void CheckDetailsBTN_Click(object sender, EventArgs e)
        {
            string error = "";
            if (StudentNameTB == null)
            {
                error += "Please enter a name.\n";
            }
            try
            {
                int age = int.Parse(StudentAgeTB.Text);
                if (age < 16 || age > 120)
                {
                    error += "Please enter a valid age between 16 and 120.\n";
                }

                if (FirstLangCB.SelectedIndex == -1)
                {
                    error += "Please select a first language.\n";
                }
                else if (SecondLangCB.SelectedIndex == -1)
                {
                    error += "Please select a second language.\n";
                }
                else if (FirstLangCB.SelectedIndex == SecondLangCB.SelectedIndex)
                {
                    error += "Please select different languages.\n";
                }
                else if ((FirstLangCB.SelectedIndex == 5 || SecondLangCB.SelectedIndex == 5) && age < 18)
                {
                    error += "You must be at least 18 years old to select 'Chinese' as a language.\n";
                }
            }
            catch
            {
                error += "Please enter a valid age.";
            }

            if (error != "")
            {
                MessageBox.Show(error, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                MessageBox.Show("Details are valid.", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
                PaymentDetailsGRP.Enabled = true;
            }
        }

        private void CreditCardPayRB_CheckedChanged(object sender, EventArgs e)
        {
            PaySplitLB.Enabled = true;
            PaySplitLB.SelectedIndex = 0;
        }

        private void CashPayRB_CheckedChanged(object sender, EventArgs e)
        {
            PaySplitLB.Enabled = false;
            PaySplitLB.SelectedIndex = -1;
        }

        private double[] CalculatePay()
        {
            double first = 1000;
            double second = 800;

            if (int.Parse(StudentAgeTB.Text) < 25)
            {
                second *= 0.9;
            }
            if (FirstLangCB.SelectedIndex == 2)
            {
                first -= 150;
            }

            if (CreditCardPayRB.Checked && PaySplitLB.SelectedIndex > 0)
            {
                switch (PaySplitLB.SelectedIndex)
                {
                    case 1:
                        first *= 1.02;
                        second *= 1.02;
                        break;
                    case 2:
                        first *= 1.04;
                        second *= 1.04;
                        break;
                    case 3:
                        first *= 1.07;
                        second *= 1.07;
                        break;
                }
            }
            double[] arr = { first, second };
            return arr;
        }

        private string GetPaymentMessage(Student st = null)
        {
            if (st != null)
            {
                return $"{st.Name}: " +
                       $"{st.FirstLanguage} {st.FirstLanguagePay.ToString()}, " +
                       $"{st.SecondLanguage} {st.SecondLanguagePay.ToString()}, " +
                       $"Payment {st.TotalPay.ToString()}";
            }

            double first = CalculatePay()[0];
            double second = CalculatePay()[1];
            double sum = first + second;

            return $"{StudentNameTB.Text}: " +
                   $"{FirstLangCB.SelectedItem} {first.ToString()}, " +
                   $"{SecondLangCB.SelectedItem} {second.ToString()}, " +
                   $"Payment {sum.ToString()}";
        }

        private void CheckPaymentBTN_Click(object sender, EventArgs e)
        {
            string msg = GetPaymentMessage();
            MessageBox.Show(msg, "Payment Details", MessageBoxButtons.OK, MessageBoxIcon.Information);
            SavePaymentBTN.Enabled = true;  
        }

        private void SavePaymentBTN_Click(object sender, EventArgs e)
        {   
            if (ShowStudentsBTN.Enabled == false)
            {
                ShowStudentsBTN.Enabled = true;
            }

            if (students.Count >= 10)
            {
                MessageBox.Show("Maximum number of students reached.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            Student st = new Student(
                StudentNameTB.Text,
                int.Parse(StudentAgeTB.Text),
                FirstLangCB.SelectedItem.ToString(),
                SecondLangCB.SelectedItem.ToString(),
                CalculatePay()[0],
                CalculatePay()[1]
            );

            students.Add(st);
            MessageBox.Show("Payment details saved successfully.", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);

            SavePaymentBTN.Enabled = false;
            PaymentDetailsGRP.Enabled = false;
        }

        private void ShowStudentsBTN_Click(object sender, EventArgs e)
        {
            string msg = "Student List:\n";
            foreach (Student st in students)
            {
                if (st.FirstLanguage == "English" || st.SecondLanguage == "English")
                {
                    msg += GetPaymentMessage(st) + "\n";
                }
            }
            if (msg == "Student List:\n")
            {
                msg = "No students with English language found.";
            }

            Form2 form2 = new Form2();
            form2.ShowStudents(msg);
            form2.Show();
        }
    }
}
