using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lesson5
{
    public partial class Form1 : Form
    {
        private Dictionary dict;
        public Form1()
        {
            InitializeComponent();
            dict = new Dictionary();
        }
        private void UploadPhotoBTN_Click(object sender, EventArgs e)
        {
            using (OpenFileDialog openFileDialog = new OpenFileDialog())
            {
                openFileDialog.Filter = "Image Files|*.jpg;*.jpeg;*.png;*.bmp;*.gif";
                openFileDialog.Title = "Select an Image";

                if (openFileDialog.ShowDialog() == DialogResult.OK)
                {
                    WordIB.Image = Image.FromFile(openFileDialog.FileName);
                }
            }
        }

        private void FindEngBTN_Click(object sender, EventArgs e)
        {
            if (FindEngHebTB.Text == "")
            {
                return;
            }
            FindEngEngTB.Text = dict.TranslateFromHebrew(FindEngHebTB.Text).getEnglishWord();
            WordIB.Image = dict.TranslateFromHebrew(FindEngHebTB.Text).getPicturePath() == null ? null : Image.FromFile(dict.TranslateFromHebrew(FindEngHebTB.Text).getPicturePath());
        }

        private void FindHebBTN_Click(object sender, EventArgs e)
        {
            if (FindHebEngTB.Text == "")
            {
                return;
            }
            FindHebHebTB.Text = dict.TranslateFromEnglish(FindHebEngTB.Text).getHebrewWord();
            WordIB.Image = dict.TranslateFromEnglish(FindHebEngTB.Text).getPicturePath() == null ? null : Image.FromFile(dict.TranslateFromEnglish(FindHebEngTB.Text).getPicturePath());
        }

        private void AddBTN_Click(object sender, EventArgs e)
        {
            if (AddEngTB.Text == "" || AddHebTB.Text == "")
            {
                return;
            }
            Word w = new Word(AddHebTB.Text, AddEngTB.Text, WordIB.ImageLocation);
            dict.AddWord(w);
            WordIB.Image = null;
            MessageBox.Show("Word added successfully");
        }

        private void ShowDicBTN_Click(object sender, EventArgs e)
        {
            if (dict == null)
            {
                return;
            }
            MessageBox.Show(dict.showDictionary());
        }

        private void ClearBTN_Click(object sender, EventArgs e)
        {
            dict.Clear();
        }

        private void UploadPicBTN_Click(object sender, EventArgs e)
        {
            using (OpenFileDialog openFileDialog = new OpenFileDialog())
            {
                openFileDialog.Filter = "Image Files|*.jpg;*.jpeg;*.png;*.bmp;*.gif";
                openFileDialog.Title = "Select an Image";
                if (openFileDialog.ShowDialog() == DialogResult.OK)
                {
                    WordIB.Image = Image.FromFile(openFileDialog.FileName);
                }
            }
        }
    }
}
