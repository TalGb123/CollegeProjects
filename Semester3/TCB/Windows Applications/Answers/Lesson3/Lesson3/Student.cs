using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lesson3
{
    internal class Student
    {
        private string name;
        private int age;
        private string firstLanguage;
        private string secondLanguage;
        private double firstLanguagePay;
        private double secondLanguagePay;
        private double totalPay;

        public Student(string name, int age, string firstLanguage, string secondLanguage, double firstLanguagePay, double secondLanguagePay)
        {
            this.name = name;
            this.age = age;
            this.firstLanguage = firstLanguage;
            this.secondLanguage = secondLanguage;
            this.firstLanguagePay = firstLanguagePay;
            this.secondLanguagePay = secondLanguagePay;
            this.totalPay = firstLanguagePay + secondLanguagePay;
        }
        public string Name
        {
            get { return name; }
            set { name = value; }
        }

        public int Age
        {
            get { return age; }
            set
            {
                if (value < 16 || value > 120)
                {
                    throw new ArgumentOutOfRangeException("Age must be between 16 and 120.");
                }
                age = value;
            }
        }

        public string FirstLanguage
        {
            get { return firstLanguage; }
            set
            {
                if (string.IsNullOrEmpty(value))
                {
                    throw new ArgumentException("First language cannot be empty.");
                }
                firstLanguage = value;
            }
        }

        public string SecondLanguage
        {
            get { return secondLanguage; }
            set
            {
                if (string.IsNullOrEmpty(value))
                {
                    throw new ArgumentException("Second language cannot be empty.");
                }
                if (value == firstLanguage)
                {
                    throw new ArgumentException("Second language must be different from the first language.");
                }
                secondLanguage = value;
            }
        }

        public double FirstLanguagePay
        {
            get { return firstLanguagePay; }
            set
            {
                if (value < 0)
                {
                    throw new ArgumentOutOfRangeException("Pay must be a non-negative value.");
                }
                firstLanguagePay = value;
            }
        }

        public double SecondLanguagePay
        {
            get { return secondLanguagePay; }
            set
            {
                if (value < 0)
                {
                    throw new ArgumentOutOfRangeException("Pay must be a non-negative value.");
                }
                secondLanguagePay = value;
            }
        }

        public double TotalPay
        {
            get { return totalPay; }
            set
            {
                if (value < 0)
                {
                    throw new ArgumentOutOfRangeException("Total pay must be a non-negative value.");
                }
                totalPay = value;
            }
        }
    }
}
